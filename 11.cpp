#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool cmp(const pair<int, int>& t1, const pair<int, int>& t2)
{
	return t1.first > t2.first;
}
	
class Solution {
public:
	

		
    int maxArea(vector<int>& height) {
  		vector<pair<int,int>/**/> line;
  		int len = height.size();
		
		for (int i = 0; i < len; i++)
			line.push_back(pair<int,int>(height[i],i));
		
		sort(line.begin(), line.end(), cmp);
		
		int min, max;
		min = line[0].second;
		max = line[0].second;
		int ans = 0;
		
		for (int i = 1; i < len; i++)
		{
			int width1 = abs(line[i].second - min);
			int width2 = abs(line[i].second - max);
			int width = width1 > width2 ? width1 : width2;
			
			//update min max
			if (line[i].second < min)
				min = line[i].second;
			if (line[i].second > max)
				max = line[i].second;
			
			int tmp_area = width * line[i].first;
			if (tmp_area > ans)
				ans = tmp_area;
		}
		
		return ans;
    }
};


int main(int argc, char* argv[])
{
	vector<int> height;
	for (int i = 0; i < 5; i++)
	{
		int tmp;
		cin >> tmp;
		height.push_back(tmp);
	}
	
	Solution m_solution;
	
	cout <<m_solution.maxArea(height) << endl;

	system("PAUSE");
	return 0;
}
