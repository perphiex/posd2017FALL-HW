#include "listIterator.h"

ListIterator::ListIterator(List* list) : _oriList(list) {}

void ListIterator::first() { _currentList = _oriList; }

void ListIterator::next() { _currentList = _currentList->tail(); }

bool ListIterator::isDone() { return !_currentList->arity(); }

Term* ListIterator::currentItem() { return _currentList->head(); }