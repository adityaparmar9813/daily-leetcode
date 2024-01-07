func numberOfArithmeticSlices(nums []int) int {
    n := len(nums)
    if n < 3 {
        return 0
    }

    dp := make([]map[int]map[int]int, n) 
    m1 := map[int]int{}
    m2 := map[int]map[int]int{}
    dp[0] = map[int]map[int]int{}

    m1[2] = 1
    m2[nums[1]-nums[0]] = m1
    dp[1] = m2

    res := 0
    for i:=2; i < n; i++ {
        m2 := map[int]map[int]int{}
        tempRes := 0
        for j:=i-1; j >= 0; j-- {
            m1 := map[int]int{}
            diff := nums[i]-nums[j]
            if _, exist := m2[diff]; !exist {
                m2[diff] = m1
            }

            if _, exist := dp[j][diff]; exist {
                for k, v := range dp[j][diff] {
                    m2[diff][k+1] += v
                    if k+1 >= 3 {
                        tempRes += v
                    }
                }
            }
            m2[diff][2] += 1
        } 
        dp[i] = m2 
        res += tempRes
    }
    return res
}

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)