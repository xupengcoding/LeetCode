#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

    	int len = s.length();
    	
    	stack<char> tmp;
    	
    	for (int i = 0; i < len; i++)
    	{    		
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				tmp.push(s[i]);
			else
			{
				if (tmp.empty())
					return false;
				
				char c = tmp.top();
				if ((s[i] == ')' && c != '(') || (s[i] == ']' && c != '[') || (s[i] == '}' && c != '{'))
					return false;
				tmp.pop();
			}
		}
		
		if (!tmp.empty())
			return false;
		else
			return true;
    }
};

int main(int argc, char* argv[])
{
	string str;
	cin >> str;
	Solution m_solution;
	cout << m_solution.isValid(str) << endl;
	system("PUASE");
	return 0;
}
