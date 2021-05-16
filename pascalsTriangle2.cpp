class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return {1};
        vector<int> row = getRow(rowIndex-1);
        row.resize(rowIndex+1);
        row[0] = 1;
        row[rowIndex] = 1;
        for(int i = rowIndex-1; i > 0; i--){
            row[i] = row[i-1] + row[i];
        }
        return row;
    }
};
