func findDuplicate(nums []int) int {
    slow, fast := 0, 0

    for {
        slow = nums[slow]
        fast = nums[nums[fast]]

        if nums[slow] == nums[fast] {
            break
        }
    }

    slow = 0
    for slow != fast {
        slow = nums[slow]
        fast = nums[fast]
    }
    return fast
}

// Time Complexity : O(n)
// Space Complexity : O(1)