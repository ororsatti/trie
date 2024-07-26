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

int main(void) {
  Trie t;
  std::string book =
      "Set in Canada and the battlefields of France and Belgium, Three-Day "
      "Road is a mesmerizing novel told through the eyes of Niska—a Canadian "
      "Oji-Cree woman living off the land who is the last of a line of healers "
      "and diviners—and her nephew Xavier. At the urging of his friend Elijah, "
      "a Cree boy raised in reserve schools, Xavier joins the war effort. "
      "Shipped off to Europe when they are nineteen, the boys are marginalized "
      "from the Canadian soldiers not only by their native appearance but also "
      "by the fine marksmanship that years of hunting in the bush has taught "
      "them. Both become snipers renowned for their uncanny accuracy. But "
      "while Xavier struggles to understand the purpose of the war and to come "
      "to terms with his conscience for the many lives he has ended, Elijah "
      "becomes obsessed with killing, taking great risks to become the most "
      "accomplished sniper in the army. Eventually the harrowing and bloody "
      "truth of war takes its toll on the two friends in different, profound "
      "ways. Intertwined with this account is the story of Niska, who herself "
      "has borne witness to a lifetime of death—the death of her people. In "
      "part inspired by the legend of Francis Pegahmagabow, the great Indian "
      "sniper of World War I, Three-Day Road is an impeccably researched and "
      "beautifully written story that offers a searing reminder about the cost "
      "of war.";

  std::string book2 =
      "If you  like most people, you don’t often think about lobsters — "
      "unless you’re eating one. However, these interesting and delicious "
      "crustaceans  very much worth considering. Their nervous system is "
      "comparatively simple, with large, easily observable neurons, the magic "
      "cells of the brain. Because of this, scientists have been able to map "
      "the neural circuitry of lobsters very accurately. This has helped us "
      "understand the structure and function of the brain and behaviour of "
      "more complex animals, including human beings. Lobsters have more in "
      "common with you than you might think (particularly when you  feeling "
      "crabby—ha ha).Lobsters live on the ocean floor. They need a home base "
      "down there, a range within which they hunt for prey and scavenge around "
      "for stray edible bits and pieces of whatever rains down from the "
      "continual chaos of carnage and death far above. They want somewhere "
      "secure, where the hunting and the gathering is good. They want a home. "
      "This can present a problem, since there  many lobsters. What if two "
      "of them occupy the same territory, at the bottom of the ocean, at the "
      "same time, and both want to live there? What if there  hundreds of "
      "lobsters, all trying to make a living and raise a family, in the same "
      "crowded patch of sand and refuse? Other creatures have this problem, "
      "too. When songbirds come north in the spring, for example, they engage "
      "in ferocious territorial disputes. The songs they sing, so peaceful and "
      "beautiful to human ears,  siren calls and cries of domination. A "
      "brilliantly musical bird is a small warrior proclaiming his "
      "sovereignty. Take the wren, for example, a small, feisty, insect-eating "
      "songbird common in North America. A newly arrived wren wants a "
      "sheltered place to build a nest, away from the wind and rain. He wants "
      "it close to food, and attractive to potential mates. He also wants to "
      "convince competitors for that space to keep their distance.";
  std::string book3 =
      "Jean Echenoz, considered by many to be the most distinguished and "
      "versatile living French novelist, turns his attention to the deathtrap "
      "of World War I in 1914. In it, five Frenchmen go off to war, two of "
      "them leaving behind a young woman who longs for their return. But the "
      "main character in this brilliant novel is the Great War itself. "
      "Echenoz, whose work has been compared to that of writers as diverse as "
      "Joseph Conrad and Laurence Sterne, leads us gently from a balmy summer "
      "day deep into the relentless and, one hundred years later, still "
      "unthinkable carnage of trench warfare. With the delicacy of a "
      "miniaturist and with an irony that is both witty and clear-eyed, "
      "Echenoz offers us an intimate epic: in the panorama of a clear blue "
      "sky, a bi-plane spirals suddenly into the ground; a piece of shrapnel "
      "shears the top off a man’s head as if it were a soft-boiled egg; we "
      "dawdle dreamily in a spring-scented clearing with a lonely "
      "shell-shocked soldier strolling innocently toward a firing squad ready "
      "to shoot him for desertion. Ultimately, the grace notes of humanity in "
      "1914 rise above the terrors of war in this beautifully crafted tale "
      "that Echenoz tells with discretion, precision, and love.";
  Corpus c;

  // t.insert2("t", "a");
  // t.insert2("te", "b");
  // t.insert2("tebula", "b");
  // t.insert2("tebula", "b");
  // t.insert2("tes", "a");
  // t.insert2("tes", "c");
  // t.insert2("testingggg", "a");
  // t.insert2("testingggg", "b");
  // c.add_doc("book", book);
  // c.add_doc("book2", book2);
  // c.add_doc("book3", book3);
  // c.print();
  //
  // t.print_tree();
  auto content_list = parseJsonContent(read_file("processed.json"));
  auto start = std::chrono::high_resolution_clock::now();
  for (const auto &pair : content_list) {
    c.add_doc(pair.first, pair.second);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;

  // Output the duration in seconds
  std::cout << "Time taken by function: " << duration.count() << " seconds"
            << std::endl;
  // vector<QueryResult> qr = c.search("rostv name count dewy princess mary");
  // std::cout << qr.size() << std::endl;
  // for (QueryResult &res : qr) {
  // std::cout << res.doc_key << " " << res.score << std::endl;
  // }
  // c.print();
  return 0;
}
