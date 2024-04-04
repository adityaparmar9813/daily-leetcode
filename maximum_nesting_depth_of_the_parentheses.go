func maxDepth(s string) int {
    curr, ans := 0, 0
    
    for _, ch := range s {
        if ch == '(' {
            curr++
        } else if ch == ')' {
            curr--
        }

        ans = max(curr, ans)
    }
    return ans
}

// Time Complexity : O(n)
// Space Complexity : O(1)
