#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "iterator.h"
#include "term.h"
#include "list.h"

class ListIterator : public Iterator {
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

#endif