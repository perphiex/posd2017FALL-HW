#include "term.h"
#include "nullIterator.h"

Atom* Term::getAtom() { return nullptr; }
Number* Term::getNumber() { return nullptr; }
Variable* Term::getVariable() { return nullptr; }
Struct* Term::getStruct() { return nullptr; }
List* Term::getList() { return nullptr; }

Iterator<Term*>* Term::createIterator() {
    return new NullIterator<Term*>(this);
}

Iterator<Term*>* Term::createDFSIterator() { return createIterator(); }

Iterator<Term*>* Term::createBFSIterator() { return createIterator(); }