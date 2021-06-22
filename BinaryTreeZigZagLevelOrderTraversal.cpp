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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //also do a full BFS, then reverse the odd indexed vectors
        if(!root)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        int level = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> tmp(size);
            for(int i = 0; i < size; i++){
                TreeNode* t = q.front();
                q.pop();
                if(level%2)
                    tmp[size-i-1] = t->val;
                else
                    tmp[i] = t->val;
                if(t->left){
                    q.push(t->left);
                }
                if(t->right)
                    q.push(t->right);
            }
            level++;
            ans.push_back(tmp);
        }
        return ans;
    }
};
