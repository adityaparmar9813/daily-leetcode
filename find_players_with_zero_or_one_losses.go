func findWinners(matches [][]int) [][]int {
    output := make([][]int, 2)
    losses := make([]int, 100_001)

    output[0] = make([]int,0)
    output[1] = make([]int,0)

    for _, match := range matches {
        if losses[match[1]] == 0 {
            losses[match[1]] = 1
        }
        if losses[match[0]] == 0 {
            losses[match[0]] = 1
        }
        losses[match[1]]++
    }
    
    for player, score := range losses {
        if score == 1 {
            output[0] = append(output[0], player)
        } else if score == 2 {
            output[1] = append(output[1], player)
        }
    }
    return output
}

// Time Complexity: O(n)
// Space Complexity: O(n)

