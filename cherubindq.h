#include <iostream>
#include <deque>

struct cherubindq {
  std::deque<char> cur_dq;
  cherubindq(std::string &x) {
    for (char i : x) {
      cur_dq.push_back(i);
    };
  };
  ~cherubindq() {};
};

std::deque<char> addint(std::deque<char> &x, std::deque<char> &x2) {
  std::deque<char> cur_dq;
  std::deque<char> bf_dq;
  unsigned int cnt;
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  unsigned int sizen;
  if (n2 > n) {
    cur_dq = x2;
    bf_dq = x;
    cnt = n2 - n;
    sizen = n2;
  } else {
    cur_dq = x;
    bf_dq = x2;
    cnt = n - n2; 
    sizen = n;
  };
  int cur_val;
  int bf_cnt;
  bool agn;
  if (bf_dq[0] == '-' || cur_dq[0] == '-') {
    return cur_dq;
  };
  for (int i = cnt; i < sizen; ++i) {
    cur_val = (int(bf_dq[i - cnt]) - 48) + (int(cur_dq[i]) - 48);
    if (cur_val > 9) {
      cur_val -= 10;
      cur_dq[i] = char(cur_val + 48);
      bf_cnt = 0;
      agn = 1;
      while (agn) {
        bf_cnt += 1;
        if (i - bf_cnt > -1) {
          if (cur_dq[i - bf_cnt] == '9') {
            cur_dq[i - bf_cnt] = '0';
          } else {
            cur_dq[i - bf_cnt] = char(int(cur_dq[i - bf_cnt]) + 1);
            agn = 0;
          };
        } else {
          cur_dq.push_front('1'); 
          cnt += 1;
          i += 1;
          sizen += 1;
          agn = 0;
        };
      };
    } else {
      cur_dq[i] = char(cur_val + 48);
    };
  };
  return cur_dq;
};

std::deque<char> addflt(std::deque<char> &x, std::deque<char> &x2) {
  std::deque<char> cur_dq;
  std::deque<char> bf_dq;
  const unsigned bf_cn = x.size();
  const unsigned bf_cn2 = x2.size();
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
    cur_dq = x2;
    bf_dq = x;
    cnt = n2 - n;
    cur_delta = (bf_cn - n) - (bf_cn2 - n2);
    sizen = bf_cn2;
    if (cur_delta > 0) {
      sizen += cur_delta;
      if (!is_dec2) {
        cur_delta -= 1;
        cur_dq.push_back('.');
      };
      for (i = 0; i < cur_delta; ++i) {
        cur_dq.push_back('0');
      };
    } else if (cur_delta < 0) {
      cur_delta *= -1;
      if (!is_dec1) {
        cur_delta -= 1;
        bf_dq.push_back('.');
      };
      for (i = 0; i < cur_delta; ++i) {
        bf_dq.push_back('.');
      };
    };
  } else {
    cur_dq = x;
    bf_dq = x2;
    cnt = n - n2; 
    cur_delta = (bf_cn2 - n2) - (bf_cn - n);
    sizen = bf_cn;
    if (cur_delta > 0) {
      sizen += cur_delta;
      if (!is_dec1) {
        cur_delta -= 1;
        cur_dq.push_back('.');
      };
      for (i = 0; i < cur_delta; ++i) {
        cur_dq.push_back('0');
      };
    } else if (cur_delta < 0) {
      cur_delta *= -1;
      if (!is_dec2) {
        cur_delta -= 1;
        bf_dq.push_back('.');
      };
      for (i = 0; i < cur_delta; ++i) {
        bf_dq.push_back('0');
      };
    };
  };
  int cur_val;
  int bf_cnt;
  if (bf_dq[0] == '-' || cur_dq[0] == '-') {
    return cur_dq;
  };
  for (i = cnt; i < sizen; ++i) {
    if (cur_dq[i] != '.') {
      cur_val = (int(bf_dq[i - cnt]) - 48) + (int(cur_dq[i]) - 48);
      if (cur_val > 9) {
        cur_val -= 10;
        cur_dq[i] = char(cur_val + 48);
        if (i - 1 > 0) {
          if (cur_dq[i - 1] != '.') {
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
            if (cur_dq[i - bf_cnt] != '.') {
              if (cur_dq[i - bf_cnt] == '9') {
                cur_dq[i - bf_cnt] = '0';
              } else {
                cur_dq[i - bf_cnt] = char(int(cur_dq[i - bf_cnt]) + 1);
                agn = 0;
              };
            };
          } else {
            cur_dq.push_front('1');
            cnt += 1;
            i += 1;
            sizen += 1;
            agn = 0;
          };
        };
      } else {
        cur_dq[i] = char(cur_val + 48);
      };
    };
  };
  return cur_dq;
};

std::deque<char> addflt2(std::deque<char> x, std::deque<char> &x2) {
  int i = 0;
  unsigned int i2 = 0;
  unsigned int cnt = 0;
  unsigned int dec_val = 0;
  unsigned int dec_val2 = 0;
  unsigned int idx_dec = 0;
  unsigned int n = x.size();
  unsigned int cur_val;
  int bf_cnt;
  bool agn;
  const unsigned int n2 = x2.size();
  std::deque<char> intr_dq;
  while (i < n) {
    if (x[i] == '.') {
      dec_val = n - 1 - i;
      x.erase(x.begin() + i);
      n -= 1;
      break;
    };
    i += 1;
  };
  while (i2 < n2) {
    if (x2[i2] == '.') {
      dec_val2 = n2 - 1 - i2;
      x2.erase(x2.begin() + i2);
      break;
    };
    i2 += 1;
  };
  if (i < i2) {
    for (i = i; i < i2; ++i) {
      x.push_front('0');
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
          x.push_front('1');
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
    x.insert(x.begin() + idx_dec, '.');
  };
  return x;
};

std::deque<char> subsint(std::deque<char> &x, std::deque<char> &x2) {
  std::deque<char> cur_dq = x;
  std::deque<char> bf_dq = x2;
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  unsigned int sizen;
  unsigned int cnt;
  int i;
  if (n >= n2) {
    sizen = n;
    cnt = n - n2;
  } else {
    return cur_dq;
  };
  int cur_val;
  int bf_cnt;
  bool agn;
  if (bf_dq[0] == '-' || cur_dq[0] == '-') {
    return cur_dq;
  };
  for (i = cnt; i < sizen; ++i) {
    cur_val = (int(cur_dq[i]) - 48) - (int(bf_dq[i - cnt]) - 48);
    if (cur_val < 0) {
      cur_val = 10 + cur_val;
      cur_dq[i] = char(int(cur_val) + 48);
      bf_cnt = 0;
      agn = 1;
      while (agn) {
        bf_cnt += 1;
        if (cur_dq[i - bf_cnt] == '0') {
          cur_dq[i - bf_cnt] = '9';
        } else {
          cur_dq[i - bf_cnt] = char(int(cur_dq[i - bf_cnt]) - 1);
          agn = 0;
        };
      };
    } else {
      cur_dq[i] = char(cur_val + 48);
    };
    if (cur_dq[0] == '0' & sizen > 1) {
      cur_dq.pop_front();
      bf_dq.pop_front();
      sizen -= 1;
      i -= 1;
    };
  };
  return cur_dq;
};

std::deque<char> subsflt(std::deque<char> &x, std::deque<char> &x2) {
  std::deque<char> cur_dq = x;
  std::deque<char> bf_dq = x2;
  const unsigned bf_cn = x.size();
  const unsigned bf_cn2 = x2.size();
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
    cur_dq = x2;
    bf_dq = x;
    cnt = n2 - n;
    cur_delta = (bf_cn - n) - (bf_cn2 - n2);
    sizen = bf_cn2;
    if (cur_delta > 0) {
      sizen += cur_delta;
      if (!is_dec2) {
        cur_delta -= 1;
        cur_dq.push_back('.');
      };
      for (i = 0; i < cur_delta; ++i) {
        cur_dq.push_back('0');
      };
    } else if (cur_delta < 0) {
      cur_delta *= -1;
      if (!is_dec1) {
        cur_delta -= 1;
        bf_dq.push_back('.');
      };
      for (i = 0; i < cur_delta; ++i) {
        bf_dq.push_back('0');
      };
    };
  } else {
    cur_dq = x;
    bf_dq = x2;
    cnt = n - n2; 
    cur_delta = (bf_cn2 - n2) - (bf_cn - n);
    sizen = bf_cn;
    if (cur_delta > 0) {
      sizen += cur_delta;
      if (!is_dec1) {
        cur_delta -= 1;
        cur_dq.push_back('.');
      };
      for (i = 0; i < cur_delta; ++i) {
        cur_dq.push_back('0');
      };
    } else if (cur_delta < 0) {
      cur_delta *= -1;
      if (!is_dec2) {
        cur_delta -= 1;
        bf_dq.push_back('.');
      };
      for (i = 0; i < cur_delta; ++i) {
        bf_dq.push_back('0');
      };
    };
  };
  int cur_val;
  int bf_cnt;
  if (bf_dq[0] == '-' || cur_dq[0] == '-') {
    return cur_dq;
  };
  for (i = cnt; i < sizen; ++i) {
    if (cur_dq[i] != '.') {
      cur_val = (int(cur_dq[i]) - 48) - (int(bf_dq[i - cnt]) - 48);
      if (cur_val < 0) {
        cur_val = 10 + cur_val;
        cur_dq[i] = char(int(cur_val) + 48);
        if (cur_dq[i - 1] != '.') {
          bf_cnt = 0;
        } else {
          bf_cnt = 1;
        };
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (cur_dq[i - bf_cnt] != '.') {
            if (cur_dq[i - bf_cnt] == '0') {
              cur_dq[i - bf_cnt] = '9';
            } else {
              cur_dq[i - bf_cnt] = char(int(cur_dq[i - bf_cnt]) - 1);
              agn = 0;
            };
          };
        };
      } else {
        cur_dq[i] = char(cur_val + 48);
      };
      if (cur_dq[0] == '0' & sizen > 1) {
        if (cur_dq[1] != '.') {
          cur_dq.pop_front();
          bf_dq.pop_front();
          i -= 1;
          sizen -= 1;
        };
      };
    };
  };
  return cur_dq;
};

std::deque<char> multint(std::deque<char> &x, unsigned int &x2) {
  std::deque<char> cur_dq = x;
  std::deque<char> cur_dq2 = x;
  unsigned int cnt = 1;
  unsigned int n = x.size();
  int cur_val;
  unsigned int delta = 0;
  int bf_cnt;
  bool agn;
  int i;
  if (cur_dq[0] == '-') {
    return cur_dq;
  };
  while (cnt != x2) {
    for (i = delta; i < n; ++i) {
      cur_val = (int(cur_dq[i]) - 48) + (int(cur_dq2[i - delta]) - 48);
      if (cur_val > 9) {
        cur_val -= 10;
        cur_dq[i] = char(cur_val + 48);
        bf_cnt = 0;
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (i - bf_cnt > -1) {
            if (cur_dq[i - bf_cnt] == '9') {
              cur_dq[i - bf_cnt] = '0';
            } else {
              cur_dq[i - bf_cnt] = char(int(cur_dq[i - bf_cnt]) + 1);
              agn = 0;
            };
          } else {
            cur_dq.push_front('1');
            i += 1;
            delta += 1;
            n += 1;
            agn = 0;
          };
        };
      } else {
        cur_dq[i] = char(cur_val + 48);
      };
    };
    cnt += 1;
  };
  return cur_dq;
};

std::deque<char> multint2(std::deque<char> &x, std::deque<char> &x2) {
  std::deque<char> cur_dq = x;
  std::deque<char> cur_dq2 = x;
  std::deque<char> bf_dq = x2;
  int cnt = 0;
  std::deque<char> eval_dq = {'1'};
  unsigned int n = x.size();
  unsigned int n2 = x2.size();
  int cur_val;
  unsigned int delta = 0;
  int cur_eval;
  int bf_cnt;
  bool agn;
  int i;
  if (bf_dq[0] == '-' || cur_dq[0] == '-') {
    return cur_dq;
  };
  while (eval_dq != bf_dq) {
    for (i = delta; i < n; ++i) {
      cur_val = (int(cur_dq[i]) - 48) + (int(cur_dq2[i - delta]) - 48);
      if (cur_val > 9) {
        cur_val -= 10;
        cur_dq[i] = char(cur_val + 48);
        bf_cnt = 0;
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (i - bf_cnt > -1) {
            if (cur_dq[i - bf_cnt] == '9') {
              cur_dq[i - bf_cnt] = '0';
            } else {
              cur_dq[i - bf_cnt] = char(int(cur_dq[i - bf_cnt]) + 1);
              agn = 0;
            };
          } else {
            cur_dq.push_front('1');
            i += 1;
            delta += 1;
            n += 1;
            agn = 0;
          };
        };
      } else {
        cur_dq[i] = char(cur_val + 48);
      };
    };
    cur_eval = int(eval_dq[cnt]) - 48;
    if (cur_eval > 8) {
      eval_dq[cnt] = '0';
      agn = 1;
      bf_cnt = 0;
      while (agn) {
        bf_cnt += 1;
        if (cnt - bf_cnt > -1) {
          if (eval_dq[cnt - bf_cnt] == '9') {
            eval_dq[cnt - bf_cnt] = '0';
          } else {
            eval_dq[cnt - bf_cnt] = char(int(eval_dq[cnt - bf_cnt]) + 1);
            agn = 0;
          };
        } else {
          eval_dq.push_front('1');
          cnt += 1;
          agn = 0;
        };
      };
    }else {
      eval_dq[cnt] = char(cur_eval + 49);
    };
  };
  return cur_dq;
};

std::deque<char> multflt2(std::deque<char> &x, std::deque<char> &x2) {
  int i;
  int i2;
  unsigned int i3;
  int n = x.size();
  int n2 = x2.size();
  bool agn;
  int add_zero = 0;
  int cur_val;
  int intr_val;
  int bf_cnt;
  int delta = 0;
  unsigned int delta2 = 0;
  std::deque<char> divider;
  std::deque<char> rtn_dq;
  std::deque<char> rtn_dq2;
  std::deque<char> rtn_dq3;
  if (n > 2) {
    agn = 1;
    i = 0;
    while (agn) {
      rtn_dq.push_back(x[i]);
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
        rtn_dq.push_back(x[i]);
        i += 1;
      };
      if (x[0] != '0') {
        n -= 1;
      } else {
        n -= 2;
        rtn_dq.pop_front();
      };
    } else {
      rtn_dq = x;
    };
  } else {
    rtn_dq = x;
  };
  if (n2 > 2) {
    agn = 1;
    i = 0;
    while (agn) {
      rtn_dq3.push_back(x2[i]);
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
        rtn_dq3.push_back(x2[i]);
        i += 1;
      };
      if (x2[0] != '0') {
        n2 -= 1;
      } else {
        n2 -= 2;
        rtn_dq3.pop_front();
      };
    } else {
      rtn_dq3 = x2;
    };
  } else {
    rtn_dq3 = x2; 
  };
  for (i = 1; i < n + n2; ++i) {
    rtn_dq2.push_back('0');
  };
  cur_val = int(rtn_dq3[0] - 48) * int(rtn_dq[0] - 48);
  if (cur_val > 9) {
    rtn_dq2.push_back('0');
    n2 += 1;
    delta2 = 1;
  };
  for (i3 = 1; i3 < add_zero; ++i3) {
    rtn_dq2.push_back('0');
    n2 += 1;
    delta += 1;
  };
  for (i2 = delta + delta2; i2 < n2; ++i2) {
    for (i = 0; i < n; ++i) {
      cur_val = int(rtn_dq2[i2 + i - delta] - 48) + int(rtn_dq3[i2 - delta - delta2] - 48) * int(rtn_dq[i] - 48);
      if (cur_val < 10) {
        rtn_dq2[i2 + i - delta] = char(cur_val + 48);
      } else {
        intr_val = 1;
        while (cur_val - (intr_val + 1) * 10 > -1) {
          intr_val += 1;
        };
        cur_val -= intr_val * 10;
        rtn_dq2[i2 + i - delta] = char(cur_val + 48);
        cur_val = int(rtn_dq2[i2 + i - delta - 1] - 48) + intr_val;
        if (cur_val < 10) {
          rtn_dq2[i2 + i - delta - 1] = char(cur_val + 48);   
        } else {
          cur_val -= 10;
          rtn_dq2[i2 + i - delta - 1] = char(cur_val + 48);
          agn = 1;
          bf_cnt = 0;
          while (agn) { 
            bf_cnt += 1;
            if (i2 + i - delta - bf_cnt - 1 > - 1) {
              if (rtn_dq2[i2 + i - delta - bf_cnt - 1] == '9') {
                rtn_dq2[i2 + i - delta - bf_cnt - 1] = '0'; 
              } else {
                rtn_dq2[i2 + i - delta - bf_cnt - 1] = char(int(rtn_dq2[i2 + i - delta - bf_cnt - 1]) + 1); 
                agn = 0;
              };
            } else {
              delta2 += 1;
              i2 += 1;
              n2 += 1;
              rtn_dq2.push_front('1');
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
      rtn_dq2.insert(rtn_dq2.begin() + delta, '.');
    } else {
      rtn_dq2.push_front('.');
      rtn_dq2.push_front('0');
      for (i = delta; i < 0; ++i) {
        rtn_dq2.insert(rtn_dq2.begin() + 2, '0');
      };
    };
  };
  return rtn_dq2;
};

std::deque<char> multbase10(std::deque<char> x, unsigned int base = 9) {
  int i = 0;
  unsigned int idx_dec;
  unsigned int lst_i;
  unsigned int lst_n;
  unsigned int n = x.size();
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
          x.push_back('0');
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
        x.erase(x.begin(), x.begin() + i);
      };
    } else {
      for (i = 0; i < base; ++i) {
        x.push_back('0');
      };
    };
  } else {
   for (i = 0; i < base; ++i) {
      x.push_back('0');
    };
  };
  return x;
};

std::deque<char> divide2(std::deque<char> &x, std::deque<char> &x2, int nb_decimal = 5) {
  std::deque<char> divided = x;
  std::deque<char> divider = x2;
  std::deque<char> divider_base = divider;
  std::deque<char> lst_divider = divider;
  std::deque<char> eval_dq;
  std::deque<char> eval_dq2 = {'0'};
  std::deque<char> lst_eval_dq2 = {'0'};
  std::deque<char> intr_str;
  if (x[0] == '-' || x2[0] == '-') {
    return divided;
  };
  unsigned int n = x2.size();
  unsigned int n_divided = x.size();
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
    divider.erase(divider.begin() + dec2);
    divider_base = divider;
    lst_divider = divider;
  };
  if (is_dec1) {
    n_divided -= 1;
    idx_dec = n_divided - dec1;
    divided.erase(divided.begin() + dec1);
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
      divided.push_back('0');
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
        cur_val = int(eval_dq2[n2] - 48) + 1;
        if (cur_val > 9) {
          eval_dq2[n2] = '0';
          bf_cnt = 0;
          agn = 1;
          while (agn) {
            bf_cnt += 1;
            if (n2 - bf_cnt > -1) {
              if (eval_dq2[n2 - bf_cnt] == '9') {
                eval_dq2[n2 - bf_cnt] = '0';
              } else {
                eval_dq2[n2 - bf_cnt] = char(int(eval_dq2[n2 - bf_cnt]) + 1);
                agn = 0;
              };
            } else {
              eval_dq2.push_front('1');
              n2 += 1;
              agn = 0;
            };
          }
        } else {
          eval_dq2[n2] = char(cur_val + 48);
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
            divider.push_front('1');
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
    cur_val = int(eval_dq2[n2] - 48) + 1;
    if (cur_val > 9) {
      eval_dq2[n2] = '0';
      bf_cnt = 0;
      agn = 1;
      while (agn) {
        bf_cnt += 1;
        if (n2 - bf_cnt > -1) {
          if (eval_dq2[n2 - bf_cnt] == '9') {
            eval_dq2[n2 - bf_cnt] = '0';
          } else {
            eval_dq2[n2 - bf_cnt] = char(int(eval_dq2[n2 - bf_cnt]) + 1);
            agn = 0;
          };
        } else {
          eval_dq2.push_front('1');
          n2 += 1;
          agn = 0;
        };
      }
    } else {
      eval_dq2[n2] = char(cur_val + 48);
    };
  };
  for (char chr : eval_dq2) {
    eval_dq.push_back(chr);
  };
  post_dec = eval_dq.size();
  if (post_dec > 1) {
    bgn = 1;
  };
  divided.push_back('0');
  divider.push_back('0');
  n_divided += 1;
  n += 1;
  cnt += 1;
  eval_dq.push_back('.');
  for (int i2 = 0; i2 < nb_decimal; ++i2) {
    eval_dq2 = {'0'};
    agn2 = 1;
    n2 = 0;
    while (agn2) {
      if (n > n_divided) {
        divider = lst_divider;
        eval_dq2 = lst_eval_dq2;
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
          eval_dq2 = lst_eval_dq2;
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
                divider.push_front('1');
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
      cur_val = int(eval_dq2[n2] - 48) + 1;
      lst_eval_dq2 = eval_dq2;
      eval_dq2[n2] = char(cur_val + 48);
    };
    for (char chr : eval_dq2) {
      eval_dq.push_back(chr);
    };
    divided.push_back('0');
    divider.push_back('0');
    n += 1;
    n_divided += 1;
    cnt += 1;
  };
  if (delta_integ > -1) {
    for (i = bgn; i <= delta_integ; ++i) {
      eval_dq.push_front('0');
      post_dec += 1;
    };
    for (i = -1; i < delta_integ; ++i) {
      eval_dq[post_dec] = eval_dq[post_dec - 1];
      post_dec -= 1;
      eval_dq[post_dec] = '.';
    };
  } else if (delta_integ < -1) {
    delta_integ *= -1;
    delta_integ -= 1;
    for (i = 0; i < delta_integ; ++i) {
      eval_dq.push_back('0');
      eval_dq[i + 1 + bgn] = eval_dq[i + 2 + bgn];
      eval_dq[i + 2 + bgn] = '.';
    };
  };
  return eval_dq;
};

std::deque<char> dividebase10_2(std::deque<char> x, int divider = 9) {
  int n = x.size();
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
        x.erase(x.begin() + idx_dec);
        x.push_front('.');
        x.push_front('0');
        x.insert(x.begin() + 2, divider - idx_dec, '0');
      };
    } else {
       if (n - divider > 0) {
        x.insert(x.begin() + n - divider, '.');
      } else {
        x.push_front('.');
        x.push_front('0');
        x.insert(x.begin() + 2, divider - n, '0');
      }; 
    };
  } else {
    return {};
  };
  return x;
};

std::string dqtostr(std::deque<char> &x) {
  std::string cur_str = "";
  for (char i : x) {
    cur_str.push_back(i);
  };
  return cur_str;
};

