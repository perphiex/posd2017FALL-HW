#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "term.h"
#include "variable.h"
#include "termIterator.h"

class Atom : public Term {
   private:
    std::string _symbol;

   public:
    Atom(std::string);
    std::string symbol();
    std::string value();
    bool match(Term&);
    Atom* getAtom();
};

#endif