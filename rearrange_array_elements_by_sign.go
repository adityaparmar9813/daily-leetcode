func rearrangeArray(nums []int) []int {
    ans := make([]int, len(nums))
    positive, negative := 0, 1

    for index := 0; index < len(nums); index++ {
        if nums[index] > 0 {
            ans[positive] = nums[index]
            positive += 2
        } else {
            ans[negative] = nums[index]
            negative += 2
        }
    }
    return ans
}

// Time Complexity : O(n)
// Space Complexity : O(n)