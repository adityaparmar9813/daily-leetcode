func climbStairs(n int) int {
    if n <= 2 {
        return n
    }
    a, b := 1, 2

    for i:=n-3; i >= 0; i-- {
        temp := a+b
        a = b
        b = temp
    }
    return b
}

// Time Complexity: O(n)
// Space Complexity: O(1)
