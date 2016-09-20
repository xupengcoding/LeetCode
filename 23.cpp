#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std; 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 struct ListNode{
 	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {} 
 };
 
 class ListNodeCmp{
 	public:
 		bool operator()(const ListNode* arg1, const ListNode* arg2){
		 	return arg1->val > arg2->val;
		 }
 };

 
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		int lists_num = lists.size();
		int tmp_len = lists_num;
		
		priority_queue<ListNode*, vector<ListNode*>, ListNodeCmp> buffer;
		
		for (int i = 0; i < tmp_len; i++)
		{
		    if (lists[i] == NULL)
		        lists_num--;
		    
			if (lists[i] != NULL)
			{
				buffer.push(lists[i]);
				lists[i] = lists[i]->next;
			}
		} 
		
		
		ListNode* merge_head = NULL;
		ListNode* merge_end = NULL;  
		
		while (lists_num)
		{
			ListNode* top_node = NULL;
			
			if (!buffer.empty())
			{
				top_node = buffer.top();
				buffer.pop();
			}
			
			if (merge_end == NULL)
				merge_end = top_node;
			else
				{
					merge_end->next = top_node;
					merge_end = merge_end->next;
				}
			if (merge_head == NULL)
				merge_head = merge_end;
			
			//top_node = top_node->next;
			if (top_node->next == NULL)
				lists_num--;
			else
				buffer.push(top_node->next);
		}
		
		while (!buffer.empty())
		{
			ListNode* top_node = NULL;
			
	
			top_node = buffer.top();
			buffer.pop();
		
			
			if (merge_end == NULL)
				merge_end = top_node;
			else
				{
					merge_end->next = top_node;
					merge_end = merge_end->next;
				}
			if (merge_head == NULL)
				merge_head = merge_end;		
		}
		
		return merge_head;
	}
};

int main(int argc, char *argv[])
{
	
}
