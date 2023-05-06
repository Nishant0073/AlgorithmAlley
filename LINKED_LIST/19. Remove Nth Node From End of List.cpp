// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 


Two Pointer approch

1 2 3 4 5 2nd
f
1 2 3 4 5
f
1 2 3 4 5
f
1 2 3 4 5
s f

1 2 3 4 5
s f

1 2 3 4 5
s f

s->next = s->next->next;

Approach
Complexity
Time complexity: O(N) 1 2 3 4 5    2nd
 f f f f f
 s s s


 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast  = head;
        ListNode* slow = head;

        while(n--)
            fast = fast->next;
        
        if(!fast)
            return head->next;

        while(fast->next!=NULL)
        {
            fast = fast->next;
            slow = slow->next; 
        }

        slow->next = slow->next->next;
        return head;


    }
};


