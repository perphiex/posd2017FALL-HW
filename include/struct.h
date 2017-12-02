#ifndef STRUCT_H
#define STRUCT_H

#include <string>
#include <sstream>
#include <vector>
#include "term.h"
#include "atom.h"
#include "iterator.h"
#include "structIterator.h"

class Struct : public Term {
   protected:
    Atom _functor;
    std::vector<Term*> _args;

   public:
    Struct(Atom, std::vector<Term*>);
    std::string symbol();
    std::string value();
    bool match(Term&);
    Struct* getStruct();
    Iterator* createIterator();
    Atom functor();
    size_t arity();
    Term* args(size_t);
};

#endif