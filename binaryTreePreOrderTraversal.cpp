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
    // vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        // if(root == NULL)
        //     return res;
        // res.push_back(root->val);
        // preorderTraversal(root->left);
        // preorderTraversal(root->right);
        // return res;
        if(root == NULL)
            return {};
        stack<TreeNode*> st;
        vector<int> res;
        st.push(root);
        TreeNode *p;
        while(!st.empty()){
            p = st.top();
            res.push_back(p->val);
            st.pop();
            if(p->right)
                st.push(p->right);
            if(p->left)
                st.push(p->left);
        }
        return res;
    }
};
