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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //BFS:
        // unordered_set<int> d(to_delete.begin(), to_delete.end());
        // queue<TreeNode*> q;
        // vector<TreeNode*> res;
        // if(!d.count(root->val))
        //     res.push_back(root);
        // q.push(root);
        // while(!q.empty()){
        //     TreeNode* p = q.front();
        //     q.pop();
        //     if(p->left)
        //         q.push(p->left);
        //     if(p->right)
        //         q.push(p->right);
        //     if(p->left && d.count(p->left->val))
        //         p->left = NULL;
        //     if(p->right && d.count(p->right->val))
        //         p->right = NULL;
        //     if(d.count(p->val)){
        //         if(p->left)
        //             res.push_back(p->left);
        //         if(p->right)
        //             res.push_back(p->right);
        //     }
        // }
        // return res;
        
        //DFS
        unordered_set<int> d(to_delete.begin(), to_delete.end());
        stack<TreeNode*> st;
        vector<TreeNode*> res;
        st.push(root);
        if(!d.count(root->val))
            res.push_back(root);
        while(!st.empty()){
            TreeNode* p = st.top();
            st.pop();
            if(p->left){
                st.push(p->left);
                if(d.count(p->left->val))
                    p->left = NULL;
            }
            if(p->right){
                st.push(p->right);
                if(d.count(p->right->val))
                    p->right = NULL;
            }
            if(d.count(p->val)){
                if(p->left)
                    res.push_back(p->left);
                if(p->right)
                    res.push_back(p->right);
            }
        }
        return res;
    }
};
