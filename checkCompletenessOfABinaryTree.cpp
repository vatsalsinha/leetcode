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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool nullFound = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto tp = q.front();
                q.pop();
                if(tp == NULL)
                    nullFound = 1;
                else{
                    if(nullFound)
                        return 0;
                    q.push(tp->left);
                    q.push(tp->right);
                }
            }
        }
        return 1;
    }
};

