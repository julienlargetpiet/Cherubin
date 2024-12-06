#include <iostream>
#include <string>
#include <algorithm>

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
            if (int(cur_str[i - bf_cnt]) - 48 > 8) {
              cur_str[i - bf_cnt] = '0';
            } else {
              cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) + 1);
              agn = 0;
            };
          } else {
            cur_str.insert(0, "1");
            bf_str.insert(0, "1");
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
                if (int(cur_str[i - bf_cnt]) - 48 > 8) {
                  cur_str[i - bf_cnt] = '0';
                } else {
                  cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) + 1);
                  agn = 0;
                };
              };
            } else {
              cur_str.insert(0, "1");
              bf_str.insert(0, "1");
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
          if (int(cur_str[i - bf_cnt]) - 48 < 1) {
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
              if (int(cur_str[i - bf_cnt]) - 48 < 1) {
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
              if (int(cur_str[i - bf_cnt]) - 48 > 8) {
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
              if (int(cur_str[i - bf_cnt]) - 48 > 8) {
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
            if (int(eval_str[cnt - bf_cnt]) - 48 > 8) {
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
                if (int(cur_str[i - bf_cnt]) - 48 > 8) {
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
          if (int(eval_str[cnt - bf_cnt]) - 48 > 8) {
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

