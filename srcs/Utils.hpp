
#ifndef SRCS_UTILS_HPP_
#define SRCS_UTILS_HPP_

namespace ft {
  template <class T>
  void swap(T & a, T & b) {
//    std::cout << "i = " << a << "\tj = " << b << std::endl;
    T tmp = a;
    a = b;
    b = tmp;
  }

  template <class T>
  T & max(T & a, T & b){
    return a > b ? a : b;
  }

  template <class T>
  T max(const T & a, const T & b) {
    return a > b ? a : b;
  }

  template <class T>
  struct less {
    bool operator() (const T & lhs, const T & rhs) const { return lhs < rhs; }
  };

  template <class InputIterator1, class InputIterator2>
  bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
  {
    while (first1!=last1) {
      if (*first1 != *first2)
        return false;
      ++first1; ++first2;
    }
    return true;
  }

  template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, BinaryPredicate pred)
  {
    while (first1!=last1) {
      if (!pred(*first1, first2))
        return false;
      ++first1; ++first2;
    }
    return true;
  }

  template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2) {
    while (first1!=last1)
    {
      if (first2==last2 || *first2<*first1) return false;
      else if (*first1<*first2) return true;
      ++first1; ++first2;
    }
    return (first2!=last2);
  }

  template <class InputIterator1, class InputIterator2, class Compare>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp) {
    while (first1!=last1)
    {
      if (first2==last2 || *first2<*first1) return false;
      else if (comp(*first1,*first2)) return true;
      ++first1; ++first2;
    }
    return (first2!=last2);
  }


  template<class T1, class T2>
  struct pair {
    typedef T1 first_type;
    typedef T2 second_type;
    first_type first;
    second_type second;

    pair(): first(), second() {};

    template<class U, class V>
    explicit pair (const pair<U,V>& pr) { *this = pr; };

    pair (const first_type& a, const second_type& b): first(a), second(b) {};


    pair& operator= (const pair& pr) { first = pr.first; second = pr.second; };


    friend bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first == rhs.first && lhs.second == rhs.second; }

    friend bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); };

    friend bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); };

    friend bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs<lhs); }

    friend bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs<lhs; }

    friend bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs<rhs); }


  };

  template <class T1, class T2>
  pair<T1,T2> make_pair (T1 x, T2 y) {
    return (pair<T1,T2>(x,y));
  };

}
#endif //SRCS_UTILS_HPP_