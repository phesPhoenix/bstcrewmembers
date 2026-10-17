//
// Created by theoi on 3/2/2026.
//

#ifndef STRING_TOKENIZER_TOKEN_H
#define STRING_TOKENIZER_TOKEN_H
#include <string>
using namespace std;

class Token {
public:
    Token();
    Token(string str, int type);
    friend ostream& operator <<(ostream& outs, const Token& t);
    int get_type() const;
    void set_type(int type);
    string type_string() const;
    void set_contents(const string& input);
    string token_str() const;
private:
    string _token;
    int _type;
};


#endif //STRING_TOKENIZER_TOKEN_H