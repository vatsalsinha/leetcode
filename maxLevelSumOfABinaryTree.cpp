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
    int maxLevelSum(TreeNode* root) {
        /* 
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,int> umap;
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                sum += tmp->val;
            }
            umap[level++] = sum;
        }
        int m = INT_MIN, ans;
        for(auto it : umap){
            if(m <= it.second){
                m = it.second;
                ans = it.first;
            }
        }
        return ans;
        */
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,int> umap;
        int level = 0, maxSum = INT_MIN, ans;
        while(!q.empty()){
            int size = q.size();
            int tsum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                tsum += tmp->val;
            }
            level++;
            if(tsum > maxSum)
                ans = level;
            maxSum = max(tsum,maxSum);
        }
        
        return ans;
    }
};
