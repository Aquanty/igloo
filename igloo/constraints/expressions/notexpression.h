#ifndef IGLOO_NOTEXPRESSION_H
#define IGLOO_NOTEXPRESSION_H
  
#include <igloo/constraints/expressions/expression_fwd.h>

namespace igloo {

  template< typename ExpressionType >
  struct NotExpression : Expression< NotExpression<ExpressionType> >
  {
    NotExpression(const ExpressionType& expression)
      : m_expression(expression)
    {
    }

    template<typename ActualType>
    bool operator()(const ActualType& actual) const
    {
      return !m_expression(actual);
    }

    ExpressionType m_expression;
  };

  template< typename ExpressionType >
  struct Stringizer< NotExpression<ExpressionType> >
  {
    static std::string ToString(const NotExpression<ExpressionType>& expression)
    {
      std::ostringstream builder;
	  builder << "not " << igloo::Stringize(expression.m_expression);

      return builder.str();
    }
  };
}

#endif
