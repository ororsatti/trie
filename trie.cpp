#include "trie.h"
#include "tokenizer.h"
#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

Node::Node(std::string key) { this->key = key; }

Node::Node() {}
Node::~Node() {
  for (auto pair : this->children) {
    delete pair.second;
  }

  this->children.clear();
  // delete this;
}

bool Node::is_leaf() const { return this->leaf.get() != nullptr; }

std::shared_ptr<TermData> Node::get_leaf() const { return this->leaf; }

void Node::add_doc_or_increment(std::string doc_key) {
  if (this->leaf->is_doc_exits(doc_key)) {
    this->leaf->inc_term_count(doc_key);
  } else {
    this->leaf->add_doc(doc_key, 1);
  }
}

std::string Node::get_key() const { return this->key; }

void Node::set_key(std::string new_key) { this->key = new_key; }
// void Node::delete_leaf() { this->leaf.reset(); }

void Node::create_leaf(std::string data, std::string initial_doc_key) {
  if (this->leaf.get()) {
    return;
  }
  this->leaf = std::make_unique<TermData>(data, initial_doc_key);
}

Comperession Node::compare(std::string key, int begin) {
  Comperession c = {
      .node_split_index = 0,
      .key_split_index = begin,
  };

  while (c.key_split_index < key.length() ||
         c.node_split_index < this->key.length()) {
    if (key[c.key_split_index] != this->key[c.node_split_index])
      break;
    c.key_split_index++;
    c.node_split_index++;
  }
  return c;
}

Trie::Trie() { this->root = new Node(); }

// std::shared_ptr<Node> Trie::search(std::shared_ptr<Node> node, std::string
// key,
//                                    int &begin) {
//   Comperession comp = node->compare(key, begin);
//
//   // word is a prefix of node.value, or they are equal
//   if (comp.node_split_index >= key.length()) {
//     return node;
//   }
//
//   // node.value is a prefix of word
//   if (comp.node_split_index >= node->get_key().length()) {
//     auto next = node->children.find(key[comp.key_split_index]);
//     if (next == node->children.end()) {
//       return node;
//     }
//     begin = comp.key_split_index;
//     return Trie::search(next->second, key, begin);
//   }
//
//   return node;
// }

// void Trie::truncate(std::shared_ptr<Node> curr) {
//   auto child = curr->children.begin()->second;
//   curr->children.clear();
//   curr->set_key(curr->get_key() + child->get_key());
//   curr->children = child->children;
//   if (child->is_leaf()) {
//     child->move_leaf_to(curr);
//   }
// }
//
// bool Trie::erase(std::shared_ptr<Node> curr, std::string key, int begin,
//                  std::string doc_key) {
//   // check if we have a match
//   if (curr != nullptr && key.substr(begin, key.length()) == curr->get_key())
//   {
//     return curr->is_leaf();
//   }
//
//   // finding the next prefix in the trie
//   int new_begin = begin + curr->get_key().length();
//   // if its larger than the length of the key there is no point to move
//   // forward
//   if (new_begin > key.length())
//     return false;
//
//   // finding the next child
//   auto next_pair = curr->children.find(key[new_begin]);
//   if (next_pair == curr->children.end())
//     return false;
//
//   auto next = next_pair->second;
//   // if the next child is matching the word we want to remove
//   if (erase(next, key, new_begin, doc_key)) {
//     auto children = next->children;
//     // when there are children we do not want to erase the node completely
//     but
//     // handle it with care
//     // 1. we remove the doc from the leaf.
//     // 2. we check if the doc is empty after the removal, and if so, we
//     remove
//     // the leaf itslef.
//     // 3. if the node is no longer a leaf node, and have only one child, we
//     // truncate it with its next child
//     if (!children.empty()) {
//       next->get_leaf()->remove_doc(doc_key);
//       if (next->get_leaf()->empty()) {
//         next->delete_leaf();
//       }
//       if (next->children.size() == 1) {
//         truncate(next);
//       }
//     } else {
//       // in the case that the next node has no children we can remove it
//       // safely if its not a leaf
//       next->get_leaf()->remove_doc(doc_key);
//       if (next->get_leaf()->empty()) {
//         curr->children.erase(key[new_begin]);
//       }
//       // making sure that we are not truncating to the root
//       if (curr->children.size() == 1 && !curr->get_key().empty()) {
//         truncate(curr);
//       }
//     }
//   }
//   return false;
// }

// void Trie::remove(std::string key, std::string doc_key) {
//   erase(this->root, key, 0, doc_key);
// }

// void Trie::remove_document(std::string content, std::string doc_key) {
//   auto words = tokenize(content);
//   for (auto word : words) {
//     this->remove(word, doc_key);
//   }
// }

// int Trie::get_document_frequency_for_term(std::string term) {
//   int begin = 0;
//   auto node = search(root, term, begin);
//   return 0;
// }

std::string print_leaf(std::shared_ptr<TermData> leaf) {
  std::string leaf_string = "";

  std::vector<std::string> keys = leaf->get_all_doc_keys();
  leaf_string += "( ";
  leaf_string += leaf->get_data();
  leaf_string += " ): [ ";
  for (std::string key : keys) {
    leaf_string += key;
    leaf_string += ":";
    leaf_string += std::to_string(leaf->get_term_count(key));
    leaf_string += " ";
  }
  leaf_string += "]";
  return leaf_string;
}
void Trie::print(const Node *node, const std::string prefix, int level) const {
  if (node == nullptr) {
    std::cout << "EMPTY" << std::endl;
    return;
  }

  if (node->get_key().empty() && node->children.empty()) {
    std::cout << "EMPTY" << std::endl;
    return;
  }

  if (node != root) {
    std::cout << std::string(level * 2, ' ') << prefix << " "
              << (node->is_leaf() ? print_leaf(node->get_leaf()) : ">")
              << std::endl;
  }

  for (const auto &child : node->children) {
    if (child.second == nullptr) {
      std::cout << "warning: you have a bug on key :" << child.second
                << std::endl;
    }
    if (child.second != nullptr) {
      print(child.second, child.second->get_key(), level + 2);
    }
  }
};

void Trie::print_tree() const { print(this->root, "", -2); }

std::string get_string_comp(Comperession comp) {
  return "key_split_index: " + to_string(comp.key_split_index) + "\n" +
         "node_split_index: " + to_string(comp.node_split_index) + "\n";
}
Node *Trie::create_path(Node *node, std::string key, std::string doc_key) {
  size_t len = key.size();
  Node *selected_node = node;
  Node *found_node = nullptr;
  for (size_t pos = 0; selected_node != nullptr && pos < len;) {
    auto pair = selected_node->children.find(key[pos]);

    if (pair == selected_node->children.end()) {
      auto new_child = new Node(key.substr(pos, key.length()));
      selected_node->children.insert({key[pos], new_child});
      return new_child;
    } else {
      Node *node = pair->second;
      Comperession cmp = node->compare(key, pos);

      // if the current node key is shorter
      if (cmp.node_split_index == node->get_key().length()) {
        selected_node = node;
      } else {
        std::string nkey = node->get_key();
        auto intermediate = new Node(nkey.substr(0, cmp.node_split_index));
        node->set_key(nkey.substr(cmp.node_split_index, nkey.length()));
        intermediate->children.insert({node->get_key()[0], node});
        selected_node->children.erase(nkey[0]);
        selected_node->children.insert({nkey[0], intermediate});
        selected_node = intermediate;
      }

      pos = cmp.key_split_index;
    }
  }
  return selected_node;
}

void Trie::insert2(std::string key, std::string doc_key) {
  auto n = this->create_path(this->root, key, doc_key);
  if (n->is_leaf()) {
    // std::cout << "dockey: " << doc_key << std::endl;
    n->add_doc_or_increment(doc_key);
  } else {
    n->create_leaf(key, doc_key);
  }
}

Trie::~Trie() { delete this->root; }
