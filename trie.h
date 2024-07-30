#include "term_data.h"
#include <iostream>
#include <memory>
#include <unordered_map>

#pragma once

typedef struct {
  int node_split_index;
  int key_split_index;
} Comperession;

class Node {

private:
  std::string key;
  TermData leaf;

public:
  std::unordered_map<char, Node *> children;

  Node();
  Node(const Node &other);
  Node(std::string key);
  ~Node();

  bool is_leaf() const;
  std::string get_key() const;
  void set_key(std::string new_key);
  void create_leaf(std::string data, std::string initial_doc_key);
  TermData &get_leaf();
  TermData &get_leaf() const;
  void delete_leaf();
  void add_doc_or_increment(std::string doc_key);
  bool move_leaf_to(Node *new_owner);
  // void merge_nodes(std::shared_ptr<Node> node_to_merge);
  Comperession compare(std::string key, int begin) const;
  // std::shared_ptr<Node> migrate_children(std::string key);
  // static std::shared_ptr<Node> create_leaf_node(std::string key,
  //                                               std::string data,
  //                                               std::string initial_doc_key);
};

class Trie {
private:
  Node *root;

public:
  Trie();
  ~Trie();
  // finds the doc @key, copys the node and its childs, I am not sure if thats
  // the right move
  const Node *search(Node *node, std::string key, int &begin);
  bool erase(Node *curr, std::string key, int begin, std::string doc_key);
  // finds the doc @key, copys the node and its childs, I am not sure if thats
  // the right move
  const Node *find_exact_match(std::string key);
  void truncate(Node *curr);
  void remove(std::string key, std::string doc_key);
  void remove_document(std::string content, std::string doc_key);
  // int get_document_frequency_for_term(std::string term);
  void print(const Node *node, const std::string prefix, int level) const;
  Node *create_path(Node *node, std::string key, std::string doc_key);
  void insert(std::string word, std::string doc_key);
  void print_tree() const;
};
