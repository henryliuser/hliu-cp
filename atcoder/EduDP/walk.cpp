// https://atcoder.jp/contests/dp/tasks/dp_r
// matrix binary exponentiation
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int add(int i, int j) {
	if ((i += j) >= MOD)
		i -= MOD;
	return i;
}
int mul(int i, int j) {
	return int((long long) i * j % MOD);
}

template<class T> struct Matrix {
	T **mat; int a, b;

	Matrix() : a(0), b(0) {}
	Matrix(int a_, int b_) : a(a_), b(b_) {
		int i, j;

		mat = new T*[a];
		for (i = 0; i < a; ++i) {
			mat[i] = new T[b];
			for (j = 0; j < b; ++j)
				mat[i][j] = 0;
		}
	}
	Matrix(const vector<vector<T>>& vt) {
		int i, j;

		*this = Matrix((int) vt.size(), (int) vt[0].size());
		for (i = 0; i < a; ++i)
			for (j = 0; j < b; ++j)
				mat[i][j] = vt[i][j];
	}
	Matrix operator*(const Matrix& m) {
		int i, j, k;

		assert(b == m.a);
		Matrix r(a, m.b);
		for (i = 0; i < a; ++i)
			for (j = 0; j < m.b; ++j)
				for (k = 0; k < b; ++k)
					r.mat[i][j] = add(r.mat[i][j],
						mul(mat[i][k], m.mat[k][j]));
		return r;
	}
	Matrix& operator*=(const Matrix& m) {
		return *this = (*this) * m;
	}
	friend Matrix power(Matrix m, long long p) {
		int i;

		assert(m.a == m.b);
		Matrix r(m.a, m.b);
		for (i = 0; i < m.a; ++i)
			r.mat[i][i] = 1;
		for ( ; p > 0; p >>= 1, m *= m)
			if (p & 1)
				r *= m;
		return r;
	}
};


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;
    vector<vector<int>> adj(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> adj[i][j];

    ll ans = 0;
    Matrix<int> mat(adj);
    auto g_k = power(mat, K);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ans = add(ans, g_k.mat[i][j]);

    cout << ans << '\n';
}
