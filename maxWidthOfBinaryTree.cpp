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
    int widthOfBinaryTree(TreeNode* root) {
        // convert the binary tree into an array. Use its indexing property to calculate width.
        // to get the width, index_right - index_left + 1
        if(!root)
            return 0;
        queue<pair<TreeNode*, int>> q; // treeNode:index
        q.push({root, 1});
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            int mx, mn, minAtLevel = q.front().second;
            for(int i = 0; i < sz; i++){
                int curr = q.front().second - minAtLevel + 1;
                auto tri = q.front().first;
                q.pop();
                if(i == 0)
                    mn = curr;
                if(i == sz-1)
                    mx = curr;
                if(tri->left != NULL)
                    q.push({tri->left, 2LL*curr});
                if(tri->right != NULL)
                    q.push({tri->right, 2LL*curr+1});
            }
            ans = max(ans, mx-mn+1);
        }
        return ans;
    }
};
