class Solution {
public:
    void backtrack(string tiles, int& count, int index){
        count++;
        for(int i = index; i < tiles.size(); i++){
            if(i != index && tiles[i] == tiles[index])
                continue;
            swap(tiles[i], tiles[index]);
            backtrack(tiles, count, index+1);
            
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        int count = -1;
        //string res;
        backtrack(tiles, count, 0);
        return count;
    }
};
