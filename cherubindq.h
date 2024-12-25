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

std::string dqtostr(std::deque<char> &x) {
  std::string cur_str = "";
  for (char i : x) {
    cur_str.push_back(i);
  };
  return cur_str;
};
