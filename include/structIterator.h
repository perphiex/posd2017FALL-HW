#pragma once

#include "iterator.h"
class Term;
class Struct;

class StructIterator : public Iterator<Term*> {
   private:
    Struct* _struct;
    size_t _index;

   public:
    StructIterator(Struct*);
    void first();
    void next();
    bool isDone();
    Term* currentItem();
};
