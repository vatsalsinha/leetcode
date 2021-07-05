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
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* tmp = head;
        while(tmp){
            tmp = tmp->next;
            len++;
        }
        int i = 0;
        tmp = head;
        ListNode* n1 = NULL, *n2 = NULL;
        while(tmp){
            if(i == k-1)
                n1 = tmp;
            if(i == len-k)
                n2 = tmp;
            i++;
            tmp = tmp->next;
        }
        swap(n1->val, n2->val);
        return head;
       //  vector<int> arr;
       //  ListNode*  tmp = head;
       //  while(tmp){
       //      arr.push_back(tmp->val);
       //      tmp = tmp->next;
       //  }
       //  int n = arr.size();
       //  swap(arr[k-1], arr[n-k]);
       //  ListNode* N = head;
       //  for(int i = 0; i < arr.size(); i++){
       //      N->val = arr[i];
       //      N = N->next;
       //  }
       //  return head;
    }
};
