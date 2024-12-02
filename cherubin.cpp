#include <iostream>
#include "cherubin.h"

std::string subsflt(std::string &x, std::string &x2) {
  std::string cur_str = x;
  std::string bf_str = x2;
  const unsigned int bf_cn = x.length();
  const unsigned int bf_n2 = x2.length();
  unsigned int sizen;
  int i;
  if (n >= n2) {
    sizen = n;
    for (i = n2; i < n; ++i) {
      bf_str = "0" + bf_str;
    };
  } else {
    return "";
  };
  int cur_val;
  int bf_cnt;
  bool agn;
  int cnt2;
  if (bf_str[0] == '-') {
    return "";
  };
  if (cur_str[0] != '-') { 
    for (i = 0; i < sizen; ++i) {
      cur_val = (int(cur_str[i]) - 48) - (int(bf_str[i]) - 48);
      if (cur_val < 0) {
        cur_val = 10 + cur_val;
        cur_str[i] = char(int(cur_val) + 48);
        bf_cnt = 0;
        agn = 1;
        while (agn) {
          bf_cnt += 1;
          if (i - bf_cnt > -1) {
            if (int(cur_str[i - bf_cnt]) - 48 < 1) {
              cur_str[i - bf_cnt] = '9';
            } else {
              cur_str[i - bf_cnt] = char(int(cur_str[i - bf_cnt]) - 1);
              agn = 0;
            };
          } else {
            cur_str[i] = char(int(10 - cur_val) + 48);
            i += 1;
            sizen += 1;
            cur_str = "-" + cur_str;
            bf_str = "-" + bf_str;
            agn = 0;
          };
        };
      } else {
        cur_str[i] = char(cur_val + 48);
      };
      cnt2 = 0;
      while (cur_str[cnt2] == '0' & cnt2 <= i & cnt2 + 1 < sizen) {
        sizen -= 1;
        i -= 1;
        cnt2 += 1;
      };
      if (cnt2 > 0) {
        cur_str = cur_str.substr(cnt2, cur_str.length());
        bf_str = bf_str.substr(cnt2, cur_str.length());
      };
    };
  } else {
    return "";
  };
  return cur_str;
};

int main() {
  std::string x = "2625.7608";
  std::string x2 = "26.564499";
  std::string xb = "2625";
  std::string xb2 = "615";
  std::cout << subsflt(xb, xb2) << "\n";
  return 0;
};


