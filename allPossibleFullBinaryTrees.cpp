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
    vector<TreeNode*> allPossibleFBT(int N) {
        // if (N % 2 == 0) 
        //     return {};
        // vector<TreeNode*> dp[N+1];
        // dp[1] = {new TreeNode()};
        // for (int n = 3; n <= N; n += 2) 
        //   for (int i = 1; i < n-1; i += 2) 
        //     for (TreeNode* left : dp[i]) 
        //       for (TreeNode* right : dp[n-i-1]) 
        //         dp[n].emplace_back(new TreeNode(0, left, right));
        // return dp[N];
        vector<TreeNode*> res;
        if(N==1){
            res.push_back(new TreeNode(0));
            return res;
        }
        N=N-1;
        for(int i=1; i<N;i+=2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N-i);
            for(auto nl: left){
                for(auto nr:right){
                    TreeNode* cur = new TreeNode(0);
                    cur->left=nl;
                    cur->right=nr;
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
};
