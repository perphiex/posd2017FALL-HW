#pragma once

#include <string>
enum Operators { SEMICOLON, COMMA, EQUALITY, TERM };

static Operators operatorsEnum(std::string tokenString) {
    if (tokenString == "=")
        return EQUALITY;
    else if (tokenString == ",")
        return COMMA;
    else if (tokenString == ";")
        return SEMICOLON;
    else
        return TERM;
}

static int operatorsProity(Operators op) {
    switch (op) {
        case EQUALITY:
            return 300;
        case COMMA:
            return 200;
        case SEMICOLON:
            return 100;
        default:
            return 999;
    }
}

class Term;
class Node {
   public:
    Node(Operators);
    Node(Operators, Term*, Node*, Node*);

    bool evaluate();
    Operators payload;
    Term* term;
    Node* left;
    Node* right;
};
