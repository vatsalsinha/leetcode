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
    ListNode *detectCycle(ListNode *head) {
        // 1. detect whether a cycle exists
        // 2. traverse until slow and fast point to the same element;
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
       if(!fast || !fast->next) 
           return NULL;
        
        slow = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
