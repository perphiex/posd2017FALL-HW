#include "../include/number.h"

Number::Number(double value) : _value(value) {}

std::string Number::getString() {
    std::ostringstream oss;
    oss << std::setprecision(std::numeric_limits<double>::max_digits10)
        << _value;
    return oss.str();
}

std::string Number::symbol() { return getString(); }

std::string Number::value() { return getString(); }

bool Number::match(Term& term) {
    Variable* variable = term.getVariable();
    if (variable) return variable->match(*this);
    Number* number = term.getNumber();
    if (number) return _value == number->_value;
    return false;
}

Number* Number::getNumber() { return this; }