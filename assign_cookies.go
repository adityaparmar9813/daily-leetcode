func findContentChildren(g []int, s []int) int {
    sort.Ints(g)
    sort.Ints(s)

    i := 0
    for j := 0; j < len(s) && i < len(g); j++ {
        if g[i] <= s[j] {
            i++
        }
    }
    return i
}

// Time Complexity : O(n)
// Space Complexity : O(1)