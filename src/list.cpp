#include "../include/list.h"

List::List() : Struct(Atom("."), {}){};
List::List(Term* head, Term* tail) : Struct(Atom("."), {head, tail}) {}

List* List::getList() { return this; }

Term* List::head() {
    if (_args.empty()) throw std::string("Accessing head in an empty list");
    return _args.front();
}

List* List::tail() {
    if (_args.empty()) throw std::string("Accessing tail in an empty list");
    return _args[_TAIL]->getList();
}

std::string List::symbol() {
    std::ostringstream oss;
    oss << "[";
    List* list;
    for (list = this; list && list->arity() == 2;
         list = list->_args[_TAIL]->getList()) {
        oss << (list != this ? ", " : "");
        oss << list->_args[_HEAD]->symbol();
    }
    oss << "]";
    return oss.str();
}

std::string List::value() {
    std::ostringstream oss;
    oss << "[";
    List* list;
    for (list = this; list && list->arity() == 2;
         list = list->_args[_TAIL]->getList()) {
        oss << (list != this ? ", " : "");
        oss << list->_args[_HEAD]->value();
    }
    oss << "]";
    return oss.str();
}

Iterator* List::createIterator() { return new ListIterator(this); }