#pragma once

#include <stack>
#include "iterator.h"

template <typename T>
class DFSIterator : public Iterator<T> {
   public:
    DFSIterator(T);
    void first();
    void next();
    bool isDone();
    T currentItem();

   private:
    std::stack<Iterator<T>*> _itStack;
    Iterator<T>* _it;
};

#include "dfsIterator.tpp"
