


#include "stokenize.h"
#include <iostream>
using namespace std;

STokenizer::STokenizer() {
    _pos = 0;
    _buffer[0] = '\0' ;
    _last_token_ready = false;
    make_table();
}

STokenizer::STokenizer(char str[]) {
    _pos = 0;
    _last_token_ready = false;
    make_table();
    int looper = 0;
    for (looper; str[looper] != '\0'; looper++) {
        _buffer[looper] = str[looper];
    }
    _buffer[looper] = '\0';
}


bool STokenizer::more() {
    return _buffer[_pos] != '\0' || _last_token_ready;
}

bool STokenizer::done() {
    return _buffer[_pos] == '\0' && !_last_token_ready;
}

void STokenizer::mark_cell(int state, char input, int new_state) {
    _table[state][(unsigned char)input] = new_state; //
}

void STokenizer::mark_success(int state) {
    _table[state][128] = 1;
}

void STokenizer::init_machines() {
    //aplhabet machine
    for (char c : ALFA) {
        //traverse states
        _table[0][c] = 5; //[0] -> 'a-z' or 'A-Z' -> [5]
        _table[5][c] = 5; //[5] -> 'a-z' or 'A-Z' -> [5]
        mark_cell(5, '\'', 6); //[5] -> apostrophe -> [6]
        _table[6][c] = 7; //[6] -> 'a-z' or 'A-Z' -> [7]
    }
    mark_success(5);
    mark_success(7);

    //double(int) machine location
    for (char c : DIGITS) {
        //traverse states
        _table[0][c] = 1; //[0] -> '0-9' -> [1]
        _table[1][c] = 1; //[1] -> '0-9' -> [1]
        mark_cell(1, '.', 2); //[1] -> decimal -> [2]
        _table[2][c] = 3; //[2] - '0-9' -> [3]
        _table[3][c] = 3; //[3] -> '0-9' -> [3]
    }
    mark_success(1);
    mark_success(3);

    //space machine location
    for (char c : SPACES) {
        _table[0][c] = 4; //[0] -> SPACES -> [4]
        _table[4][c] = 4; //[4] -> SPACES -> [4]
    }
    mark_success(4);

    //punc location
    for (char c : PUNC) {
        _table[0][c] = 8; //[0] -> PUNC -> [8]
    }
    mark_success(8);
}

void STokenizer::make_table() {
    //fill the whole thing up with -1 to start
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            _table[i][j] = -1;
        }
    }
    init_machines();
}

bool STokenizer::get_token(string& _token, int& state) {
    _token = "";

    if (_last_token_ready && _buffer[_pos] == '\0') {
        _last_token_ready = false;
        return false;
    }

    int next_state = 0;
    int last_success = -1;
    int last_success_pos = _pos;
    int walker = _pos;
    int start_pos = _pos;

    while (_buffer[walker] != '\0') {
        next_state = _table[next_state][(unsigned char)_buffer[walker]];
        if (next_state == -1) {
            break;
        }

        walker++;

        if (_table[next_state][128] == 1) {
            last_success = next_state;
            last_success_pos = walker;
        }
    }

    if (last_success != -1) {
        for (int i = start_pos; i < last_success_pos; i++) {
            _token += _buffer[i];
        }

        _pos = last_success_pos;
        state = last_success;

        if (_buffer[_pos] == '\0') {
            _last_token_ready = true;
        }

        return true;
    }

    if (_buffer[_pos] != '\0') {
        _token = _buffer[_pos];
        _pos++;
        state = TOKEN_UNKNOWN;

        if (_buffer[_pos] == '\0') {
            _last_token_ready = true;
        }

        return true;
    }

    return false;
}

void STokenizer::set_string(char str[]) {
    _pos = 0;
    _last_token_ready = false;
    int looper = 0;
    for (looper; str[looper] != '\0'; looper++) {
        _buffer[looper] = str[looper];
    }
    _buffer[looper] = '\0';
}

STokenizer& operator >>(STokenizer& s, Token& t) {
    int state = TOKEN_UNKNOWN;
    string token = "";
    s.get_token(token, state);
    switch (state) {
        case -1: state = TOKEN_UNKNOWN; break;
        case 5: state = TOKEN_ALPHA; break;
        case 7: state = TOKEN_ALPHA; break;
        case 1: state = TOKEN_NUMBER; break;
        case 3: state = TOKEN_NUMBER; break;
        case 4: state = TOKEN_SPACE; break;
        case 8: state = TOKEN_PUNC; break;
            default: state = TOKEN_UNKNOWN; break;
    }
    t.set_contents(token);
    t.set_type(state);
    return s;
}
