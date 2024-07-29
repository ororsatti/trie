#include "corpus.h"
#include "tokenizer.h"
#include "trie.h"
#include <fstream>
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
  Trie *t = new Trie();
  auto x = parseJsonContent(read_file("test.json"));
  auto start = std::chrono::high_resolution_clock::now();
  for (const auto &pair : x) {
    vector<string> words = tokenize(pair.second);
    for (const auto &word : words) {
      t->insert2(word, pair.first);
    }
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  std::cout << "Time taken by function: " << duration.count() << " seconds"
            << std::endl;

  delete t;
}

int main(void) {
  Trie *t;

  t = new Trie();
  std::string doc1 = "doc1";
  std::string doc2 = "doc2";

  std::string word1 = "t";
  std::string word2 = "te";
  std::string word3 = "tes";
  std::string word4 = "test";

  t->insert2(word1, doc1);
  t->insert2(word2, doc1);
  t->insert2(word3, doc2);
  t->insert2(word4, doc2);
  t->insert2(word1, doc2);
  t->insert2(word2, doc2);

  // test_content_list();
  // t->print_tree();
  // t->remove(word1, "doc1");
  // t->remove(word1, "doc2");
  // t->print_tree();
  delete t;
  return 0;
}
