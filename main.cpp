#include <iostream>
#include "srcs/iterator.hpp"
#include "srcs/list.hpp"
#include <list>
#include <vector>
#include "srcs/vector.hpp"
#include "srcs/tree.hpp"
#include <map>
#include "srcs/map.hpp"
using namespace ft;

bool fncomp (char lhs, char rhs) {return lhs>rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  ft::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  ft::map<char,int> second (first.begin(),first.end());

  ft::map<char,int> third (second);

  ft::map<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

  fifth['a']=10;
  fifth['b']=30;
  fifth['c']=50;
  fifth['d']=70;

  for (ft::map<char, int, bool(*)(char,char)>::iterator i = fifth.begin(); i != fifth.end(); i++)
    std::cout << "fifth: " << i->first << " -> " << i->second << std::endl;

  return 0;
}