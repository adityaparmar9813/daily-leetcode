class Solution {
public:
    int findTheWinner(int n, int k) {
        if (k % n == 1) {
            return n;
        } else if (k > n) {
            k = k % n;
        } else if (k == 0) {
            k = n;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        while (q.size() != 1) {
            int count = k-1;

            while (count > 0) {
                int curr = q.front();
                q.pop();
                q.push(curr);
                count--;
            }
            q.pop();
        }
        return q.front();
    }
};

// Time Complexity : O(n * k)
// Space Complexity : O(n)
