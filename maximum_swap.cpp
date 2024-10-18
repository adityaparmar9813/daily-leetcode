class Solution {
public:
    int maximumSwap(int num) {
    string s = to_string(num);
    int n = s.size();
    vector<int> maxIdx(n);
    maxIdx[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; --i) {
        if (s[i] > s[maxIdx[i + 1]]) {
            maxIdx[i] = i;
        } else {
            maxIdx[i] = maxIdx[i + 1];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] != s[maxIdx[i]]) {
            swap(s[i], s[maxIdx[i]]);
            break;
        }
    }

    return stoi(s);

    }
};
