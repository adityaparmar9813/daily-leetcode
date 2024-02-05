func firstUniqChar(s string) int {
    mp := make([]int, 26)

    for _, ch := range s {
        mp[ch - 'a']++
    }

    for index, ch := range s {
        if mp[ch - 'a'] == 1 {
            return index
        }
    }
    return -1
}

// Time Complexity : O(n)
// Space Complexity : O(1)