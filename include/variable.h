#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"
#include "iterator.h"

class Variable : public Term {
   private:
    std::string _symbol;
    Term* _instance = nullptr;

   public:
    Variable(std::string);
    std::string symbol();
    std::string value();
    bool match(Term&);
    Variable* getVariable();
};

#endif