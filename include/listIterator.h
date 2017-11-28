#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "termIterator.h"
#include "term.h"
#include "list.h"

class ListIterator : public TermIterator {
   private:
    List* _oriList;
    List* _currentList;

   public:
    ListIterator(List*);
    void first();
    void next();
    bool isDone();
    Term* CurrentItem();
};

#endif