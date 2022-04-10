# https://leetcode.com/contest/weekly-contest-288/problems/minimize-result-by-adding-parentheses-to-expression/
# troll question
class Solution:
    def minimizeResult(self, exp: str) -> str:

        def myeval(e):
            s = []
            a = e.find('(')
            s += [e[:a]]
            if a and e[a - 1] != '+':
                s += ['*']
            b = e.find(')')
            s += [e[a:b+1]]
            if b < len(e) - 1 and e[b + 1] != '+':
                s += ['*']
            s += [e[b+1:]]
            return eval(''.join(s))

        N = len(exp)
        ans = [eval(exp), '(' + exp + ')']
        p = exp.find('+')
        for i in range(p):
            for j in range(p+3, N+2):
                s = []
                c = 0
                for k in range(N + 2):
                    if k == i:
                        s += ['(']
                    elif k == j:
                        s += [')']
                    else:
                        s += [exp[c]]
                        c += 1
                try:
                    s = ''.join(s)
                    e = myeval(s)
                    if e < ans[0]:
                        ans = [e, ''.join(s)]
                except:
                    pass
        return ans[1]
