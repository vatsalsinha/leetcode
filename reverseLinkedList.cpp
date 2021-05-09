/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ListNode *curr = head;
        // ListNode *prev = NULL, *next = NULL;
        // while(curr != NULL){
        //     next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        // head = prev;
        // return head;
        if(head == NULL || head->next == NULL)
            return head;
        else{
            ListNode *p = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return p;
        }
    }
};
