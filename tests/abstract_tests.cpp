
//          Copyright Joakim Karlsson & Kim Gräsman 2010-2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tests/igloo_self_test.h>

using namespace igloo;

ParentContext(Common)
{
  virtual ~TO_CONTEXT(Common)() {}
  virtual void SetUp() = 0;
  
  Spec(TestIt)
  {
    Assert::That(val, Is().LessThan(4));
  }
  
  int val;
};

SubContext(Specific1, Common)
{
  virtual ~TO_CONTEXT(Specific1)() {}
  
  void SetUp()
  {
    val = 3;
  }
};

SubContext(Specific2, Common)
{
  virtual ~TO_CONTEXT(Specific2)() {}
  
  void SetUp()
  {
    val = 2;
  }
};
