#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSmallVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    bool isLargeVowel(char ch) {
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;
        return false;
    }

    string sortVowels(string s) {
        vector<char> v;

        for(int i=0; i<s.size(); i++) {
            if(isSmallVowel(s[i]) || isLargeVowel(s[i])) {
                v.push_back(s[i]);
                s[i] = 'a';
            }
        }
        
        int l = 0, r = v.size()-1;
        while(l < r) {
            while(l < r && !isSmallVowel(v[l])) l++;
            while(r > l && !isLargeVowel(v[r])) r--;

            if(isSmallVowel(v[l]) && isLargeVowel(v[r])) swap(v[l], v[r]);
        }

        int ptr = 0;
        for(; ptr < v.size(); ptr++) if(isSmallVowel(v[ptr])) break;

        sort(v.begin(), v.begin()+ptr);
        sort(v.begin()+ptr, v.end());

        ptr = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'a') s[i] = v[ptr++];
        }

        return s;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)