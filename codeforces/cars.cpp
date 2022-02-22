// https://codeforces.com/contest/1635/problem/E
// build a graph with cars as nodes and restrictions as edges
// (track the types for each edge)
// if between 2 nodes are 2 different edges, obviously NO
// dfs to check bipartite-ness of graph
// if not bipartite then NO
// reasoning: if 2 cars destined then they have opposite direction
// if 2 cars irrelevant, they also have opposite direction
// if graph is not bipartite, then some of these opposite
// restrictions have been violated.
// After arbitrarily assigning some direction to the first,
// we have some position restrictions based on L's and R's
// Top sorting these positional restrictions forms a solution
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

}
