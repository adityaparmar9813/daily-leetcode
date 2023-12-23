class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int, int>, int> locations = {{{0, 0}, 1}};
        pair<int, int> pos = {0, 0};

        for (char dir : path) {
            if(dir == 'N') pos = {pos.first, pos.second+1};
            else if(dir == 'S') pos = {pos.first, pos.second-1};
            else if(dir == 'E') pos = {pos.first+1, pos.second};
            else pos = {pos.first-1, pos.second};

            if (locations[pos] == 1) return true;
            locations[pos] = 1;
        }
        return false;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(n)