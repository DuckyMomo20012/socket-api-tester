#include <helpers.h>

string headerToString(vector<vector<string>> headers) {
  stringstream res;
  for (auto header : headers) {
    if (header.size() > 1) {
      res << header[0] << ":" << header[1] << "\r\n";
    }
    res << header[0] << "\r\n";
  }
  return res.str();
}

pair<string, string> headerParse(string header) {
  int pos = header.find(":", 0);
  string key = header.substr(0, pos);
  string value = ltrim(header.substr(pos + 1));
  pair<string, string> res = make_pair(key, value);
  return res;
}
