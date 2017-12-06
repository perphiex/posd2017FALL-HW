template <typename T>
BFSIterator<T>::BFSIterator(T instance) : _it(instance->createIterator()) {}

template <typename T>
void BFSIterator<T>::first() {
    _itQueue = std::queue<Iterator<T>*>();
    _it->first();
    _itQueue.push(_it);
}

template <typename T>
void BFSIterator<T>::next() {
    Iterator<T>* it = _itQueue.front();
    Iterator<T>* itemIt = it->currentItem()->createIterator();
    itemIt->first();
    it->next();
    if (!itemIt->isDone()) _itQueue.push(itemIt);
    while (!_itQueue.empty() && _itQueue.front()->isDone()) _itQueue.pop();
}

template <typename T>
bool BFSIterator<T>::isDone() {
    return _itQueue.empty();
}

template <typename T>
T BFSIterator<T>::currentItem() {
    return _itQueue.front()->currentItem();
}