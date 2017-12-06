#pragma once

#include <queue>
#include "iterator.h"

template <typename T>
class BFSIterator : public Iterator<T> {
   public:
    BFSIterator(T);
    void first();
    void next();
    bool isDone();
    T currentItem();

   private:
    std::queue<Iterator<T>*> _itQueue;
    Iterator<T>* _it;
};

#include "../src/bfsIterator.tpp"
