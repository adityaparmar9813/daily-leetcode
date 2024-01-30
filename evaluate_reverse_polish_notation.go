func evalRPN(tokens []string) int {
    stack := []int{}

    for i := 0; i < len(tokens); i++ {
        if isOperator(tokens[i]) {
            doOperation(&stack, tokens[i])
        } else {
            num, _ := strconv.Atoi(tokens[i])
            stack = append(stack, num)
        }
    }

    return stack[0]
}

func isOperator(op string) bool {
    if op == "+" || op == "-" || op == "*" || op == "/" {
        return true
    }
    return false
}

func doOperation(stack *[]int, op string) {
    num2 := (*stack)[len(*stack)-1]
    num1 := (*stack)[len(*stack)-2]
    *stack = (*stack)[:len(*stack)-2]

    res := 0
    if op == "+" {
        res = num1 + num2
    } else if op == "-" {
        res = num1 - num2
    } else if op == "*" {
        res = num1 * num2
    } else {
        res = num1 / num2
    }
    *stack = append(*stack, res)
}

// Time Complexity : O(n)
// Space Complexity : O(n)
