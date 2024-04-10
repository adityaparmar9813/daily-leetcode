class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        sort(deck.begin(), deck.end());
        vector<int> res(deck.size());
        
        for (int i = 0; i < deck.size(); i++) {
            q.push(i);
        }
        
        int j = 0;
        while (!q.empty()) {
            int index = q.front();
            res[index] = deck[j++];

            q.pop();

            if (q.size() > 1) {
                int k = q.front();
                q.pop();
                q.push(k);
            }
        }
        return res;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
