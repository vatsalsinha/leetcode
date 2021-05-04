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
    //vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        //recursive approach
        // if(root == NULL)
        //     return res;
        // inorderTraversal(root->left);
        // res.emplace_back(root->val);
        // inorderTraversal(root->right);
        // return res;
        //iterative approach
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *tmp = root;
        while(!st.empty() || tmp != NULL){
            while(tmp != NULL){
                st.push(tmp);
                tmp = tmp->left;
            }
            tmp = st.top();
            res.emplace_back(tmp->val);
            st.pop();
            tmp = tmp->right;
        }
        return res;
    }
};
