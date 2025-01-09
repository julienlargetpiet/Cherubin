#include "abstraction4.h"

//@T chasin
//@U std::string chasin(std::string &x, std::string base = "1.570796", unsigned int n_polynom = 10)
//@X
//@D Returns the result of asin(x)
//@A x : is the input, int or float as std string
//@A base : is the closest value to pi/2 
//@A n_polynom : is the size of the polynom used for the approximation by the taylor serie
//@X
//@E std::string x = "-0.97";
//@E chasin(x);
//@E "-1.32584700000"
//@X

std::string chasin(std::string &x, std::string base = "1.570796", unsigned int n_polynom = 10) {
  std::string rtn_str = chacos(x, base, n_polynom);
  rtn_str = subsabstraction(base, rtn_str);
  return rtn_str;
};
