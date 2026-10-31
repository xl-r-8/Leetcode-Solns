class Solution {
public:
    int val(char c){
        if(c == 'R') return 0;
        if(c == 'B') return 1;
        return 2;
    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = edges.size() + 1; //coz its a tree
        vector<vector<int>> adjL(n);
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }

        int tempRoot = -1;

        for(int u = 0; u<n; u++){
            int numParents = 0;
            int numChildren = 0;

            for(int v: adjL[u]){
                int valu = val(colors[u]); 
                int valv = val(colors[v]);
                if(valu == valv) return -1;
                if(valv == (valu+1)%3) numChildren++;
                else //if(valv == (valu-1 + 3)%3)
                {
                    numParents++;
                }
            }

            if(numParents > 1) return -1;//multiple parents
            if(numChildren > 2) return -1;//more than 2 children
            if(numParents == 0){
                if(tempRoot != -1) return -1;//another root
                tempRoot = u;
            }
        }

        return tempRoot;
    }
};