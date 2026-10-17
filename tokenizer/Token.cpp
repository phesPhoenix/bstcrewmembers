//
// Created by theoi on 3/2/2026.
//

#include "Token.h"
#include <iostream>
#include "constants.h"

using namespace std;

Token::Token() {
    _token = "";
    _type = TOKEN_UNKNOWN;
}

Token::Token(string str, int type) {
    _token = str;
    _type = type;
}

ostream & operator<<(ostream &outs, const Token &t) {
    outs << "|" << t._token << "|";
    return outs;
}

int Token::get_type() const {
    return _type;
}

void Token::set_type(int type) {
    _type = type;
}

string Token::type_string() const {
    switch (_type) {
        case TOKEN_ALPHA:   return "ALPHA";
        case TOKEN_NUMBER:  return "NUMBER";
        case TOKEN_SPACE:   return "SPACE";
        case TOKEN_PUNC:    return "PUNC";
        default:            return "UNKNOWN";
    }
}

void Token::set_contents(const string &input) {
    _token = input;
}

string Token::token_str() const {
    return _token;
}