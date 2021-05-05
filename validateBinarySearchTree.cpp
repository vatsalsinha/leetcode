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
    void inorderTraversal(TreeNode* root, vector<int> &nodes){
        stack<TreeNode*> st;
        TreeNode *tmp = root;
        while(!st.empty() || tmp != NULL){
            while(tmp != NULL){
                st.push(tmp);
                tmp = tmp->left;
            }
            tmp = st.top();
            st.pop();
            nodes.push_back(tmp->val);
            tmp = tmp->right;
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> nodes;
        inorderTraversal(root, nodes);
        for(int i = 0; i < nodes.size()-1; i++){
            if(nodes[i] >= nodes[i+1])
                return false;
        }
        return true;
    }
};
