class Solution {
public:
    string removeOccurrences(string s, string part) {
	/*
	string ans;
			for(auto a:s)
			{
				ans.push_back(a);
				if(ans.size()>=part.size()&&ans.substr(ans.size()-part.size())==part)
				{
					int m=part.size();
					while(m--)
					{
						ans.pop_back();
					}
				}

			}
			return ans; 
	*/
        stack<char> st;
        int m = part.size();
        for(auto c : s){
            st.push(c);
            if(!st.empty() && st.size() >= m){
                // If any of the characters
                // differ, it means that K
                // is not present in the stack
                string temp;
                int x = m;
                while(!st.empty() && x--){
                    temp += st.top();
                    st.pop();
                    
                }
                reverse(temp.begin(),temp.end());
                if(temp == part)
                    continue;
                else 
                    for(int j=0;j<temp.size();j++)
                        st.push(temp[j]);
            }
        }
        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
