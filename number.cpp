#include "number.h"

Number::Number(double number) {
    ostringstream oss;
    oss << number;
    _value = oss.str();
}

string Number::symbol() { return _value; }

string Number::value() { return _value; }

bool Number::match(Term& term) {
    if (term.getVariable()) return term.match(*this);
    return value() == term.value();
}
