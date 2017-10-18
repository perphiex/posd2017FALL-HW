#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"

using std::string;

class Variable : public Term {
   private:
    string _symbol;
    Term* _term;

   public:
    Variable(string);
    string symbol() const;
    string value() const;
    bool match(Term&);
};

#endif