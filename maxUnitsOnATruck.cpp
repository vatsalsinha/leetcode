class Solution {
public:
    bool static cmp(vector<int> a, vector<int> b){
        return b[1] < a[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int capacity = truckSize;
        int score = 0;
        for(int i = 0; i < boxTypes.size(); i++){
            if(capacity >= boxTypes[i][0]){
                score += boxTypes[i][0] * boxTypes[i][1];
                cout<<i<<":"<<score<<" ";
                capacity -= boxTypes[i][0];
                cout<<"capacity="<<capacity<<"\n";
            }
            else if(capacity < boxTypes[i][0] && capacity > 0){
                int diff = capacity;
                score += boxTypes[i][1] * diff;
                cout<<i<<":"<<score<<" ";
                capacity -= diff;
                cout<<"diff="<<capacity<<" ";
                cout<<"capacity="<<capacity<<"\n";
            }
        }
        return score;
    }
};
