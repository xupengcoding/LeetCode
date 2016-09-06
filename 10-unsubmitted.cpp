#include <iostream>
#include <cstdlib>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		vector<pair<char, int> > elem;
		int len_p = p.size();
		for (int i = 0; i < len_p; i++)
		{
			if (i < len_p-1 & p[i] == '*')
			{
				elem.push_back(pair<char, int>(p[i], 1));
				i++;
			}
			else
			{
				elem.push_back(pair<char, int>(p[i], 0));
			}
		} 
		
		queue<pair<string, int> > pattern;
		
		pair<char, int> tmp = elem[0];
		string tmp_pattern = "";
		pattern.push(pair<string, int>(tmp_pattern, 0));
		int elem_size = elem.size();
		bool match = false;
		while(!pattern.empty())
		{
			pair<string, int> tmp_pattern = pattern.front();
			pattern.pop();
			if (tmp_pattern == s)
				return true;
			if (tmp_pattern.second == elem_size)
				continue;
			
			if (elem[tmp_pattern.second].second == 0)
			{	
				if (elem[tmp_pattern.second].first == '.')
					tmp_pattern.first += s[tmp_pattern.first.size()];
				else
					tmp_pattern.first += elem[tmp_pattern.second].first;
				
				tmp_pattern.second++;
				int tmp_len = tmp_pattern.first.size();
				if (s.substr(0, tmp_len) != tmp_pattern.first)
					continue;
				pattern.push(tmp_pattern); 
			}
			else//*
			{
				//still use *
				if (elem[tmp_pattern.second].first == '.')
					tmp_pattern.first += s[tmp_pattern.first.size()];
				else
					tmp_pattern.first += elem[tmp_pattern.second].first;
				
				int tmp_len = tmp_pattern.first.size();
				if (s.substr(0, tmp_len) == tmp_pattern.first)
					pattern.push(tmp_pattern);
				
				//no use *
				tmp_pattern.first = tmp_pattern.first.substr(0, tmp_pattern.first.size()-1);
				tmp_pattern.second++;
				pattern.push(tmp_pattern);
			}
		}
		
		return false;
		
    }
};
