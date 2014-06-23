#ifndef IGLOO_GTESTOUTPUT_H
#define IGLOO_GTESTOUTPUT_H

#include <igloo/core/testlistener.h>
#include <igloo/core/outputters/consoleoutputcolors.h>
namespace igloo {

  class GTestResultsOutput : public TestResultsOutput, public NullTestListener
  {
  private:
    size_t _caseCounter;
  public: 
      GTestResultsOutput(std::ostream& outstream = std::cout) : TestResultsOutput(outstream) {}

      void SpecRunStarting(const ContextBase& context, const std::string& specName)
      {
          output << PASSED_OUTPUT_COLOR << "[ RUN      ] "<<DEFAULT_OUTPUT_COLOR<<context.Name()<<"."<<specName<<std::endl;
      }

      void SpecSucceeded(const ContextBase& context, const std::string& specName)
      {
          output << PASSED_OUTPUT_COLOR << "[       OK ] "<<DEFAULT_OUTPUT_COLOR<<context.Name()<<"."<<specName<<std::endl;
      }

      void SpecFailed(const ContextBase& context, const std::string& specName)
      {
          output << FAILED_OUTPUT_COLOR << "[  FAILED  ] "<<DEFAULT_OUTPUT_COLOR<<context.Name()<<"."<<specName<<std::endl;   
      }

      virtual void ContextRunStarting(const ContextBase&)
      {
        _caseCounter++;
      }

      void PrintResult(const TestResults& results) const
      {
          // output << "[==========] Running "<<results.NumberOfTestsRun()<<" tests."<< std::endl;
          // for (TestResults::SucceededTestsType::const_iterator it = results.SucceededTests().begin(); it != results.SucceededTests().end(); it++)
          // {
          //     const SucceededTestResult& result = *it;
          //     output << "[       OK ] "<<result.GetContextName() << "." << result.GetSpecName() << std::endl;
          // }
          output << PASSED_OUTPUT_COLOR << "[==========] "<<DEFAULT_OUTPUT_COLOR<<results.NumberOfTestsRun()<<" tests ran."<< std::endl;
          output << PASSED_OUTPUT_COLOR << "[  PASSED  ] "<<DEFAULT_OUTPUT_COLOR<<results.NumberOfSucceededTests()<<" tests." << std::endl;
          if (results.NumberOfFailedTests() > 0) 
          {
            output << FAILED_OUTPUT_COLOR << "[  FAILED  ] "<<DEFAULT_OUTPUT_COLOR<<results.NumberOfFailedTests()<<" tests, listed below"<<std::endl;
          }
          for (TestResults::FailedTestsType::const_iterator it = results.FailedTests().begin(); it != results.FailedTests().end(); it++)
          {
            const FailedTestResult& result = *it;
            output << FAILED_OUTPUT_COLOR << "[  FAILED  ] "<<DEFAULT_OUTPUT_COLOR<< result.GetContextName() << "." << result.GetSpecName() << std::endl;

            if(result.HasLineNumber() && result.HasFilename())
            {
              output <<  result.Filename() << "(" << result.LineNumber() << "): Assertion failed." << std::endl << result.GetErrorMessage() << std::endl;
            }
            else
            {
              output << result.GetErrorMessage() << std::endl;
            }
          }
          if (results.NumberOfFailedTests() > 0) 
          {
            output <<results.NumberOfFailedTests()<<" FAILED TESTS"<<std::endl;
          }
        }
  };
}
#endif