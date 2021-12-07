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
    int getDecimalValue(ListNode* head) {
        int num = 0, p = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            int n = tmp->val;
            num = n + (num<<1);
            tmp = tmp->next;
        }
        return num;
    }
};
