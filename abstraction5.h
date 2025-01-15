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

//@T chbeta
//@U std::string chbeta(std::string &x, std::string &x2)
//@X
//@D Returns the result of the beta function
//@A x : is the first input
//@A y : is the second input
//@X
//@E std::string x = "2";
//@E std::string y = "3";
//@E std::string out = chbeta(x, y);
//@E "0.08333333" 
//@X

std::string chbeta(std::string &x, std::string &y) {
  std::string divided1 = chgamma(x);
  std::string divided2 = chgamma(y);
  std::string dividedf = multflt(divided1, divided2);
  std::string divider;
  std::string ref_subs = "1";
  std::string x_divider = addflt(x, y);
  if (is_decimal(x_divider)) {
    x_divider = rmzero(x_divider);
  };
  divider = chgamma(x_divider);
  return divide2(dividedf, divider);
};


