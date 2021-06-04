class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> umap;
        for(int i =  0; i < deck.size(); i++){
            umap[deck[i]]++;
        }
        int n = 0;
        //int res;
        for(auto it : umap){
            n = __gcd(it.second, n);
        }
        return n >=2 ? true : false;
    }
};
