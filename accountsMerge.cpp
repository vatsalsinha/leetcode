class Solution {
public:
    vector<vector<string>> ans;
    int parent[1000];
    int findParent(int index){
        if(index == parent[index])
            return index;
        return parent[index] = findParent(parent[index]);
    }
    void unian(int x, int y){
        x = findParent(x);
        y = findParent(y);
        parent[x] = y;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> isVisited; // email : index
        unordered_map<int, vector<string>> mp; // index : vector<emails>
        for(int i = 0; i < accounts.size(); i++){
            parent[i] = i;
            for(int j = 1; j < accounts[i].size(); j++){
                // if(same email as before) unian
                if(isVisited.find(accounts[i][j]) != isVisited.end()){
                    int x = findParent(i);
                    int y = findParent(isVisited[accounts[i][j]]);
                    unian(x,y);
                }
                else{ // not seen thus new email so itself parent
                    isVisited[accounts[i][j]] = parent[i];
                }
            }
        }
        for(auto it : isVisited){ // mapping index to vector of same parent emails
            int index = findParent(it.second);
            mp[index].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(auto it : mp){ // calculating answers 
            auto v = it.second;
            sort(v.begin(), v.end());
            v.insert(v.begin(), accounts[it.first][0]);
            ans.push_back(v);
        }
        return ans;
    }
};

/*
john : johnsmith@mail.com -----> john_newyork@mail.com ----> john00@mail.com

*/