    #include<iostream>
    #include<vector>
    #include<unordered_set>
    using namespace std;

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // Directions: North, East, South, West
        vector<pair<int,int>> dir = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };
        
        int d = 0; // start facing North
        
        // Store obstacles using encoding (faster than string)
        unordered_set<long long> st;
        for(auto &o : obstacles) {
            long long key = ((long long)o[0] << 32) | (o[1] & 0xffffffff);
            st.insert(key);
        }
        
        int x = 0, y = 0;
        int maxDist = 0;
        
        for(int cmd : commands) {
            
            if(cmd == -1) {
                d = (d + 1) % 4; // turn right
            }
            else if(cmd == -2) {
                d = (d + 3) % 4; // turn left
            }
            else {
                // move step by step
                for(int step = 0; step < cmd; step++) {
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;
                    
                    long long key = ((long long)nx << 32) | (ny & 0xffffffff);
                    
                    if(st.count(key)) break; // obstacle found
                    
                    x = nx;
                    y = ny;
                    
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        
        return maxDist;
    }