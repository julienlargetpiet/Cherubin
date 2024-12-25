#include <iostream>
#include <vector>

//@D This library if for very large and precise number (integers or floating points) manipulation those who can not be stored in an other datatype than <code>std::string</code> or <code>std::deque</code>. The only limit is the system memory.
//@D This branch is dedicated to <code>std::string</code> datatype for storing and manipulating numbers, contrary on the other branch (which is in development) that uses <code>std::deque<char></code> for the same purposes. This branch is more appropriate for medium sized number manipulation and the need for a lot of number declaration since a number declaration in the other branch will copy the elements of the declared string (also starting with string for convenience) to a deque at a cost of little computation each time. However, the other branch functions (in development) will be significantly faster especially for exponential functions.

//@M docimage.jpg

//@L1 Addition

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

//@L2 Integers

//@T addint
//@U std::string addint(std::string &x, std::string &x2)
//@X
//@D Returns the result as a std string.
//@A x : is the first positive int as a string
//@A x2 is the second positive int as a string
//@X
//@E std::string a = "4";
//@E std::string b = "112";
//@E addint(a, b);
//@E "116"
//@E
//@E x = "1458970";
//@E x2 = "563489287";
//@E addint(x, x2);
//@E "564948257"
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
//@A x : is one of the int or float that will be part of the addition operation 
//@A x2 : is one of the int or float that will be part of the addition operation
//@X
//@E
//@E std::string x = "14589.70";
//@E std::string x2 = "5634.89287";
//@E adflt(x, x2);
//@E "20224.59287"
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

//@T addflt2
//@U std::string addflt(std::string x, std::string x2)
//@X
//@D Same as <code>addflt</code> with another algorithm.
//@A x : is one of the int or float that will be part of the addition operation 
//@A x2 : is one of the int or float that will be part of the addition operation 
//@X
//@E
//@E std::string x = "14589.70";
//@E std::string x2 = "5634.89287";
//@E adflt2(x, x2);
//@E "20224.59287"
//@E
//@X

std::string addflt2(std::string x, std::string &x2) {
  int i = 0;
  unsigned int i2 = 0;
  unsigned int cnt = 0;
  unsigned int dec_val = 0;
  unsigned int dec_val2 = 0;
  unsigned int idx_dec = 0;
  unsigned int n = x.length();
  unsigned int cur_val;
  int bf_cnt;
  bool agn;
  const unsigned int n2 = x2.length();
  std::string intr_str;
  while (i < n) {
    if (x[i] == '.') {
      dec_val = n - 1 - i;
      intr_str = x.substr(0, i);
      x = x.substr(i + 1, n);
      x = intr_str + x;
      n-= 1;
      break;
    };
    i += 1;
  };
  while (i2 < n2) {
    if (x2[i2] == '.') {
      dec_val2 = n2 - 1 - i2;
      intr_str = x2.substr(0, i2);
      x2 = x2.substr(i2 + 1, n2);
      x2 = intr_str + x2;
      break;
    };
    i2 += 1;
  };
  if (i < i2) {
    for (i = i; i < i2; ++i) {
      x.insert(0, 1, '0');
      n += 1;
    };
  } else if (i > i2) {
    cnt = i - i2;
  };
  if (dec_val < dec_val2) {
    for (i = 0; i < dec_val2 - dec_val; ++i) {
      x.push_back('0');
      n += 1;
    };
    idx_dec = n - dec_val2;
  } else if (dec_val > 0) {
    idx_dec = n - dec_val;
    n -= (dec_val - dec_val2);
  };
  for (i = cnt; i < n; ++i) {
    cur_val = int(x[i] - 48) + int(x2[i - cnt] - 48);
    if (cur_val > 9) {
      cur_val -= 10;
      x[i] = char(cur_val + 48);
      bf_cnt = 0;
      agn = 1;
      while (agn) {
        bf_cnt += 1;
        if (i - bf_cnt > -1) {
          if (x[i - bf_cnt] == '9') {
            x[i - bf_cnt] = '0';
          } else {
            x[i - bf_cnt] = char(int(x[i - bf_cnt]) + 1);
            agn = 0;
          };
        } else {
          x.insert(0, 1, '1');
          i += 1;
          n += 1;
          cnt += 1;
          agn = 0;
          idx_dec += 1;
        };
      };
    } else {
      x[i] = char(cur_val + 48);
    };
  };
  if (idx_dec != 0) {
    x.insert(idx_dec, 1, '.');
  };
  return x;
};

//@L1 Substraction

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

//@L2 Integers

//@T subsint
//@U std::string subsint(std::string &x, std::string &x2)
//@X
//@D Returns the result as a std string.
//@A x : is the first positive int as a string, must be greater or equal to to x2
//@A x2 is the second positive int as a string, must be lower or equal to x
//@X
//@E
//@E std::string x = "1458970";
//@E std::string x2 = "563489287";
//@E subsint(x2, x);
//@E "562030317"
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
      if (cur_str[0] == '0' & sizen > 1) {
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
//@E std::string x = "14589.70";
//@E std::string x2 = "56348.9287";
//@E subsflt(x2, x) ;
//@E "41759.2287" 
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
        if (cur_str[0] == '0' & cur_str.length() > 1) {
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

//@L1 Multiplication

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

//@L2 Integers

//@T multint
//@U std::string multint(std::string &x, unsigned int &x2)
//@X
//@D Returns the multiplication of two integers as std string.
//@A x : is an integer higher than 0 as a std string
//@A x2 : is an unsigned integer higher than 0 
//@X
//@E
//@E std::string x = "1458970";
//@E unsigned int x2b = 45;
//@E multint(x, x2);
//@E "65653650"
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
//@E std::string x = "1458970";
//@E std::string x2 = "563489287";
//@E multint2(x, x2);
//@E "822113965054390"
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
//@E std::string x = "1458.970";
//@E std::string x2 = "563489.287";
//@E multflt(x, x2);
//@E "822113965.054390"
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

//@T multflt2
//@U std::string multflt2(std::string &x, std::string &x2)
//@X
//@D Same as <code>multflt</code>, but with another algorithm.
//@A x : is a floating points or integer as a std string
//@A x2 : is a floating points or integer as a std string
//@X
//@E
//@E std::string x = "1458.970";
//@E std::string x2 = "563489.287";
//@E multflt2(x, x2);
//@E "822113965.05439000000"
//@E
//@X

std::string multflt2(std::string &x, std::string &x2) {
  if (x2 == "0") {
    return "0";
  };
  int i;
  int i2;
  unsigned int i3;
  int n = x.length();
  int n2 = x2.length();
  bool agn;
  int add_zero = 0;
  int cur_val;
  int intr_val;
  int bf_cnt;
  int delta = 0;
  unsigned int delta2 = 0;
  std::string divider;
  std::string rtn_str = "";
  std::string rtn_str2 = "";
  std::string rtn_str3 = "";
  if (n > 2) {
    agn = 1;
    i = 0;
    while (agn) {
      rtn_str += x[i];
      i += 1;
      if (i + 1 == n) {
        agn = 0;
      } else if (x[i] == '.'){
        agn = 0;
      };
    };
    if (i + 1 < n) {
      add_zero = n - 1 - i;
      i += 1;
      while (i < n) {
        rtn_str += x[i];
        i += 1;
      };
      if (x[0] != '0') {
        n -= 1;
      } else {
        n -= 2;
        rtn_str = rtn_str.substr(1, i - 2);
      };
    } else {
      rtn_str = x;
    };
  } else {
    rtn_str = x;
  };
  if (n2 > 2) {
    agn = 1;
    i = 0;
    while (agn) {
      rtn_str3 += x2[i];
      i += 1;
      if (i + 1 == n2) {
        agn = 0;
      } else if (x2[i] == '.'){
        agn = 0;
      };
    };
    if (i + 1 < n2) {
      add_zero += n2 - 1 - i;
      i += 1;
      while (i < n2) {
        rtn_str3 += x2[i];
        i += 1;
      };
      if (x2[0] != '0') {
        n2 -= 1;
      } else {
        n2 -= 2;
        rtn_str3 = rtn_str3.substr(1, i - 2);
      };
    } else {
      rtn_str3 = x2;
    };
  } else {
    rtn_str3 = x2; 
  };
  for (i = 1; i < n + n2; ++i) {
    rtn_str2 += "0";
  };
  cur_val = int(rtn_str3[0] - 48) * int(rtn_str[0] - 48);
  if (cur_val > 9) {
    rtn_str2 += "0";
    n2 += 1;
    delta2 = 1;
  };
  for (i3 = 1; i3 < add_zero; ++i3) {
    rtn_str2 += "0";
    n2 += 1;
    delta += 1;
  };
  for (i2 = delta + delta2; i2 < n2; ++i2) {
    for (i = 0; i < n; ++i) {
      cur_val = int(rtn_str2[i2 + i - delta] - 48) + int(rtn_str3[i2 - delta - delta2] - 48) * int(rtn_str[i] - 48);
      if (cur_val < 10) {
        rtn_str2[i2 + i - delta] = char(cur_val + 48);
      } else {
        intr_val = 1;
        while (cur_val - (intr_val + 1) * 10 > -1) {
          intr_val += 1;
        };
        cur_val -= intr_val * 10;
        rtn_str2[i2 + i - delta] = char(cur_val + 48);
        cur_val = int(rtn_str2[i2 + i - delta - 1] - 48) + intr_val;
        if (cur_val < 10) {
          rtn_str2[i2 + i - delta - 1] = char(cur_val + 48);   
        } else {
          cur_val -= 10;
          rtn_str2[i2 + i - delta - 1] = char(cur_val + 48);
          agn = 1;
          bf_cnt = 0;
          while (agn) { 
            bf_cnt += 1;
            if (i2 + i - delta - bf_cnt - 1 > - 1) {
              if (rtn_str2[i2 + i - delta - bf_cnt - 1] == '9') {
                rtn_str2[i2 + i - delta - bf_cnt - 1] = '0'; 
              } else {
                rtn_str2[i2 + i - delta - bf_cnt - 1] = char(int(rtn_str2[i2 + i - delta - bf_cnt - 1]) + 1); 
                agn = 0;
              };
            } else {
              delta2 += 1;
              i2 += 1;
              n2 += 1;
              rtn_str2.insert(0, 1, '1');
              agn = 0;
            };
          };
        };
      };
    };
  };
  if (add_zero != 0) {
    delta = n2 + n - add_zero * 2;
    if (delta > 0){
      rtn_str2.insert(delta, ".");
    } else {
      rtn_str2.insert(0, "0.");
      for (i = delta; i < 0; ++i) {
        rtn_str2.insert(2, 1, '0');
      };
    };
  };
  return rtn_str2;
};

//@T multbase10
//@U std::string multbase10(std::string x, unsigned int base = 9)
//@X
//@A x : is the int of float that will be multiplied, as a std string
//@A base : is the number of 0 of the base 10 multiplicator
//@X
//@E
//@E std::string x = "1458.970";
//@E multbase10(x);
//@E "1458970000000.0"
//@E
//@X

std::string multbase10(std::string x, unsigned int base = 9) {
  int i = 0;
  unsigned int idx_dec;
  unsigned int lst_i;
  unsigned int lst_n;
  unsigned int n = x.length();
  bool agn = 1;
  if (n > 2) {
    while (agn) {
      i += 1;
      if (i + 1 == n) {
        agn = 0;
      } else if (x[i] == '.') {
        idx_dec = i;
        agn = 0;
      };
    };
    if (i + 1 < n) {
      if (base > n - 1 - i) {
        lst_i = i;
        lst_n = n;
        for (i = 0; i < base + 2 + lst_i - lst_n; ++i) {
          x += "0";
          n += 1;
        };
      };
      for (i = 0; i < base; ++i) {
        x[idx_dec] = x[idx_dec + 1];
        idx_dec += 1;
        x[idx_dec] = '.';
      };
      i = -1;
      agn = 1;
      while (agn) {
        i += 1;
        if (i + 1 == n) {
          agn = 0;
        } else if (x[i] != '0') {
          agn = 0;
        };
      };
      if (i > 0) {
        x = x.substr(i, n - 1);
      };
    } else {
      for (i = 0; i < base; ++i) {
        x += "0";
      };
    };
  } else {
   for (i = 0; i < base; ++i) {
      x += "0";
    };
  };
  return x;
};

//@L1 Division

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

//@T divide2
//@U std::string divide2(std::string &x, std::string &x2, unsigned int nb_decimal = 8)
//@X
//@D Returns the result of a division between ints or floats represented as std string.
//@A x : is a int or float that will be divided represented as a std string, must be superior or equal to 1, refer to <code href="centerizer">centerizer()</code> to center your division to make the divided equal to 1 or higher
//@A x2 : is a int or float that will divide represented as a std string
//@A nb_decimal : is an int representing the number of decimal to keep as a result
//@X
//@E
//@E std::string x = "1458.970";
//@E std::string x2 = "563489.287";
//@E divide2(x2, x);
//@E "386.22400"
//@E
//@X

std::string divide2(std::string &x, std::string &x2, int nb_decimal = 5) {
  if (x[0] == '-' || x2[0] == '-') {
    return "";
  };
  std::string divided = x;
  std::string divider = x2;
  std::string divider_base = divider;
  std::string lst_divider = divider;
  std::string eval_str = "";
  std::string eval_str2 = "0";
  std::string lst_eval_str2 = "0";
  std::string intr_str;
  unsigned int n = x2.length();
  unsigned int n_divided = x.length();
  unsigned int idx_dec = 0;
  unsigned int idx_dec2 = 0;
  unsigned int cnt = 0;
  unsigned int i2;
  int i = 0;
  unsigned int dec1 = 0;
  unsigned int dec2 = 0;
  unsigned int integ1;
  unsigned int integ2;
  bool agn;
  bool is_dec1 = 0;
  bool is_dec2 = 0;
  unsigned int bgn = 0;
  while (i < n) {
    if (divider[i] == '.') {
      is_dec2 = 1;
      break;
    };
    dec2 += 1;
    i += 1;
  };
  i = 0;
  while (i < n_divided) {
    if (divided[i] == '.') {
      is_dec1 = 1;
      break;
    };
    dec1 += 1;
    i += 1;
  };
  if (is_dec2) {
    n -= 1;
    idx_dec2 = n - dec2;
    intr_str = divider.substr(0, dec2);
    divider = divider.substr(dec2 + 1, n);
    divider = intr_str + divider;
    divider_base = divider;
    lst_divider = divider;
  };
  if (is_dec1) {
    n_divided -= 1;
    idx_dec = n_divided - dec1;
    intr_str = divided.substr(0, dec1);
    divided = divided.substr(dec1 + 1, n_divided);
    divided = intr_str + divided;
  };
  if (idx_dec > idx_dec2) {
    for (i = 0; i < idx_dec - idx_dec2; ++i) {
      divider.push_back('0');
      divider_base.push_back('0');
      lst_divider.push_back('0');
      n += 1;
    };
  } else if (idx_dec < idx_dec2) {
    for (i = 0; i < idx_dec2 - idx_dec; ++i) {
      divided.push_back('0');
      n_divided += 1;
    };
  };
  int delta_integ = n - n_divided;
  idx_dec = n;
  if (delta_integ > -1) {
    for (i = -1; i < delta_integ; ++i) {
      divided += "0";
      n_divided += 1;
    };
  } else if (delta_integ < -1) {
    for (i = -1; i > delta_integ; --i) {
      divider.push_back('0');
      divider_base.push_back('0');
      lst_divider.push_back('0');
      n += 1;
    };
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
        if (n != lst_n) {
          cnt -= 1;
          n = lst_n;
        };
        break;
      } else if (i == n) {
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
              eval_str2.insert(0, 1, '1');
              n2 += 1;
              agn = 0;
            };
          }
        } else {
          eval_str2[n2] = char(cur_val + 48);
        };
        break;
      };
    };
    lst_divider = divider;
    lst_n = n;
    for (i = cnt; i < n; ++i) {
      cur_val = (int(divider[i]) - 48) + (int(divider_base[i - cnt]) - 48);
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
            divider.insert(0, 1, '1');
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
          eval_str2.insert(0, 1, '1');
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
  if (post_dec > 1) {
    bgn = 1;
  };
  divided += "0";
  divider += "0";
  n_divided += 1;
  n += 1;
  cnt += 1;
  eval_str += ".";
  for (int i2 = 0; i2 < nb_decimal; ++i2) {
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
            n = lst_n;
          };
          break;
        } else if (i == n) {
          break;
        };
      };
      lst_divider = divider;
      lst_n = n;
      for (i = cnt; i < n; ++i) {
          cur_val = (int(divider[i]) - 48) + (int(divider_base[i - cnt]) - 48);
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
                divider.insert(0, 1, '1');
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
      cur_val = int(eval_str2[n2] - 48) + 1;
      lst_eval_str2 = eval_str2;
      eval_str2[n2] = char(cur_val + 48);
    };
    eval_str += eval_str2; 
    divided += "0";
    divider += "0";
    n += 1;
    n_divided += 1;
    cnt += 1;
  };
  if (delta_integ > -1) {
    for (i = bgn; i <= delta_integ; ++i) {
      eval_str.insert(0, 1, '0');
      post_dec += 1;
    };
    for (i = -1; i < delta_integ; ++i) {
      eval_str[post_dec] = eval_str[post_dec - 1];
      post_dec -= 1;
      eval_str[post_dec] = '.';
    };
  } else if (delta_integ < -1) {
    delta_integ *= -1;
    delta_integ -= 1;
    for (i = 0; i < delta_integ; ++i) {
      eval_str.push_back('0');
      eval_str[i + 1 + bgn] = eval_str[i + 3];
      eval_str[i + 2 + bgn] = '.';
    };
  };
  return eval_str;
};

//@T divide
//@U std::string divide(std::string &x, std::string &x2, unsigned int nb_decimal = 8)
//@X
//@D !!Obsolete!! Returns the result of a division between ints or floats represented as std string.
//@A x : is a int or float that will be divided represented as a std string, must be superior or equal to 1, refer to <code href="centerizer">centerizer()</code> to center your division to make the divided equal to 1 or higher
//@A x2 : is a int or float that will divide represented as a std string
//@X
//@E
//@E std::string x = "1458.970";
//@E std::string x2 = "563489.287";
//@E divide(x2, x);
//@E "386.2240" 
//@E
//@X

std::string divide(std::string &x, std::string &x2, unsigned int nb_decimal = 5) {
  if (x[0] == '-' || x2[0] == '-') {
    return "";
  };
  std::string divided = x;
  std::string divider = x2;
  std::string divider_base = divider;
  std::string lst_divider = divider;
  std::string eval_str = "";
  std::string eval_str2 = "0";
  std::string lst_eval_str2 = "0";
  std::string intr_str;
  unsigned int n = x2.length();
  unsigned int n_divided = x.length();
  unsigned int idx_dec = 0;
  unsigned int idx_dec2 = 0;
  unsigned int cnt = 0;
  unsigned int i2;
  int i = 0;
  unsigned int dec1 = 0;
  unsigned int dec2 = 0;
  unsigned int integ1;
  unsigned int integ2;
  bool agn;
  bool is_dec1 = 0;
  bool is_dec2 = 0;
  unsigned int bgn = 0;
  while (i < n) {
    if (divider[i] == '.') {
      is_dec2 = 1;
      break;
    };
    dec2 += 1;
    i += 1;
  };
  i = 0;
  while (i < n_divided) {
    if (divided[i] == '.') {
      is_dec1 = 1;
      break;
    };
    dec1 += 1;
    i += 1;
  };
  if (is_dec2) {
    n -= 1;
    idx_dec2 = n - dec2;
    intr_str = divider.substr(0, dec2);
    divider = divider.substr(dec2 + 1, n);
    divider = intr_str + divider;
    divider_base = divider;
    lst_divider = divider;
  };
  if (is_dec1) {
    n_divided -= 1;
    idx_dec = n_divided - dec1;
    intr_str = divided.substr(0, dec1);
    divided = divided.substr(dec1 + 1, n_divided);
    divided = intr_str + divided;
  };
  if (idx_dec > idx_dec2) {
    for (i = 0; i < idx_dec - idx_dec2; ++i) {
      divider.push_back('0');
      divider_base.push_back('0');
      lst_divider.push_back('0');
      n += 1;
    };
  } else if (idx_dec < idx_dec2) {
    for (i = 0; i < idx_dec2 - idx_dec; ++i) {
      divided.push_back('0');
      n_divided += 1;
    };
  };
  int delta_integ = n - n_divided + 1;
  idx_dec = n;
  if (delta_integ > -1) {
    for (i = 0; i < delta_integ; ++i) {
      divided += "0";
      n_divided += 1;
    };
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
        if (n != lst_n) {
          cnt -= 1;
          n = lst_n;
        };
        break;
      } else if (i == n) {
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
        break;
      };
    };
    lst_divider = divider;
    lst_n = n;
    for (i = cnt; i < n; ++i) {
      cur_val = (int(divider[i]) - 48) + (int(divider_base[i - cnt]) - 48);
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
  divided += ".0";
  divider += ".0";
  divider_base += ".0";
  lst_divider += ".0";
  n += 2;
  n_divided += 2;
  eval_str += eval_str2;
  post_dec = eval_str.length();
  if (post_dec > 1 & delta_integ > -1) {
    bgn = 1;
  };
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
      divider_base = divider_base.substr(1, divider_base.length() - 1);
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
              n = lst_n;
            };
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
        lst_eval_str2 = eval_str2;
        eval_str2[n2] = char(cur_val + 48);
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
          divider_base = divider_base.substr(1, divider_base.length() - 1);
        };
      };
    };
  };
  if (delta_integ > 0) {
    for (i = bgn; i < delta_integ; ++i) {
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
//@A base : is the number of 0 of the base 10 multiplicator
//@X
//@E
//@E std::string x2 = "563489.287";
//@E dividebase10(x2);
//@E "0.000563489287"
//@E
//@X

std::string dividebase10(std::string &x, unsigned int base = 9) {
  if (base == 0) {
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
      if (base + 1 > idx_dec) {
        lst_n = idx_dec;
        for (i = 0; i < base - lst_n + 1; ++i) {
          to_add.insert(0, "0");
          idx_dec += 1;
          n += 1;
        };
      };
      for (i = 0; i < base; ++i) {
        to_add[idx_dec] = to_add[idx_dec - 1];
        idx_dec -= 1;
        to_add[idx_dec] = '.';
      };
    }else {
      if (base + 1 > n) {
        lst_n = n;
        for (i = 0; i < base - lst_n + 1; ++i) {
          to_add.insert(0, "0");
          n += 1;
        };
      };
      to_add += ".";
      idx_dec = n;
      n += 1;
      for (i = 0; i < base; ++i) {
        to_add[idx_dec] = to_add[idx_dec - 1];
        idx_dec -= 1;
        to_add[idx_dec] = '.';
      };
    };
  } else {
    if (base + 1 > n) {
      lst_n = n;
      for (i = 0; i < base - lst_n + 1; ++i) {
        to_add.insert(0, "0");
        n += 1;
      };
    };
    to_add += ".";
    idx_dec = n;
    n += 1;
    for (i = 0; i < base; ++i) {
      to_add[idx_dec] = to_add[idx_dec - 1];
      idx_dec -= 1;
      to_add[idx_dec] = '.';
    };
  };
  return to_add;
};

//@T dividebase10_2
//@U std::string dividebase10_2(std::string x, int divider = 9)
//@X
//@D Returns the result of an int or float (as a std string) divided by a base 10 divider.
//@A x : is the int of float that will be divided
//@A divider : is an int that indicates the number of zero of the base 10 divider
//@X
//@E
//@E std::string x2 = "563489.287";
//@E dividebase10_2(x2);
//@E "0.000563489287"
//@E
//@X

std::string dividebase10_2(std::string x, int divider = 9) {
  std::string to_power;
  std::string intr_str;
  int n = x.length();
  int i;
  bool agn;
  unsigned int idx_dec;
  if (divider > 0) {
    i = -1;
    agn = 1;
    while (agn) {
      i += 1;
      if (i + 1 == n) {
        agn = 0;
      } else if (x[i] == '.') {
        idx_dec = i;
        agn = 0;
      };
    };
    if (i + 1 < n) {
      if (i - divider > 0) {
        for (i = 0; i < divider; ++i) {
          x[idx_dec] = x[idx_dec - 1];
          idx_dec -= 1;
          x[idx_dec] = '.';
        };
      } else {
        intr_str = x.substr(idx_dec + 1, n);
        x = "0." + x.substr(0, idx_dec) + intr_str;
        x.insert(2, divider - idx_dec, '0');
      };
    } else {
       if (n - divider > 0) {
        x.insert(n - divider, 1, '.');
      } else {
        x.insert(0, "0.");
        x.insert(2, divider - n, '0');
      }; 
    };
  } else {
    return "";
  };
  return x;
};

//@L2 Remainder
//@L3 Integers

//@T remainderint
//@U std::string remainderint(std::string &x, std::string &x2)
//@X
//@D Returns the remainder of a division between two int represented as a std string
//@A x : is the int that will be divided, represented as a string, must be greater or equal to x2
//@A x2 : is the divider which is a int represented as a string, must be lower or equal to x
//@X
//@E
//@E std::string x = "1458970";
//@E std::string x2 = "563489287";
//@E remainderint(x2, x);
//@E "326867"
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
//@X
//@E
//@E std::string x = "14589.70";
//@E std::string x2 = "56348.9287";
//@E remainderflt(x2, x);
//@E "12579.8287"
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
//@E std::string x = "1458970";
//@E std::string x2 = "563489287";
//@E quotientint(x2, x);
//@E "386"
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
//@E std::string x = "14589.70";
//@E std::string x2 = "563489.287";
//@E quotientflt(x2, x);
//@E "38"
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

//@L1 Power
//@L2 Integers

//@T powerint3
//@U std::string powerint3(std::string &x, std::string &x2)
//@X
//@D Returns the result of an int or float (as a std string) to the power of an int
//@A x : is an int or float as a std string
//@A x2 : is an inst as a std string
//@X
//@E
//@E std::string x = "14589";
//@E std::string x2 = "56";
//@E powerint3(x, x2);
//@E "153260190174219811934128137332827906929119558402173805060214522716822523044456122073019142584098371366854238645863580507697977504775933822261516593995310407783049191696069368377535301569706808049310753775157932309020336358163020676961"
//@E
//@X

std::string powerint3(std::string &x, std::string &x2) {
  if (x2 == "0") {
    return "0";
  } else if (x2 == "1") {
    return x;
  };
  int i;
  int i2;
  unsigned int i3;
  unsigned int n = x.length();
  unsigned int lst_n = n;
  bool agn;
  int n2 = 0;
  unsigned int add_zero = 0;
  unsigned int ref_add_zero = 0;
  int cur_val;
  int intr_val;
  int bf_cnt;
  int delta = 0;
  unsigned int delta2;
  std::string divider;
  std::string eval_str = "1";
  std::string rtn_str = "";
  std::string rtn_str2 = "";
  std::string rtn_str3 = "";
  if (n > 2) {
    agn = 1;
    i = 0;
    while (agn) {
      rtn_str += x[i];
      i += 1;
      if (i + 1 == n) {
        agn = 0;
      } else if (x[i] == '.'){
        agn = 0;
      };
    };
    if (i + 1 < n) {
      add_zero = n - 1 - i;
      i += 1;
      while (i < n) {
        rtn_str += x[i];
        i += 1;
      };
      n -= 1;
      lst_n -= 1;
    } else {
      rtn_str = x;
    };
  } else {
    rtn_str = x;
  };
  for (i = 0; i < n; ++i) {
    rtn_str2 += "0";
  };
  rtn_str3 = rtn_str;
  ref_add_zero = add_zero;
  while (eval_str != x2) {
    add_zero += ref_add_zero;
    cur_val = int(rtn_str3[0] - 48) * int(rtn_str[0] - 48);
    delta = 0;
    delta2 = 0;
    if (cur_val > 9) {
      rtn_str2 += "0";
      n += 1;
      delta2 = 1;
    };
    for (i3 = 1; i3 < lst_n; ++i3) {
      rtn_str2 += "0";
      n += 1;
      delta += 1;
    };
    for (i = 0; i < n; ++i) {
      rtn_str2[i] = '0';
    };
    for (i2 = delta + delta2; i2 < n; ++i2) {
      for (i = 0; i < lst_n; ++i) {
        cur_val = int(rtn_str2[i2 + i - delta] - 48) + int(rtn_str3[i2 - delta - delta2] - 48) * int(rtn_str[i] - 48);
        if (cur_val < 10) {
          rtn_str2[i2 + i - delta] = char(cur_val + 48);
        } else {
          intr_val = 1;
          while (cur_val - (intr_val + 1) * 10 > -1) {
            intr_val += 1;
          };
          cur_val -= intr_val * 10;
          rtn_str2[i2 + i - delta] = char(cur_val + 48);
          cur_val = int(rtn_str2[i2 + i - delta - 1] - 48) + intr_val;
          if (cur_val < 10) {
            rtn_str2[i2 + i - delta - 1] = char(cur_val + 48);   
          } else {
            cur_val -= 10;
            rtn_str2[i2 + i - delta - 1] = char(cur_val + 48);
            agn = 1;
            bf_cnt = 0;
            while (agn) { 
              bf_cnt += 1;
              if (i2 + i - delta - bf_cnt - 1 > - 1) {
                if (rtn_str2[i2 + i - delta - bf_cnt - 1] == '9') {
                  rtn_str2[i2 + i - delta - bf_cnt - 1] = '0'; 
                } else {
                  rtn_str2[i2 + i - delta - bf_cnt - 1] = char(int(rtn_str2[i2 + i - delta - bf_cnt - 1]) + 1); 
                  agn = 0;
                };
              } else {
                delta2 += 1;
                i2 += 1;
                n += 1;
                rtn_str2.insert(0, 1, '1');
                agn = 0;
              };
            };
          };
        };
      };
    };
    rtn_str3 = rtn_str2;
    cur_val = int(eval_str[n2] - 48) + 1;
    if (cur_val > 9) {
      cur_val -= 10;
      eval_str[n2] = char(cur_val + 48);
      agn = 1;
      bf_cnt = 0;
      while(agn) {
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
  if (add_zero != 0) {
    rtn_str2.insert(n - add_zero, ".");
  };
  return rtn_str2;
};

//@T poweroddn
//@U std::string poweroddn(std::string &x, std::string &x2)
//@X
//@D Returns the result of an int or float, as a std string to the power of 2 to the power of n, which is an int as a std string. 
//@A x : is the int or float (as a std string) that will be raised to the power of x2
//@A x2 : is an int
//@X
//@E
//@E std::string x = "14.589";
//@E std::string x2 = "6";
//@E poweroddn(x, x2);
//@E "314509345202142665193410679125428033118438342864761586343543406788602813321.829414037501712790360016267236804103022451365560402812257231544584303307790019122009329449912834283039886749776498473622284482191189951072052752453908143338819524431841597590758370489688259841" 
//@E
//@X

std::string poweroddn(std::string &x, std::string &x2) {
  if (x2 == "0") {
    return x;
  };
  int i;
  int i2;
  unsigned int i3;
  unsigned int n = x.length();
  unsigned int lst_n = n;
  bool agn;
  unsigned int n2 = 0;
  unsigned int add_zero = 0;
  int cur_val;
  int intr_val;
  int bf_cnt;
  int delta = 0;
  unsigned int delta2;
  std::string divider;
  std::string eval_str = "0";
  std::string rtn_str = "";
  std::string rtn_str2 = "";
  if (n > 2) {
    agn = 1;
    i = 0;
    while (agn) {
      rtn_str += x[i];
      i += 1;
      if (i + 1 == n) {
        agn = 0;
      } else if (x[i] == '.'){
        agn = 0;
      };
    };
    if (i + 1 < n) {
      add_zero = n - 1 - i;
      i += 1;
      while (i < n) {
        rtn_str += x[i];
        i += 1;
      };
      n -= 1;
      lst_n -= 1;
    } else {
      rtn_str = x;
    };
  } else {
    rtn_str = x;
  };
  for (i = 0; i < n; ++i) {
    rtn_str2 += "0";
  };
  while (eval_str != x2) {
    add_zero *= 2;
    cur_val = int(rtn_str[0] - 48) * int(rtn_str[0] - 48);
    delta = 0;
    delta2 = 0;
    if (cur_val > 9) {
      rtn_str2 += "0";
      n += 1;
      delta2 = 1;
    };
    for (i3 = 1; i3 < lst_n; ++i3) {
      rtn_str2 += "0";
      n += 1;
      delta += 1;
    };
    for (i = 0; i < n; ++i) {
      rtn_str2[i] = '0';
    };
    for (i2 = delta + delta2; i2 < n; ++i2) {
      for (i = 0; i < lst_n; ++i) {
        cur_val = int(rtn_str2[i2 + i - delta] - 48) + int(rtn_str[i2 - delta - delta2] - 48) * int(rtn_str[i] - 48);
        if (cur_val < 10) {
          rtn_str2[i2 + i - delta] = char(cur_val + 48);
        } else {
          intr_val = 1;
          while (cur_val - (intr_val + 1) * 10 > -1) {
            intr_val += 1;
          };
          cur_val -= intr_val * 10;
          rtn_str2[i2 + i - delta] = char(cur_val + 48);
          cur_val = int(rtn_str2[i2 + i - delta - 1] - 48) + intr_val;
          if (cur_val < 10) {
            rtn_str2[i2 + i - delta - 1] = char(cur_val + 48);   
          } else {
            cur_val -= 10;
            rtn_str2[i2 + i - delta - 1] = char(cur_val + 48);
            agn = 1;
            bf_cnt = 0;
            while (agn) { 
              bf_cnt += 1;
              if (i2 + i - delta - bf_cnt - 1 > - 1) {
                if (rtn_str2[i2 + i - delta - bf_cnt - 1] == '9') {
                  rtn_str2[i2 + i - delta - bf_cnt - 1] = '0'; 
                } else {
                  rtn_str2[i2 + i - delta - bf_cnt - 1] = char(int(rtn_str2[i2 + i - delta - bf_cnt - 1]) + 1); 
                  agn = 0;
                };
              } else {
                delta2 += 1;
                i2 += 1;
                n += 1;
                rtn_str2.insert(0, 1, '1');
                agn = 0;
              };
            };
          };
        };
      };
    };
    rtn_str = rtn_str2;
    lst_n = n;
    cur_val = int(eval_str[n2] - 48) + 1;
    if (cur_val > 9) {
      cur_val -= 10;
      eval_str[n2] = char(cur_val + 48);
      agn = 1;
      bf_cnt = 0;
      while(agn) {
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
  if (add_zero != 0) {
    rtn_str2.insert(n - add_zero, ".");
  };
  return rtn_str2;
};

//@L2 Floating points

//@T powerflt
//@U std::string powerflt(std::string &x, std::string &x2, unsigned int nb_polynomial = 20)
//@X
//@D Returns the result of a int or float (as std string) to the power of int or float (as std string) 
//@A x : is the number (int or float as std string) that will be elevated to an exponent
//@A x2 : is the exponent (int or float as std string)
//@A nb_polynomial : is the length of the polynomial used for the taylor serie of exp(x) that allow the function to work. The bigger log(x) times x2 is, the bigger <code>nb_polynomial</code> should be.
//@X
//@E
//@E std::string x = "3.478";
//@E std::string x2 = "10.58";
//@E powerflt(x, x2);
//@E "537525.0830373820"
//@E
//@X

//@L1 Exponential

//@T chexp1
//@U std::string chexp1(std::string x, int accuracy = 1000)
//@X
//@D !!Not recommended, just a proof of concept!! Returns the result of an exponential. Works with the formula <b>(1 + x/accuracy) ** accuracy</b>
//@A x : is the int or float that will be elevated to exponentiation
//@A accuracy : is the accuracy factor, the higher it is, the more precise it gets at a computational cost
//@X
//@E
//@E std::string x = "8";
//@E chexp1(x);
//@E "2887.5672632" // + lot of accuracy
//@E
//@X

std::string chexp1(std::string x, int accuracy = 1000) {
  if (accuracy == 1 || accuracy == 0) {
    return "";
  };
  unsigned int n = x.length();
  unsigned int i;
  int i2;
  int i3;
  bool agn;
  unsigned int idx_dec = 0;
  int cur_val;
  int delta = 0;
  unsigned int delta2;
  int intr_val;
  unsigned int intr_val2;
  int bf_cnt;
  unsigned int int_val;
  std::string rtn_str;
  std::string ref_str = "";
  std::string cur_str = "";
  std::string intr_str = "";
  i = -1;
  agn = 1;
  while (agn) {
    i += 1;
    if (i + 1 == n) {
      ref_str += x[i];
      cur_str += "0";
      agn = 0;
    } else if (x[i] == '.') {
      idx_dec = i;
      agn = 0;
    } else {
      ref_str += x[i];
      cur_str += "0";
    };
  };
  if (i + 1 < n) {
    int_val = i;
    i += 1;
    while (i < n) {
      ref_str += x[i];
      cur_str += "0";
      i += 1;
    };
    idx_dec = n - 1 - idx_dec;
    n -= 1;
  } else {
    int_val = n;
  };
  intr_val = 1;
  intr_val2 = 1;
  while (accuracy - 10 * intr_val > 0) {
    intr_val *= 10;
    intr_val2 += 1;
  };
  idx_dec += intr_val2;
  if (intr_val2 < int_val) {
    cur_val = int(ref_str[n - 1 - intr_val2] - 48) + 1;
    if (cur_val > 9) {
      cur_val -= 10;
      ref_str[n - 1 - intr_val2] = char(cur_val + 48);
      agn = 1;
      bf_cnt = 0;
      while (agn) {
        if (n - 1 - intr_val2 - bf_cnt > -1) {
          if (ref_str[n - 1 - intr_val2 - bf_cnt] == '9') {
            ref_str[n - 1 - intr_val2 - bf_cnt] = '0';
          } else {
            ref_str[n - 1 - intr_val2 - bf_cnt] = char(int(ref_str[n - 1 - intr_val2 - bf_cnt]) + 1);
            agn = 0;
          };
        } else {
          agn = 0;
          ref_str.insert(0, 1, '1');
          n += 1;
        };
      };
    } else {
      ref_str[n - 1 - intr_val2] = char(cur_val + 48);
    };
  } else {
    intr_str = "1";
    cur_str.push_back('0');
    n += 1;
    for (i = int_val; i < intr_val2; ++i) {
      cur_str.push_back('0');
      n += 1;
      intr_str.push_back('0');
    };
    ref_str = intr_str + ref_str;
  };
  rtn_str = ref_str;
  unsigned int n2 = n;
  unsigned int add_zero = idx_dec;
  for (i = 1; i < accuracy; ++i) {
    cur_val = int(ref_str[0] - 48) * int(rtn_str[0] - 48);
    delta2 = 0;
    delta = 0;
    if (cur_val > 9) {
      delta2 = 1;
      n += 1;
      cur_str.push_back('0');
    };
    for (i2 = 1; i2 < n2; ++i2) {
      delta += 1;
      n += 1;
      cur_str.push_back('0');
    };
    for (i2 = delta + delta2; i2 < n; ++i2) {
      for (i3 = 0; i3 < n2; ++i3) {
        cur_val = int(cur_str[i2 - delta + i3] - 48) + int(rtn_str[i2 - delta - delta2] - 48) * int(ref_str[i3] - 48);
        if (cur_val < 10) {
          cur_str[i2 + i3 - delta] = char(cur_val + 48);
        } else {
          intr_val = 1;
          while (cur_val - (intr_val + 1) * 10 > 0) {
            intr_val += 1;
          };
          cur_val -= intr_val * 10;
          cur_str[i2 + i3 - delta] = char(cur_val + 48); 
          cur_val = int(cur_str[i2 + i3 - delta - 1] - 48) + intr_val;
          if (cur_val < 10) {
            cur_str[i2 + i3 - delta - 1] = char(cur_val + 48);
          } else {
            cur_val -= 10;
            cur_str[i2 + i3 - delta - 1] = char(cur_val + 48);
            agn = 1;
            bf_cnt = 0;
            while (agn) {
              bf_cnt += 1;
              if (i2 + i3 - delta - 1 - bf_cnt > -1) {
                if (cur_str[i2 + i3 - delta - 1 - bf_cnt] == '9') {
                  cur_str[i2 + i3 - delta - 1 - bf_cnt] = '0';
                } else {
                  cur_str[i2 + i3 - delta - 1 - bf_cnt] = char(int(cur_str[i2 + i3 - delta - 1 - bf_cnt]) + 1);
                  agn = 0;
                };
              } else {
                agn = 0;
                cur_str.insert(0, 1, '1');
                n += 1;
                delta2 += 1;
                i2 += 1;
              }
            };
          };
        };
      };
    };
    rtn_str = cur_str;
    for (i2 = 0; i2 < n; ++i2) {
      cur_str[i2] = '0';
    };
  };
  if (n > idx_dec * accuracy) {
    rtn_str.insert(n - idx_dec * accuracy, 1, '.');
  } else {
    
  };
  return rtn_str;
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


//@L1 Logarithms

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

//@L2 Base n

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

//@L1 Factorial

//@T factorial
//@U std::string factorial(std::string &x)
//@X
//@D Returns the factorial (of a positive integer number), represented as a std string
//@A x : is an positive integer as a std string
//@X
//@E
//@E std::string x = "1203";
//@E factorial(x);
//@E " 110291182274320302868335540036971957964398761049288945189514522265495848012966079388748606697973923857953863340967082130666006801995552084113814868238243311858913795154784617153902296146662261034010473803827569767538493678138342890947302327880659767989629372970546995369789051829636976020229377210033943230084516335699249033857428772315591104623952693868236895725991085709158040233167679112351936991424971264582253948780887379967819939333395587783920859359861012157863588005375328833992235770831819662357991853643303111244309326324373091074509115218770474031745001085058150484834220026432804625434128103617316002317240235816361436134297139959662483729719647267876280118259712947551023653444555174490944979196787361320691724054489811739772152714191015590466907891601064590715046011898180534740537300129250803125492992577415551304378939332611237562776293561035832294489499225804565027267569023949255161282391174997210303446793139678706808650493259713137854061821137461397796722386790250701776810015961428197556815751881087003157545471521009580843663460817191196050241064752581934463558830010132138518790930470384585398937993248316524232578527264460878228840418064555725329100375022428626309365502567689206415068383514463527804702179358835752389190241844166925965937482139489983646084680324516474595845898026896254328710351184166557725020369476995517380367529937617113231359792819905104507614147780421528883484133295052608745099678446222414535404890949882402139712822530829693616183501644591032729707298565386443307563497032672316273198489049829030913715144490221271583537916723475841857831273842405894134590613795155682863064577984556748493737206351932583104172335734280226763088742592195979407131112600953429663256089713211540343880345163689494478845964979135658780819094129142572035559733121669788156352259750384591475246232016769075079376829857776400589333076596715030915886442811852204991104123222836145828125630564312184996547014552284493145574519304072039703973936965896586108737637067695497470660389631858282834386074427079639087770744487891233683053513892666630403886028137795177406237525249875396197418728093989786482185147005153853264518939124417226373486941967057099550815354237514275032081881610961521996825319734630187988769835736334129937206125352211558436128168257565762561098798685898910181724217378427847755791561092496954234588923027413794716484601714639867544884155288670222887376305424677401569213422442327166342634374955584061782891358081777309625180826661062844058991327824113050412205823174208534851051558677681043793002218008919992212282871525955992706178455492690945449945439208089933822268665877269583213533003120330908157497449182538729547002189479274597896996222446035150842524951733342788124468436353810664498768586798231949004761871215217176571499053572447150628068308187071772821239484551881596985264424435373729446965693122971789819834691063207833724791029760000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
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

//@L1 Inverse functions

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

//@L1 Comparisons

//@T is_greater
//@U bool is_greater(std::string &x, std::string &x2)
//@X
//@D Returns 1 if the first number (int as a std string) is greater than the second (int as a std string) .
//@A x : is a int as a string
//@A x2 : is a int as a string
//@X
//@E
//@E std::string x = "1203";
//@E std::string x2 = "6";
//@E is_greater(x, x2);
//@E 1
//@E
//@X

bool is_greater(std::string &x, std::string &x2) {
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
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
  } else {
    return 0;
  };
  return 1;
};

//@T is_greaterflt
//@U bool is_greaterflt(std::string &x, std::string &x2)
//@X
//@D Returns 1 if the first number, int or float (as a std string) is greater than the second, int or float (as a std string) .
//@A x : is a number (int or float) as a string
//@A x2 : is a number (int or float) as a string
//@X
//@E
//@E std::string x = "1.203";
//@E std::string x2 = "6";
//@E is_greaterflt(x, x2);
//@E 0
//@E
//@X

bool is_greaterflt(std::string &x, std::string &x2) {
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  unsigned int integ_val;
  unsigned int integ_val2;
  unsigned int dec_val;
  unsigned int dec_val2;
  unsigned int dec_valf;
  unsigned int i = 0;
  for (integ_val = 0; integ_val < n; ++integ_val) {
    if (x[integ_val] == '.') {
      break;
    };
  };
  dec_val = n - 1 - integ_val;
  for (integ_val2 = 0; integ_val2 < n2; ++integ_val2) {
    if (x2[integ_val2] == '.') {
      break;
    };
  };
  dec_val2 = n2 - 1 - integ_val2;
  if (dec_val < dec_val2) {
    dec_valf = dec_val;
  } else {
    dec_valf = dec_val2;
  };
  unsigned int val1;
  unsigned int val2;
  if (integ_val == integ_val2) {
    while (i < integ_val) {
      val1 = int(x[i]);
      val2 = int(x2[i]);
      if (val1 != val2) {
        if (val1 > val2) {
          return 1;
        } else {
          return 0;
        };
      };
      i += 1;
    };
    while (i < n + dec_valf) {
      val1 = int(x[i]);
      val2 = int(x2[i]);
      if (val1 != val2) {
        if (val1 > val2) {
          return 1;
        } else {
          return 0;
        };
      };
      i += 1;
    };
    if (dec_valf != dec_val2) {
      while (i < n + dec_val2)  {
        if (x2[i] != '0') {
          return 0;
        };
        i += 1;
      };
    } else if (dec_valf != dec_val) {
      while (i < n + dec_val)  {
        if (x[i] != '0') {
          return 1;
        };
        i += 1;
      };
    }
    return 0;
  } else if (integ_val > integ_val2) {
    return 1;
  } else {
    return 0;
  };
  return 1;
};

//@L1 Round

//@T roundstr
//@U std::string roundstr(std::string &x, int &digits)
//@X
//@D Round the input number entered as a std string. 
//@A x : is a std string representing a number
//@A digits : is the number of digits to round from, can be negative
//@X
//@E
//@E std::string x = "156.203";
//@E int x2b = 2;
//@E roundstr(x, x2b);
//@E 156.20
//@E x2b = -1;
//@E roundstr(x,; x2b);
//@E 160 
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

//@L1 Other Tools

//@T rmzero
//@U std::string rmzero(std::string x)
//@X
//@D Removes unnecessary 0 at the end of a floating point.
//@A is an float as a std string
//@X
//@E
//@E std::string x = "156.203000";
//@E rmzero(x);
//@E "156.203"
//@E
//@X

std::string rmzero(std::string x) {
  unsigned int n = x.length() - 1;
  while (x[n] == '0') {
    x.pop_back();
    n -= 1;
  };
  return x;
};

//@T intpart
//@U std::string intpart(std::string x)
//@X
//@D Returns the integer part of a float
//@A x : is a float as a std string
//@X
//@E
//@E std::string x = "156.203";
//@E intpart(x);
//@E "156"
//@E
//@X

std::string intpart(std::string x) {
  unsigned int i = x.length() - 1;
  while (x[i] != '.') {
    x.pop_back();
    --i;
  };
  x.pop_back();
  return x;
}

//@T fltpart
//@U std::string fltpart(std::string &x)
//@X
//@D Returns the float part of a float
//@A x : is a float as a std string
//@X
//@E
//@E std::string x = "156.203";
//@E fltpart(x);
//@E "203"
//@E
//@X

std::string fltpart(std::string &x) {
  std::string rtn_str = "";
  const unsigned int n = x.length();
  unsigned int i = 0;
  while (x[i] != '.') {
    i += 1;
  };
  i += 1;
  while (i < n) {
    rtn_str.push_back(x[i]);
    i += 1;
  };
  return rtn_str;
}

//@T is_decimal
//@U bool is_decimal(std::string &x)
//@X
//@D Returns if a number as a std string, is a float
//@A x : is the input number, as a std string
//@X
//@E
//@E std::string x = "156.203";
//@E is_decimal(x);
//@E 1
//@E x = "156";
//@E is_decimal(x);
//@E 0
//@E
//@X

bool is_decimal(std::string &x) {
  bool rtn = 0;
  const unsigned int n = x.length();
  for (unsigned int i = 0; i < n; ++i) {
    if (x[i] == '.') {
      return 1;
    };
  };
  return 0;
};

//@T centerizer
//@U std::vector&lt;std::string&gt; centerizer(std::string x, std::string x2)
//@D Returns the numerator and denominator transformed for the numerator to be higher or equal to 1 
//@X
//@A x : is the divided as a std string
//@A x2 : is the divider as a std string
//@X
//@E
//@E std::string x = "0.001562";
//@E std::string x2 = "6.8987";
//@E std::vector&lt;std::string&gt; out = centerizer(x, x2);
//@E "1.562" "6898.7"
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
  while (x2[dec] != '.' & dec < n2) {
    dec += 1;
  };
  unsigned int i = 2;
  unsigned int cnt = dec;
  const unsigned int n = x.length();
  if (dec < n2) {
    while (x[i - 2] == '0' & i < n) {
      x[i - 1] = x[i];
      x[i] = '.';
      if (cnt + 1 < n2) {
        x2[cnt] = x2[cnt + 1];
        x2[cnt + 1] = '.';
        if (cnt + 2 == n2) {
          x2.pop_back();
          n2 -= 1;
        };
      } else {
        x2.push_back('0');
      };
      cnt += 1;
      i += 1;
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

///// NOT TO BE USED  ////

double chstod(const std::string &x) {
  double rtn = int(x[0]) - 48;
  const int n = x.size();
  int i = 1;
  int m = 1;
  while (int(x[i]) != 46) {
    rtn *= 10;
    rtn += (int(x[i]) - 48);
    i += 1;
  };
  i += 1;
  while (i < n) {
    m *= 10;
    rtn *= 10;
    rtn += (int(x[i]) - 48);
    i += 1;
  };
  return rtn / m;
};




