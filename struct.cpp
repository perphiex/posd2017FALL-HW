#include "struct.h"

Struct::Struct(Atom atom, vector<Term*> args) : _name(atom), _args(args) {}

Atom Struct::name() const { return _name; }

Term* Struct::args(int index) const { return _args[index]; }

size_t Struct::arity() const { return _args.size(); }

string Struct::symbol() {
    ostringstream oss;
    oss << _name.symbol() << "(";
    for (int i = 0; i < _args.size(); i++) {
        oss << _args[i]->symbol();
        if (i != _args.size() - 1) oss << ", ";
    }
    oss << ")";
    return oss.str();
}

string Struct::value() {
    ostringstream oss;
    oss << _name.value() << "(";
    for (int i = 0; i < _args.size(); i++) {
        oss << _args[i]->value();
        if (i != _args.size() - 1) oss << ", ";
    }
    oss << ")";
    return oss.str();
}

bool Struct::match(Term& term) {
    if (term.getVariable()) return term.match(*this);
    Struct* structure = term.getStruct();
    if (structure == nullptr) return false;
    Atom structName = structure->name();
    if (!name().match(structName)) return false;
    if (arity() != structure->arity()) return false;
    for (int i = 0; i < arity(); i++)
        if (!args(i)->match(*(structure->args(i)))) return false;
    return true;
}

Struct::Struct(Atom name, Term* head, Term* tail)
    : _name(name), _args({head, tail}) {}

Struct* Struct::getStruct() { return this; }