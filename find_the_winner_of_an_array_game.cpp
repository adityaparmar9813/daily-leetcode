class Solution {
public:
       int getWinner(vector<int>& arr, int k) {
        int curr = arr[0], winCount = 0;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > curr) {
                curr = arr[i];
                winCount = 0;
            }
            if (++winCount == k) break;
        }
        return curr;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)