#include "structIterator.h"

StructIterator::StructIterator(Struct* structure) : _struct(structure) {}

void StructIterator::first() { _index = 0; }

void StructIterator::next() { _index++; }

bool StructIterator::isDone() { return _index == _struct->arity(); }

Term* StructIterator::currentItem() { return _struct->args(_index); }