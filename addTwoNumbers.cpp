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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode (0);
        ListNode *curr = res;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            int val1 = l1 != NULL ? l1->val : 0;
            int val2= l2!= NULL ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum/10;
            ListNode *newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = curr->next;
            l1 = l1 != NULL ? l1->next : NULL;
            l2 = l2 != NULL ? l2->next : NULL;
        }
        if(carry > 0){
            ListNode *newNode = new ListNode(carry);
            curr->next = newNode;
        }
        return res->next;
    }
};
