func lengthOfLastWord(s string) int {
    count, index := 0, len(s)-1
    
    for s[index] == ' ' {
        index--
    }
    
    for i := index; i >= 0; i-- {
        if s[i] == ' ' {
            return count
        }
        count++
    }
    return count
}
