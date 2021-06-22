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
    int find(TreeNode* root, int m){
        if(!root)
            return 0;
        if(root->val >= m)
            return 1 + find(root->left, root->val) + find(root->right, root->val);
        return find(root->left, m) + find(root->right, m);
    }
    int goodNodes(TreeNode* root) {
        // if(root->left == NULL && root->right == NULL)
        //     return 1;
        // stack<pair<TreeNode*, int>> st;
        // st.push({root, root->val});
        // int count = 0;
        // int m = root->val;
        // while(!st.empty()){
        //    TreeNode* p = st.top().first;
        //     int parent = st.top().second;
        //     st.pop();
        //     if(p->val >= parent){
        //         parent = p->val;
        //         count++;
        //     }
        //     if(p->left)
        //         st.push({p->left, max(parent,p->val)});
        //     if(p->right)
        //         st.push({p->right,max(parent,p->val)});
        // }
        // return count;
        return find(root, INT_MIN);
        
    }
};
