void dfs(string node, string& beginWord, unordered_map<string,int>& mp,vector<string> list, vector<vector<string>>& ans){
    list.push_back(node);
    if(node==beginWord){//base case
        // cout<<node<<endl;
        reverse(list.begin(),list.end());
        ans.push_back(list);
        return;
    }
    // cout<<node<<"->";
    for(int i=0; i<node.size();i++){
        string neighbor=node;
        for(char ch='a';ch<='z';ch++){
            neighbor[i]=ch;
            if(mp.find(neighbor) != mp.end()){
                if(mp[neighbor]==mp[node]-1){
                    // cout<<" neighbor "<<neighbor<<endl;
                    dfs(neighbor,beginWord,mp,list,ans);
                }
            }
        }
    }
}

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        queue<string> q;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord)) return ans; // early check
        q.push(beginWord);
        if (dict.find(beginWord) != dict.end())dict.erase(beginWord);

        unordered_map<string,int> mp;
        mp[beginWord]=0;

        while(!q.empty()){
            string node = q.front(); q.pop();
            for(int i=0; i<node.size();i++){
                string neighbor=node;
                for(char ch='a';ch<='z';ch++){
                    neighbor[i]=ch;
                    if (dict.find(neighbor) != dict.end()) {
                        dict.erase(neighbor);//we just need to know the level of each word and since each word appears at exactly 1 level, so agar 1 level pe usko ek baar bhi mark kar liya to chalta hai we dont need to visit it again and again at the same level just coz there exist multiple paths that contains it
                        mp[neighbor]=mp[node]+1;
                        q.push(neighbor);
                    }
                }
            }
        }
        vector<string>list;
        dfs(endWord,beginWord,mp,list,ans);
        return ans;
    }
};