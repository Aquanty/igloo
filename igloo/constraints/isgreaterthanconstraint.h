#ifndef IGLOO_ISGREATERTHANCONSTRAINT_H
#define IGLOO_ISGREATERTHANCONSTRAINT_H

#include "igloo/constraints/expressions/expression.h"

namespace igloo {

  template< typename ExpectedType >
  struct IsGreaterThanConstraint : Expression< IsGreaterThanConstraint<ExpectedType> >
  {
    IsGreaterThanConstraint(const ExpectedType& expected)
      : m_expected(expected)
    {
    }

    template<typename ActualType>
    bool operator()(const ActualType& actual) const
    {
      return (actual > m_expected);
    }

    ExpectedType m_expected;
  };

  template< typename ExpectedType >
  inline IsGreaterThanConstraint<ExpectedType> IsGreaterThan(const ExpectedType& expected)
  {
    return IsGreaterThanConstraint<ExpectedType>(expected);
  }

  inline IsGreaterThanConstraint<std::string> IsGreaterThan(const char* expected)
  {
    return IsGreaterThanConstraint<std::string>(expected);
  }

  template< typename ExpectedType >
  struct Stringizer< IsGreaterThanConstraint< ExpectedType > >
  {
    static std::string ToString(const IsGreaterThanConstraint<ExpectedType>& constraint)
    {
      std::ostringstream builder;
      builder << "greater than " << Stringize(constraint.m_expected);

      return builder.str();
    }
  };
}

#endif
