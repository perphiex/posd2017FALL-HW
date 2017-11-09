#ifndef ATOM_H
#define ATOM_H

#include <string>

#include "term.h"

using std::string;

class Atom : public Term {
   private:
    string _symbol;

   public:
    Atom(string);
    string symbol();
    string value();
    bool match(Term&);
};

#endif