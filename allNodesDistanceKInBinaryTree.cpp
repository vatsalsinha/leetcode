/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void constructGraph(TreeNode* root, unordered_map<int, vector<int>>& graph){
        if(!root)
            return;
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            constructGraph(root->left, graph);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            constructGraph(root->right, graph);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0)
            return {target->val};
        unordered_map<int, vector<int>> graph;
        constructGraph(root, graph);
        unordered_set<int> vis;
        vector<int> ans;
        queue<int> q;
        q.push(target->val);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            int tmp;
            while(sz--){
                tmp = q.front();
                vis.insert(tmp);
                q.pop();
                for(auto i : graph[tmp])
                    if(vis.count(i) == 0)
                        q.push(i);
            }
            level++;
            if(level == k){
                while(!q.empty()){
                    ans.push_back(q.front());
                    q.pop();
                }
            }
        }
        return ans;
    }
};

/*
8: 1 
0: 1 
1: 3 0 8 
4: 2 
7: 2 
2: 5 7 4 
6: 5 
5: 3 6 2 
3: 5 1 
*/
