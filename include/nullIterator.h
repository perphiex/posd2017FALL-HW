#ifndef NULLITERATOR_H
#define NULLITERATOR_H

#include "term.h"
#include "iterator.h"

class NullIterator : public Iterator {
   private:
    Term* _term;
    bool _isDone;

   public:
    NullIterator(Term*);
    void first();
    void next();
    bool isDone();
    Term* currentItem();
};

#endif