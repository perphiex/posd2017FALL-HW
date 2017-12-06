#pragma once

#include "iterator.h"
class Term;
class List;

class ListIterator : public Iterator<Term*> {
   private:
    List* _oriList;
    List* _currentList;

   public:
    ListIterator(List*);
    void first();
    void next();
    bool isDone();
    Term* currentItem();
};
