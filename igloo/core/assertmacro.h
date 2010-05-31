
//          Copyright Joakim Karlsson & Kim Gräsman 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef IGLOO_ASSERTMACRO_H
#define IGLOO_ASSERTMACRO_H

#include <igloo/core/assert.h>

#define AssertThat(p1,p2)\
   try\
   {\
      Assert::That((p1), (p2));\
   }\
   catch (AssertionException& e)\
   {\
      std::ostringstream str;\
      str << __FILE__ << "(" << __LINE__ << ") : Test Failure!" << std::endl;\
      str << e.GetMessage();\
      throw AssertionException(str.str());\
   }

#endif	// IGLOO_ASSERTMACRO_H
