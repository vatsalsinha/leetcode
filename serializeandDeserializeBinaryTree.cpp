/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "NULL";
        string s;
        s += to_string(root->val);
        string l = serialize(root->left);
        string r = serialize(root->right);
        return s + "," + l + "," + r;
    }
    
    TreeNode* decode(queue<string> &q){
        if(q.empty())
            return NULL;
        string a = q.front();
        q.pop();
        if(a == "NULL")
            return NULL;
        int n = stoi(a);
        TreeNode *root = new TreeNode(n);
        root->left = decode(q);
        root->right = decode(q);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string tmp;
        for(int i = 0; i < data.length(); i++){
            if(data[i] == ','){
                q.push(tmp);
                tmp = "";
            }
            else{
                tmp += data[i];
            }
        }
        return decode(q);
        return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
