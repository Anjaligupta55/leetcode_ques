# class Solution:
#     def divide(self, dividend: int, divisor: int) -> int:

#         if (dividend <0 and divisor<0):
#             r=dividend//divisor
#             return r
#         if (dividend <0 or divisor<0):
#             a=-dividend if dividend<0 else dividend
#             b=-divisor if divisor<0 else divisor
#             r=a//b
#             return -r
        
#         r=dividend//divisor
#         return r
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # Define 32-bit integer limits
        INT_MAX = 2**31 - 1   # 2147483647
        INT_MIN = -2**31      # -2147483648

        # Handle overflow case
        if dividend == INT_MIN and divisor == -1:
            return INT_MAX  # Prevent overflow

        # Determine sign of the quotient
        negative = (dividend < 0) ^ (divisor < 0)  # XOR to determine if signs are different

        # Work with positive values
        dividend, divisor = abs(dividend), abs(divisor)

        quotient = 0

        # Bitwise subtraction using left shift
        while dividend >= divisor:
            temp, multiple = divisor, 1
            while dividend >= (temp << 1):  # Try doubling until it exceeds dividend
                temp <<= 1
                multiple <<= 1

            # Subtract the maximum multiple found
            dividend -= temp
            quotient += multiple

        # Apply the sign
        return -quotient if negative else quotient
