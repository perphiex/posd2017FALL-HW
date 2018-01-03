#pragma once

#include <string>
#include <vector>

#include "struct.h"
class Term;

class List : public Struct {
   private:
    const int _HEAD = 0;
    const int _TAIL = 1;

   public:
    List();
    List(Term*, Term*);
    List(std::vector<Term*>);
    List(std::initializer_list<Term*>);
    std::string symbol();
    std::string value();
    List* getList();
    Term* head();
    List* tail();
};
