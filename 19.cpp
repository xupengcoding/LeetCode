#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
 		ListNode *pre, *suc, *cur;
 		int cur_pos = 0;
 		pre = NULL;
 		cur = head;
 		suc = head->next;
 		
 		ListNode *ptr = head;
		for (int i = 0; i < n-1; i++)
			ptr = ptr->next;
		
		while (ptr->next != NULL)
		{
			pre = cur;
			cur = suc;
			suc = suc->next;
			ptr = ptr->next;
		}
		
		if (pre == NULL)
			return suc;
		
		pre->next = suc;
		return head;
    }
};

