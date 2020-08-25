#pragma once
#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
	/**
	*
	* @param tokens string×Ö·û´®vector
	* @return intÕûĞÍ
	*/
	int evalRPN(vector<string>& tokens) {
		// write code here
		if (tokens.empty())
			return 0;
		stack<int> si;
		for (int i = 0; i<tokens.size(); i++) {
			if (tokens[i] != "+" && tokens[i] != "-"&&tokens[i] != "*"&&tokens[i] != "/") {
				si.push(stoi(tokens[i]));
			}
			else {
				int b = si.top();
				si.pop();
				int a = si.top();
				si.pop();
				int v;
				if (tokens[i] == "+") {
					v = a + b;
				}
				else if (tokens[i] == "-") {
					v = a - b;
				}
				else if (tokens[i] == "*") {
					v = a*b;
				}
				else {
					v = a / b;
				}
				si.push(v);
			}
		}
		return si.top();
	}
};
