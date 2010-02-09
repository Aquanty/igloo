#ifndef IGLOO_STRINGIZERS_H
#define IGLOO_STRINGIZERS_H

namespace igloo {

  namespace detail {

    template <typename Container>
    struct SequentialContainerStringizer
    {
      static std::string ToString(const Container& cont)
      {
        std::ostringstream stm;
        typedef typename Container::const_iterator Iterator;

        stm << "[ ";
        for(Iterator it = cont.begin(); it != cont.end();)
        {
          stm << igloo::Stringize(*it);

          if(++it != cont.end()) 
          {
            stm << ", ";
          }
        }
        stm << " ]";
        return stm.str();
      }
    };
  }
  
  template<typename T>
  struct Stringizer< std::vector<T> > : detail::SequentialContainerStringizer< std::vector<T> >
  {
  };

  template<typename T>
  struct Stringizer< std::deque<T> > : detail::SequentialContainerStringizer< std::deque<T> >
  {
  };

  template<typename T>
  struct Stringizer< std::list<T> > : detail::SequentialContainerStringizer< std::list<T> >
  {
  };
}

#endif
