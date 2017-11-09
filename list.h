#ifndef LIST_H
#define LIST_H

#include "struct.h"

class List : public Struct {
   private:
    const int _HEAD = 0;
    const int _TAIL = 1;

   public:
    List(Term* = nullptr, Term* = nullptr);
    Term* head() const;
    List* tail() const;
    string symbol();
    string value();
    List* getList();
};

#endif