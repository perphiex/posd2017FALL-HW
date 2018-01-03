#pragma once

#include <string>
enum Operators { SEMICOLON, COMMA, EQUALITY, TERM };

static Operators operatorsEnum(std::string tokenString) {
    if (tokenString == "=")
        return EQUALITY;
    else if (tokenString == ",")
        return COMMA;
    else
        return SEMICOLON;
}

static std::string operatorsEnumToString(Operators op) {
    if (op == COMMA)
        return ",";
    else
        return ";";
}

static int operatorsProity(Operators op) {
    switch (op) {
        case COMMA:
            return 200;
        case SEMICOLON:
            return 100;
        default:
            return 300;
    }
}

class Term;
class Node {
   public:
    Node(Operators);
    Node(Operators, Term*, Node*, Node*);

    bool evaluate();
    std::string getResult();
    Operators payload;
    Term* term;
    Node* left;
    Node* right;
    Node* parent;
};
