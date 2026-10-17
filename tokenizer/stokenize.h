//
// Created by theoi on 3/2/2026.
//

#ifndef STRING_TOKENIZER_STOKENIZER_H
#define STRING_TOKENIZER_STOKENIZER_H

#include "Token.h"
#include "constants.h"
#include <string>

using namespace std;

class STokenizer {
public:
    STokenizer();
    STokenizer(char str[]);
    bool done();
    bool more();
    //---------------
    //extract one token (very similar to the way cin >> works)
    friend STokenizer& operator >> (STokenizer& s, Token& t);

    //set a new string as the input string
    void set_string(char str[]);

private:
    //create table for all the tokens we will recognize
    //                      (e.g. doubles, words, etc.)
    void make_table();
    void init_machines();
    void mark_cell(int state, char input, int new_state);
    void mark_success(int state);

    //extract the longest string that match
    //     one of the acceptable token types
    bool get_token(string& token, int& state);
    //---------------------------------
    char _buffer[MAX_BUFFER];       //input string
    int _pos;                       //current position in the string
    int _table[MAX_ROWS][MAX_COLUMNS];
    bool _last_token_ready;
};


#endif //STRING_TOKENIZER_STOKENIZER_H