#pragma once

#include <string>
#include <vector>
#include "term.h"
#include "atom.h"

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
    Atom functor();
    size_t arity();
    Term* args(size_t);
};
