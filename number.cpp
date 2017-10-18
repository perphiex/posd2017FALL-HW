#include "number.h"

Number::Number(double number) {
    ostringstream oss;
    oss << number;
    _value = oss.str();
}

string Number::symbol() const { return _value; }

string Number::value() const { return _value; }

bool Number::match(Term& term) {
    if (dynamic_cast<Variable*>(&term) != nullptr) return term.match(*this);
    return value() == term.value();
}
