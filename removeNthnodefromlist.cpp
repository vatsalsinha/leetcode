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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode *tmp = head;
        int len = 0;
        while(tmp != NULL){
            len++;
            tmp = tmp->next;
        }
        tmp = head;
        int pos_to_remove = len - n;
        if(pos_to_remove == 0){
            return head->next;
        }
        else{
            int i = 0;
            tmp = head;
            while(i < pos_to_remove-1){
                tmp = tmp->next;
                i++;
            }
            tmp->next = tmp->next->next;
        }
        return head;
    }
};
