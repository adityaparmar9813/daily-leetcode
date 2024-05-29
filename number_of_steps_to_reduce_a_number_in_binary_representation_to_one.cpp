class Solution {
public:
    void increment(string& s) {
        int n = s.size()-1;

        while (n >= 0 && s[n] == '1') {
            s[n--] = '0';
        }

        if (n == -1) {
            s = '1' + s;
        } else {
            s[n] = '1';
        }
    }

    void half(string& s) {
        s.pop_back();
    }

    int numSteps(string s) {
        int steps = 0;

        while (s != "1") {
            s.back() == '0' ? half(s) : increment(s);
            steps++;
        }
        return steps;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
