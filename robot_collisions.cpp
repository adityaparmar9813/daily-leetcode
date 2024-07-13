class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string& directions) {
        const int n=positions.size();
        vector<pair<int, int>> robot(n);
        vector<int> stack;

        for (int i=0; i < n; i++) {
            robot[i] = {positions[i], i};
        }
        sort(robot.begin(), robot.end(), greater<>());

        for(auto& [pos, i]: robot) {
            if (directions[i]=='L') {
                stack.push_back(i);
            }
            else {
                while (!stack.empty() && healths[i] > 0) {
                    int j = stack.back();
                    int x = healths[j] - healths[i];

                    if (x>0) {
                        healths[j]--, healths[i]=0;
                    }
                    else if (x < 0) {
                        healths[j] = 0;
                        healths[i]--;
                        stack.pop_back();
                    }
                    else {
                        healths[i] = healths[j] = 0;
                        stack.pop_back();
                    }
                }
            }
        }

        vector<int> ans;
        
        for (int x: healths) {
            if (x > 0) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(n)
