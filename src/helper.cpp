#include <helper.h>
#include <sstream>

string headerToString(vector<vector<string>> headers) {
  stringstream res;
  for (auto header : headers) {
    res << header[0] << ":" << header[1] << "\r\n";
  }
  return res.str();
}
