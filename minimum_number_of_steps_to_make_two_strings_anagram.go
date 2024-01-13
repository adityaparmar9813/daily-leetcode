func minSteps(s string, t string) int {
    mp := make([]int, 26)
    ans := 0

    for i:=0; i< len(s); i++ {
        mp[s[i]-'a']++
        mp[t[i]-'a']--
    }

    for i:=0; i < 26; i++ {
        if mp[i] > 0 {
            ans += mp[i]
        }
    }

    return ans
}

// Time Complexity: O(n)
// Space Complexity: O(1)
