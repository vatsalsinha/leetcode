class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int max_width) {
        // if the curr is the last line then left justify
        // if curr has exactly one word then left justify
        vector<string> res;
        for(int q = 0, p = q, sw = max_width; q < words.size(); p = q, sw = max_width){
            for(; q < words.size() && sw >= int(words[q].size()); sw -= words[q++].size()+1);
            int sp = (q >= words.size() || q-p == 1) ? q - p - 1: sw + q - p;
            res.push_back(words[q-1] + string(sw+q-p-sp, ' '));
            for(int i = q-2; p <= i; sp -= sp/(i-p+1), i--)
                res.back() = words[i] + string(sp / (i-p+1), ' ') + res.back();
        }
        return res;
    }
};
