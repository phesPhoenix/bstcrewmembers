
//
// Created by theoi on 3/22/2026.
//

#ifndef ST_05_FILE_TOKENIZER_THEODOREFARRIS27_FTOKENIZER_H
#define ST_05_FILE_TOKENIZER_THEODOREFARRIS27_FTOKENIZER_H

#include <fstream>
#include "stokenize.h"
#include "Token.h"
#include "constants.h"

// ADDED: Needed for storing CSV rows and fields.
#include <vector>
#include <string>

class FTokenizer {
public:
    static const int MAX_BLOCK = MAX_BUFFER;

    FTokenizer(const char* fname);
    Token next_token();
    bool more();             // returns current value of _more
    int pos();               // returns current position in file
    int block_pos();         // returns current position in current block

    friend FTokenizer& operator>>(FTokenizer& f, Token& t);

    //returns false when there are no more rows
    bool next_csv_row(std::vector<std::string>& fields);

private:
    bool get_new_block();
    std::ifstream _f;
    STokenizer _stk;
    int _pos;
    int _blockPos;
    bool _more;
    std::ifstream _csvFile;
};

#endif //ST_05_FILE_TOKENIZER_THEODOREFARRIS27_FTOKENIZER_H
