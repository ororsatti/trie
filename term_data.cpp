#include "term_data.h"
#include <iostream>
#include <string>
#include <vector>
std::string TermData::get_data() { return this->term; }

size_t TermData::get_term_count(std::string doc_id) {
  auto pair = this->docs_term_count.find(doc_id);
  if (pair == this->docs_term_count.end())
    return 0;
  return pair->second;
}
void TermData::add_doc(std::string doc_id, size_t term_count) {
  this->docs_term_count[doc_id] = term_count;
}
bool TermData::remove_doc(std::string doc_id) {
  return (bool)this->docs_term_count.erase(doc_id);
}

void TermData::inc_term_count(std::string doc_id) {
  if (this->docs_term_count.find(doc_id) != this->docs_term_count.end()) {
    this->docs_term_count[doc_id]++;
  }
}

TermData::TermData(std::string term, std::string initial_doc_key) {
  this->term = term;
  this->docs_term_count[initial_doc_key] = 1;
}

std::vector<std::string> TermData::get_all_doc_keys() {
  std::vector<std::string> doc_keys;
  for (auto pair : this->docs_term_count) {
    doc_keys.push_back(pair.first);
  }
  return doc_keys;
}

bool TermData::is_doc_exits(std::string doc_key) {
  return this->docs_term_count.find(doc_key) != this->docs_term_count.end();
}

bool TermData::empty() { return this->docs_term_count.empty(); }
