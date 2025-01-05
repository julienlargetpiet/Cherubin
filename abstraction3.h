#include "abstraction2.h"

//@T inverse
//@U std::string inverse(std::string &a, std::string &b, std::string (*f)(std::string&, std::string&))
//@X
//@D Returns the inverse of the result of a function passed as a parameter.
//@A f : is the function passed as a parameter
//@A a : is the first number, as a std string, of the function passed as a parameter
//@A b : is the second number, as a std string, of the function passed as a parameter
//@X
//@E
//@E std::string x = "3";
//@E std::string x2 = "10";
//@E inverse(x, x2, powerint3)
//@E "0.0000169350" // is 1/3**10
//@E
//@X

std::string inverse(std::string &a, std::string &b, std::string (*f)(std::string&, std::string&)) {
  std::string x = "1";
  std::string rtn_str = f(a, b);
  return divide2(x, rtn_str);
};


//@T powerflt
//@U std::string powerflt(std::string &x, std::string &x2, unsigned int nb_polynomial = 20)
//@X
//@D Returns the result of a int or float (as std string) to the power of int or float (as std string) 
//@A x : is the number (int or float as std string) that will be elevated to an exponent
//@A x2 : is the exponent (int or float as std string)
//@A nb_polynomial : is the length of the polynomial used for the taylor serie of exp(x) that allow the function to work. The bigger log(x) times x2 is, the bigger <code>nb_polynomial</code> should be.
//@E
//@E std::string x = "3.478";
//@E std::string x2 = "10.58";
//@E powerflt(x, x2);
//@E "537525.0830373820"
//@E
//@X

std::string powerflt(std::string &x, std::string &x2) {
  std::string rtn_str = chlognatural1(x);
  rtn_str = multflt2(rtn_str, x2);
  return chexp3(rtn_str);
};

//@T chcos
//@U std::string chcos(std::string &x, std::string base = "3.141593", unsigned int nb_polynom = 10)
//@X
//@D Returns the result of cosinus(x) with the help of taylor serie
//@A x : is the input number, int or float as std string
//@A base : is the closest value of pi
//@A nb_polynom : is the ssize of the polynom used for the approximation
//@X
//@E std::string x = "-125.5";
//@E std::string final_rslt = chcos(x);
//@E -0.9866278020907 
//@X

std::string chcos(std::string &x, std::string base = "3.141593", unsigned int nb_polynom = 10) {
  std::string new_x = x;
  if (new_x[0] == '-') {
    new_x = new_x.substr(1, x.length());
  };
  new_x = remainderflt(new_x, base);
  std::string rslt = "1";
  std::string cur_divided;
  std::string cur_divider;
  std::string addr = "2";
  std::string cur_add = "2";
  std::string cur_rslt;
  for (unsigned int i = 1; i < nb_polynom; ++i) {
    cur_divided = powerint3(new_x, cur_add);
    cur_divider = factorial(cur_add);
    cur_rslt = divide2(cur_divided, cur_divider);
    if (i % 2 == 0) {
      rslt = addabstraction(rslt, cur_rslt);
    } else {
      rslt = subsabstraction(rslt, cur_rslt);
    };
    cur_add = addint(cur_add, addr);
  };
  return rslt;
};

