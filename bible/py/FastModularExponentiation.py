def mod_exp(x, y, n):
    p = 1
    while y > 0:
        if y % 2 == 1:
            p = p*x % n
        x = x*x % n
        y //= 2
    if p < 0: return p+n
    return p

# also:
pow(x, y, n)
