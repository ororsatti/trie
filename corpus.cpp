#include "corpus.h"
#include "tokenizer.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
Corpus::Corpus(){};
Corpus::~Corpus(){};
bool Corpus::is_doc_exists(std::string doc_key) {
  return this->docs.find(doc_key) != docs.end();
}

bool Corpus::add_doc(std::string doc_key, std::string doc_content) {
  if (this->is_doc_exists(doc_key)) {
    std::cout << "Warning: you are trying to insert an existing document"
              << std::endl;
    return false;
  }
  vector<std::string> tokens = tokenize(doc_content);
  for (const auto &token : tokens) {
    this->index.insert(token, doc_key);
  }
  auto doc = make_shared<Document>();
  doc->words_count = tokens.size();
  doc->key = doc_key;
  this->docs.insert({doc_key, doc});
  return true;
}

void Corpus::remove_doc(std::string doc_key, std::string doc_content) {
  this->index.remove_document(doc_content, doc_key);
  this->docs.erase(doc_key);
}
void Corpus::print() { this->index.print_tree(); }

/*
 * IDF(t) = ln (((N - DF + 0.5) / (DF + 0.5)) + 1)
 * N - total # of documents
 * DF - how many documents containing the term t;
 * ln - natural log
 * */
double Corpus::calculate_idf(std::string key) {
  int begin = 0;
  size_t docs_count = this->docs.size(); // get_corpus_size(corpus);
  auto node = this->index.find_exact_match(key);

  if (node == nullptr)
    return 0;

  auto term_data = node->get_leaf();
  size_t df = term_data->get_all_doc_keys().size();

  double numerator = docs_count - df + 0.5;
  double denominator = df + 0.5;

  return log(1 + (numerator / denominator));
}

double Corpus::get_avg_doc_len() {
  size_t avg = 0;
  for (auto doc : this->docs) {
    size_t wc = doc.second->words_count;
    avg += wc;
  }
  return (double)avg / this->docs.size();
}

size_t Corpus::get_doc_word_count(std::string doc_key) {
  auto doc = this->docs.find(doc_key);
  if (doc == this->docs.end())
    return 0;

  return doc->second->words_count;
}

double Corpus::calculate_bm25_for_doc(std::string key, std::string doc_key) {
  std::shared_ptr<Node> n = this->index.find_exact_match(key);
  double k = 1.25;
  double b = 0.75;
  double dlen = this->get_doc_word_count(doc_key);
  double avgl = this->get_avg_doc_len();
  if (n == nullptr) {
    return 0;
  }
  std::shared_ptr<TermData> td = n->get_leaf();
  size_t freq = td->get_term_count(doc_key);
  double numerator = freq * (k + 1);
  double denumirator = freq + k * (1 - b + (b * (dlen / avgl)));
  double idf = this->calculate_idf(key);
  double tf = numerator / denumirator;

  return tf * idf;
}

vector<QueryResult> Corpus::bm25(vector<std::string> query) {
  std::unordered_map<std::string, QueryResult> qr;

  for (std::string &word : query) {
    std::shared_ptr<Node> n = this->index.find_exact_match(word);
    if (n == nullptr) {
      continue;
    }
    std::shared_ptr<TermData> td = n->get_leaf();
    auto docs = td->get_all_doc_keys();

    for (std::string &doc_key : docs) {
      auto doc_instance = qr.find(doc_key);
      double doc_score = calculate_bm25_for_doc(word, doc_key);

      if (doc_instance == qr.end()) {
        QueryResult dqr = {
            .doc_key = doc_key,
            .score = doc_score,
        };
        qr.insert({doc_key, dqr});
      } else {
        doc_instance->second.score += doc_score;
      }
    }
  }
  vector<QueryResult> res;
  for (std::unordered_map<std::string, QueryResult>::iterator it = qr.begin();
       it != qr.end(); ++it) {
    res.push_back(it->second);
  }
  return res;
}
bool compare_query_results(const QueryResult &a, const QueryResult &b) {
  return a.score > b.score;
}
vector<QueryResult> Corpus::search(std::string query) {
  auto split_query = tokenize(query);
  std::vector<QueryResult> unsorted = bm25(split_query);
  std::sort(unsorted.begin(), unsorted.end(), compare_query_results);
  return unsorted;
}

shared_ptr<Node> Corpus::find_node(std::string query) {
  return this->index.find_exact_match(query);
}
