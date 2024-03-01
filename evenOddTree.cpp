/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
bool check(vector<int> &v, int &l){
        if(l % 2 == 0){
            if(v[0] % 2 == 0){
                return false;
            }
            for(int i = 1; i < v.size(); i++){
                if(v[i] % 2 == 0 || v[i-1] >= v[i]){
                    return false;
                }
            }
        }
        else if(l % 2 != 0){
            if(v[0] % 2 != 0){
                return false;
            }
            for(int i = 1; i < v.size(); i++){
                if(v[i]%2 != 0 || v[i-1] <= v[i]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            // int prev = -1;
            vector<int> v;
            while(sz--) {
                auto tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            if(!check(v, level))
                return 0;
            level++;
        }
        return 1;
    }
};
