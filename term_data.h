#ifndef SEARCH_TERM_DATA
#define SEARCH_TERM_DATA
#include <string>
#include <unordered_map>
#include <vector>

#pragma once

using namespace std;
class TermData {
private:
  std::string term;
  // doc_id to word count
  std::unordered_map<std::string, size_t> docs_term_count;

public:
  ~TermData();
  TermData();
  TermData(TermData &&src);
  TermData(std::string &&term, std::string initial_doc_key);
  TermData &operator=(TermData &&other);
  std::string get_data();
  size_t get_term_count(std::string doc_id);
  void add_doc(std::string doc_id, size_t term_count);
  std::vector<std::string> get_all_doc_keys();
  void inc_term_count(std::string doc_id);
  bool remove_doc(std::string doc_id);
  bool is_doc_exists(std::string doc_key);
  bool empty() const;
};

#endif
