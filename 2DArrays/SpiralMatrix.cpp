#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 6

void spiralPrint(int m, int n, int a[R][C])
{
	int i, k = 0, l = 0;

	/* k - starting row index
		m - ending row index
		l - starting column index
		n - ending column index
		i - iterator
	*/

	while (k < m && l < n) {
        
        // to print the starting row
		for (i = l; i < n; ++i) {
			cout << a[k][i] << " ";
		}
		k++;

        // to print the ending col
		for (i = k; i < m; ++i) {
			cout << a[i][n - 1] << " ";
		}
		n--;

		// Print the ending row in reverse order
		if (k < m) {
			for (i = n - 1; i >= l; --i) {
				cout << a[m - 1][i] << " ";
			}
			m--;
		}

		// print the starting col in reverse order
		if (l < n) {
			for (i = m - 1; i >= k; --i) {
				cout << a[i][l] << " ";
			}
			l++;
		}
	}
}

int main()
{
	int a[R][C] = { { 1, 2, 3, 4, 5, 6 },
					{ 7, 8, 9, 10, 11, 12 },
					{ 13, 14, 15, 16, 17, 18 } };

	spiralPrint(R, C, a);

	return 0;
}

