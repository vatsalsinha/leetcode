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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //iterative solution:
        // ListNode *tmp1 = l1, *tmp2 = l2;
        // ListNode *tmp = new ListNode(0);
        // ListNode *res = tmp;
        // if(l1 == NULL && l2 != NULL){
        //     return l2;
        // }
        // if(l2 == NULL && l1 != NULL){
        //     return l1;
        // }
        // if(l1==NULL && l2==NULL){
        //     return NULL;
        // }
        // while(tmp1 && tmp2){
        //     if(tmp1->val <= tmp2->val){
        //         tmp->next = tmp1;
        //         tmp1 = tmp1->next;
        //     }
        //     // if(tmp1->val < tmp2->val){
        //     //     tmp->next = tmp1;
        //     //     tmp1 = tmp1->next;
        //     // }
        //     else{
        //         tmp->next = tmp2;
        //         tmp2 = tmp2->next;
        //     }
        //     tmp = tmp->next;
        // }
        // if(tmp1 == NULL)
        //     tmp->next = tmp2;
        // if(tmp2 == NULL)
        //     tmp->next = tmp1;
        // return res->next;
        //..................................................................
        //recursive solution:
        if(l1 == NULL && l2 != NULL){
             return l2;
         }
        if(l2 == NULL && l1 != NULL){
            return l1;
        }
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        ListNode *tmp;
        if(l1->val <= l2->val){
            tmp = l1;
            tmp->next = mergeTwoLists(l1->next, l2);
        }
        else{
            tmp = l2;
            tmp->next = mergeTwoLists(l1, l2->next); 
        }
        return tmp;
    }
};
