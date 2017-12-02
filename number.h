#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include "term.h"
#include "variable.h"
#include "iterator.h"

class Number : public Term {
   private:
    double _value;
    std::string getString();

   public:
    Number(double);
    std::string symbol();
    std::string value();
    bool match(Term&);
    Number* getNumber();
};

#endif