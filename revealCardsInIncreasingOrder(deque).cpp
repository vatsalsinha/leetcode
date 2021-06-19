class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        /*
        deck= {2,3,5,7,11,13,17}
        dq = {0,1,2,3,4,5,6,1,3,5,1,5} (after a nmber of dq operations)
        ans= {2,13,3,11,5,17,7}
        */
        deque<int> dq;
        for(int i = 0; i < deck.size(); i++)
            dq.push_back(i);
        vector<int> ans(deck.size(),0);
        sort(deck.begin(), deck.end());
        for(auto c : deck){
            cout<<"ans["<<dq.front()<<"]="<<c<<" ";
            ans[dq.front()] = c;
            cout<<"pop"<<dq.front()<<" ";
            dq.pop_front();
            if(!dq.empty()){
                cout<<"pushing....."<<dq.front()<<" ";
                dq.push_back(dq.front());
                cout<<"popping......"<<dq.front()<<" ";
                dq.pop_front();
            }
        }
        return ans;
    }
};
