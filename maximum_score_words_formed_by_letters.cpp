class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> letterCount;

        for (auto& c : letters) {
            letterCount[c]++;
        }

        unordered_map<char, int> charScore;

        for (char c = 'a'; c <= 'z'; c++) {
            charScore[c] = score[c - 'a'];
        }
        return helper(words, letterCount, charScore, 0);
    }

    bool canPick(unordered_map<char, int>& charCount, unordered_map<char, int>& letterCount) {
        for (auto& [c, f] : charCount) {
            if (f > letterCount[c]) return false;
        }
        return true;
    }

    int helper(vector<string>& words, unordered_map<char, int>& letterCount, unordered_map<char, int>& charScore, int i) {
        if (i == words.size()) {
            return 0;
        }

        int skip = helper(words, letterCount, charScore, i + 1);
        int pick = 0;

        unordered_map<char, int> charCount;
        int score = 0;

        for (auto& c : words[i]) {
            charCount[c]++, score += charScore[c];
        }

        if (canPick(charCount, letterCount)) {
            for (auto& [c, f] : charCount) letterCount[c] -= f;
            pick = score + helper(words, letterCount, charScore, i + 1);
            for (auto& [c, f] : charCount) letterCount[c] += f;
        }
        return max(skip, pick);
    }
};

// Time Complexity: O(2^n * m)
// Space Complexity: O(n)
