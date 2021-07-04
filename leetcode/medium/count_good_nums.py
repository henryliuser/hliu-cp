class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = int(1e9 + 7)
        # fast mod exponentiation
        # compute: x^y % n
        def mod_exp(x, y, n):
            p = 1
            while y > 0:
                if y % 2 == 1:
                    p = p*x % n
                x = x*x % n
                y //= 2
            if p < 0: return p+n
            return p

        evens = ceil(n / 2)  # number of even positions
        odds = n // 2        # number of odd positions

        e = mod_exp(5, evens, MOD)  # ways to arrange evens
        o = mod_exp(4, odds, MOD)   # ways to arrange primes

        return int((e * o) % MOD)   # 
