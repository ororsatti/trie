#include "tokenizer.h"
#include "trie.h"

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

  auto words = tokenize(book);
  for (auto word : words) {
    t.insert(word, "11");
  }

  auto words2 = tokenize(book2);
  for (auto word : words2) {
    t.insert(word, "22");
  }
  // std::string content1 = "...";
  // std::string content2 = "this is content";
  // auto words = tokenize(content1);
  // for (auto word : words) {
  //   t.insert(word, "11");
  // }
  // auto words2 = tokenize(content2);
  // for (auto word : words2) {
  //   t.insert(word, "2");
  // }
  // t.insert("same", "22");
  // t.insert("same", "22");
  // t.insert("sand", "22");
  // t.insert("same", "22");
  t.remove_document(book, "11");
  // t.remove("same", "22");
  // t.remove("same", "22");
  // t.remove("sand", "22");
  // t.remove_document(book2, "22");
  t.print_tree();
  // t.print_tree();
  return 0;
}
