func customSortString(order string, s string) string {
    mp := make([]int, 26)
    var ans []rune
    for _, val := range s {
        mp[val-'a']++
    }

    for _, val := range order {
        for mp[val-'a'] > 0 {
            ans = append(ans, val)
            mp[val-'a']--
        }
    }

    for ch := 0; ch < 26; ch++ {
        for mp[ch] > 0 {
            ans = append(ans, 'a'+rune(ch))
            mp[ch]--
        }
    }
    return string(ans)
}

// Time Complexity : O(n)
// Space Complexity : O(n)