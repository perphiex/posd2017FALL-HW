#include "nullIterator.h"

NullIterator::NullIterator(Term* term) : _term(term) {}

void NullIterator::first() { _isDone = false; }

void NullIterator::next() { _isDone = true; }

bool NullIterator::isDone() { return _isDone; }

Term* NullIterator::currentItem() {
  if (_isDone) {
    return nullptr;
  }
  return _term;
}