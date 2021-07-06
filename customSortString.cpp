class Solution {
public:
    unordered_map<char, int> umap;
    string customSortString(string order, string str) {
        for(int i = 0; i < order.size(); i++)
            umap[order[i]] = i+1;
        sort(str.begin(), str.end(),
             [&](char a, char b) { return umap[a] < umap[b]; });
        //[&] is a lambda function. It introduces a lambda expression. The contents of the square brackets indicate what is to be captured inside the lambda. Having only a & in there means that everything that is mentioned inside the lambda and can be found outside of its scope is captured by reference.
        return str;
    }
};