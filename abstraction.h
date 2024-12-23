#include "cherubin.h"
#include <math.h>

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

std::string multabstraction(std::string x, std::string x2) {
  std::string rtn_str;
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  if (x[0] == '-' & x2[0] == '-') {
    x = x.substr(1, n);
    x2 = x2.substr(1, n2);
    return multflt(x, x2);
  } else if (x[0] == '-') {
    rtn_str = "-";
    x = x.substr(1, n);
    rtn_str += multflt(x, x2);
    return rtn_str;
  } else if (x2[0] == '-') {
    rtn_str = "-";
    x2 = x2.substr(1, n2);
    rtn_str += multflt(x, x2);
    return rtn_str;
  } else {
    return multflt(x, x2);
  };
};

std::string divideabstraction(std::string x, std::string x2) {
  std::string rtn_str;
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  if (x[0] == '-' & x2[0] == '-') {
    x = x.substr(1, n);
    x2 = x2.substr(1, n2);
    return divide2(x, x2);
  } else if (x[0] == '-') {
    rtn_str = "-";
    x = x.substr(1, n);
    rtn_str += divide2(x, x2);
    return rtn_str;
  } else if (x2[0] == '-') {
    rtn_str = "-";
    x2 = x2.substr(1, n2);
    rtn_str += divide2(x, x2);
    return rtn_str;
  } else {
    return divide2(x, x2);
  };
};


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

std::string chlognatural1(std::string &x) {
  std::string base_natural = "2.718281";
  std::string cbase_natural = base_natural;
  std::string lst_str;
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

