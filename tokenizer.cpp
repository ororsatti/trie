#include <cctype>
#include <vector>
using namespace std;

// namespace antonio {

size_t _trim_left(string content, size_t cursor) {
    size_t new_cursor = cursor, 
        len = content.length();
    while(new_cursor < len) {
        char c = content[new_cursor];
        if(c == '\t' || c == '\n' || c == '\r' || c == ' ') { 
            new_cursor++;
            continue;
        }
        break;
    }
    return new_cursor;
} 

bool is_quote_between_alpha(string content, size_t cursor) {
    size_t len = content.length();
    if(cursor - 1 < 0 || cursor + 1 > len) return false;
    char quote = content[cursor];
    char before = content[cursor - 1];
    char after = content[cursor + 1];

    return quote == '\'' && isalpha(before) && isalpha(after);
}
string get_next_word(string content, size_t &cursor) {
    string token;
    // trimming all the spaces to the left
    size_t len = content.length();
    cursor = _trim_left(content, cursor);
    while(cursor < len) {
        char c = tolower(content[cursor]);
        // when hitting a digit, get all digits and letters
        // example: 2nd, 100th
        if(isdigit(c) == 1) {
            while (cursor < len && isdigit(c) == 1 || isalpha(c) == 1) {
                token += c;
                cursor++;
                c = tolower(content[cursor]);
            }
            return token;
        }
        // when hitting a letter, get all letters
        // example: mom, table
        if(isalpha(c) == 1) {
            while (cursor < len && (isalpha(c) == 1 || is_quote_between_alpha(content, cursor))) {
                token += c;
                cursor++;
                c = tolower(content[cursor]);
            }
            return token;
        }
        // if special char take till a break:".", ","
        else {
            token += c;
            cursor++;
            return token;
        }
    }
    return token;
}
vector<string> tokenize(string content) {
    size_t cursor = 0;
    vector<string> tokens;
    while (cursor < content.length()) {
        string next_word = get_next_word(content, cursor);
        if(next_word.empty()) continue;
        tokens.push_back(next_word);
    }

    return tokens;
}
