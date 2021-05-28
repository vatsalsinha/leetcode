class TrieNode{
public:
    TrieNode* child[2];
    bool isEnd;
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
       int maxA = 0;
        TrieNode* root = new TrieNode();
        //insert
        for(int i = 0; i < nums.size(); i++){
            TrieNode* curr = root;
            for(int j = 31; j >= 0; j--){
                int l = (nums[i]&(1<<j)) > 0 ? 1 : 0;
                if(!curr->child[l])
                    curr->child[l] = new TrieNode();
                curr = curr->child[l];
            }
        }
        /* Perform query to retrieve the maximum xor value possible for arr[i]. We know xor of different type of bits(0 ^ 1 or 1 ^ 0) is always 1. So during query for each bit, try to traverse node holding opposite bit. This will make that particular bit 1 result in maximizing xor value. If there is no node with opposite bit, only then traverse the same bit node.*/
        
        //xor
        for(int i = 0; i < nums.size(); i++){
            TrieNode* curr = root;
            int val = 0;
            for(int j = 31; j >= 0; j--){
                int bit = (nums[i]&(1<<j)) > 0 ? 1 : 0;
                if(bit == 0){
                    if(curr->child[1]){
                        val = val*2 + 1;
                        curr = curr->child[1];
                    }
                    else{
                        val = val * 2;
                        curr = curr->child[0];
                    }
                }
                else{
                    if(curr->child[0]){
                        val = val * 2 + 1;
                        curr = curr->child[0];
                    }
                    else{
                        val = val * 2;
                        curr = curr->child[1];
                    }
                }
            }
            maxA = max(maxA, val);
        }
        return maxA;
    }
};
