#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	//find idx
		//int pivot;
		int len = nums.size();
		if (len == 1)
		{
			if (target == nums[0])
				return 0;
			else
				return -1;
		}
		if (len == 2)
		{
			if (target == nums[0])
				return 0;
			else if (target == nums[1])
				return 1;
			else
				return -1;
		}
		int left = 0;
		int right = len-1;
		int mid = (left+right)/2;
		int pivot = -2;
		if (nums[0] < nums[len-1])
			pivot = -1;
		while (right > left+1 && pivot != -1)
		{	
			if (nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1])
			{	
				pivot = mid-1;
				break;
			}
			
			if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
			{
				pivot = mid;
				break;
			}
			
			if (nums[left] > nums[mid])
			{
				right = mid;
				mid = (left + right)/2;
			}
			
			if (nums[right] < nums[mid])
			{
				left = mid;
				mid = (left + right)/2;
			}
		}    
		
		//binary search
		left = 0;
		right = len-1;
		mid = (left+right)/2;
		while (left < right)
		{
			mid = (left+right)/2;
			
			int convert_left = convertIdx(pivot, left, len);
			int convert_right = convertIdx(pivot, right, len);
			int convert_mid = convertIdx(pivot, mid, len); 
			
			if (left+1 == right)
			{
				if (nums[convert_left] == target)
					return convert_left;
				if (nums[convert_right] == target)
					return convert_right;
				return -1;
			}
			
			if (nums[convert_mid] == target)
				return convert_mid;
			
			if (nums[convert_mid] < target)
			{
				left = mid;
				mid = (left+right)/2;
			}
			
			if (nums[convert_mid] > target)
			{
				right = mid;
				mid = (left+right) / 2;
			}
		}
		
		return -1;
    }
    
    int convertIdx(int pivot,int idx, int len)
    {
		return (idx+pivot+1)%len;
	}
};

int main(int argc, char* argv[])
{
	vector<int> nums(7, 0);
	for (int i = 0; i < 7; i++)
		cin >> nums[i];
	
	Solution m_solution;
	cout << m_solution.search(nums, 2) << endl;
	
	system("PAUSE");
	return 0;
}
