#ifndef _ASSERTIONS_H
#define	_ASSERTIONS_H
#include "not_constraint.h"
#include "equalto_constraint.h"
#include "is.h"

class Assert
{
public:
  template <typename T>
  static void That(T actual, ConstraintExpression& constraint)
  {
    stack<bool> resultStack;

    IOperator* op;
    while((op = constraint.PopOperator()) != NULL)
    {
      if(op->IsLogicalOperator())
      {
        LogicalOperator* logical = dynamic_cast<LogicalOperator*>(op);
        logical->Evaluate(resultStack);
      }
      else
      {
        Constraint<T>* constraint = dynamic_cast<Constraint<T>* >(op);
        resultStack.push(constraint->Evaluate(actual));
      }
    }

    if(!resultStack.top())
    {
      throw AssertionException("WTF!?");
    }
  }

  static void That(bool& actual)
  {
    if(!actual)
      {
      throw AssertionException("Expected condition to be true");
    }
  }
};

#endif	/* _ASSERTIONS_H */

