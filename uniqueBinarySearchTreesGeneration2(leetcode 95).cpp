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
    vector<TreeNode*> generateSubTree(int start, int end){
        vector<TreeNode*> res;
        if(start > end){
            res.push_back(NULL);
            return res;
        }
        for(int i = start; i < end + 1; i++){
            vector<TreeNode*> left = generateSubTree(start, i-1);
            vector<TreeNode*> right = generateSubTree(i+1, end);
            
            for(auto l: left){
                for(auto r: right){
                    TreeNode *root = new TreeNode(i, l, r);
                    res.emplace_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        res = generateSubTree(1, n);
        return res;
    }
};
