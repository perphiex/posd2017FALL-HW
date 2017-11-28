#ifndef TERM_H
#define TERM_H

#include <string>
#include "nullIterator.h"

class Atom;
class Number;
class Variable;
class Struct;
class List;
class TermIterator;

class Term {
   public:
    virtual std::string symbol() = 0;
    virtual std::string value() = 0;
    virtual bool match(Term&) = 0;
    virtual Atom* getAtom();
    virtual Number* getNumber();
    virtual Variable* getVariable();
    virtual Struct* getStruct();
    virtual List* getList();
    virtual TermIterator* createIterator();
};

#endif