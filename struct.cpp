#include "struct.h"

Struct::Struct(Atom atom, vector<Term*> args) {
    _name = new Atom(atom.symbol());
    _args = args;
}

Atom Struct::name() const { return *_name; }

Term* Struct::args(int index) const { return _args[index]; }

string Struct::symbol() const {
    ostringstream oss;
    oss << _name->symbol() << "(";
    for (int i = 0; i < _args.size(); i++) {
        oss << _args[i]->symbol();
        if (i != _args.size() - 1) oss << ", ";
    }
    oss << ")";
    return oss.str();
}

string Struct::value() const {
    ostringstream oss;
    oss << _name->value() << "(";
    for (int i = 0; i < _args.size(); i++) {
        oss << _args[i]->value();
        if (i != _args.size() - 1) oss << ", ";
    }
    oss << ")";
    return oss.str();
}

bool Struct::match(Term& term) {
    if (dynamic_cast<Variable*>(&term) != nullptr) return term.match(*this);
    return value() == term.value();
}