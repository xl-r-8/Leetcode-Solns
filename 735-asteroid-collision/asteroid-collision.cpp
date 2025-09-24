class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n=asteroids.size();
        for(int i=0; i<n; i++){
            if(asteroids[i]>=0) s.push(asteroids[i]);
            else{
                if(s.empty()){
                    s.push(asteroids[i]);
                    continue;
                } 
                while(!s.empty()){
                    int ele= s.top();
                    int negele=asteroids[i];
                    if(ele>=0){
                        if(negele+ele<0){
                            s.pop();
                            if(s.empty()){
                                s.push(negele);
                                break;
                            }
                        }
                        else if(negele+ele==0){
                            s.pop();
                            break;
                        }
                        else break;
                    }
                    else{
                        s.push(negele);
                        break;
                    }
                }
            }
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top()); s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};