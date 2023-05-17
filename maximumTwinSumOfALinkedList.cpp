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
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    int pairSum(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while(curr){
            len++;
            curr = curr->next;
        }
        curr = head;
        ListNode* prev;
        for(int i = 0; i < len/2; i++){
            curr = curr->next;
        }
        prev = reverseLinkedList(curr);
        curr = head;
        int sum = 0;
        while(prev && curr){
            sum = max(sum, curr->val+prev->val);
            curr = curr->next;
            prev = prev->next;
        }
        return sum;
    }
};
