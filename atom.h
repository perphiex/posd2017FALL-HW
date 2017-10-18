#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "term.h"
#include "struct.h"
#include "variable.h"

using std::string;

class Atom : public Term {
   private:
    string _symbol;

   public:
    Atom(string);
    string symbol() const;
    string value() const;
    bool match(Term&);
};

#endif