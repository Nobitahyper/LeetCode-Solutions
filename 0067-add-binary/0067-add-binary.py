class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i, j = len(a) - 1, len(b) - 1
        carry = 0
        result = []
        
        # Traverse both strings from right to left
        while i >= 0 or j >= 0 or carry:
            bit_a = int(a[i]) if i >= 0 else 0
            bit_b = int(b[j]) if j >= 0 else 0
            
            # Compute the sum of bits and carry
            total = bit_a + bit_b + carry
            result.append(str(total % 2))  # Append the resulting bit
            carry = total // 2  # Update the carry
            
            i -= 1
            j -= 1
        
        # Reverse and join the result list to form the final string
        return ''.join(reversed(result))