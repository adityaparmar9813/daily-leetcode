class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int index = s[n-1] == '1' ? 0 : n-1;

        for(int i=0; i < n-1; i++) {
            if(s[i] == '1') {
                swap(s[i], s[index]);
                index = (index+1) % n;
            }
        }
        return s;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)