#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int len1 = nums1.size();
    	int len2 = nums2.size();
    	
    	if ((len1 + len2) % 2 == 0)
		{
			int median = (len1 + len2)/2;
			return findKthSortedArrays(nums1, nums2, median);
		} 
		else
		{
			int median1 = (len1 + len2)/2;
			int median2 = median1 + 1;
			
			return  (findKthSortedArrays(nums1, nums2, median1) + findKthSortedArrays(nums1, nums2, median2))/2.0; 
		}
	    
    }
    
    double findKthSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) {
		int half = k/2;
		int resi = k - half;
		int start1, start2;
		start1 = start2 = 0;
		int len1 = nums1.size();
		int len2 = nums2.size();
		
		while (resi > 0)
		{
			if (start1 == len1)
			{
				return nums2[start2+resi-1];
			}
			
			if (start2 == len2)
			{
				return nums1[start1+resi-1];
			}
			
			int p1 = half + start1 > len1 ? (len1-1) : (half+start1-1);
			int p2 = half + start2 > len2 ? (len2-1) : (half+start2-1);
			
			if (nums1[p1] <= nums2[p2])
			{
				start1 = p1+1;
				int tmp = half;
				half = resi/2;
				resi = resi - tmp;
				if (resi == 0)
					return nums1[p1];
			}
			else
			{
				start2 = p2 + 1;
				int tmp = half;
				half = resi/2;
				resi = resi - tmp;
				if (resi == 0)
					return nums2[p2];
			}
		}
		
		return -1;
	}
    
};
