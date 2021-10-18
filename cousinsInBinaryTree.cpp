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
    pair<TreeNode*, pair<TreeNode*, int>> bfs(TreeNode* root, int x){ // curr : parent : level
        queue<pair<TreeNode*, pair<TreeNode*, int>>> q;
        int level = 0;
        q.push({root, {NULL, level}});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int l = q.front().second.second;
            if(curr->val == x)
                return q.front();
            q.pop();
            if(curr->left){
                q.push({curr->left, {curr, l+1}});
            }
            if(curr->right){
                q.push({curr->right, {curr, l+1}});
            } 
        }
        return {};
    }
    bool isCousins(TreeNode* root, int x, int y) {
        auto a1 = bfs(root, x);
        auto a2 = bfs(root, y);
        return a1.second.first != a2.second.first && a1.second.second == a2.second.second;
    }
};
