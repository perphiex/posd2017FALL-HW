#ifndef TERM_H
#define TERM_H

#include <string>

using std::string;

class Term
{
  protected:
    string _symbol;
    string _value;

  public:
    string symbol() const;
    string value() const;

    template <typename T>
    bool match(T& term)
    {
        if (term.value().empty())
            term._value = value();
        if (_value.empty())
            _value = term.value();
        return value() == term.value();
    }
};

#endif
