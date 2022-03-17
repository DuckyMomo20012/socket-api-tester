#include "helpers.h"

string headerToString(vector<vector<string>> headers) {
  stringstream res;
  for (auto header : headers) {
    if (header.size() > 1) {
      res << header[0] << ":" << header[1] << "\r\n";
      continue;
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

void writeFile(string fileName, string buffer, ios_base::openmode mode) {
  fstream writeFile;
  writeFile.open(fileName, ios::out | mode);
  if (writeFile.is_open()) {
    writeFile << buffer;
  } else {
    string errMsg = "Cannot open file: " + fileName + "\n";
    throw invalid_argument(errMsg);
  }
  writeFile.close();
}

void readFile(string fileName, string &buffer) {
  fstream readFile;
  readFile.open(fileName, ios::in);
  readFile >> buffer;
  readFile.close();
}
