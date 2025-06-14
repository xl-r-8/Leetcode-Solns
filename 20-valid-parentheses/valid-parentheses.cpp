class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char ch: s){
            if(ch=='(' or ch=='{' or ch=='[') st.push(ch);
            else{
                if(st.empty())return false;
                char ele=st.top();
                st.pop();
                if(ch==')' and ele!='(') return false;
                else if(ch=='}' and ele!='{') return false;
                else if(ch==']' and ele!='[') return false;
            }
        }
        if(!st.empty())return false;
        return true;

    }
};