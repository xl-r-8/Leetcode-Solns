class Solution {
public:
    void func(int i, string word, vector<string>& storage, string& digits, vector<string>& ans){
        int n = digits.size();
        if(i == n){
            ans.push_back(word);
            return;
        }
        int ind = digits[i] - '0';
        string temp = storage[ind];
        
        for(char ch: temp){
            func(i+1, word + ch, storage, digits, ans);
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> storage = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        func(0, "", storage, digits, ans);

        return ans;
    }
};