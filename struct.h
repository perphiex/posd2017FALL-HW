#ifndef STRUCT_H
#define STRUCT_H

#include <sstream>
#include <string>
#include <vector>
#include "term.h"
#include "atom.h"
#include "variable.h"

class Atom;

using std::ostringstream;
using std::string;
using std::vector;

class Struct : public Term {
   private:
    Atom* _name;
    vector<Term*> _args;

   public:
    Struct(Atom, vector<Term*>);
    Atom name() const;
    Term* args(int) const;
    string symbol() const;
    string value() const;
    size_t size() const;
    bool match(Term&);
};

#endif