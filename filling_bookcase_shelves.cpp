class Solution {
public:
    int solve(int index, vector<vector<int>>& books, int shelfWidth, vector<int>& dp) {
        if (index == books.size()) {
            return -1;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        int ans = 1e9, currMaxHeight = 0, currWidth = 0;

        for (int i = index; i < books.size(); i++) {
            currWidth += books[i][0];
            if (currWidth > shelfWidth) {
                break;
            }

            currMaxHeight = max(books[i][1], currMaxHeight);
            ans = min(ans, currMaxHeight + solve(i+1, books, shelfWidth, dp));
        }

        return dp[index] = ans;
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size(), -1);
        return 1 + solve(0, books, shelfWidth, dp);
    }
};

// Time Complexity : O(n ^ 2)
// Space Complexity : O(n ^ 2)
