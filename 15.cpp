#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>

using namespace std;


class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        
        int len = nums.size();
		if (len < 3)
		{
			vector<vector<int> > ans;
			return ans;
		}
		sort(nums.begin(), nums.end());
		//
    	int start = nums[0];
    	int end = nums[len-1];
    	int range = end - start + 1;
    	int *mark = new int[range];
    	memset(mark, 0, sizeof(int)*range);
    	
    	for (int i = 0; i < len; i++)
    		mark[nums[i]-start] += 1;
    		
    	vector<vector<int> > ans;
    	for (int i = 0; i < len; i++)
    	{
    		if (i > 0)
    		{
				if (nums[i] == nums[i-1])
					continue;
			}
    		
			for (int j = i+1; j < len; j++)
			{
				if (j == len-1)
					continue;
				if ( j > i+1)
				{
					if(nums[j] == nums[j-1])
						continue; 
				} 
				int a = nums[i];
				int b = nums[j];
				int c = 0-a-b;
				
				if (c < b)
					continue;
				if (c > nums[len-1])
					continue;
					
				mark[a-start]--;
				mark[b-start]--;
				if (mark[c-start] > 0)
				{
					vector<int> tmp;
					tmp.push_back(a);
					tmp.push_back(b);
					tmp.push_back(c);
					//ans.push_back(tmp);
					ans.push_back(tmp);
				}
				mark[a-start]++;
				mark[b-start]++;
			}
		}
		
		//unique
		
		//set<vector<int> >::iterator iter = ans.begin();
		//vector<vector<int> > vec_ans;
		
		//for (;iter != ans.end(); iter++)
			//vec_ans.push_back(*iter);
		
		delete mark;
		return ans;
	}
    
};

int main(int argc, char* argv[])
{
	vector<int> nums;
	
	for (int i = 0; i < 4; i++)
	{
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	
	Solution m_solution;
	
	vector<vector<int> > ans = m_solution.threeSum(nums);
	
	int ans_len = ans.size();
	for(int i = 0; i < ans_len; i++)
	{
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
	}
	
	system("PAUSE");
	return 0;
}
