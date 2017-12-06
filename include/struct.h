#pragma once

#include <string>
#include <vector>
#include "term.h"
#include "atom.h"

template <typename T>
class Iterator;

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
    Iterator<Term*>* createIterator();
    Iterator<Term*>* createDFSIterator();
    Iterator<Term*>* createBFSIterator();
    Atom functor();
    size_t arity();
    Term* args(size_t);
};
