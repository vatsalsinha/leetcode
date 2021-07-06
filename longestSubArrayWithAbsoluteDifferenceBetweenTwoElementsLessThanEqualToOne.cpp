int pickingNumbers(vector<int> a) {
    sort(a.begin(), a.end());
    int maxLen = 0;
    for(int i = 0; i < a.size(); i++){
        int j = i+1;
        while(abs(a[i] - a[j]) <= 1 && j < a.size()){
            j++;
        }
        maxLen = max(maxLen, j-i);
    }
    return maxLen;
}
