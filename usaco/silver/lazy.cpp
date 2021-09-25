// OFFICIAL EDITORIAL. NOT MY SOLUTION
// http://www.usaco.org/current/data/sol_lazy_silver.html
#include <fstream>

#define MAX 801

using namespace std;

int n,k,mat[MAX][MAX],best;

int main()
{
	ifstream fin("lazy.in");
	fin >> n >> k;
	// rotate the matrix 45 degrees
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			fin >> mat[i+j][n-i+j-1];
	fin.close();

	// 45 degree rotation expands the size of the matrix
	// it also includes the cells with half distance
	int t=(n+1)%2;	// t is used to avoid non-lattice points
	n=n*2-1;
	for (int i=0; i<n; i++,t=1-t)
	{
		// calculate the sum of 2k x 2k region
		// Bessie can only be positioned in lattice points
		int sum=0;
		for (int a=max(i-k,0); a<n && a<=i+k; a++)
			for (int b=max(t-k,0); b<n && b<=t+k; b++)
				sum+=mat[a][b];
		if (best<sum) best=sum;

		// slide the region
		for (int j=t+1; j+k<n; j++)
		{
			for (int a=max(i-k,0); a<n && a<=i+k; a++)
			{
				if (j-k-1>=0) sum-=mat[a][j-k-1];
				sum+=mat[a][j+k];
			}
			// update the sum only in lattice points
			if (j%2==t && best<sum) best=sum;
		}
	}

	ofstream fout("lazy.out");
	fout << best << endl;
	fout.close();
}
