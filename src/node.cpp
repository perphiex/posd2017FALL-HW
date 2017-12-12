#include "../include/term.h"
#include "../include/node.h"

Node::Node(Operators op) : payload(op), term(0), left(0), right(0) {}
Node::Node(Operators op, Term* t, Node* l, Node* r)
    : payload(op), term(t), left(l), right(r) {}

bool Node::evaluate() {
    switch (payload) {
        case COMMA:
            return left->evaluate() && right->evaluate();
        case SEMICOLON: {
            bool leftIsTrue = left->evaluate();
            bool rightIsTrue = right->evaluate();
            return leftIsTrue || rightIsTrue;
        }
        case EQUALITY:
            return ((left->term)->match(*right->term));
        default:
            return true;
    }
}