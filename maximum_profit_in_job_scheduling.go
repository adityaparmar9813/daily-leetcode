func jobScheduling(startTime []int, endTime []int, profit []int) int {
    N := len(startTime)
    jobs := [][3]int{}
    for i:=0; i<N; i++ {
        jobs = append(jobs, [3]int{startTime[i], endTime[i], profit[i]})
    }
    
    sort.Slice(jobs, func(i, j int) bool {
        return jobs[i][0] < jobs[j][0]
    })
    
    memo := map[int]int{}
    
    var dfs func(i int) int
    dfs = func(i int) int {        
        if i == N {
            return 0
        }
        if v, ok := memo[i]; ok {
            return v
        }

        profit1 := dfs(i+1)
        l, r := i+1, N
        for l < r {
            mid := l + (r-l)/2
            if jobs[mid][0] < jobs[i][1] {
                l = mid + 1
            } else {
                r = mid
            }
        }
        profit2 := jobs[i][2] + dfs(l)   
        memo[i] = max(profit1, profit2)
        return memo[i]
    }
    return dfs(0)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

// Time Complexity : O(nlog(n))
// Space Complexity : O(n)