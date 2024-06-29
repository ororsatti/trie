#include "term_data.h"
#include <iostream>
#include <memory>
#include <unordered_map>

typedef struct {
  int node_split_index;
  int key_split_index;
} Comperession;

class Node {

private:
  std::string key;
  std::shared_ptr<TermData> leaf;

public:
  std::unordered_map<char, std::shared_ptr<Node>> children;

  Node();
  Node(std::string key);

  bool is_leaf();
  std::string get_key();
  void set_key(std::string new_key);
  void create_leaf(std::string data, std::string initial_doc_key);
  std::shared_ptr<TermData> get_leaf();
  void delete_leaf();
  void add_doc_or_increment(std::string doc_key);
  void move_leaf_to(std::shared_ptr<Node> new_owner);
  void merge_nodes(std::shared_ptr<Node> node_to_merge);
  Comperession compare(std::string key, int begin);
  std::shared_ptr<Node> migrate_children(std::string key);
  static std::shared_ptr<Node> create_leaf_node(std::string key,
                                                std::string data,
                                                std::string initial_doc_key);
};

class Trie {
private:
  std::shared_ptr<Node> root;

public:
  Trie();
  std::shared_ptr<Node> search(std::shared_ptr<Node> node, std::string key,
                               int &begin);
  void insert(std::string word, std::string doc_key);
  bool erase(std::shared_ptr<Node> curr, std::string key, int begin,
             std::string doc_key);
  void truncate(std::shared_ptr<Node> curr);
  void remove(std::string key, std::string doc_key);
  void remove_document(std::string content, std::string doc_key);
  void print(const std::shared_ptr<Node> node, const std::string prefix,
             int level) const;
  void print_tree() const;
};
