#include "utils.h"
const string WHITESPACE = "";

string ltrim(string s) {
  string_view tmp = s;
  tmp.remove_prefix(min(tmp.find_first_not_of(" "), tmp.size()));
  string res = string{tmp};
  return res;
}
