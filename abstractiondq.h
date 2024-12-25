#include "cherubin.h"
#include <math.h>

//@T addabstraction
//@U std::string addabstraction(std::string x, std::string x2)
//@X
//@D Returns the result of any addition between positive and/or negative values. Handles the abstraction for <code>addflt</code> function that normally does not accept negative value.
//@A x : the first number (int or float as std string)
//@A x2 : the second number (int or float as std string)
//@X
//@E
//@E std::string x = "0.5";
//@E std::string x2 = "2.5";
//@E addabstraction(x, x2);
//@E "3.0"
//@E x2 = "-2.5";
//@E addabstraction(x, x2);
//@E "-2.0" 
//@E
//@X

std::string addabstraction(std::string x, std::string x2) {
  std::string rtn_str;
  bool grt;
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  if (x == x2) {
    return "0";
  } else if (x[0] == '-' & x2[0] == '-') {
    rtn_str = "-";
    x = x.substr(1, n);
    x2 = x2.substr(1, n2);
    rtn_str += addflt(x, x2);
    return rtn_str;
  } else if (x2[0] == '-') {
    x2 = x2.substr(1, n2);
    grt = is_greater(x2, x);
    if (grt) {
      rtn_str = "-";
      rtn_str += subsflt(x2, x);
      return rtn_str;
    } else {
      return subsflt(x, x2);
    };
  } else if (x[0] == '-') {
    x = x.substr(1, n);
    grt = is_greater(x, x2);
    if (grt) {
      rtn_str = "-";
      rtn_str += subsflt(x, x2);
      return rtn_str;
    } else {
      return subsflt(x2, x);
    };
  } else {
    return addflt(x, x2);
  };
};

//@T multabstraction
//@U std::string multabstraction(std::string x, std::string x2)
//@X
//@D Returns the result of a multiplication. Handles the abstraction for <code>multflt2</code> that normaly does not accept negative values.
//@A x : is the first number (int or float as std string)
//@A x2 : is the second number (int or float as std string)
//@X
//@E
//@E std::string x = "-569.87";
//@E std::string x2 = "459372";
//@E multabstraction(x, x2);
//@E "-261782321.640"
//@E
//@X

std::string multabstraction(std::string x, std::string x2) {
  std::string rtn_str;
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  if (x[0] == '-' & x2[0] == '-') {
    x = x.substr(1, n);
    x2 = x2.substr(1, n2);
    return multflt2(x, x2);
  } else if (x[0] == '-') {
    rtn_str = "-";
    x = x.substr(1, n);
    rtn_str += multflt2(x, x2);
    return rtn_str;
  } else if (x2[0] == '-') {
    rtn_str = "-";
    x2 = x2.substr(1, n2);
    rtn_str += multflt2(x, x2);
    return rtn_str;
  } else {
    return multflt2(x, x2);
  };
};

//@T divideabstraction
//@U std::string divideabstraction(std::string x, std::string x2, unsigned int nb_decimal = 5)
//@X
//@D Returns the result of a division. Handles the abstraction for <code>divide2</code> that normaly does not accept negative values.
//@A x : is the first number (int or float as std string)
//@A x2 : is the second number (int or float as std string)
//@A nb_decimal : is the number of decimal to keep
//@X
//@E
//@E std::string x = "-569.87";
//@E std::string x2 = "459372";
//@E divideabstraction(x, x2);
//@E "-0.001240541"
//@E
//@X

std::string divideabstraction(std::string x, std::string x2, unsigned int nb_decimal = 5) {
  std::string rtn_str;
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  if (x[0] == '-' & x2[0] == '-') {
    x = x.substr(1, n);
    x2 = x2.substr(1, n2);
    return divide2(x, x2, nb_decimal);
  } else if (x[0] == '-') {
    rtn_str = "-";
    x = x.substr(1, n);
    rtn_str += divide2(x, x2, nb_decimal);
    return rtn_str;
  } else if (x2[0] == '-') {
    rtn_str = "-";
    x2 = x2.substr(1, n2);
    rtn_str += divide2(x, x2, nb_decimal);
    return rtn_str;
  } else {
    return divide2(x, x2, nb_decimal);
  };
};

//@T chexp2
//@U std::string chexp2(std::string &x, unsigned int nb_polynomial = 21)
//@X
//@D Returns the result of the exponential function for any value.
//@A x : is the number (int or float as std string) that we want to calculate the exponential from
//@A nb_polynomial : is the length of the polynomial used for the taylor serie for the approximation of the exponential function. Higher <code>x</code> is, higher the value of this parameter should be.
//@X
//@E
//@E std::string x = "56.87";
//@E chexp2(x, 390);
//@E "17408961367637823234360092375649240274962948816922400656258834086662691682597949182878181506839462714090174265636968592012539404439115388571203863053175373763348307275660537898101671121177016775956775125086597870411101884320489957750.4944500000" 
//@E
//@X

std::string chexp2(std::string &x, unsigned int nb_polynomial = 21) {
  std::string rtn_str = "1";
  std::string addr = "1";
  std::string ref_add = "1";
  std::string rslt;
  std::string numerator;
  std::string denumerator;
  for (unsigned int i = 1; i < nb_polynomial; ++i) {
    numerator = powerint3(x, addr);
    denumerator = factorial(addr);
    rslt = divide2(numerator, denumerator, 10);
    rtn_str = addflt(rtn_str, rslt);
    addr = addint(addr, ref_add);
  };
  return rtn_str;
};

//@T chlognatural1
//@U std::string chlognatural1(std::string &x)
//@X
//@D Returns the result of the natural logarithm for any value. 
//@A x : is an int or float as std string
//@X
//@E
//@E std::string x = "5687.58";
//@E chlognatural1(x);
//@E "8.646042"
//@E
//@X

std::string chlognatural1(std::string &x) {
  std::string base_natural = "2.718281";
  std::string cbase_natural = base_natural;
  std::string lst_str = "1";
  std::string intr_str;
  std::string rslt;
  std::string base_add = "0";
  std::string addr = "1";
  double cur_val;
  while (is_greaterflt(x, base_natural)) {
    lst_str = base_natural;
    base_natural = multflt2(base_natural, cbase_natural);
    if (is_decimal(base_natural)) {
      base_natural = rmzero(base_natural);
    };
    base_add = addint(base_add, addr);
  };
  rslt = divide2(x, lst_str);
  cur_val = chstod(rslt);
  cur_val = log(cur_val);
  intr_str = std::to_string(cur_val);
  base_add = addflt(base_add, intr_str);
  return base_add;
};
