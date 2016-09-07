#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > pattern(n);
        if (n == 0)
        	return pattern[0];
        pattern[0].push_back("()");
        
        for (int i = 2; i <= n; i++)
        {
			//first case
			int pre_len = pattern[i-1-1].size();
			for (int j = 0; j < pre_len; j++)
			{
				pattern[i-1].push_back("("+pattern[i-1-1][j]+")");
			}
			for (int l = 1; l < i; l++)
			{
				int r = i-l;
				int l_len = pattern[l-1].size();
				int r_len = pattern[r-1].size();
				
				for (int il = 0; il < l_len; il++)
				{
					for (int ir = 0; ir < r_len; ir++)
					{
						pattern[i-1].push_back(pattern[l-1][il]+pattern[r-1][ir]);
					}
				}
			}
		}
		
		return pattern[n-1];
    }
};

int main(int argc, char *argv[])
{
	
}
