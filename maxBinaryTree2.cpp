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
    // vector<int> a;
    // void preOrder(TreeNode* root){
    //     if(!root)
    //         return;
    //     preOrder(root->left);
    //     a.push_back(root->val);
    //     preOrder(root->right);
    // }
    // TreeNode* construct(vector<int> a, int start, int end){
    //     if(start > end)
    //         return NULL;
    //     int index = start;
    //     // for(int i = start; i < end+1; i++){
    //     //     if(a[i] > a[index])
    //     //         index = i;
    //     // }
    //     auto it = max_element(a.begin()+start, a.begin()+end+1);
    //     index = it - a.begin();
    //     TreeNode* root = new TreeNode(a[index]);
    //     root->left = construct(a, start, index-1);
    //     root->right = construct(a, index+1, end);
    //     return root;
    // }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        // preOrder(root);
        // a.push_back(val);
        // return construct(a, 0, a.size()-1);
        
        //approach 2
        if(root && root->val > val){
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
        TreeNode* node = new TreeNode(val);
        node->left = root;
        return node;
    }
};
