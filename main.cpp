#include "corpus.h"
#include "tokenizer.h"
#include "trie.h"
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

// Function to read a file into a string
std::string read_file(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    return "";
  }

  std::string content((std::istreambuf_iterator<char>(file)),
                      std::istreambuf_iterator<char>());
  return content;
}

std::vector<std::pair<std::string, std::string>>
parseJsonContent(const std::string &jsonContent) {
  std::vector<std::pair<std::string, std::string>> contentList;

  size_t pos = 0;
  while ((pos = jsonContent.find("\"title\":", pos)) != std::string::npos) {
    pos = jsonContent.find("\"", pos + 8); // Move to the start of title
    size_t start = pos + 1;
    size_t end = jsonContent.find("\"", start);
    if (end != std::string::npos) {
      std::string title = jsonContent.substr(start, end - start);
      pos = jsonContent.find("\"content\":", end);
      pos = jsonContent.find("\"", pos + 10); // Move to the start of content
      start = pos + 1;
      end = jsonContent.find("\"", start);
      if (end != std::string::npos) {
        std::string content = jsonContent.substr(start, end - start);
        contentList.push_back(std::make_pair(title, content));
        pos = end;
      } else {
        break;
      }
    } else {
      break;
    }
  }

  return contentList;
}

void test_content_list() {
  Corpus c;
  auto x = parseJsonContent(read_file("test.json"));
  auto start = std::chrono::high_resolution_clock::now();
  for (const auto &pair : x) {
    c.add_doc(pair.first, pair.second);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  std::cout << "Time taken by function: " << duration.count() << " seconds"
            << std::endl;
  vector<QueryResult> res = c.search("London is so beautiful this year");
  // std::cout << res.size() << "\n";
  for (const auto el : res) {
    std::cout << el.doc_key << " " << el.score << "\n";
  }
}

int main(void) {
  Trie *t;
  Corpus c;
  t = new Trie();
  std::string doc1 = "doc1";
  std::string doc2 = "doc2";
  std::string doc1content = "this is my content";
  std::string doc2content = "this is a test content for doc 2";

  c.add_doc(doc1, doc1content);
  c.add_doc(doc2, doc2content);
  // vector<QueryResult> res = c.search("this my");
  // for (const auto el : res) {
  //   std::cout << el.doc_key << " " << el.score << "\n";
  // }
  // c.remove_doc(doc2, doc2content);
  // std::string content =
  //     "this! is a test this is so, fast,100st and awesome, cool. ";
  // auto x = tokenize_regex(content);
  // for (const std::string word : x) {
  //   std::cout << word << "\n";
  // }
  test_content_list();
  // c.print();
  // const Node *x = c.find_node("this");
  // //
  // if (x == nullptr) {
  //   std::cout << "didnt find " << "this" << "\n";
  //   delete t;
  //   return 0;
  // }
  // std::cout << x->get_key() << "\n";
  // t->print_tree();
  // t->remove(word1, "doc1");
  // t->remove(word1, "doc2");
  // t->print_tree();
  // delete t;
  return 0;
}
