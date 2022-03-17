#ifndef _REQUEST_H_
#define _REQUEST_H_
#include "helpers.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string get(string uri,
           vector<vector<string>> headers = vector<vector<string>>{},
           string body = "");

#endif
