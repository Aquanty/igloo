/* 
* File:   testresult.h
* Author: joakim
*
* Created on December 8, 2009, 8:32 PM
*/

#ifndef IGLOO_TESTRESULT_H
#define	IGLOO_TESTRESULT_H

namespace igloo {
  class TestResult
  {
  public:
     TestResult(const std::string& fixtureName, const std::string& methodName, bool success, const std::string& errorMessage)
      : m_fixtureName(fixtureName), m_methodName(methodName), m_success(success), m_errorMessage(errorMessage)
    {
    }

    const std::string& GetFixtureName() const
    {
      return m_fixtureName;
    }

    const std::string& GetMethodName() const
    {
      return m_methodName;
    }

    bool GetSuccess() const
    {
      return m_success;
    }

    const std::string& GetErrorMessage() const
    {
      return m_errorMessage;
    }

  private:
    std::string m_fixtureName;
    std::string m_methodName;
    bool m_success;
    std::string m_errorMessage;
  };
}

#endif /* IGLOO_TESTRESULT_H */

