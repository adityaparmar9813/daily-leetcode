func firstPalindrome(words []string) string {
    for _, word := range words {
        flag := false

        for i, j := 0, len(word)-1; i < j; i, j = i+1, j-1 {
            if word[i] != word[j] {
                flag = true
                break
            }
        }
        if !flag {
            return word
        }
    }
    return ""
}


// Time Complexity : O(n*m)
// Space Complexity : O(1)