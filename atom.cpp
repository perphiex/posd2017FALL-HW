#include "atom.h"

Atom::Atom(string s) { _symbol = s; }

string Atom::symbol() const { return _symbol; }

string Atom::value() const { return _symbol; }

bool Atom::match(Term& term) {
    if (dynamic_cast<Variable*>(&term) != nullptr ||
        dynamic_cast<Struct*>(&term) != nullptr)
        return term.match(*this);
    return value() == term.value();
}
