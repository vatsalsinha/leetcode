class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        path+="/";
        string temp="";
        for(int i=0;i<path.length();i++){
            if(path[i]=='/'){
                if(temp==""||temp=="."){
                    temp="";
                    continue;
                }else if(temp==".."){
                    if(st.size()){
                        st.pop();
                    }
                    temp="";
                }else{
                    st.push(temp);
                    temp="";
                }
            }else{
                temp+=path[i];
            }
        }
        temp="";
        while(st.size()){
            temp=st.top()+"/"+temp;
            st.pop();
        }
        if(temp!=""){
            temp.pop_back();
        }
        temp="/"+temp;
        return temp;
    }
};
