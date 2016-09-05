#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;


class Solution {
public:
    int reverse(int x) {
    	if (x == 0)
    		return 0;
        int digit_num = 0; 
        int div = 1;
        int tmpx = x;
        while (x != 0)
        {
			x = x / 10;
			digit_num++;
		}
		div = pow(10, digit_num-1);
		int div1 = 1;
		int ans = 0;
		x = tmpx;
		int min = 0x80000000;
		int max = 0x7fffffff;
		for (int i = 0; i < digit_num; i++)
		{
			
			double tmp = ((double)x/div)*div1;
			if (tmp > max || tmp < min)
				return 0;
			
			ans += (x / div)*div1;
			x = x % div;
			div /= 10;
			div1 *= 10;
			
			if ((tmpx > 0 && ans < 0) || (tmpx < 0 && ans > 0))
				return 0;
		}
		
		return ans;
    }
};


int main(int argc, char* argv[])
{
	Solution m_solution;
	
	int x;
	cin >> x;
	
	cout << m_solution.reverse(x) << endl;
	system("PAUSE");
	return 0;
}
