class Solution {
public:
    string pushDominoes(string dominoes) {
        string res;
        int n = dominoes.size();
        vector<int> forces(n);
        int force = 0;
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'R')
                force = n;
            else if(dominoes[i] == 'L')
                force = 0;
            else
                force = max(force-1, 0);
            forces[i] += force;
        }
        for(int i = n-1; i > -1; i--){
            if(dominoes[i] == 'L')
                force = n;
            else if(dominoes[i] == 'R')
                force = 0;
            else
                force = max(force-1, 0);
            forces[i] -= force;
        }
        for(auto f : forces){
            if(f > 0)
                res += 'R';
            else if(f <  0)
                res += 'L';
            else
                res += '.';
        }
        return res;
    }
};
