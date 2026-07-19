class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);

        for(char ch: s){
            freq[ch-'a']++;
        }

        vector<bool> flag(26, false);
        stack<int> st;
        for(char ch: s){
            int ele = ch - 'a';
            freq[ele]--;
            if(flag[ele]) continue;
            while(!st.empty()){
                if(st.top()<=ele or freq[st.top()]<=0) break;
                flag[st.top()] = false;
                st.pop();
            }
            if(!flag[ele]){
                st.push(ele);
                flag[ele]=true;
            }
        }

        string ans = "";
        while(!st.empty()){
            ans += (char)(st.top() + 'a');
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};