#ifndef TERM_H
#define TERM_H

#include <string>

class List;
class Struct;
class Variable;

using std::string;

class Term {
   public:
    virtual string symbol() = 0;
    virtual string value() = 0;
    virtual bool match(Term&) = 0;
    virtual List* getList();
    virtual Struct* getStruct();
    virtual Variable* getVariable();
};

#endif