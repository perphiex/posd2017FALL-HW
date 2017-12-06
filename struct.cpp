#include <sstream>
#include "term.h"
#include "atom.h"
#include "struct.h"
#include "structIterator.h"
#include "dfsIterator.h"
#include "bfsIterator.h"

Struct::Struct(Atom functor, std::vector<Term*> args)
    : _functor(functor), _args(args) {}

Atom Struct::functor() { return _functor; }

Term* Struct::args(size_t index) { return _args[index]; }

size_t Struct::arity() { return _args.size(); }

std::string Struct::symbol() {
    std::ostringstream oss;
    oss << _functor.symbol() << "(";
    for (int i = 0; i < _args.size(); i++) {
        oss << _args[i]->symbol();
        if (i != _args.size() - 1) oss << ", ";
    }
    oss << ")";
    return oss.str();
}

std::string Struct::value() {
    std::ostringstream oss;
    oss << _functor.value() << "(";
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
    Atom structName = structure->functor();
    if (!functor().match(structName)) return false;
    if (arity() != structure->arity()) return false;
    for (int i = 0; i < arity(); i++)
        if (!args(i)->match(*(structure->args(i)))) return false;
    return true;
}

Struct* Struct::getStruct() { return this; }

Iterator<Term*>* Struct::createIterator() { return new StructIterator(this); }

Iterator<Term*>* Struct::createDFSIterator() {
    return new DFSIterator<Term*>(this);
}

Iterator<Term*>* Struct::createBFSIterator() {
    return new BFSIterator<Term*>(this);
}