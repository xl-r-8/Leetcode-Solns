void dfs(string node, string& endWord, unordered_map<string,int>& mp,vector<string> list, vector<vector<string>>& ans){
    list.push_back(node);
    if(node==endWord){//base case
        // cout<<node<<endl;
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
                    dfs(neighbor,endWord,mp,list,ans);
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
        q.push(endWord);
        dict.erase(endWord);
        if (!dict.count(beginWord)) dict.insert(beginWord);//add beginWord to the set

        unordered_map<string,int> mp;
        mp[endWord]=0;

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
        // for(pair<string,int>p: mp){
        //     cout<<p.first<<":"<<p.second<<endl;
        // }
        vector<string>list;
        dfs(beginWord,endWord,mp,list,ans);
        return ans;
    }
};