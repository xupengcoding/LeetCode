#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	
    	//special
    	if (x < 0)
    		return false;
    	
		if (x < 10)
    		return true;
    	
    	
        int digit_num = 0;
        int tmpx = x;
        while (tmpx)
        {
			tmpx /= 10;
			digit_num++;
		}
		cout << "digit_num " << digit_num << endl; 
		int half = digit_num/2;
		
		int right = x % ((int)pow(10, half));
		int left = x/((int)pow(10,half));
		if (digit_num % 2 != 0)
			left /= 10;
			
		cout << left << " " << right << endl;
		
		int div1 = pow(10,half-1);
		int div2 = 10;
		
		
		while (half)
		{
			int pos_left = left / div1;
			int pos_right = right % div2;
			left = left % div1;
			right = right / div2;
			div1/=10;
			//div2*=10;
			if (pos_left != pos_right)
				return false;
			half--;
		}
		
		return true;
		
    }
};

int main(int argc, char* argv[])
{
	int x;
	cin >> x;
	Solution m_solution;
	cout << m_solution.isPalindrome(x) << endl;
	
	system("PAUSE");
	return 0;
}
