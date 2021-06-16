/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // vector<int> ans;
    // void inorder(TreeNode* root){
    //     if(!root)
    //         return;
    //     inorder(root->left);
    //     ans.push_back(root->val);
    //     inorder(root->right);
    // }
    
    void pushleft(stack<TreeNode*> &s, TreeNode* n){
        while(n != NULL)
            s.push(exchange(n, n->left)); //Replaces the value of n with n->left and returns the old value of n.
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // inorder(root1);
        // inorder(root2);
        // sort(ans.begin(), ans.end());
        // return ans;
        vector<int> ans;
        stack<TreeNode*> s1, s2;
        pushleft(s1, root1);
        pushleft(s2, root2);
        while(!s1.empty() || !s2.empty()){
            stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : s1.top()->val < s2.top()->val ? s1 : s2;
            auto n = s.top();
            s.pop();
            ans.push_back(n->val);
            pushleft(s, n->right);
        }
        return ans;
    }
};
