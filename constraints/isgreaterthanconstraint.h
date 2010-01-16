#ifndef INCLUDED_ISGREATERTHANCONSTRAINT_H
#define INCLUDED_ISGREATERTHANCONSTRAINT_H

#include "expressions/expression.h"

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
inline std::string Stringize(const IsGreaterThanConstraint<ExpectedType>& constraint)
{
  std::ostringstream builder;
  builder << "greater than " << constraint.m_expected;

  return builder.str();
}

#endif INCLUDED_ISGREATERTHANCONSTRAINT_H