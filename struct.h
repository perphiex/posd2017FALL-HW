#ifndef STRUCT_H
#define STRUCT_H

#include <sstream>
#include <string>
#include <vector>
#include "atom.h"
#include "term.h"

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
    bool match(Term&);
};

#endif