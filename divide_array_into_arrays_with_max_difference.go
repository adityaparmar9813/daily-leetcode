func divideArray(nums []int, k int) [][]int {
    var ans [][]int
    sort.Ints(nums)

    for i := 2; i < len(nums); i = i + 3 {
        if nums[i]-nums[i-2] > k {
            return nil
        }
        ans = append(ans, []int{nums[i-2], nums[i-1], nums[i]})
    }
    return ans
}

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
