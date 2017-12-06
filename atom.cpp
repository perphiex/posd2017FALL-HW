#include "atom.h"
#include "variable.h"

Atom::Atom(std::string symbol) : _symbol(symbol) {}

std::string Atom::symbol() { return _symbol; }

std::string Atom::value() { return _symbol; }

bool Atom::match(Term& term) {
    Variable* variable = term.getVariable();
    if (variable) return variable->match(*this);
    Atom* atom = term.getAtom();
    if (atom) return _symbol == atom->symbol();
    return false;
}

Atom* Atom::getAtom() { return this; }