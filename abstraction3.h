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
//@A x2 : is the exponent (int or float as std string), can be negative
//@A nb_polynomial : is the length of the polynomial used for the taylor serie of exp(x) that allow the function to work. The bigger log(x) times x2 is, the bigger <code>nb_polynomial</code> should be.
//@E
//@E std::string x = "3.478";
//@E std::string x2 = "10.58";
//@E powerflt(x, x2);
//@E "537525.0830373820"
//@E
//@X

std::string powerflt(std::string &x, std::string &x2) {
  std::string new_x2 = x2;
  std::string rtn_str;
  std::string divided = "1";
  bool is_negative = 0;
  if (x2[0] == '-') {
    new_x2 = new_x2.substr(1, new_x2.length());
    is_negative = 1;
  };
  rtn_str = chlognaturalabstraction(x);
  rtn_str = multabstraction(rtn_str, new_x2);
  if (rtn_str[0] != '-') {
    rtn_str = chexp3(rtn_str);
  } else {
    rtn_str = rtn_str.substr(1, rtn_str.length());
    rtn_str = chexp3(rtn_str);
    rtn_str = divide2(divided, rtn_str);
  };
  if (is_negative) {
    return divide2(divided, rtn_str);
  } else {
    return rtn_str;
  };
};

//@T chlognabstraction
//@U std::string chlognabstraction(std::string &x, std::string &base)
//@X
//@D Returns the result for logn(x)
//@A x : is the input (int or float as std string)
//@A base : is the base of the log
//@X
//@E
//@X

std::string chlognabstraction(std::string &x, std::string &base) {
  std::string rtn_str;
  std::string ref_val = "1";
  std::vector<std::string> cur_v;
  if (is_greaterflt(x, ref_val) || x == ref_val) {
    return chlogn(x, base);
  } else {
    rtn_str = x;
    cur_v = centerizer(ref_val, rtn_str);
    rtn_str = cur_v[1];
    ref_val = cur_v[0];
    rtn_str = divide2(ref_val, rtn_str);
    rtn_str = chlogn(rtn_str, base);
    rtn_str.insert(0, 1, '-');
    return rtn_str;
  };
};

//@T chcos
//@U std::string chcos(std::string &x, std::string base = "3.141593", unsigned int nb_polynom = 10)
//@X
//@D Returns the result of cosinus(x) with the help of taylor serie
//@A x : is the input number, int or float as std string
//@A base : is the closest value of 2 times pi
//@A nb_polynom : is the ssize of the polynom used for the approximation
//@X
//@E std::string x = "-125.5";
//@E std::string final_rslt = chcos(x);
//@E -0.9866278020907 
//@X

std::string chcos(std::string &x, std::string base = "6.283185", unsigned int nb_polynom = 10) {
  std::string new_x = x;
  if (new_x[0] == '-') {
    new_x = new_x.substr(1, x.length());
  };
  if (is_greaterflt(new_x, base) || x == base) {
    new_x = remainderflt(new_x, base);
  };
  bool eq_zero = 1;
  for (char chr : new_x) {
    if (chr != '0' & chr != '.') {
      eq_zero = 0;
      break;
    };
  };
  if (eq_zero) {
    return "1";
  };
  std::string rslt = "1";
  std::string cur_divided;
  std::string cur_divider;
  std::string addr = "2";
  std::string cur_add = "2";
  std::string cur_rslt;
  std::vector<std::string> cur_vec;
  for (unsigned int i = 1; i < nb_polynom; ++i) {
    cur_divided = powerint3(new_x, cur_add);
    cur_divider = factorial(cur_add);
    cur_vec = centerizer(cur_divided, cur_divider);
    cur_divided = cur_vec[0];
    cur_divider = cur_vec[1];
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

//@T chsin 
//@U std::string chsin(std::string &x, std::string base = "6.283185", unsigned int n_polynom = 15)
//@X
//@D Returns the result of sinus function.
//@A x : is the input int of float as std string
//@A base : is the closest value to 2 times pi
//@A n_polynom : is the length of the polynom used by the taylor serie
//@X
//@E std::string x = "5.8";
//@E std::string out = chsin(x);
//@E "-0.464629431880273"
//@X

std::string chsin(std::string &x, std::string base = "6.283185", unsigned int n_polynom = 15) {
  bool is_negative = 0;
  if (x[0] == '-') {
    is_negative = 1;
    x = x.substr(1, x.length());
  };
  std::string new_x = x;
  if (is_greaterflt(x, base)) {
    new_x = remainderflt(x, base);
  }; 
  if (is_zero(new_x)) {
    return "0";
  };
  std::string rslt = new_x;
  std::string cur_add = "3";
  std::string addr = "2";
  std::string cur_divided;
  std::string cur_divider;
  std::string cur_rslt;
  std::vector<std::string> cur_v;
  for (unsigned int i = 1; i < n_polynom; ++i) {
    cur_divided = powerint3(new_x, cur_add);
    cur_divider = factorial(cur_add);
    cur_v = centerizer(cur_divided, cur_divider);
    cur_divided = cur_v[0];
    cur_divider = cur_v[1];
    cur_rslt = divide2(cur_divided, cur_divider);
    if (i % 2 == 0) {
      rslt = addabstraction(rslt, cur_rslt);
    } else {
      rslt = subsabstraction(rslt, cur_rslt);
    };
    cur_add = addint(cur_add, addr);
  };
  if (is_negative) {
    if (rslt[0] != '-') {
      rslt = "-" + rslt;
    } else {
      rslt.erase(rslt.begin());
    };
  };
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
  std::string rslt = x;
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

