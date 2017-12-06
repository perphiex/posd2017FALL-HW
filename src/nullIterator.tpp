#pragma once

template <typename T>
NullIterator<T>::NullIterator(T instance) : _instance(instance) {}

template <typename T>
void NullIterator<T>::first() {}

template <typename T>
void NullIterator<T>::next() {}

template <typename T>
bool NullIterator<T>::isDone() {
    return true;
}

template <typename T>
T NullIterator<T>::currentItem() {
    return _instance;
}
