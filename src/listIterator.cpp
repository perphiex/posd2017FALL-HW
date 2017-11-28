#include "../include/listIterator.h"

ListIterator::ListIterator(List* list) : _oriList(list) {}

void ListIterator::first() { _currentList = _oriList; }

void ListIterator::next() { _currentList = _currentList->tail(); }

bool ListIterator::isDone() {
    Term* tail = _currentList->tail();
    List* list = tail->getList();
    if (!list)
        return true;
    else
        return false;
}

Term* ListIterator::CurrentItem() { return _currentList->head(); }