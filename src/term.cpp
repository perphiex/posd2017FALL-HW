#include "../include/term.h"

Atom* Term::getAtom() { return nullptr; }
Number* Term::getNumber() { return nullptr; }
Variable* Term::getVariable() { return nullptr; }
Struct* Term::getStruct() { return nullptr; }
List* Term::getList() { return nullptr; }

TermIterator* Term::createIterator() { return new NullIterator(this); }