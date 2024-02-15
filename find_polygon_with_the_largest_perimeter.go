func largestPerimeter(nums []int) int64 {
    sort.Ints(nums)
    ans := int64(0) 
    for _, num := range nums {
        ans += int64(num)
    }

    for i := len(nums)-1; i >= 2; i-- {
        if ans > int64(nums[i]*2) {
            return ans
        }
        ans -= int64(nums[i])
    }
    return -1
}

// Time Complexity : O(n*log(n))
// Space Complexity : O(1)