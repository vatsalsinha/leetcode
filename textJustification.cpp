class Solution {
public:
    string middleJustify(vector<string> words, int diff, int i, int j){
            int spacesNeeded = j-i-1;
            int spaces = diff / spacesNeeded;
            int extraSpaces = diff % spacesNeeded;
            string result = words[i];
            for(int k = i+1; k < j; k++){
                int spacesToApply = spaces + (extraSpaces-- > 0 ? 1 : 0);
                string tmp;
                for(int q = 0; q < spacesToApply; q++){
                    tmp += " ";
                }
            
                result.append(tmp + words[k]);
            }
            return result;
            
        }
    string leftJustify(vector<string> words, int diff, int i, int j){
            int spacesOnRight = diff - (j-i-1);
            string result = words[i];
            for(int k = i+1; k < j; k++){
                result.append(" " + words[k]);
            }
            for(int q = 0; q < spacesOnRight; q++){
                result.append(" ");
            }
            return result;
            
        }
    vector<string> fullJustify(vector<string>& words, int max_width) {
        // if the curr is the last line then left justify
        // if curr has exactly one word then left justify
        // diff = maxWidth - lineLength
        // spacesNeeded = j - i - 1
        //middlejustify:
        //spaces = diff / spacesNeeded
        // extraSpaces = diff % spacesNeeded
        //leftjustify:
        //spacesOnRight = diff - (j-i-1) 
        
        vector<string> result;
        int i = 0, n = words.size();
        while(i < n){
            int j = i+1;
            int linelength = int(words[i].length());
            while(j < n && (linelength + int(words[j].length()) + (j-i-1) < max_width)){
                linelength += words[j].length();
                j++;
            }
            int diff = max_width - linelength;
            int numWords = j-i;
            if(numWords == 1 || j >= n) 
                result.push_back(leftJustify(words, diff, i, j));
            else
                result.push_back(middleJustify(words, diff, i, j));
            i = j;
        }
        return result;
        
        /* 
        vector<string> res;
        for(int q = 0, p = q, sw = max_width; q < words.size(); p = q, sw = max_width){
            for(; q < words.size() && sw >= int(words[q].size()); sw -= words[q++].size()+1);
            int sp = (q >= words.size() || q-p == 1) ? q - p - 1: sw + q - p;
            res.push_back(words[q-1] + string(sw+q-p-sp, ' '));
            for(int i = q-2; p <= i; sp -= sp/(i-p+1), i--)
                res.back() = words[i] + string(sp / (i-p+1), ' ') + res.back();
        }
        return res;
        */
    }
};