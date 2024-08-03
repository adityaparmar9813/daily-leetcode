class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        sort(target.begin(), target.end());

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != target[i]) {
                return false;
            }
        }
        return true;
    }
};

// Time Complexity : O(n * log(n))
// Space Complexity : O(1)
