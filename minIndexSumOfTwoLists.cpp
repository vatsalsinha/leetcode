class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> dict;
        int min = INT_MAX;
        vector<string> res;
        for(int i = 0; i <list1.size(); i++){
            dict[list1[i]] = i;
        }
        for(int i = 0; i < list2.size(); i++){
            if(dict.find(list2[i]) != dict.end()){
                if(dict[list2[i]] + i < min){
                    min = dict[list2[i]] + i;
                    res.clear();
                    res.push_back(list2[i]);
                }
                else if(dict[list2[i]] + i == min)
                    res.push_back(list2[i]);
            }
        }
        return res;
    }
};
