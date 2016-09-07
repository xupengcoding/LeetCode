#include <iostream>
#include <cstdlib>
#include <>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *merge = NULL;
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        ListNode *ans = NULL;
        
       	while (ptr1 != NULL && ptr2 != NULL)
		{
			if (ptr1->val < ptr2->val)
			{
				if (merge == NULL)
				{
					merge = ptr1;
					ans = merge;
				}
				else
				{
					merge->next = ptr1;
					merge = merge->next;
				}
				ptr1 = ptr1->next;
				//merge = merge->next;
			}
			else
			{
				if (merge == NULL)
				{
					merge = ptr2;
					ans = merge;
				}
				else
				{
					merge->next = ptr2;
					merge = merge->next;
				}
				ptr2 = ptr2->next;
				//merge = merge->next;
			}
		}
		
		while (ptr1 != NULL)
		{
			if (merge == NULL)
			{
				merge = ptr1;
				ans = merge;
			}
			else
			{
				merge->next = ptr1;
				merge = merge->next;
			}
			ptr1 = ptr1->next;
			//merge = merge->next;
		}	
		
		while (ptr2 != NULL)
		{
			if (merge == NULL)
			{
				merge = ptr2;
				ans = merge;
			}
			else
			{
				merge->next = ptr2;
				merge = merge->next;
			}
			ptr2 = ptr2->next;
			//merge = merge->next;
		}
		
		return ans;

    }
};
