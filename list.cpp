#include "list.h"

Term* List::head() const {
    if (_elements.empty()) throw string("Accessing head in an empty list");
    return _elements.front();
}

List* List::tail() const {
    if (_elements.empty()) throw string("Accessing tail in an empty list");
    return new List(vector<Term*>(_elements.begin() + 1, _elements.end()));
}

string List::symbol() const {
    ostringstream oss;
    oss << "[";
    for (int i = 0; i < size(); i++) {
        oss << _elements[i]->symbol();
        if (i != size() - 1) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

string List::value() const {
    ostringstream oss;
    oss << "[";
    for (int i = 0; i < size(); i++) {
        oss << _elements[i]->value();
        if (i != size() - 1) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

bool List::match(Term& term) {
    if (dynamic_cast<Variable*>(&term) != nullptr) return term.match(*this);
    List* list = dynamic_cast<List*>(&term);
    if (list == nullptr) return false;
    if (size() != list->size()) return false;
    for (int i = 0; i < size(); i++)
        if (!elements(i)->match(*(list->elements(i)))) return false;
    return true;
}
Term* List::elements(int index) const { return _elements[index]; }
size_t List::size() const { return _elements.size(); }