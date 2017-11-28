#ifndef LIST_H
#define LIST_H

#include <string>
#include <vector>
#include <sstream>
#include "term.h"
#include "atom.h"
#include "struct.h"
#include "termIterator.h"
#include "listIterator.h"

class List : public Struct {
   private:
    const int _HEAD = 0;
    const int _TAIL = 1;

   public:
    List();
    List(Term*, Term*);
    std::string symbol();
    std::string value();
    List* getList();
    TermIterator* createIterator();
    Term* head();
    List* tail();
};
#endif