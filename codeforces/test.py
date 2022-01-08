ans = []
N = int(1e18+1)
for i in range(10):
    x = [i]
    for dx in range(10):
        while len(x) < 19:
            y = x[-1] + dx
            if y >= 10: break
            x += [y]
        ans += [int(''.join(map(str, x[::-1])))]
print(sorted(set(ans)))
