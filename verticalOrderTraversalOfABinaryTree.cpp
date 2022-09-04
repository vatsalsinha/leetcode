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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> mp;
        queue<pair<pair<TreeNode*, int>, int>> q;
        q.push({{root, 0}, 0});
        while(!q.empty()){
            multiset<pair<int, int>> ms; // used to store values in order
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto tmp = q.front();
                ms.insert({tmp.second, tmp.first.first->val});
                q.pop();
                if(tmp.first.first->left)
                    q.push({{tmp.first.first->left, tmp.first.second-1}, tmp.second-1});
                if(tmp.first.first->right)
                    q.push({{tmp.first.first->right, tmp.first.second+1}, tmp.second+1});
            }
            for(auto it : ms)
                mp[it.first].push_back(it.second);
        }
        vector<vector<int>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
