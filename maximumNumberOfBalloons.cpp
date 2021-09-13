class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp; // or use an array[26];
        for(auto c : text){
            mp[c]++;
        }   
        return min(mp['b'], min(mp['a'], min(mp['l']/2, min(mp['o']/2,mp['n']))));
    }
};
