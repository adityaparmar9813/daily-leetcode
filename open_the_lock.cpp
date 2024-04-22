class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<bool> visited(10000, 0);
        for(string s: deadends) {
            visited[stoi(s)] = 1;
        }
        if(visited[0] == 1) {
            return -1;
        }

        queue<pair<int, string>> q;
        q.push({0, "0000"});
        visited[0] = 1;

        while(!q.empty()) {
            auto [turn, s] = q.front(); 
            q.pop();

            if(s == target) {
                return turn;
            }
            for(int i = 0; i < 4; i++){
                for(int j = -1; j <= 1; j += 2) {
                    string t = s;
                    char& move = t[i];
                    move = (move - '0' + j + 10) % 10 + '0';
                    int x = stoi(t);

                    if (!visited[x]) {
                        q.push({turn+1, t});
                        visited[x] = 1;
                    }
                }
            }
        }
        return -1;
    }
};

// Time Complexity : O(10000)
// Space Complexity : O(10000)
