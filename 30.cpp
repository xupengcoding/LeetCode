#include <iostream>
#include <cstdlib>
#include <vector>
#include <dequeue>
#include <stack>
#include <cstring>

using namespace std; 

class State
{
public:
	int lr;//0-l 1-r
	int valid_len;
	
	State()
	{
		lr = 0;
		valid_len = 0;
	}
	
	State(int _lr, int _valid_len)
	{
		valid_len = _valid_len;
		lr = _lr;
	}
	
	State(int _lr)
	{
		lr = _lr;
		valid_len = 0;
	}
}

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<State, vector<State>> buffer;
        
        int ans = 0;
        int s_len = s.length();
        
        int start_pos = 0;
        for (; start_pos < s_len; start_pos++)
        	if (s[start_pos] == '(')
        		break;
        
        while (start_pos < s_len)
        {
			
		}
    }
};
