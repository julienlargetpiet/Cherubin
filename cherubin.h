#include <iostream>
#include <vector>

//@L Addition
//@L2 Integers

//@T addint
//@U std::string addint(std::string &x, std::string &x2)
//@X
//@D Returns the result as a std string.
//@A x : is the first positive int as a string
//@A x2 is the second positive int as a string
//@X
//@E
//@X

std::string addint(std::string &x, std::string &x2) {
  std::string cur_str;
  std::string bf_str;
  unsigned int cnt;
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  unsigned int sizen;
  if (n2 > n) {
    cur_str = x2;
    bf_str = x;
    cnt = n2 - n;
    sizen = n2;
  } else {
    cur_str = x;
    bf_str = x2;
    cnt = n - n2; 
    sizen = n;
  };
  int cur_val;
  int bf_cnt;
  bool agn;
  if (bf_str[0] == '-') {
    return "";
  };
  if (cur_str[0] != '-') {
    for (int i = cnt; i < sizen; ++i) {
      cur_val = (int(bf_str[i - cnt]) - 48) + (int(cur_str[i]) - 48);
      if (cur_val > 9) {
        cur_val -= 10;
        cur_str[i] = char(cur_val + 48);
        bf_cnt = 0;
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (i - bf_cnt > -1) {
            if (cur_str[i - bf_cnt] == '9') {
              cur_str[i - bf_cnt] = '0';
            } else {
              cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) + 1);
              agn = 0;
            };
          } else {
            cur_str.insert(0, "1");
            cnt += 1;
            i += 1;
            sizen += 1;
            agn = 0;
          };
        };
      } else {
        cur_str[i] = char(cur_val + 48);
      };
    };
  } else {
    return "";
  };
  return cur_str;
};

//@L2 Floating points

//@T addflt
//@U std::string addflt(std::string &x, std::string &x2)
//@X
//@D Returns the addition of two floating points as a std string. Accepts integers, but if you plan to add integers, <code>addint</code> is preferable to use.
//@A 
//@A
//@E
//@X

std::string addflt(std::string &x, std::string &x2) {
  std::string cur_str;
  std::string bf_str;
  const unsigned bf_cn = x.length();
  const unsigned bf_cn2 = x2.length();
  unsigned int cnt = 0;
  bool agn = 1;
  bool is_dec1 = 0;
  bool is_dec2 = 0;
  int i;
  int cur_delta = 0;
  while (agn) {
    cnt += 1;
    if (cnt == bf_cn) {
      agn = 0;
    } else if (x[cnt] == '.') {
      is_dec1 = 1;
      agn = 0;
    };
  };
  const unsigned int n = cnt;
  agn = 1;
  cnt = 0;
  while (agn) {
    cnt += 1;
    if (cnt == bf_cn2) {
      agn = 0;
    } else if (x2[cnt] == '.') {
      is_dec2 = 1;
      agn = 0;
    };
  };
  const unsigned int n2 = cnt;
  unsigned int sizen;
  if (n2 > n) {
    cur_str = x2;
    bf_str = x;
    cnt = n2 - n;
    cur_delta = (bf_cn - n) - (bf_cn2 - n2);
    sizen = bf_cn2;
    if (cur_delta > 0) {
      sizen += cur_delta;
      if (!is_dec2) {
        cur_delta -= 1;
        cur_str += ".";
      };
      for (i = 0; i < cur_delta; ++i) {
        cur_str += "0";
      };
    } else if (cur_delta < 0) {
      cur_delta *= -1;
      if (!is_dec1) {
        cur_delta -= 1;
        bf_str += ".";
      };
      for (i = 0; i < cur_delta; ++i) {
        bf_str += "0";
      };
    };
  } else {
    cur_str = x;
    bf_str = x2;
    cnt = n - n2; 
    cur_delta = (bf_cn2 - n2) - (bf_cn - n);
    sizen = bf_cn;
    if (cur_delta > 0) {
      sizen += cur_delta;
      if (!is_dec1) {
        cur_delta -= 1;
        cur_str += ".";
      };
      for (i = 0; i < cur_delta; ++i) {
        cur_str += "0";
      };
    } else if (cur_delta < 0) {
      cur_delta *= -1;
      if (!is_dec2) {
        cur_delta -= 1;
        bf_str += ".";
      };
      for (i = 0; i < cur_delta; ++i) {
        bf_str += "0";
      };
    };
  };
  int cur_val;
  int bf_cnt;
  if (bf_str[0] == '-') {
    return "";
  };
  if (cur_str[0] != '-') {
    for (i = cnt; i < sizen; ++i) {
      if (cur_str[i] != '.') {
        cur_val = (int(bf_str[i - cnt]) - 48) + (int(cur_str[i]) - 48);
        if (cur_val > 9) {
          cur_val -= 10;
          cur_str[i] = char(cur_val + 48);
          if (i - 1 > 0) {
            if (cur_str[i - 1] != '.') {
              bf_cnt = 0;
            } else {
              bf_cnt = 1;
            };
          } else {
            bf_cnt = 0;
          };
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (i - bf_cnt > -1) {
              if (cur_str[i - bf_cnt] != '.') {
                if (cur_str[i - bf_cnt] == '9') {
                  cur_str[i - bf_cnt] = '0';
                } else {
                  cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) + 1);
                  agn = 0;
                };
              };
            } else {
              cur_str.insert(0, "1");
              cnt += 1;
              i += 1;
              sizen += 1;
              agn = 0;
            };
          };
        } else {
          cur_str[i] = char(cur_val + 48);
        };
      };
    };
  } else {
    return "";
  };
  return cur_str;
};

//@L Substraction
//@L2 Integers

//@T subsint
//@U std::string subsint(std::string &x, std::string &x2)
//@X
//@D Returns the result as a std string.
//@A x : is the first positive int as a string, must be greater or equal to to x2
//@A x2 is the second positive int as a string, must be lower or equal to x
//@X
//@E
//@X

std::string subsint(std::string &x, std::string &x2) {
  std::string cur_str = x;
  std::string bf_str = x2;
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  unsigned int sizen;
  unsigned int cnt;
  int i;
  if (n >= n2) {
    sizen = n;
    cnt = n - n2;
  } else {
    return "";
  };
  int cur_val;
  int bf_cnt;
  bool agn;
  if (bf_str[0] == '-') {
    return "";
  };
  if (cur_str[0] != '-') { 
    for (i = cnt; i < sizen; ++i) {
      cur_val = (int(cur_str[i]) - 48) - (int(bf_str[i - cnt]) - 48);
      if (cur_val < 0) {
        cur_val = 10 + cur_val;
        cur_str[i] = char(int(cur_val) + 48);
        bf_cnt = 0;
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (cur_str[i - bf_cnt] == '0') {
            cur_str[i - bf_cnt] = '9';
          } else {
            cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) - 1);
            agn = 0;
          };
        };
      } else {
        cur_str[i] = char(cur_val + 48);
      };
      if (cur_str[0] == '0') {
        cur_str = cur_str.substr(1, cur_str.length());
        bf_str = bf_str.substr(1, cur_str.length());
        sizen -= 1;
        i -= 1;
      };
    };
  } else {
    return "";
  };
  return cur_str;
};

//@L2 Floating points

//@T subsflt
//@U std::string subsflt(std::string &x, std::string &x2) 
//@X
//@D Returns the substraction of two floating point numbers. Accepts integers, but if you plan to substract integers, it is preferable to use <code>subsint</code> function.
//@A x : is a number represented as a string, must be higher or equal to the second number 
//@A x2 : is a number represented as a string, must be lower or equal to the second number 
//@X
//@E
//@X

std::string subsflt(std::string &x, std::string &x2) {
  std::string cur_str = x;
  std::string bf_str = x2;
  const unsigned bf_cn = x.length();
  const unsigned bf_cn2 = x2.length();
  unsigned int cnt = 0;
  bool agn = 1;
  bool is_dec1 = 0;
  bool is_dec2 = 0;
  int i;
  int cur_delta = 0;
  while (agn) {
    cnt += 1;
    if (cnt == bf_cn) {
      agn = 0;
    } else if (x[cnt] == '.') {
      is_dec1 = 1;
      agn = 0;
    };
  };
  const unsigned int n = cnt;
  agn = 1;
  cnt = 0;
  while (agn) {
    cnt += 1;
    if (cnt == bf_cn2) {
      agn = 0;
    } else if (x2[cnt] == '.') {
      is_dec2 = 1;
      agn = 0;
    };
  };
  const unsigned int n2 = cnt;
  unsigned int sizen;
  if (n2 > n) {
    cur_str = x2;
    bf_str = x;
    cnt = n2 - n;
    cur_delta = (bf_cn - n) - (bf_cn2 - n2);
    sizen = bf_cn2;
    if (cur_delta > 0) {
      sizen += cur_delta;
      if (!is_dec2) {
        cur_delta -= 1;
        cur_str += ".";
      };
      for (i = 0; i < cur_delta; ++i) {
        cur_str += "0";
      };
    } else if (cur_delta < 0) {
      cur_delta *= -1;
      if (!is_dec1) {
        cur_delta -= 1;
        bf_str += ".";
      };
      for (i = 0; i < cur_delta; ++i) {
        bf_str += "0";
      };
    };
  } else {
    cur_str = x;
    bf_str = x2;
    cnt = n - n2; 
    cur_delta = (bf_cn2 - n2) - (bf_cn - n);
    sizen = bf_cn;
    if (cur_delta > 0) {
      sizen += cur_delta;
      if (!is_dec1) {
        cur_delta -= 1;
        cur_str += ".";
      };
      for (i = 0; i < cur_delta; ++i) {
        cur_str += "0";
      };
    } else if (cur_delta < 0) {
      cur_delta *= -1;
      if (!is_dec2) {
        cur_delta -= 1;
        bf_str += ".";
      };
      for (i = 0; i < cur_delta; ++i) {
        bf_str += "0";
      };
    };
  };
  int cur_val;
  int bf_cnt;
  if (bf_str[0] == '-') {
    return "";
  };
  if (cur_str[0] != '-') { 
    for (i = cnt; i < sizen; ++i) {
      if (cur_str[i] != '.') {
        cur_val = (int(cur_str[i]) - 48) - (int(bf_str[i - cnt]) - 48);
        if (cur_val < 0) {
          cur_val = 10 + cur_val;
          cur_str[i] = char(int(cur_val) + 48);
          if (cur_str[i - 1] != '.') {
            bf_cnt = 0;
          } else {
            bf_cnt = 1;
          };
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (cur_str[i - bf_cnt] != '.') {
              if (cur_str[i - bf_cnt] == '0') {
                cur_str[i - bf_cnt] = '9';
              } else {
                cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) - 1);
                agn = 0;
              };
            };
          };
        } else {
          cur_str[i] = char(cur_val + 48);
        };
        if (cur_str[0] == '0') {
          cur_str = cur_str.substr(1, cur_str.length());
          bf_str = bf_str.substr(1, cur_str.length());
          i -= 1;
          sizen -= 1;
        };
      };
    };
  } else {
    return "";
  };
  return cur_str;
};

//@L Multiplication
//@L2 Integers

//@T multint
//@U std::string multint(std::string &x, unsigned int &x2)
//@X
//@D Returns the multiplication of two integers as std string.
//@A x : is an integer higher than 0 as a std string
//@A x2 : is an unsigned integer higher than 0 
//@X
//@E
//@X

std::string multint(std::string &x, unsigned int &x2) {
  std::string cur_str = x;
  std::string cur_str2 = x;
  unsigned int cnt = 1;
  unsigned int n = x.length();
  int cur_val;
  unsigned int delta = 0;
  int bf_cnt;
  bool agn;
  int i;
  if (cur_str[0] != '-') {
    while (cnt != x2) {
      for (i = delta; i < n; ++i) {
        cur_val = (int(cur_str[i]) - 48) + (int(cur_str2[i - delta]) - 48);
        if (cur_val > 9) {
          cur_val -= 10;
          cur_str[i] = char(cur_val + 48);
          bf_cnt = 0;
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (i - bf_cnt > -1) {
              if (cur_str[i - bf_cnt] == '9') {
                cur_str[i - bf_cnt] = '0';
              } else {
                cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) + 1);
                agn = 0;
              };
            } else {
              cur_str.insert(0, "1");
              i += 1;
              delta += 1;
              n += 1;
              agn = 0;
            };
          };
        } else {
          cur_str[i] = char(cur_val + 48);
        };
      };
      cnt += 1;
    };
  } else {
    return "";
  };
  return cur_str;
};

//@T multint2
//@U std::string multint2(std::string &x, std::string &x2)
//@X
//@D Returns the multiplication of two integers as std string.
//@A x : is an integer higher tha 0 as a std string
//@A x2 : is an integer higher than 0 as a std string
//@X
//@E
//@X

std::string multint2(std::string &x, std::string &x2) {
  std::string cur_str = x;
  std::string cur_str2 = x;
  std::string bf_str = x2;
  int cnt = 0;
  std::string eval_str = "1";
  unsigned int n = x.length();
  unsigned int n2 = x2.length();
  int cur_val;
  unsigned int delta = 0;
  int cur_eval;
  int bf_cnt;
  bool agn;
  int i;
  if (bf_str[0] == '-') {
    return "";
  };
  if (cur_str[0] != '-') {
    while (eval_str != bf_str) {
      for (i = delta; i < n; ++i) {
        cur_val = (int(cur_str[i]) - 48) + (int(cur_str2[i - delta]) - 48);
        if (cur_val > 9) {
          cur_val -= 10;
          cur_str[i] = char(cur_val + 48);
          bf_cnt = 0;
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (i - bf_cnt > -1) {
              if (cur_str[i - bf_cnt] == '9') {
                cur_str[i - bf_cnt] = '0';
              } else {
                cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) + 1);
                agn = 0;
              };
            } else {
              cur_str.insert(0, "1");
              i += 1;
              delta += 1;
              n += 1;
              agn = 0;
            };
          };
        } else {
          cur_str[i] = char(cur_val + 48);
        };
      };
      cur_eval = int(eval_str[cnt]) - 48;
      if (cur_eval > 8) {
        eval_str[cnt] = '0';
        agn = 1;
        bf_cnt = 0;
        while (agn) {
          bf_cnt += 1;
          if (cnt - bf_cnt > -1) {
            if (eval_str[cnt - bf_cnt] == '9') {
              eval_str[cnt - bf_cnt] = '0';
            } else {
              eval_str[cnt - bf_cnt] = char(int(eval_str[cnt - bf_cnt]) + 1);
              agn = 0;
            };
          } else {
            eval_str.insert(0, "1");
            cnt += 1;
            agn = 0;
          };
        };
      }else {
        eval_str[cnt] = char(cur_eval + 49);
      };
    };
  } else {
    return "";
  };
  return cur_str;
};

//@L2 Floating points

//@T multflt
//@U std::string multflt(std::string &x, std::string &x2)
//@X
//@D Returns the result of a multpilication as a std string from floating points or integers as std string.
//@A x : is a floating points or integer as a std string
//@A x2 : is a floating points or integer as a std string
//@X
//@E
//@X

std::string multflt(std::string &x, std::string &x2) {
  std::string cur_str = "";
  int cnt = 0;
  if (x[0] == '-' || x2[0] == '-') {
    return "";
  };
  unsigned int n = x.length();
  for (cnt = 0; cnt < n; ++cnt) {
    if (x[cnt] != '.') {
      cur_str += "0";
    } else {
      cur_str += ".";
    };
  };
  std::string cur_str2 = x;
  std::string cur_str2b;
  std::string bf_str = x2;
  std::string cur_part;
  std::string inter_str2;
  const unsigned int n2 = x2.length();
  bool is_dec = 0;
  int pos_dec;
  int pos_dec2;
  for (cnt = 0; cnt < n; ++cnt) {
    if (cur_str[cnt] == '.') {
      is_dec = 1;
      break;
    };
  };
  pos_dec = cnt;
  cnt = 0;
  std::string eval_str = "0";
  unsigned int decnb2 = 0;
  bool agn = 1;
  while (agn) {
    cur_part += bf_str[cnt];
    cnt += 1;
    if (cnt < n2) {
      if (bf_str[cnt] == '.') {
        agn = 0;
        decnb2 = (n2 - cnt - 1);
      };
    } else {
      agn = 0;
    };
  };
  int agn_cnt = cnt;
  if (decnb2 > 0) {
    if (!is_dec) {
      cur_str += ".";
      cur_str2 += ".";
      n += 1;
    };
    for (cnt = 0; cnt < decnb2; ++cnt) {
      cur_str += "0";
      cur_str2 += "0";
      n += 1;
    };
  };
  cnt = 0;
  int cur_val;
  unsigned int delta = 0;
  unsigned int delta2 = 0;
  int cur_eval;
  int bf_cnt;
  bool agn2 = 1;
  bool underzero = 0;
  int i;
  while (agn2) {
    if (eval_str == cur_part) {
      cnt = 0;
      if (agn_cnt + 1 > n2) {
        return cur_str; 
      } else {
        agn = 1;
        pos_dec2 = 0;
        while (agn) {
          agn_cnt += 1;
          delta2 += 1;
          pos_dec2 += 1;
          if (agn_cnt < n2) {
            if (bf_str[agn_cnt] != '0') {
              agn = 0;
            };
          } else {
            return cur_str;
          };
        };
        if (pos_dec - pos_dec2 > 0) {
          cur_str2b = cur_str2.substr(pos_dec + 1, n);
          inter_str2 = "";
          for (i = pos_dec2; i > 0; --i){
            inter_str2 += cur_str2[pos_dec - i];
          };
          pos_dec -= pos_dec2;
          cur_str2 = cur_str2.substr(0, pos_dec);
          cur_str2 += "." + inter_str2 + cur_str2b;
        } else if (!underzero) {
          cur_str2b = cur_str2;
          cur_str2 = "0";
          underzero = 1;
          pos_dec -= pos_dec2;
          i = 0;
          while (cur_str2b[i] != '.') {
            cur_str2 += cur_str2b[i];
            i += 1;
          };
          i += 1;
          while (i < n) {
            cur_str2 += cur_str2b[i];
            i += 1;
          };
        };
        cur_part = bf_str[agn_cnt];
        eval_str = "0";
      };
    };
    for (i = delta + delta2; i < n; ++i) {
      if (cur_str[i] != '.') {
        cur_val = (int(cur_str[i]) - 48) + (int(cur_str2[i - delta - delta2]) - 48);
        if (cur_val > 9) {
          cur_val -= 10;
          cur_str[i] = char(cur_val + 48);
          if (i > 0) {
            if (cur_str[i - 1] != '.') {
              bf_cnt = 0;
            } else {
              bf_cnt = 1;
            };
          } else {
            bf_cnt = 0;
          };
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (i - bf_cnt > -1) {
              if (cur_str[i - bf_cnt] != '.') {
                if (cur_str[i - bf_cnt] == '9') {
                  cur_str[i - bf_cnt] = '0';
                } else {
                  cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) + 1);
                  agn = 0;
                };
              };
            } else {
              cur_str.insert(0, "1");
              cur_str2 += "0";
              i += 1;
              delta += 1;
              n += 1;
              agn = 0;
            };
          };
        } else {
          cur_str[i] = char(cur_val + 48);
        };
      };
    };
    cur_eval = int(eval_str[cnt]) - 48;
    if (cur_eval > 8) {
      eval_str[cnt] = '0';
      agn = 1;
      bf_cnt = 0;
      while (agn) {
        bf_cnt += 1;
        if (cnt - bf_cnt > -1) {
          if (eval_str[cnt - bf_cnt] == '9') {
            eval_str[cnt - bf_cnt] = '0';
          } else {
            eval_str[cnt - bf_cnt] = char(int(eval_str[cnt - bf_cnt]) + 1);
            agn = 0;
          };
        } else {
          eval_str.insert(0, "1");
          cnt += 1;
          agn = 0;
        };
      };
    }else {
      eval_str[cnt] = char(cur_eval + 49);
    };
  };
  return cur_str;
};

//@L Division

//@T divide
//@U std::string divide(std::string &x, std::string &x2, unsigned int nb_decimal = 8)
//@X
//@D Returns the result of a division between ints or floats represented as std string.
//@A x : is a int or float that will be divided represented as a std string, must be superior or equal to 1, refer to <code href="centerizer">centerizer()</code> to center your division to make the divided equal to 1 or higher
//@A x2 : is a int or float that will divide represented as a std string
//@X
//@E
//@X

std::string divide(std::string &x, std::string &x2, unsigned int nb_decimal = 5) {
  if (x[0] == '-' || x2[0] == '-') {
    return "";
  };
  std::string divided = x;
  std::string divider = x2;
  std::string divider_base = divider;
  std::string lst_divider = x2;
  std::string eval_str = "";
  std::string eval_str2 = "0";
  std::string lst_eval_str2 = "0";
  unsigned int n = x2.length();
  unsigned int n_divided = x.length();
  unsigned int idx_dec;
  unsigned int idx_dec2;
  unsigned int delta = 0;
  unsigned int cnt = 0;
  unsigned int i2;
  int i;
  unsigned int dec1;
  unsigned int dec2;
  unsigned int integ1;
  unsigned int integ2;
  bool is_dec1 = 0;
  bool is_dec2 = 0;
  bool agn = 1;
  if (n > 2) {
    while (agn) {
      cnt += 1;
      if (cnt + 1 == n) {
        agn = 0;
      } else if (divider[cnt] == '.') {
        idx_dec = cnt;
        is_dec1 = 1;
        agn = 0;
      };
    };
    dec1 = n - cnt - 1;
    integ1 = n - dec1 - 2;
  } else {
    dec1 = 0;
    integ1 = n - 1;
  };
  if (n_divided > 2) {
    cnt = 0;
    agn = 1;
    while (agn) {
      cnt += 1;
      if (cnt + 1 == n_divided) {
        agn = 0;
      } else if (divided[cnt] == '.') {
        is_dec2 = 1;
        idx_dec2 = cnt;
        agn = 0;
      };
    };
    dec2 = n_divided - cnt - 1;
    integ2 = n_divided - dec2 - 2;
  } else {
    dec2 = 0;
    integ2 = n_divided - 1;
  };
  int delta_integ = integ1 - integ2 + 1;
  if (delta_integ > 0) {
    if (!is_dec2) {
      for (i = 0; i < delta_integ; ++i) {
        divided += "0";
        n_divided += 1;
      };
    } else {
      for (i = 0; i < delta_integ; ++i) {
        divided[idx_dec2] = divided[idx_dec2 + 1];
        divided[idx_dec2 + 1] = '.';
        idx_dec2 += 1;
        divided += "0";
        n_divided += 1;
      };
    };
  };
  if (dec1 > dec2) {
    if (!is_dec2) {
      divided += ".";
      n_divided += 1;
    };
    for (i = 0; i < dec1 - dec2; ++i) {
      divided += "0";
      n_divided += 1;
    };
  } else if (dec1 < dec2) {
    if (!is_dec1) {
      divider += ".";
      divider_base += ".";
      lst_divider += ".";
      idx_dec = n;
      n += 1;
    };
    for (i = 0; i < dec2 - dec1; ++i) {
      divider += "0";
      divider_base += "0";
      lst_divider += "0";
      n += 1;
    };
  } else if (!is_dec1 || !is_dec2) {
    std::cout << "HEREE\n";
    divided += ".0";
    divider += ".0";
    divider_base += ".0";
    lst_divider += ".0";
    idx_dec = n;
    n += 2;
    n_divided += 2;
  };
  cnt = 0;
  int n2 = 0;
  int cur_val;
  int bf_cnt;
  bool agn2 = 1;
  unsigned int post_dec;
  unsigned int lst_n = n;
  while (agn2) { 
    if (n > n_divided) {
      divider = lst_divider;
      cnt -= 1;
      n -= 1;
      break;
    } else if (n == n_divided) {
      i = 0;
      while (i < n) {
        if (divided[i] != divider[i]) {
          if (int(divided[i] - 48) < int(divider[i] - 48)) {
            agn2 = 0;
            break;
          } else {
            break;
          };
        };
        i += 1;
      };
      if (!agn2) {
        divider = lst_divider;
        if (cnt != lst_n) {
          cnt -= 1;
        };
        n = lst_n;
        break;
      } else if (i == n) {
        break;
      };
    };
    lst_divider = divider;
    lst_n = n;
    for (i = cnt; i < n; ++i) {
      if (divider[i] != '.') {
        cur_val = (int(divider[i]) - 48) + (int(divider_base[i - cnt]) - 48);
        if (cur_val > 9) {
          cur_val -= 10;
          divider[i] = char(cur_val + 48);
          if (i - 1 > 0) {
            if (divider[i - 1] != '.') {
              bf_cnt = 0;
            } else {
              bf_cnt = 1;
            };
          } else {
            bf_cnt = 0;
          };
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (i - bf_cnt > -1) {
              if (divider[i - bf_cnt] != '.') {
                if (divider[i - bf_cnt] == '9') {
                  divider[i - bf_cnt] = '0';
                } else {
                  divider[i - bf_cnt] = char(int(divider[i - bf_cnt]) + 1);
                  agn = 0;
                };
              };
            } else {
              divider.insert(0, "1");
              cnt += 1;
              i += 1;
              n += 1;
              agn = 0;
            };
          };
        } else {
          divider[i] = char(cur_val + 48);
        };
      };
    };
    cur_val = int(eval_str2[n2] - 48) + 1;
    if (cur_val > 9) {
      eval_str2[n2] = '0';
      bf_cnt = 0;
      agn = 1;
      while (agn) {
        bf_cnt += 1;
        if (n2 - bf_cnt > -1) {
          if (eval_str2[n2 - bf_cnt] == '9') {
            eval_str2[n2 - bf_cnt] = '0';
          } else {
            eval_str2[n2 - bf_cnt] = char(int(eval_str2[n2 - bf_cnt]) + 1);
            agn = 0;
          };
        } else {
          eval_str2.insert(0, "1");
          n2 += 1;
          agn = 0;
        };
      }
    } else {
      eval_str2[n2] = char(cur_val + 48);
    };
  };
  eval_str += eval_str2;
  post_dec = eval_str.length();
  if (nb_decimal > 1) {
    divided += "0";
    divider += "0";
    n_divided += 1;
    n += 1;
    cnt += 1;
    divider_base[idx_dec] = divider_base[idx_dec - 1]; 
    idx_dec -= 1;
    divider_base[idx_dec] = '.'; 
    if (idx_dec == 0) {
      cnt += 1;
      delta = 1;
    };
    eval_str += ".";
    for (unsigned int i2 = 1; i2 < nb_decimal; ++i2) {
      eval_str2 = "0";
      agn2 = 1;
      n2 = 0;
      while (agn2) { 
        if (n > n_divided) {
          divider = lst_divider;
          eval_str2 = lst_eval_str2;
          cnt -= 1;
          n -= 1;
          break;
        } else if (n == n_divided) {
          i = 0;
          while (i < n) {
            if (divided[i] != divider[i]) {
              if (int(divided[i] - 48) < int(divider[i] - 48)) {
                agn2 = 0;
                break;
              } else {
                break;
              };
            };
            i += 1;
          };
          if (!agn2) {
            divider = lst_divider;
            eval_str2 = lst_eval_str2;
            if (n != lst_n) {
              cnt -= 1;
            };
            n = lst_n;
            break;
          } else if (i == n) {
            break;
          };
        };
        lst_divider = divider;
        lst_n = n;
        for (i = cnt; i < n; ++i) {
          if (divider[i] != '.') {
            cur_val = (int(divider[i]) - 48) + (int(divider_base[i - cnt + delta]) - 48);
            if (cur_val > 9) {
              cur_val -= 10;
              divider[i] = char(cur_val + 48);
              if (i - 1 > 0) {
                if (divider[i - 1] != '.') {
                  bf_cnt = 0;
                } else {
                  bf_cnt = 1;
                };
              } else {
                bf_cnt = 0;
              };
              agn = 1;
              while (agn) {
                bf_cnt += 1;
                if (i - bf_cnt > -1) {
                  if (divider[i - bf_cnt] != '.') {
                    if (divider[i - bf_cnt] == '9') {
                      divider[i - bf_cnt] = '0';
                    } else {
                      divider[i - bf_cnt] = char(int(divider[i - bf_cnt]) + 1);
                      agn = 0;
                    };
                  };
                } else {
                  divider.insert(0, "1");
                  cnt += 1;
                  i += 1;
                  n += 1;
                  agn = 0;
                };
              };
            } else {
              divider[i] = char(cur_val + 48);
            };
          };
        };
        cur_val = int(eval_str2[n2] - 48) + 1;
        lst_eval_str2 = eval_str2;
        if (cur_val < 10) {
          eval_str2[n2] = char(cur_val + 48);
        };
      };
      eval_str += eval_str2; 
      divided += "0";
      divider += "0";
      n += 1;
      n_divided += 1;
      cnt += 1;
      if (idx_dec > 0) {
        divider_base[idx_dec] = divider_base[idx_dec - 1]; 
        idx_dec -= 1;
        divider_base[idx_dec] = '.'; 
        if (idx_dec == 0) {
          cnt += 1;
          delta = 1;
        };
      };
    };
  };
  if (delta_integ > 0) {
    for (i = 1; i < delta_integ; ++i) {
      eval_str.insert(0, "0");
      post_dec += 1;
    };
    for (i = 0; i < delta_integ; ++i) {
      eval_str[post_dec] = eval_str[post_dec - 1];
      post_dec -= 1;
      eval_str[post_dec] = '.';
    };
  };
  return eval_str;
};

//@T dividebase10
//@U std::string dividebase10(std::string &x, unsigned int accuracy = 9)
//@X
//@D Returns the result of a division base 10.
//@A x : is the int or float that will be divided, as a std string
//@X
//@E
//@X

std::string dividebase10(std::string &x, unsigned int accuracy = 9) {
  if (accuracy == 0) {
    return "";
  };
  unsigned int i = 0;
  unsigned int n = x.length();
  unsigned int lst_n;
  unsigned int idx_dec;
  bool agn = 1;
  std::string to_add = x;
  if (n > 2) {
    while (agn) {
      i += 1;
      if (i + 1 == n) {
        agn = 0;
      } else if (to_add[i] == '.'){
        idx_dec = i;
        agn = 0;
      };
    };
    if (i + 1 < n) {
      if (accuracy + 1 > idx_dec) {
        lst_n = idx_dec;
        for (i = 0; i < accuracy - lst_n + 1; ++i) {
          to_add.insert(0, "0");
          idx_dec += 1;
          n += 1;
        };
      };
      for (i = 0; i < accuracy; ++i) {
        to_add[idx_dec] = to_add[idx_dec - 1];
        idx_dec -= 1;
        to_add[idx_dec] = '.';
      };
    }else {
      if (accuracy + 1 > n) {
        lst_n = n;
        for (i = 0; i < accuracy - lst_n + 1; ++i) {
          to_add.insert(0, "0");
          n += 1;
        };
      };
      to_add += ".";
      idx_dec = n;
      n += 1;
      for (i = 0; i < accuracy; ++i) {
        to_add[idx_dec] = to_add[idx_dec - 1];
        idx_dec -= 1;
        to_add[idx_dec] = '.';
      };
    };
  } else {
    if (accuracy + 1 > n) {
      lst_n = n;
      for (i = 0; i < accuracy - lst_n + 1; ++i) {
        to_add.insert(0, "0");
        n += 1;
      };
    };
    to_add += ".";
    idx_dec = n;
    n += 1;
    for (i = 0; i < accuracy; ++i) {
      to_add[idx_dec] = to_add[idx_dec - 1];
      idx_dec -= 1;
      to_add[idx_dec] = '.';
    };
  };
  return to_add;
};

//@L2 Remainder
//@L3 Integers

//@T remainderint
//@U std::string remainderint(std::string &x, std::string &x2)
//@X
//@D Returns the remainder of a division between two int represented as a std string
//@A x : is the int that will be divided, represented as a string, must be greater or equal to x2
//@A x2 : is the divider which is a int represented as a string, must be lower or equal to x
//@E
//@X

std::string remainderint(std::string &x, std::string &x2) {
  if (x[0] == '-' || x2[0] == '-') {
    return "";
  };
  std::string divided = x;
  std::string divider = x2;
  std::string divider_base = x2;
  std::string lst_divider = divider;
  unsigned int cnt = 0;
  unsigned int n = divider.length();
  unsigned int n_divided = x.length();
  bool agn;
  bool agn2 = 1;
  int bf_cnt = 0;
  int i;
  int cur_val;
  while (agn2) {
    if (n > n_divided) {
      break;
    } else if (n == n_divided) {
      i = 0;
      while (i < n) {
        if (int(divider[i] + 48) > int(divided[i] + 48)) {
          agn2 = 0;
          break;
        } else if (int(divider[i] + 48) < int(divided[i] + 48)) {
          break;
        };
        i += 1;
      };
      if (i == n) {
        break;
      };
      if (agn2 == 0) {
        break;
      };
    };
    lst_divider = divider;
    for (i = cnt; i < n; ++i) {
      cur_val = (int(divider_base[i - cnt]) - 48) + (int(divider[i]) - 48);
      if (cur_val > 9) {
        cur_val -= 10;
        divider[i] = char(cur_val + 48);
        bf_cnt = 0;
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (i - bf_cnt > -1) {
            if (divider[i - bf_cnt] == '9') {
              divider[i - bf_cnt] = '0';
            } else {
              divider[i - bf_cnt] = char(int(divider[i - bf_cnt]) + 1);
              agn = 0;
            };
          } else {
            divider.insert(0, "1");
            i += 1;
            n += 1;
            cnt += 1;
            agn = 0;
          };
        };
      } else {
        divider[i] = char(cur_val + 48);
      };
    };
  };
  cnt = divided.length() - lst_divider.length();
  for (i = cnt; i < n_divided; ++i) {
    cur_val = int(divided[i] - 48) - int(lst_divider[i - cnt] - 48);
    if (cur_val < 0) {
      cur_val += 10; 
      divided[i] = char(cur_val + 48);
      bf_cnt = 0;
      agn = 1;
      while (agn) {
        bf_cnt += 1;
        if (i - bf_cnt > 0) {
          if (divided[i - bf_cnt] == '0') {
            divided[i - bf_cnt] = '9';
          } else {
            divided[i - bf_cnt] = char(int(divided[i - bf_cnt]) - 1);
            agn = 0;
          };
        } else {
          agn = 0;
        };
      };
    } else {
      divided[i] = char(cur_val + 48); 
    };
    if (divided[0] == '0' & n_divided > 1) {
      lst_divider = lst_divider.substr(1, n);
      divided = divided.substr(1, n);
      n_divided -= 1;
      i -= 1;
    };
  };
  return divided;
};

//@L3 Floting Points

//@T remainderflt
//@U std::string remainderflt(std::string &x, std::string &x2)
//@X
//@D Returns the remainder of a division between two int or floating point represented as a std string
//@A x : is the int or floating point that will be divided, represented as a string, must be greater or equal to x2
//@A x2 : is the divider which is a int or floating point represented as a string, must be lower or equal to x
//@E
//@X

std::string remainderflt(std::string &x, std::string &x2) {
  if (x[0] == '-' || x2[0] == '-') {
    return "";
  };
  std::string divided = x;
  std::string divider = x2;
  std::string divider_base = x2;
  std::string lst_divider = divider;
  unsigned int n = divider.length();
  unsigned int n_divided = x.length();
  bool is_dec1 = 0;
  bool is_dec2 = 0;
  unsigned int dec1;
  unsigned int dec2;
  unsigned int cnt = 0;
  bool agn2 = 1;
  if (n > 2) {
    while (agn2) {
      cnt += 1;
      if (cnt + 1 == n) {
        agn2 = 0;
      } else if (divider[cnt] == '.') {
        is_dec1 = 1;
        agn2 = 0;
      };
    };
    dec1 = n - cnt - 1;
  } else {
    dec1 = 0;
  };
  if (n_divided > 2) {
    agn2 = 1;
    cnt = 0;
    while (agn2) {
      cnt += 1;
      if (cnt + 1 == n_divided) {
        agn2 = 0;
      } else if (divided[cnt] == '.') {
        is_dec2 = 1;
        agn2 = 0;
      };
    };
    dec2 = n_divided - cnt - 1;
  } else {
    dec2 = 0;
  };
  if (dec1 > dec2) {
    if (!is_dec2) {
      divided += ".";
      n_divided += 1;
    };
    for (cnt = 0; cnt < dec1 - dec2; ++cnt) {
      divided += "0";
      n_divided += 1;
    };
  } else if (dec1 < dec2) {
    if (!is_dec1) {
      divider += ".";
      divider_base += ".";
      n += 1;
    };
    for (cnt = 0; cnt < dec2 - dec1; ++cnt) {
      divider += "0";
      divider_base += "0";
      n += 1;
    };
  };
  agn2 = 1;
  int bf_cnt = 0;
  bool agn;
  int i;
  int cur_val;
  cnt = 0;
  while (agn2) {
    if (n > n_divided) {
      break;
    } else if (n == n_divided) {
      i = 0;
      while (i < n) {
        if (int(divider[i] + 48) > int(divided[i] + 48)) {
          agn2 = 0;
          break;
        } else if (int(divider[i] + 48) < int(divided[i] + 48)) {
          break;
        };
        i += 1;
      };
      if (i == n) {
        break;
      };
      if (agn2 == 0) {
        break;
      };
    };
    lst_divider = divider;
    for (i = cnt; i < n; ++i) {
      if (divider[i] != '.') {
        cur_val = (int(divider_base[i - cnt]) - 48) + (int(divider[i]) - 48);
        if (cur_val > 9) {
          cur_val -= 10;
          divider[i] = char(cur_val + 48);
          if (i - 1 > 0) {
            if (divider[i - 1] == '.') {
              bf_cnt = 1;
            } else {
              bf_cnt = 0;
            };
          } else {
            bf_cnt = 0;
          };
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (i - bf_cnt > -1) {
              if (divider[i - bf_cnt] != '.') {
                if (divider[i - bf_cnt] == '9') {
                  divider[i - bf_cnt] = '0';
                } else {
                  divider[i - bf_cnt] = char(int(divider[i - bf_cnt]) + 1);
                  agn = 0;
                };
              };
            } else {
              divider.insert(0, "1");
              i += 1;
              n += 1;
              cnt += 1;
              agn = 0;
            };
          };
        } else {
          divider[i] = char(cur_val + 48);
        };
      };
    };
  };
  cnt = divided.length() - lst_divider.length();
  for (i = cnt; i < n_divided; ++i) {
    if (divided[i] != '.') {
      cur_val = int(divided[i] - 48) - int(lst_divider[i - cnt] - 48);
      if (cur_val < 0) {
        cur_val += 10; 
        divided[i] = char(cur_val + 48);
        if (i > 0) {
          if (divided[i - 1] == '.') {
            bf_cnt = 1;
          } else {
            bf_cnt = 0;
          };
        } else {
          bf_cnt = 0;
        };
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (i - bf_cnt > -1) {
            if (divided[i - bf_cnt] != '.') {
              if (divided[i - bf_cnt] == '0') {
                divided[i - bf_cnt] = '9';
              } else {
                divided[i - bf_cnt] = char(int(divided[i - bf_cnt]) - 1);
                agn = 0;
              };
            };
          } else {
            agn = 0;
          };
        };
      } else {
        divided[i] = char(cur_val + 48); 
      };
      if (divided[0] == '0' & n_divided > 1) {
        lst_divider = lst_divider.substr(1, n);
        divided = divided.substr(1, n);
        n_divided -= 1;
        i -= 1;
      };
    };
  };
  return divided;
};

//@L2 Quotient
//@L3 Integers

//@T quotientint
//@U std::string quotientint(std::string &x, std::string &x2)
//@X
//@A x : is the int that will be divided, represented as a string.
//@A x2 : is the int that will divide x, represented as a string.
//@X
//@E
//@X

std::string quotientint(std::string &x, std::string &x2) {
  if (x[0] == '-' || x2[0] == '-') {
    return "";
  };
  std::string divided = x;
  std::string divider = x2;
  std::string divider_base = x2;
  std::string eval_str = "0";
  unsigned int cnt = 0;
  unsigned int n = divider.length();
  int n2 = 0;
  unsigned int n_divided = x.length();
  bool agn;
  bool agn2 = 1;
  int bf_cnt = 0;
  int i;
  unsigned int cur_val;
  while (agn2) {
    if (n > n_divided) {
      break;
    } else if (n == n_divided) {
      i = 0;
      for (i = 0; i < n; ++i) {
        if (int(divider[i] + 48) > int(divided[i] + 48)) {
          agn2 = 0;
          break;
        } else if (int(divider[i] + 48) < int(divided[i] + 48)) {
          break;
        };
      };
      if (agn2 == 0) {
        break;
      };
    };
    for (i = cnt; i < n; ++i) {
      cur_val = (int(divider_base[i - cnt]) - 48) + (int(divider[i]) - 48);
      if (cur_val > 9) {
        cur_val -= 10;
        divider[i] = char(cur_val + 48);
        bf_cnt = 0;
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (i - bf_cnt > -1) {
            if (divider[i - bf_cnt] != '.') {
              if (divider[i - bf_cnt] == '9') {
                divider[i - bf_cnt] = '0';
              } else {
                divider[i - bf_cnt] = char(int(divider[i - bf_cnt]) + 1);
                agn = 0;
              };
            };
          } else {
            divider.insert(0, "1");
            i += 1;
            n += 1;
            cnt += 1;
            agn = 0;
          };
        };
      } else {
        divider[i] = char(cur_val + 48);
      };
    };
    cur_val = int(eval_str[n2] - 48) + 1;
    if (cur_val > 9) {
      eval_str[n2] = '0';
      bf_cnt = 0;
      agn = 1;
      while (agn) {
        bf_cnt += 1;
        if (n2 - bf_cnt > -1) {
          if (eval_str[n2 - bf_cnt] == '9') {
            eval_str[n2 - bf_cnt] = '0';
          } else {
            eval_str[n2 - bf_cnt] = char(int(eval_str[n2 - bf_cnt]) + 1);
            agn = 0;
          };
        } else {
          eval_str.insert(0, "1");
          n2 += 1;
          agn = 0;
        };
      };
    } else {
      eval_str[n2] = char(cur_val + 48);
    };
  };
  return eval_str;
};

//@L3 Floating points

//@T quotientflt
//@U std::string quotientflt(std::string &x, std::string &x2)
//@X
//@A x : is the int or floating point that will be divided, represented as a string.
//@A x2 : is the int or floating point that will divide x, represented as a string.
//@X
//@E
//@X

std::string quotientflt(std::string &x, std::string &x2) {
  if (x[0] == '-' || x2[0] == '-') {
    return "";
  };
  std::string divided = x;
  std::string divider = x2;
  std::string divider_base = x2;
  std::string eval_str = "0";
  unsigned int cnt = 0;
  unsigned int n = divider.length();
  int n2 = 0;
  unsigned int n_divided = x.length();
  unsigned int dec1;
  unsigned int dec2;
  bool agn;
  bool agn2 = 1;
  bool is_dec1 = 0;
  bool is_dec2 = 0;
  if (n > 2) {
    while (agn2) {
      cnt += 1;
      if (cnt + 1 == n) {
        agn2 = 0;
      } else if (divider[cnt] == '.') {
        is_dec1 = 1;
        agn2 = 0;
      };
    };
    dec1 = n - cnt - 1;
  } else {
    dec1 = 0;
  };
  if (n_divided > 2) {
    agn2 = 1;
    cnt = 0;
    while (agn2) {
      cnt += 1;
      if (cnt + 1 == n_divided) {
        agn2 = 0;
      } else if (divided[cnt] == '.') {
        is_dec2 = 1;
        agn2 = 0;
      };
    };
    dec2 = n_divided - cnt - 1;
  } else {
    dec2 = 0;
  };
  if (dec2 > dec1) {
    if (!is_dec1) {
      divider += ".";
      divider_base += ".";
      n += 1;
    };
    for (cnt = 0; cnt < dec2 - dec1; ++cnt) {
      n += 1;
      divider += "0";
      divider_base += "0";
    };
  } else if (dec2 < dec1) {
    if (!is_dec2) {
      divided += ".";
      n_divided += 1;
    };
    for (cnt = 0; cnt < dec1 - dec2; ++cnt) {
      divided += "0";
      n_divided += 1;
    };
  };
  agn2 = 1;
  cnt = 0;
  int bf_cnt = 0;
  int i;
  unsigned int cur_val;
  while (agn2) {
    if (n > n_divided) {
      break;
    } else if (n == n_divided) {
      i = 0;
      for (i = 0; i < n; ++i) {
        if (int(divider[i] + 48) > int(divided[i] + 48)) {
          agn2 = 0;
          break;
        } else if (int(divider[i] + 48) < int(divided[i] + 48)) {
          break;
        };
      };
      if (agn2 == 0) {
        break;
      };
    };
    for (i = cnt; i < n; ++i) {
      if (divider[i] != '.') {
        cur_val = (int(divider_base[i - cnt]) - 48) + (int(divider[i]) - 48);
        if (cur_val > 9) {
          cur_val -= 10;
          divider[i] = char(cur_val + 48);
          if (i - 1 > 0) {
            if (divider[i - 1] != '.') {
              bf_cnt = 0;
            } else {
              bf_cnt = 1;
            };
          } else {
            bf_cnt = 0;
          };
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (i - bf_cnt > -1) {
              if (divider[i - bf_cnt] != '.') {
                if (divider[i - bf_cnt] == '9') {
                  divider[i - bf_cnt] = '0';
                } else {
                  divider[i - bf_cnt] = char(int(divider[i - bf_cnt]) + 1);
                  agn = 0;
                };
              };
            } else {
              divider.insert(0, "1");
              i += 1;
              n += 1;
              cnt += 1;
              agn = 0;
            };
          };
        } else {
          divider[i] = char(cur_val + 48);
        };
      };
    };
    cur_val = int(eval_str[n2] - 48) + 1;
    if (cur_val > 9) {
      eval_str[n2] = '0';
      bf_cnt = 0;
      agn = 1;
      while (agn) {
        bf_cnt += 1;
        if (n2 - bf_cnt > -1) {
          if (eval_str[n2 - bf_cnt] == '9') {
            eval_str[n2 - bf_cnt] = '0';
          } else {
            eval_str[n2 - bf_cnt] = char(int(eval_str[n2 - bf_cnt]) + 1);
            agn = 0;
          };
        } else {
          eval_str.insert(0, "1");
          n2 += 1;
          agn = 0;
        };
      };
    } else {
      eval_str[n2] = char(cur_val + 48);
    };
  };
  return eval_str;
};

//@L2 Center the divided at 1 or higher

//@T centerizer
//@U std::vector<std::string> centerizer(std::string x, std::string x2)
//@D Returns the numerator and denominator transformed for the numerator to be higher or equal to 1 
//@X
//@A x : is the divided as a std string
//@A x2 : is the divider as a std string
//@X
//@E
//@X

std::vector<std::string> centerizer(std::string x, std::string x2) {
  std::vector<std::string> rtn_v = {x, x2};
  if (x[0] != '0') {
    return rtn_v;
  };
  if (x.length() < 2) {
    return rtn_v;
  };
  unsigned int dec = 1;
  unsigned int n2 = x2.length();
  bool is_dec;
  while (x2[dec] != '.' & dec < n2) {
    dec += 1;
  };
  unsigned int i = 2;
  const unsigned int n = x.length();
  if (dec < n2) {
    is_dec = 1;
    while (x[i - 2] == '0' & i < n) {
      x[i - 1] = x[i];
      x[i] = '.';
      if (i < n2) {
        x2[i - 1] = x2[i];
        x2[i] = '.';
      } else {
        if (is_dec) {
          x2[i - 1] = x2[i];
          x2[i] = '.';
          is_dec = 0;
          x2.pop_back();
          n2 -= 1;
        };
        x2 += "0";
        n2 += 1;
      };
      i += 1;
    };
    if (x2[n2 - 1] == '.') {
      x2.pop_back();
    };
  } else {
    while (x[i - 2] == '0' & i < n) {
      x[i - 1] = x[i];
      x[i] = '.';
      x2 += "0";
      i += 1;
    };
  };
  x = x.substr(i - 2, n - 1);
  if (x[n - i + 1] == '.') {
    x.pop_back();
  };
  rtn_v[0] = x;
  rtn_v[1] = x2;
  return rtn_v;
};

//@L Power
//@L2 Integers

//@T powerint
//@U std::string powerint(std::string &x, std::string &x2)
//@X
//@D Returns the result of int power to int as a std string
//@A x : is the int that will be elevated to an exponent, represented as a std string
//@A x2 : is the integer exponent, represented as a std string
//@X
//@E
//@X

std::string powerint(std::string &x, std::string &x2) {
  if (x[0] == '-' || x2[0] == '-') {
    return "";
  };
  if (x2 == "0") {
    return "1";
  };
  std::string cur_str = x;
  std::string eval_str = "1";
  std::string lst_str;
  std::string eval_str2;
  unsigned int n = x.length();
  unsigned int n2 = 0;
  unsigned int n3 = 0;
  unsigned int cnt = 0;
  int cur_val;
  int bf_cnt;
  bool agn;
  while (eval_str != x2) {
    eval_str2 = "1";
    lst_str = cur_str;
    cnt = 0;
    n3 = 0;
    while (eval_str2 != x) {
      for (int i = cnt; i < n; ++i) {
        cur_val = (int(cur_str[i]) - 48) + (int(lst_str[i - cnt]) - 48);
        if (cur_val > 9) {
          cur_val -= 10;
          cur_str[i] = char(cur_val + 48);
          bf_cnt = 0;
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (i - bf_cnt > -1) {
              if (cur_str[i - bf_cnt] == '9') {
                cur_str[i - bf_cnt] = '0';
              } else {
                cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) + 1);
                agn = 0;
              };
            } else {
              cur_str.insert(0, "1");
              i += 1;
              n += 1;
              cnt += 1;
              agn = 0;
            };
          };
        } else {
          cur_str[i] = char(cur_val + 48);
        };
      };
      cur_val = int(eval_str2[n3] - 48) + 1;
      if (cur_val > 9) {
        eval_str2[n3] = '0';
        bf_cnt = 0;
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (n3 - bf_cnt > -1) {
            if (eval_str2[n3 - bf_cnt] == '9') {
              eval_str2[n3 - bf_cnt] = '0';
            } else {
              eval_str2[n3 - bf_cnt] = char(eval_str2[n3 - bf_cnt] + 1);
              agn = 0;
            };
          } else {
            eval_str2.insert(0, "1");
            n3 += 1;
            agn = 0;
          };
        };
      } else {
        eval_str2[n3] = char(eval_str2[n3] + 1);
      };
    };
    cur_val = int(eval_str[n2] - 48) + 1;
    if (cur_val > 9) {
      eval_str[n2] = '0';
      bf_cnt = 0;
      agn = 1;
      while (agn) {
        bf_cnt += 1;
        if (n2 - bf_cnt > -1) {
          if (eval_str[n2 - bf_cnt] == '9') {
            eval_str[n2 - bf_cnt] = '0';
          } else {
            eval_str[n2 - bf_cnt] = char(eval_str[n2 - bf_cnt] + 1);
            agn = 0;
          };
        } else {
          eval_str.insert(0, "1");
          n2 += 1;
          agn = 0;
        };
      };
    } else {
      eval_str[n2] = char(eval_str[n2] + 1);
    };
  };
  return cur_str;
};

//@T powerint2
//@U std::string powerint2(std::string &x, unsigned int &x2)
//@X
//@D Returns the result of int power to int as a std string. It is preferable to use this function if the exponent can be described as an unsigned int.
//@A x : is the int that will be elevated to an exponent, represented as a std string
//@A x2 : is the integer exponent, represented as an unsigned int
//@X
//@E
//@X

std::string powerint2(std::string &x, unsigned int &x2) {
  if (x[0] == '-') {
    return "";
  };
  if (x2 == 0) {
    return "1";
  };
  std::string cur_str = x;
  unsigned int eval_int = 1;
  std::string lst_str;
  std::string eval_str2;
  unsigned int n = x.length();
  unsigned int n2 = 0;
  unsigned int n3 = 0;
  unsigned int cnt = 0;
  int cur_val;
  int bf_cnt;
  bool agn;
  while (eval_int != x2) {
    eval_str2 = "1";
    lst_str = cur_str;
    cnt = 0;
    n3 = 0;
    while (eval_str2 != x) {
      for (int i = cnt; i < n; ++i) {
        cur_val = (int(cur_str[i]) - 48) + (int(lst_str[i - cnt]) - 48);
        if (cur_val > 9) {
          cur_val -= 10;
          cur_str[i] = char(cur_val + 48);
          bf_cnt = 0;
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (i - bf_cnt > -1) {
              if (cur_str[i - bf_cnt] == '9') {
                cur_str[i - bf_cnt] = '0';
              } else {
                cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) + 1);
                agn = 0;
              };
            } else {
              cur_str.insert(0, "1");
              i += 1;
              n += 1;
              cnt += 1;
              agn = 0;
            };
          };
        } else {
          cur_str[i] = char(cur_val + 48);
        };
      };
      cur_val = int(eval_str2[n3] - 48) + 1;
      if (cur_val > 9) {
        eval_str2[n3] = '0';
        bf_cnt = 0;
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (n3 - bf_cnt > -1) {
            if (eval_str2[n3 - bf_cnt] == '9') {
              eval_str2[n3 - bf_cnt] = '0';
            } else {
              eval_str2[n3 - bf_cnt] = char(eval_str2[n3 - bf_cnt] + 1);
              agn = 0;
            };
          } else {
            eval_str2.insert(0, "1");
            n3 += 1;
            agn = 0;
          };
        };
      } else {
        eval_str2[n3] = char(eval_str2[n3] + 1);
      };
    };
    eval_int += 1;
  };
  return cur_str;
};

//@L Factorial

//@T factorial
//@U std::string factorial(std::string &x)
//@X
//@D Returns the factorial (of a positive integer number), represented as a std string
//@A x : is an positive integer as a std string
//@X
//@E
//@X

std::string factorial(std::string &x) {
  if (x[0] == '-') {
    return "";
  };
  if (x == "1") {
    return "1";
  } else if (x == "2") {
    return "2";
  };
  std::string cur_str = x;
  std::string eval_str = x;
  std::string cur_str2;
  std::string eval_str2;
  unsigned int cnt = 0;
  unsigned int n = x.length();
  unsigned int n2 = n - 1;
  int id_n3 = 0;
  int cur_val;
  int bf_cnt;
  bool agn;
  int i;
  cur_val = int(eval_str[n2] - 48) - 1;
  if (cur_val < 0) {
    eval_str[n2] = '9';
    bf_cnt = 0;
    agn = 1;
    while (agn) {
      bf_cnt += 1;
      if (eval_str[n2 - bf_cnt] == '0') {
        eval_str[n2 - bf_cnt] = '9';
      } else {
        eval_str[n2 - bf_cnt] = char(int(eval_str[n2 - bf_cnt]) - 1);
        if (eval_str[0] == '0') {
          eval_str = eval_str.substr(1, eval_str.length());
          n2 -= 1;
        };
        agn = 0;
      };
    };
  } else {
    eval_str[n2] = char(int(eval_str[n2]) - 1);
  };
  while (eval_str != "1") {
    cur_str2 = cur_str;
    cur_val = int(eval_str[n2] - 48) - 1;
    if (cur_val < 0) {
      eval_str[n2] = '9';
      bf_cnt = 0;
      agn = 1;
      while (agn) {
        bf_cnt += 1;
        if (eval_str[n2 - bf_cnt] == '0') {
          eval_str[n2 - bf_cnt] = '9';
        } else {
          eval_str[n2 - bf_cnt] = char(int(eval_str[n2 - bf_cnt]) - 1);
          if (eval_str[0] == '0') {
            eval_str = eval_str.substr(1, eval_str.length());
            n2 -= 1;
          };
          agn = 0;
        };
      };
    } else {
      eval_str[n2] = char(int(eval_str[n2]) - 1);
    };
    eval_str2 = "0";
    id_n3 = 0;
    cnt = 0;
    while (eval_str2 != eval_str) { 
      for (i = cnt; i < n; ++i) {
        cur_val = (int(cur_str[i]) - 48) + (int(cur_str2[i - cnt]) - 48);
        if (cur_val > 9) {
          cur_val -= 10;
          cur_str[i] = char(cur_val + 48);
          bf_cnt = 0;
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (i - bf_cnt > -1) {
              if (cur_str[i - bf_cnt] == '9') {
                cur_str[i - bf_cnt] = '0';
              } else {
                cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) + 1);
                agn = 0;
              };
            } else {
              cur_str.insert(0, "1");
              i += 1;
              n += 1;
              cnt += 1;
              agn = 0;
            };
          };
        } else {
          cur_str[i] = char(cur_val + 48);
        };
      };
      cur_val = int(eval_str2[id_n3] - 48) + 1;
      if (cur_val > 9) {
        eval_str2[id_n3] = '0';
        bf_cnt = 0;
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (id_n3 - bf_cnt > -1) {
            if (eval_str2[id_n3 - bf_cnt] == '9') {
              eval_str2[id_n3 - bf_cnt] = '0';
            } else {
              eval_str2[id_n3 - bf_cnt] = char(int(eval_str2[id_n3 - bf_cnt]) + 1);
              agn = 0;
            };
          } else {
            eval_str2.insert(0, "1");
            id_n3 += 1;
            agn = 0;
          };
        };
      } else {
        eval_str2[id_n3] = char(cur_val + 48);
      };
    };
  };
  return cur_str;
};

//@L Comparisons

//@T is_greater
//@U bool is_greater(std::string &x, std::string &x2)
//@X
//@D Returns 1 if the first number (as a std string) is greater than the second (as a std string) .
//@A x : is a number as a string
//@A x2 : is a number as a string
//@X
//@E
//@X

bool is_greater(std::string &x, std::string &x2) {
  const unsigned int n = x.size();
  const unsigned int n2 = x.size();
  unsigned int val1;
  unsigned int val2;
  if (n == n2) {
    for (unsigned int i = 0; i < n; ++i) {
      val1 = int(x[i]);
      val2 = int(x2[i]);
      if (val1 != val2) {
        if (val1 > val2) {
          return 1;
        } else {
          return 0;
        };
      };
    };
  } else if (n > n2) {
    return 1;
  };
  return 0;
};

//@L Round

//@T roundstr
//@U std::string roundstr(std::string &x, int &digits)
//@X
//@D Round the input number entered as a std string. 
//@A x : is a std string representing a number
//@A digits : is the number of digits to round from, can be negative
//@X
//@E
//@X

std::string roundstr(std::string &x, int &digits) {
  unsigned int cnt = 0;
  std::string rtn_str;
  unsigned int i;
  while (x[cnt] != '.') {
    cnt += 1;
  };
  if (digits < 0) {
    unsigned int cnt2 = cnt;
    cnt += digits;
    if (cnt > 0) {
      if (58 - int(x[cnt]) < 6) {
        x[cnt - 1] = char(int(x[cnt - 1]) + 1);
      };
    };
    for (i = 0; i < cnt; ++i) {
        rtn_str += x[i];
    };
    for (i = cnt; i < cnt2; ++i) {
        rtn_str += '0';
    };
  } else if (digits > 0) {
    cnt += digits;
    if (cnt + 1 < x.length()) {
      if (58 - int(x[cnt + 1]) < 6) {
        x[cnt] = char(int(x[cnt]) + 1);
      };
    };
    for (i = 0; i < cnt + 1; ++i) {
        rtn_str += x[i];
    };
  } else {
    if (cnt + 1 < x.length()) {
      if (58 - int(x[cnt + 1]) < 6) {
        x[cnt - 1] = char(int(x[cnt - 1]) + 1);
      };
    };
    for (i = 0; i < cnt; ++i) {
        rtn_str += x[i];
    };
  };
  return rtn_str;
};

