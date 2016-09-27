#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;


// Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
 bool cmp(const Interval& arg1, const Interval& arg2)
 {
 	return arg1.start < arg2.start;
 }
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), cmp);
		
		vector<Interval> merge_intervals;
		
		int len = intervals.size();
		if (len == 0)
			return merge_intervals;
		
		int tmp_start, tmp_end;
		tmp_start = intervals[0].start;
		tmp_end = intervals[0].end;
		//if (len == 1)
		//{
			//merge_intervals.push_back(intervals[0]);
			
		//}
		for (int i = 1; i < len; i++)
		{
			if (intervals[i].start <= tmp_end)
			{
				if (intervals[i].end > tmp_end)
					tmp_end = intervals[i].end;
			}
			else
			{
				merge_intervals.push_back(Interval(tmp_start, tmp_end));
				tmp_start = intervals[i].start;
				tmp_end = intervals[i].end;
			}
		}
		
		merge_intervals.push_back(Interval(tmp_start, tmp_end));
		
		return merge_intervals;
    }
};

int main(int argc, char *argv[])
{
	return 0;
}
