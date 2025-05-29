class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        map<string,int> mp;//mp[word]=1=> word exists in wordList, mp[word]=2=> word is visited in the bfs traversal
        for(string word: wordList){
            mp[word]=1;
        }
        q.push({beginWord,0});
        mp[beginWord]=2;
        int ans=0;
        while(!q.empty()){
            pair<string,int> p = q.front(); q.pop();
            // process node here
            string node=p.first;
            int distance=p.second;
            if(node==endWord) return distance+1;
            for(int i=0; i<node.size();i++){
                string neighbor=node;
                for(int j=0; j<26;j++){
                    neighbor[i]='a'+j;
                    if(mp[neighbor]==1){
                        mp[neighbor]=2;
                        int dist_neigh=distance+1;
                        if(neighbor==endWord) return dist_neigh+1;
                        q.push({neighbor,distance+1});
                    }
                }
            }
        }
        return ans;
    }
};