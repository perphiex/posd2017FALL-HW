#ifndef NUMBER_H
#define NUMBER_H

#include <sstream>
#include <string>
#include "term.h"
#include "variable.h"

using std::ostringstream;

class Number : public Term {
   private:
    string _value;

   public:
    Number(double);
    string symbol() const;
    string value() const;
    bool match(Term&);
};

#endif