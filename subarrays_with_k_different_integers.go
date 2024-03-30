func findAtMostK(n int, k int, nums []int) int {
    ans, left, right := 0, 0, 0
    mp := make(map[int]int)

    for right < n {
        mp[nums[right]]++

        for len(mp) > k && left <= right {
            mp[nums[left]]--

            if mp[nums[left]] == 0 {
                delete(mp, nums[left])
            }
            left++
        }
        ans += right-left+1
        right++
    }
    return ans
}

func subarraysWithKDistinct(nums []int, k int) int {
    n := len(nums)
    return findAtMostK(n, k, nums) - findAtMostK(n, k-1, nums)
}


// Time Complexity : O(n)
// Space Complexity : O(n)
