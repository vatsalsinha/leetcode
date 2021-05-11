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
    TreeNode* constructTree(vector<int> inorder, vector<int> preorder, int n, int &preIndex , int start, int end,  unordered_map<int, int> &mp)
{
        if(start > end)
          return NULL;

        int currIndex = mp[preorder[preIndex]];

        TreeNode* root = new TreeNode(preorder[preIndex++]);
        root -> left = constructTree(inorder, preorder, n, preIndex, start, currIndex - 1, mp);
        root -> right = constructTree(inorder, preorder, n, preIndex, currIndex + 1, end, mp);

        return root;
}
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int, int> mp;
        int n = preorder.size();
        for(int i = 0; i < n; i++)
         mp[inorder[i]] = i;

        int preIndex = 0;
        return constructTree(inorder, preorder, n, preIndex, 0, n-1, mp);
    }
};
