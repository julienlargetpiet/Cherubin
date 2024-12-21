#include "cherubin.h"

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
    rslt = divide2(numerator, denumerator);
    rtn_str = addflt(rtn_str, rslt);
    addr = addint(addr, ref_add);
  };
  return rtn_str;
};
