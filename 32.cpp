#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <deque>
#include <cstring>

using namespace std; 

class State
{
public:
	int lr;//0 - l 1-r
	int count;
	State()
	{
		lr = 0;
		count = 0;
	}
};

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<State, vector<State> > buffer;
        int ptr = 0;
        int s_len = s.length();
        for (;ptr < s_len; ptr++)
        	if (s[ptr] == '(')
        		break;
        int sub_max = 0;
        int ans = 0;
        while (ptr < s_len)
        {
			if (s[ptr] == '(')
			{
				State tmp;
				tmp.count = sub_max;
				sub_max = 0;
				buffer.push(tmp);
			}
			else if (s[ptr] == ')')
			{
				if (buffer.empty())
				{
					sub_max = 0;
				}
				else
				{
					State tmp = buffer.top();
					if (tmp.lr == 0)
					{
						buffer.pop();
						sub_max += tmp.count + 2;
						if (ans < sub_max)
							ans = sub_max;
					}
				}				
			}
			ptr++;
		}
		
		return ans;
    }
};

int main(int argc, char* argv[])
{
	string s;
	cin >> s;
	Solution m_solution;
	cout << m_solution.longestValidParentheses(s) << endl;
	system("PAUSE");
	return 0; 
	
}
