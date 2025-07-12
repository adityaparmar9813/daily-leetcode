class Solution {
public:
    vector<int> solve(int n, int firstPlayer, int secondPlayer) {
        if (firstPlayer + secondPlayer == n-1) {
            return {1, 1};
        }

        int nn = n / 2;
        int ansmi = INT_MAX, ansmx = INT_MIN;
        for (int nmask = 0; nmask < (1<<nn); nmask++) {
            int tmask = nmask;
            if (n % 2) {
                tmask |= (1 << nn);
            } 

            for (int i = 0; i < nn; i++) {
                if ((nmask & (1 << i)) == 0) {
                    tmask+=(1<<(n-1-i));
                }
            }
            if ((tmask & (1 << firstPlayer)) == 0 || (tmask & (1 << secondPlayer)) == 0) continue;
            int cnt=-1;
            int nf = -1,ns = -1;

            for (int k = 0; k < n; k++) {
                if((tmask & (1 << k))) {
                    cnt++;

                    if (k == firstPlayer) {
                        nf = cnt;
                    }
                    else if (k == secondPlayer) {
                        ns=cnt;
                    }
                }
            }
            vector<int> rec = solve((n + 1) / 2, nf, ns);
            ansmi = min(ansmi, 1 + rec[0]);
            ansmx = max(ansmx, 1 + rec[1]);
       }
       return {ansmi, ansmx};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        firstPlayer--;
        secondPlayer--;
        return solve(n,firstPlayer,secondPlayer) ; 
    }
};

// Time Complexity : O(2 ^ n * n)
// Space Complexity : O(2 ^ n * n)
