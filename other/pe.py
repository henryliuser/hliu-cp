out = open('/Users/henryliu/Desktop/hliu-cp/other/e2.txt', 'w')
# with open("/Users/henryliu/Desktop/hliu-cp/other/e.txt", 'r') as f:
#     s = f.readline().strip()[1:-1]
#     s = s.split('},{')
#     out.write(f"{len(s)}\n")
#     for p in s:
#         p = tuple(map(int, p.strip('{}').split(',')))
#         out.write(f"{p[0]} {p[1]}\n")

V = int(1e5)
E = int(1.3*V)
edges = set()
