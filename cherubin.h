//@L Addition
//@L2 Int

//@T addint
//@U std::string addint(std::string &x, std::string &x2)
//@X
//@D Returns the result as a std string.
//@A x : is the first int
//@A x2 is the second int
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
  std::cout << "cnt: " << cnt << "\n";
  std::cout << "cur_str: " << cur_str << "\n";
  if (cur_str[0] != '-') {
    for (int i = cnt; i < sizen; ++i) {
      cur_val = (int(bf_str[i - cnt]) - 48) + (int(cur_str[i]) - 48);
      std::cout << cur_val << " cur_val\n";
      std::cout << cur_str << " cur_str \n";
      std::cout << i << " i\n";
      if (cur_val >= 10) {
        cur_val -= 10;
        std::cout << cur_val << " cur_val2\n";
        cur_str[i] = char(cur_val + 48);
        bf_cnt = 0;
        std::cout << "WTF: " << i - bf_cnt << "\n";
        agn = 1;
        while (agn) {
          std::cout << "ICI\n";
          bf_cnt += 1;
          if (i - bf_cnt > -1) {
            if (int(cur_str[i - bf_cnt]) - 48 > 8) {
              cur_str[i - bf_cnt] = '0';
              agn = 1;
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
        cur_str[i] = char(cur_val + 48);
      };
    };
  };
  return cur_str;
};
