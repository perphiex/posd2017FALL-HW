#pragma one

#include <vector>

template <typename T>
DFSIterator<T>::DFSIterator(T instance) : _it(instance->createIterator()) {}

template <typename T>
void DFSIterator<T>::first() {
    _itStack = std::stack<Iterator<T>*>();
    _it->first();
    _itStack.push(_it);
}

template <typename T>
void DFSIterator<T>::next() {
    Iterator<T>* it = _itStack.top();
    Iterator<T>* itemIt = it->currentItem()->createIterator();
    itemIt->first();
    it->next();
    if (!itemIt->isDone()) _itStack.push(itemIt);
    while (!_itStack.empty() && _itStack.top()->isDone()) _itStack.pop();
}

template <typename T>
bool DFSIterator<T>::isDone() {
    return _itStack.empty();
}

template <typename T>
T DFSIterator<T>::currentItem() {
    return _itStack.top()->currentItem();
}