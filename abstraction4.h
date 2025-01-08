#include "abstraction3.h"

//@T chtan
//@U std::string chtan(std::string &x, std::string base = "6.283185", unsigned int n_polynom = 10)
//@X
//@D Returns the result of tan(x)
//@A x : is the input number, int or float as std string 
//@A base : is the closest value to 2 times pi
//@A n_polynom : is the length of the polynom used for the taylor approximation
//@X
//@E std::string x = "-3.5";
//@E unsigned int nb = 10;
//@E std::string base = "6.283185";
//@E std::string out = chtan(x, base, nb);
//@E "-0.374584" 
//@X

std::string chtan(std::string &x, std::string base = "6.283185", unsigned int n_polynom = 10) {
  std::string divided = chsin(x, base, n_polynom);
  std::string divider = chcos(x, base, n_polynom);
  bool divided_dec = 0;
  bool divider_dec = 0;
  if (divided[0] == '-') {
    divided_dec = 1;
    divided = divided.substr(1, divided.length());
  };
  if (divider[0] == '-') {
    divider_dec = 1;
    divider = divider.substr(1, divider.length());
  };
  std::vector<std::string> cur_v = centerizer(divided, divider);
  divided = cur_v[0];
  divider = cur_v[1];
  if (divided_dec) {
    divided = "-" + divided;
  };
  if (divider_dec) {
    divider = "-" + divider;
  };
  std::string rslt = divideabstraction(divided, divider);
  return rslt;
};

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


