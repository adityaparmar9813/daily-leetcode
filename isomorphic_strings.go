func isIsomorphic(s string, t string) bool {
    mp := make(map[rune]rune)
    mapped := make(map[rune]bool)

    for i := 0; i < len(s); i++ {
        if val, exists := mp[rune(s[i])]; exists {
            if val != rune(t[i]) {
                return false
            }
        } else {
            if mapped[rune(t[i])] {
                return false
            }
            mp[rune(s[i])] = rune(t[i])
            mapped[rune(t[i])] = true
        }
    }
    return true
}


// Time Complexity: O(n)
// Space Complexity: O(1)
