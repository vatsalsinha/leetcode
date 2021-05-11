/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //approach 1
    // if (root) {
    //   if (root->left) {
    //     root->left->next = root->right;
    //     if (root->next)
    //       root->right->next = root->next->left;
    //     connect(root->left);
    //     connect(root->right);
    //   }
    // }
    // return root;
        //approach 2
        // Node *tl ,*tr;
        // if(root){
        //     tl = root->left;
        //     tr = root->right;
        //     while(tl){
        //         tl->next = tr;
        //         tl = tl->right;
        //         tr = tr->left;
        //     }
        //     connect(root->left);
        //     connect(root->right);
        // }
        // return root;
        if(root == NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node *tmp = q.front();
                if(size - 1 == i)
                    tmp->next = NULL;
                q.pop();
                if(size - 1 != i)
                    tmp->next = q.front();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
        }
        return root;
  }
};
