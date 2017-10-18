#include "struct.h"

Struct::Struct(Atom atom, vector<Term*> args) {
    _name = new Atom(atom.symbol());
    _args = args;
}

Atom Struct::name() const { return *_name; }

Term* Struct::args(int index) const { return _args[index]; }

size_t Struct::size() const { return _args.size(); }

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
    Struct* structure = dynamic_cast<Struct*>(&term);
    if (structure == nullptr) return false;
    Atom structName = structure->name();
    if (!name().match(structName)) return false;
    if (size() != structure->size()) return false;
    for (int i = 0; i < size(); i++)
        if (!args(i)->match(*(structure->args(i)))) return false;
    return true;
}