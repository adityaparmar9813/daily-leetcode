class Solution {
public:
    int maxScore(string s) {
        int totalOneCount = count(s.begin(), s.end(), '1');
        int zeroCount = 0, oneCount = 0, ans = 0;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                zeroCount++;
            } else {
                oneCount++;
            }

            ans = max(ans, zeroCount + totalOneCount - oneCount);
        }

        return ans;
    }
};