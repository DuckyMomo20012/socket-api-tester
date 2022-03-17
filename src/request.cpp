#include "request.h"

string get(string uri, vector<vector<string>> headers, string body) {
  stringstream request;
  request << "GET " + uri + " HTTP/1.1" + "\r\n";
  request << headerToString(headers);
  request << "\r\n\r\n";
  request << body;
  return request.str();
}
