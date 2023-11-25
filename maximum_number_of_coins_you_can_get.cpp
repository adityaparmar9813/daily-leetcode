class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int sum = 0,n = piles.size();
        sort(piles.begin(),piles.end());

        for(int i = n / 3; i < n; i += 2) sum += piles[i];
        return sum;
    }
};

// Time Complexity : O(n*log(n))
// Space Complexity : O(1)