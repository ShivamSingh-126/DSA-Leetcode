class Solution:
    def threeFibonacciSum(self, n: int) -> bool:
        
        # The sum must be even and at least 2 (0 + 1 + 1)
        if n % 2 != 0 or n < 2:
            return False
        
        target = n // 2
        
        # Generate Fibonacci numbers to check if target exists in the sequence
        a, b = 1, 1
        while a < target:
            a, b = b, a + b
            
        return a == target