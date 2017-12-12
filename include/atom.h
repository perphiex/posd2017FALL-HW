#pragma once

#include <string>
#include "term.h"

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