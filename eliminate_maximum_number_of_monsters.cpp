class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> time;
        for(int i=0; i<dist.size(); i++) time.push_back((float)dist[i]/speed[i]);

        sort(time.begin(), time.end());
        int attack = 0;

        for(int i=0; i<time.size(); i++) {
            if(time[i] <= attack) break;
            attack++;
        }
        return attack;
    }
};

// Time Complexity : O(nlog(n))
// Space Complexity : O(n)