#ifndef STRUCTITERATOR_H
#define STRUCTITERATOR_H

#include "termIterator.h"
#include "term.h"
#include "struct.h"

class StructIterator : public TermIterator {
   private:
    Struct* _struct;
    size_t _index;

   public:
    StructIterator(Struct*);
    void first();
    void next();
    bool isDone();
    Term* CurrentItem();
};

#endif