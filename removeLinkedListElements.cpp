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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *t = head, *prev = NULL;
        if(head == NULL)
            return head;
        while(t && t->val == val){
            t = t->next;
        }
        head = t;
        while(t){
            if(t->next && t->next->val == val){
                t->next = t->next->next;
            }
            else{
                t = t->next;
            }
        }
        return head;
    }
};
