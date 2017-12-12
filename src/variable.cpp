#include "../include/term.h"
#include "../include/variable.h"

Variable::Variable(std::string symbol) : _symbol(symbol) {}

std::string Variable::symbol() { return _symbol; }

std::string Variable::value() {
    if (_instance) return _instance->value();
    return _symbol;
}

Variable* Variable::getVariable() { return this; };

bool Variable::match(Term& term) {
    if (_instance == nullptr) {
        if (this != &term) _instance = &term;
        return true;
    }
    return _instance->match(term);
};