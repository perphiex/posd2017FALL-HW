#include "dfsIterator.h"

#include <iostream>
#include <vector>
DFSIterator::DFSIterator(Term* term) : _term(term){};

void DFSIterator::first() {
  _iteratorStack = std::stack<Iterator*>();
  Iterator* it = _term->createIterator();
  it->first();
  _termStack.push(_term);
  _iteratorStack.push(it);
}

void DFSIterator::next() {
  Iterator* it = _iteratorStack.top();
  if (!it->isDone()) {
    Term* term = it->currentItem();
    Iterator* itNested = term->createIterator();
    itNested->first();
    _termStack.push(term);
    _iteratorStack.push(itNested);
  } else {
    _iteratorStack.pop();
    _termStack.pop();
  }
}

bool DFSIterator::isDone() { return _iteratorStack.empty(); }

Term* DFSIterator::currentItem() { return _iteratorStack.top()->currentItem(); }