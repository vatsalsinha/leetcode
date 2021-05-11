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
    TreeNode *solve(vector<int>& inorder, vector<int>& postorder, int &l, int s, int e, unordered_map<int,int>& mp){
        if(s > e)
            return NULL;
        TreeNode *root = new TreeNode(postorder[l]);
        int idx = mp[postorder[l]];
        l--;
        root->right = solve(inorder, postorder, l, idx+1, e, mp);
         root->left = solve(inorder, postorder, l, s, idx-1, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // approach 1
//         if(postorder.size() == 0)
//             return NULL;
//         TreeNode *root = new TreeNode(postorder[postorder.size()-1]);
//         int ind = 0;
//         for(int i = 0; i < postorder.size(); i++){
//             if(inorder[i] == postorder[postorder.size()-1]){
//                 ind = i;
//                 break;
//             }
//         }
//         vector<int> postL(postorder.begin(), postorder.begin()+ind);
//         vector<int> postR(postorder.begin()+ind, postorder.end()-1);
        
//         vector<int> inL(inorder.begin(), inorder.begin()+ind);
//         vector<int> inR(inorder.begin()+ind+1, inorder.end());
        
//         root->left = buildTree(inL, postL);
//         root->right = buildTree(inR, postR);
//         return root;
        unordered_map<int, int> mp;
        int l = postorder.size()-1;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return solve(inorder, postorder, l, 0, inorder.size()-1, mp);
        
    }
};
