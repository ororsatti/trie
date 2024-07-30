#ifndef SEARCH_TOKENIZER
#define SEARCH_TOKENIZER
#include <iostream>
#include <set>
#include <vector>
using namespace std;

string get_next_word(string content, size_t &cursor);
vector<string> tokenize(string content);
#endif
