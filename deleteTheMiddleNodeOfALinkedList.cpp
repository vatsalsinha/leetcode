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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL)
            return NULL;
        ListNode* tmp = head;
        int n = 0;
        while(tmp != NULL){
            n++;
            tmp = tmp->next;
        }
        int i = 0;
        tmp = head;
        ListNode* prev = head;
        while(tmp != NULL && i < n/2){
            ++i;
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        return head;
    }
};
