#include "list.h"

List::List(Term* head, Term* tail) : Struct(Atom("."), head, tail) {}

List* List::getList() { return this; }

Term* List::head() const {
    if (_args.empty()) throw string("Accessing head in an empty list");
    return _args.front();
}

List* List::tail() const {
    if (_args.empty()) throw string("Accessing tail in an empty list");
    return _args[_TAIL]->getList();
}

string List::symbol() {
    ostringstream oss;
    oss << "[";
    List* list;
    for (list = this; list && list->_args[_TAIL];
         list = list->_args[_TAIL]->getList()) {
        oss << (list != this ? ", " : "");
        oss << list->_args[_HEAD]->symbol();
    }
    oss << "]";
    return oss.str();
}

string List::value() {
    ostringstream oss;
    oss << "[";
    List* list;
    for (list = this; list && list->_args[_TAIL];
         list = list->_args[_TAIL]->getList()) {
        oss << (list != this ? ", " : "");
        oss << list->_args[_HEAD]->value();
    }
    oss << "]";
    return oss.str();
}