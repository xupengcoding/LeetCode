#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <stack>
#include <utility>
#include <memory.h>

using namespace std; 

class Mark 
{
public:
	int row[9];
	int col[9];
	int rect[9];
	int next;
	int b[81];
	int count;
	Mark()
	{
		//row = col = rect = 0;
		memset(row, 0, sizeof(int)*9);
		memset(col, 0, sizeof(int)*9);
		memset(rect, 0, sizeof(int)*9);
		memset(b, 0, sizeof(int)*81);
		next = -1;
		count = 0;
	}
};

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
		stack<Mark, vector<Mark> > state;
		
		Mark init;	
		//read the board;
		vector<pair<int, int> > blank;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					int num = board[i][j] - '0';
					init.row[i] |= (1 << num);
					init.col[j] |= (1 << num);
					int rec_id = (i/3)*3+(j/3);
					init.rect[rec_id] |= (1 << num); 	
					//init.b[i*9+j] = num;
				}
				else
				{
					blank.push_back(pair<int,int>(i,j));
				}
			}
		}
		
		init.next = 0;
		init.count = 0;
		state.push(init);
		
		int blank_len = blank.size();
		
		while (!state.empty())
		{
			Mark tmp = state.top();
			state.pop();
			int start_pos = tmp.next;
			if (start_pos >= blank_len)
				continue;
			for (int i = start_pos; i < start_pos+1; i++)
			{
				int row_id = blank[i].first;
				int col_id = blank[i].second;
				int rec_id = (row_id/3)*3 + (col_id/3);
				
				int mark = tmp.row[row_id] | tmp.col[col_id] | tmp.rect[rec_id];
				//check 0-9
				for (int j = 1; j <= 9; j++)
				{
					if ((mark & (1<<j)) == 0)
					{
						//find a state
						//Mark next_state;
						tmp.row[row_id] |= (1 << j);
						tmp.col[col_id] |= (1 << j);
						tmp.rect[rec_id] |= (1 << j);
						tmp.next =  i+1;
						int pre = tmp.b[row_id*9+col_id];
						tmp.b[i] = j;
						tmp.count++;
						if (tmp.count == blank_len)
						{
							for (int k = 0; k < blank_len; k++)
								board[blank[k].first][blank[k].second] = tmp.b[k]+'0'; 
							return;
						}
						//
						state.push(tmp);
						//reset state
						tmp.row[row_id] &= (~(1<<j));
						tmp.col[col_id] &= (~(1<<j));
						tmp.rect[rec_id] &= (~(1<<j));
						tmp.next = start_pos;
						tmp.b[i] = pre;
						tmp.count--;
					}
					
				}
			}
		}
		
		return;
    }
    
};

int main(int argc, char* argv[])
{
	vector<vector<char> > board(9, vector<char>(9));
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			char tmp;
			cin >> tmp;
			board[i][j] = tmp;
		}
	
	Solution m_solution;
	m_solution.solveSudoku(board);
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << board[i][j];
		cout << endl;
	}
	
	system("PAUSE");
	return 0;
}
