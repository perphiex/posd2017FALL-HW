#ifndef NULLITERATOR_H
#define NULLITERATOR_H

#include "term.h"
#include "termIterator.h"

class NullIterator : public TermIterator {
   private:
    Term* _term;
    bool _isDone;

   public:
    NullIterator(Term*);
    void first();
    void next();
    bool isDone();
    Term* CurrentItem();
};

#endif