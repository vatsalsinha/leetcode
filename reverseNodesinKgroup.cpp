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
    ListNode* reverse(ListNode *head, int k){
        ListNode *prev = NULL, *Next = NULL, *curr = head;
        while(curr != NULL && k-- > 0){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        head = prev;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1){
            return head;
        }
        //ListNode *tmp = head;
        ListNode *res = new ListNode(0);
        ListNode *curr = head;
        ListNode *prev = res;
        while(curr != NULL){
            ListNode *tail = curr;
            int index = 0;
            while(curr != NULL && index < k){
                curr = curr->next;
                index++; 
            }
            if(index!=k){
                prev->next = tail;
            }else{
                prev->next = reverse(tail, k);
                prev = tail;
            }
        }
        return res->next;
    }
};
