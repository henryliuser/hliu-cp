from collections import defaultdict

# 150
a = 19 + 34 + 8 + 83 + 26 + 38 + 72.5 + 13 + 25.4 + 19 + 57.8 + 23 + 33.4 + 43 + 5 + 60.5
b = 33 + 64 + 8 + 99 + 28 + 47 + 83.0 + 17 + 50.0 + 52 + 62.0 + 36 + 35.0 + 55 + 5 + 61.0
a += 90 + 18.75 + 37
b += 94 + 85 + 40
hw = a/b
mt1 = 98 / 105
mt2 = 80 / 100
lab = 12/13
fin = 0.81
P = [hw, mt1, mt2, lab, fin]
W = [.45, .1, .1, .1, .25]
print('150:', sum(P[i]*W[i] for i in range(5)))

# 241
hw = 226 / 300
proj = 3/5
mt1 = 53.9/60
mt2 = 29/60
fin = 4.6/7
P2 = [hw, proj, mt1, mt2, fin]
W2 = [.15, .05, .25, .15, .4]
W3 = [.15, .05, .25, .25, .3]
s1 = sum(P2[i]*W2[i] for i in range(5))
s2 = sum(P2[i]*W3[i] for i in range(5))
print('241:', s1, s2)

# 418
W418 = [0.08, 0.1, 0.11, 0.11, 0.11, .25, .12, .12]
P418 = [0.91, 0.86, 0.975, 0.825, 0.6, 0.8, 0.7, 0.8]
print('418:', sum(P418[i]*W418[i] for i in range(8)))

# 173
mt = 27.5/30
at = .64
qz = 11/23
fi = 21/30
W = [.15, .25, .3, .3]
G = [ at,  qz, mt, fi]
print('173:', sum(W[i]*G[i] for i in range(4)))

gpa = 0
c = defaultdict(int)
# g = [3,  3,  3, 3, 4,  4,  4, 4,  4]
# u = [12, 10, 10, 9, 5, 12, 12, 9, 5]
g = [3,  3,  2,  2, 4]#,  4,  4,  4, 4]
u = [12, 10, 10, 9, 5]#, 12, 12, 9, 5]
t = sum(u)
for i in range(len(u)):
    c[g[i]] += u[i]
for k,v in c.items():
    gpa += k*v/t
print(gpa)
