#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		int i = 0;
		char tmp;
		while ((tmp = s[i]) != '\0') {
			switch (tmp) {
			case '(':
			case '[':
			case '{': 
				st.push(tmp);
				break;
			case ')':
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
					return false;
				break;
			case ']':
				if (!st.empty() && st.top() == '[')
					st.pop();
				else
					return false;
				break;
			case '}':
				if (!st.empty() && st.top() == '{')
					st.pop();
				else
					return false;
				break;
			default:
				break;
			}
			i++;
		}
		return st.empty();
	}
};


int main() {
	string s = ")))";
	char tmp1 = s[0];
	Solution sln;
	bool res = sln.isValid(s);
	cout << "result:" << res << endl;
	return 0;
}
