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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *tmp = head;
        ListNode *prev = NULL;
        while(tmp != NULL){
            if(tmp->next != NULL && tmp->val == tmp->next->val){
                while(tmp->next != NULL && tmp->val == tmp->next->val){
                    tmp->next = tmp->next->next;
                }
                if(tmp == head){
                    head = head->next;
                }
                else{
                    prev->next = tmp->next;
                }
            }
            else{
                prev = tmp;
            }
            tmp = tmp->next;
        }
        return head;
    }
};