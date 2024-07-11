#include "trie.h"
#include <cstddef>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#pragma once

typedef struct {
  std::string key;
  size_t words_count;
} Document;

typedef struct {
  std::string doc_key;
  double score;
} QueryResult;

class Corpus {
private:
  std::unordered_map<std::string, std::shared_ptr<Document>> docs;
  Trie index;
  std::string gen_doc_short_key(std::string doc_key);
  vector<QueryResult> bm25(vector<std::string> query);
  double calculate_idf(std::string word);
  double calculate_bm25_for_doc(std::string query, std::string doc_key);

public:
  Corpus();
  ~Corpus();
  bool is_doc_exists(std::string doc_key);
  bool add_doc(std::string doc_key, std::string doc_content);
  void remove_doc(std::string doc_key, std::string doc_content);
  vector<QueryResult> search(std::string query);
  shared_ptr<Node> find_node(std::string word);
  size_t get_doc_word_count(std::string doc_key);
  double get_avg_doc_len();
  void print();
};
