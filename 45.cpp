#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        //int min_step[]
		int next_end = 0;
		int cur_end = nums[0];
		int step = 1;
		
		int len = nums.size();
		next_end = cur_end;
		
		if (len == 1 || len == 0)
			return 0;
		
		if (cur_end >= len-1)
			return 1;
		
		
		
		for (int i = 1; i < len-1; i++)
		{
			if (i <= cur_end)
			{
				if ( i+nums[i] > next_end)
					next_end = i+nums[i];
			}
			if (i == cur_end)
			{
				cur_end = next_end;
				step++;
				if (cur_end >= len-1)
					return step;
			}
			
		}
		return step;
	}
		
};


int main(int argc, char *argv[])
{
	vector<int> nums(4);
	for (int i = 0; i < 4; i++)
		cin >> nums[i];
	
	Solution m_solution;
	cout << m_solution.jump(nums) << endl;
	system("PAUSE");
	return 0;
}

