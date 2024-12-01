#include <iostream>

//@L Addition
//@L2 Int

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
            cur_str = "1" + cur_str;
            bf_str = "1" + bf_str;
            i += 1;
            sizen += 1;
            agn = 0;
          };
        };
      } else {
        cur_str[i] = char(int(cur_val) + 48);
      };
    };
  } else {
    return "";
  };
  return cur_str;
};

//@L Substraction
//@L2 Int

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
  int i;
  if (n > n2) {
    sizen = n;
    for (i = n2; i < n; ++i) {
      bf_str = "0" + bf_str;
    };
  } else {
    sizen = n2;
    for (i = n; i < n2; ++i) {
      cur_str = "0" + cur_str;
    };
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
