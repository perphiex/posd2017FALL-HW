#include <sstream>
#include "../include/term.h"
#include "../include/atom.h"
#include "../include/struct.h"
#include "../include/list.h"

List::List() : Struct(Atom("."), {}){};
List::List(Term* head, Term* tail) : Struct(Atom("."), {head, tail}) {}

List::List(std::vector<Term*> elements) : Struct(Atom("."), {}) {
    if (!elements.size()) return;
    List* tail = new List();
    for (int i = elements.size() - 1; i > 0; i--)
        tail = new List(elements[i], tail);
    _args.push_back(elements[0]);
    _args.push_back(tail);
}

List::List(std::initializer_list<Term*> list) : Struct(Atom("."), {}) {
    if (!list.size()) return;
    std::vector<Term*> elements = list;
    List* tail = new List();
    for (int i = elements.size() - 1; i > 0; i--)
        tail = new List(elements[i], tail);
    _args.push_back(elements[0]);
    _args.push_back(tail);
}

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
