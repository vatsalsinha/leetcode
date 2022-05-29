class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(), 0);
        int j = 0;
        for(auto str : words){
            for(int i = 0; i < str.size(); i++){
                mask[j] |= 1 << (str[i]-'a');
            }
            j++;
        }
        int res = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                if(!(mask[i] & mask[j])){
                    int l1 = words[i].size();
                    int l2 = words[j].size();
                    res = max(l1*l2, res);
                }
            }
        }
        return res;
    }
};

/*
map alphabets to bit masks. 
        // a 1->1
        // b 2->10
        // c 4->100
        // ab 3->11
        // ac 5->101
        // abc 7->111
        // az 33554433->10000000000000000000000001
*/
