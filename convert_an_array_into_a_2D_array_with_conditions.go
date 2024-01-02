func findMatrix(nums []int) [][]int {
    mp := make(map[int]int)
    maxi := 0

    for _, num := range nums {
        mp[num]++
        maxi = max(maxi, mp[num])
    }

    ans := make([][]int, maxi)
    for num, count := range mp {
        for i := 0; i < count; i++ {
            ans[i] = append(ans[i], num)
        }
    }
    return ans
}

// Time Complexity : O(n)
// Space Complexity : O(n)