class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // //map approach============================================================
        // queue<pair<string,int>> q;
        // map<string,int> mp;//mp[word]=1=> word exists in wordList, mp[word]=2=> word is visited in the bfs traversal
        // for(string word: wordList){
        //     mp[word]=1;
        // }
        // q.push({beginWord,0});
        // // mp[beginWord]=2;//beginword will not even be in list, so this step is unnecessary
        // if (mp.find(beginWord) != mp.end()) mp.erase(beginWord);  // optional: skip inserting if it already exists // mark as visited by removing it
        // int ans=0;
        // while(!q.empty()){
        //     pair<string,int> p = q.front(); q.pop();
        //     // process node here
        //     string node=p.first;
        //     int distance=p.second;
        //     if(node==endWord) return distance+1;
        //     for(int i=0; i<node.size();i++){
        //         string neighbor=node;
        //         for(int j=0; j<26;j++){
        //             neighbor[i]='a'+j;
        //             // if(mp[neighbor]==1){
        //             //     mp[neighbor]=2;//mark as visited
        //             //     int dist_neigh=distance+1;
        //             //     if(neighbor==endWord) return dist_neigh+1;
        //             //     q.push({neighbor,dist_neigh});
        //             // }
        //             //better map
        //             if (mp.find(neighbor) != mp.end()) {
        //                 mp.erase(neighbor); // mark as visited by deleting it
        //                 int dist_neigh=distance+1;
        //                 if(neighbor==endWord) return dist_neigh+1;
        //                 q.push({neighbor, dist_neigh});
        //             }
        //         }
        //     }
        // }
        // return ans;

        //set approach============================================================
        queue<pair<string,int>> q;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0; // early check
        q.push({beginWord,0});
        if (dict.find(beginWord) != dict.end())dict.erase(beginWord); // mark as visited
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
                    if (dict.find(neighbor) != dict.end()) {
                        dict.erase(neighbor); // mark as visited
                        int dist_neigh=distance+1;
                        if(neighbor==endWord) return dist_neigh+1;
                        q.push({neighbor, dist_neigh});
                    }
                }
            }
        }
        return ans;
    }
};