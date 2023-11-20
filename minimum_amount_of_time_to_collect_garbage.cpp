class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0,time_m = 0,time_p = 0,time_g = 0;

        for(int i=0; i < garbage.size(); i++) {
            bool flag_p = false, flag_m = false, flag_g = false;
            for(int j=0; j<garbage[i].length(); j++){
                if(garbage[i][j] == 'M') flag_m = true;
                if(garbage[i][j] == 'P') flag_p = true;
                if(garbage[i][j] == 'G') flag_g = true;
                time++;                                 
            }

            if(flag_m) {
               time += time_m;
               time_m = 0;
            } if(flag_p) {
               time += time_p;
               time_p = 0;
            } if(flag_g) {
               time += time_g;
               time_g = 0;
            }
            if(i != garbage.size()-1) {
            time_p += travel[i];
            time_g += travel[i];
            time_m += travel[i];
            }
        }
        return time;
    }
};

// Time Complexity : O(n*m)
// Space Complexity : O(1)