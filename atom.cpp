#include "atom.h"

Atom::Atom(string s) { _symbol = s; }

string Atom::symbol() { return _symbol; }

string Atom::value() { return _symbol; }

bool Atom::match(Term& term) {
    if (term.getVariable()) return term.match(*this);
    return value() == term.value();
}
