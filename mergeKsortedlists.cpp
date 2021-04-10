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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        if(lists.size() == 1){
            return lists[0];
        }
        ListNode *ans = lists[0];
        for(int i = 1; i < lists.size();i++){
            ans = mergeTwoLists(ans, lists[i]);  
        }
        return ans;
    }
};
