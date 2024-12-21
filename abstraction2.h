#include "abstraction.h"

std::string subsabstraction(std::string x, std::string x2) {
  std::string rtn_str;
  bool grt;
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  if (x == x2) {
    return "0";
  } else if (x2[0] == '-') {
    return addabstraction(x, x2);
  } else if (x[0] == '-') {
      x = x.substr(1, n);
      rtn_str = "-";
      rtn_str += addflt(x, x2);
      return rtn_str;
  } else {
    grt = is_greater(x, x2);
    if (grt || x == x2) {
      return subsflt(x, x2);
    } else {
      rtn_str = "-";
      rtn_str += subsflt(x2, x);
      return rtn_str;
    };
  };
};


