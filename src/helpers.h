#ifndef _HELPERS_H_
#define _HELPERS_H_
#include <iostream>
#include <sstream>
#include <string>
#include <utils.h>
#include <vector>
using namespace std;

string headerToString(vector<vector<string>> headers);
pair<string, string> headerParse(string header);

#endif
