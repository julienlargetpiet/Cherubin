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

//@T chacos
//@U std::string chacos(std::string &x, std::string base = "1.570796", unsigned int n_polynom = 10)
//@X
//@D Returns the result of acos(x)
//@A x : is the input (int or float as std string)
//@A base : is the closest value to pi / 2
//@A n_polynom : is the size of the polynom used for the approximation of arcos with taylor serie
//@X
//@E std::string x = "-0.99";
//@E chacos(x);
//@E "3.00017080000"
//@X

std::string chacos(std::string &x, std::string base = "1.570796", unsigned int n_polynom = 10) {
  bool is_negative = 0;
  std::string new_x = x;
  if (x[0] == '-') {
    new_x = new_x.substr(1, x.length());
    is_negative = 1;
  };
  std::string cur_divider;
  std::string cur_divided1;
  std::string cur_divided2;
  std::string cur_dividedf;
  std::string cur_rslt;
  std::string cur_add = "3";
  std::string addr = "2";
  std::string rslt = new_x;
  std::string cnt;
  std::string ref_subs = "2";
  std::string ref_subsb = "1";
  std::string val_pi = multflt2(base, ref_subs);
  std::vector<std::string> cur_v;
  std::string ref_max = "0.92";
  std::string ref_square = "0.5";
  if (!is_greaterflt(new_x, ref_max)) {
    for (unsigned int i = 1; i < n_polynom; ++i) {
      cur_divided1 = powerint3(new_x, cur_add);
      cnt = cur_add;
      cnt = subsint(cnt, ref_subs);
      cur_divided2 = cnt;
      if (cnt != "1") {
        cnt = subsint(cnt, ref_subs);
        while (cnt != "1") {
          cur_divided2 = multint2(cur_divided2, cnt); 
          cnt = subsint(cnt, ref_subs);
        };
      };
      cur_dividedf = multabstraction(cur_divided1, cur_divided2);
      cur_divider = cur_add;
      cnt = subsint(cur_add, ref_subsb);
      while (cnt != "0") {
        cur_divider = multint2(cur_divider, cnt);
        cnt = subsint(cnt, ref_subs);
      };
      cur_v = centerizer(cur_dividedf, cur_divider);
      cur_dividedf = cur_v[0];
      cur_divider = cur_v[1];
      cur_rslt = divideabstraction(cur_dividedf, cur_divider);
      rslt = addabstraction(rslt, cur_rslt);
      cur_add = addint(cur_add, addr);
    };
    rslt = subsabstraction(base, rslt);
  } else {
    rslt = subsflt(ref_subsb, new_x);
    rslt = multflt2(rslt, ref_subs);
    rslt = powerflt(rslt, ref_square);
  };
  if (is_negative) {
    rslt = subsabstraction(val_pi, rslt);
  };
  return rslt;
};

