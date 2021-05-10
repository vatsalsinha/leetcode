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
    //vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        // if(root == NULL)
        //     return res;
        // postorderTraversal(root->left);
        // postorderTraversal(root->right);
        // res.push_back(root->val);
        // return res;
	//.........................................................
        // if(!root)
        //     return {};
        // vector<int> res;
        // stack<TreeNode*> st;
        // st.push(root);
        // while(!st.empty()){
        //     TreeNode *p = st.top();
        //     res.push_back(p->val);
        //     st.pop();
        //     if(p->left)
        //         st.push(p->left);
        //     if(p->right)
        //         st.push(p->right);
        // }
        // reverse(res.begin(), res.end());
        // return res;
	//.......................................................
        if(!root)
            return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *p = st.top();
            if(!p)
                st.pop();
            else{
                if(p->left){
                    st.push(p->left);
                    p->left = NULL;
                }
               else if(p->right){
                    st.push(p->right);
                    p->right = NULL;
                }
                else{
                    res.push_back(p->val);
                    st.pop();
                }
            }
            
        }
        return res;
    }
};