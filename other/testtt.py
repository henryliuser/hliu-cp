from collections import defaultdict

a = 19 + 34 + 8 + 83 + 26 + 38 + 72.5 + 13 + 25.4 + 19 + 57.8 + 23 + 33.4 + 43 + 5 + 60.5
b = 33 + 64 + 8 + 99 + 28 + 47 + 83.0 + 17 + 50.0 + 52 + 62.0 + 36 + 35.0 + 55 + 5 + 61.0
# a += 250
# b += 300
hw = a/b
mt1 = 98 / 105
mt2 = 90 / 105
lab = 11/12
fin = 0.8
P = [hw, mt1, mt2, lab, fin]
W = [.45, .1, .1, .1, .25]
print(sum(P[i]*W[i] for i in range(5)))

hw = 6.5/9
proj = 4.5/5
mt1 = 54/60
mt2 = 50/60
fin = 50/60
P2 = [hw, proj, mt1, mt2, fin]
W2 = [.15, .05, .25, .15, .4]
W3 = [.15, .05, .25, .25, .3]
s1 = sum(P2[i]*W2[i] for i in range(5))
s2 = sum(P2[i]*W3[i] for i in range(5))
print(s1, s2)

gpa = 0
c = defaultdict(int)
# g = [3,  3,  3, 4, 4,   4,  4]
# u = [12, 12, 9, 9, 5,   15, 9]
g = [2,  3,  4, 4, 4,   4,  4]
u = [12, 12, 9, 9, 5,   15, 9]
t = sum(u)
for i in range(len(u)):
    c[g[i]] += u[i]
for k,v in c.items():
    gpa += k*v/t
print(gpa)
