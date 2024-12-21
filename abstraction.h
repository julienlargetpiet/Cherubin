#include "cherubin.h"

std::string addabstraction(std::string x, std::string x2) {
  std::string rtn_str;
  bool grt;
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  if (x[0] == '-' & x2[0] == '-') {
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

std::string chexp2(std::string &x, unsigned int nb_polynomial = 20) {
  std::string rtn_str = "1";
  std::string addr = "1";
  std::string ref_add = "1";
  std::string rslt;
  std::string numerator;
  std::string denumerator;
  for (unsigned int i = 1; i < nb_polynomial; ++i) {
    numerator = powerint3(x, addr);
    denumerator = factorial(addr);
    std::cout << "numerator: " << numerator << "\n";
    std::cout << "denumerator: " << denumerator << "\n";
    rslt = divide2(numerator, denumerator, 10);
    rtn_str = addflt(rtn_str, rslt);
    addr = addint(addr, ref_add);
  };
  return rtn_str;
};
