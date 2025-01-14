#include "abstraction.h"

//@T subsabstraction
//@U std::string subsabstraction(std::string x, std::string x2)
//@X
//@D Returns the result of a substraction. Handles the abstraction needed for <code>subsflt</code> function  that normally does not accept negative inputs. 
//@A x : is the number that will be substracted (int or float as std string)
//@A x2 : is the number that will substract <code>x</code>
//@X
//@E
//@E std::string x = "-5687.58";
//@E std::string x2 = "-459372";
//@E subsabstraction(x2, x);
//@E "-465059.58"
//@E
//@X

std::string subsabstraction(std::string x, std::string x2) {
  std::string rtn_str;
  bool grt;
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  if (x == x2) {
    return "0";
  } else if (x[0] == '-' & x2[0] == '-'){
    x.erase(x.begin());
    x2.erase(x2.begin());
    grt = is_greaterflt(x, x2);
    if (grt) {
      rtn_str = "-";
      rtn_str += subsflt(x, x2);
      return rtn_str;
    } else {
      return subsflt(x2, x);
    };
  } else if (x2[0] == '-') {
    return addabstraction(x, x2);
  } else if (x[0] == '-') {
      x = x.substr(1, n);
      rtn_str = "-";
      rtn_str += addflt(x, x2);
      return rtn_str;
  } else {
    grt = is_greaterflt(x, x2);
    if (grt || x == x2) {
      return subsflt(x, x2);
    } else {
      rtn_str = "-";
      rtn_str += subsflt(x2, x);
      return rtn_str;
    };
  };
};

//@T chlogn
//@U std::string chlogn(std::string &x, std::string base)
//@X
//@D Returns the value of a logarithm for any base.
//@A x : is the value (int or float as std string) we want to find the logarithm from
//@A base : is the base (int or float as std string) of the logarithm
//@X
//@E
//@E std::string x = "5687.58";
//@E std::string x2 = "10";
//@E chlogn(x, x2);
//@E "3.754931"
//@E
//@X

std::string chlogn(std::string &x, std::string base) {
  std::string rtn_str = chlognatural1(x);
  base = chlognatural1(base);
  std::vector<std::string> cur_v = centerizer(rtn_str, base);
  rtn_str = cur_v[0];
  base = cur_v[1];
  rtn_str = divide2(rtn_str, base);
  return rtn_str;
};

//@T chlognaturalabstraction
//@U std::string chlognaturalabstraction(std::string &x)
//@X
//@D Returns the result for log(x)
//@A x : is the input (int or float as std string)
//@X
//@E
//@X

std::string chlognaturalabstraction(std::string &x) {
  std::string rtn_str;
  std::string ref_val = "1";
  std::vector<std::string> cur_v;
  if (is_greaterflt(x, ref_val) || x == ref_val) {
    return chlognatural1(x);
  } else {
    rtn_str = x;
    cur_v = centerizer(ref_val, rtn_str);
    rtn_str = cur_v[1];
    ref_val = cur_v[0];
    rtn_str = divide2(ref_val, rtn_str);
    rtn_str = chlognatural1(rtn_str);
    rtn_str.insert(0, 1, '-');
    return rtn_str;
  };
};

