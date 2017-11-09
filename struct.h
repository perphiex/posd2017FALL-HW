#ifndef STRUCT_H
#define STRUCT_H

#include <sstream>
#include <string>
#include <vector>

#include "atom.h"
#include "variable.h"

using std::ostringstream;
using std::string;
using std::vector;

class Struct : public Term {
   public:
    Struct(Atom, vector<Term*>);
    Atom name() const;
    Term* args(int) const;
    string symbol();
    string value();
    size_t size() const;
    bool match(Term&);
    Struct* getStruct();

   protected:
    Struct(Atom, Term*, Term*);
    Atom _name;
    vector<Term*> _args;
};

#endif