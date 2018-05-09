# Problem

	Codeforces 918Div1A - The monster

## Aproach

	Stack

## Solution

	If we ignore the question marks at this problem, it becomes a trivial balanced parentheses problem, then we could keep a counter to represent a stack and if the input is '(' we increment the counter, otherwise the input is ')' and we decrement the counter. If in any moment the counter is negative the input is not balanced, because there is at least one close parentheses without open. If not, we just have to check at the end if the counter is 0, because if it is not 0 there is at least one open parentheses without close.

	So, including the question marks in the problem, we can aproach it in a similar way, but now, keeping an auxiliar counter to the question markers. If at some moment, the question markers counter is greater than the stack counter, it means that there is a closed parentheses without open and a question marker before that parentheses. So, we can "use" that question marker as an open parentheses. Now, we have to check the other conditions. If at some moment the stack counter is negative, there is a closed parentheses without open or possible question marker to replace it, the sequence is not balanced, and in the end we have just to check if the question markers counter is greater or equal the stack counter and the sequence is even, because in this case we can use the question markers to close the opened parentheses and the sequence is balanced, otherwise the sequence is not balanced.

## Complexity

	How the input string has at most 5000 characters, we can check the property for each substring. Then we get a O(n^2) complexity. 
	
