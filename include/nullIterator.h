#pragma once

#include "iterator.h"

template <typename T>
class NullIterator : public Iterator<T> {
   private:
    T _instance;

   public:
    NullIterator(T);
    void first();
    void next();
    bool isDone();
    T currentItem();
};

#include "../src/nullIterator.tpp"
