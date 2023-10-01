#include <algorithm>
#include <iostream>
using namespace std;

int cutRod(int prices[], int n)
{
	int mat[n + 1][n + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				mat[i][j] = 0;
			}
			else {
				if (i == 1) {
					mat[i][j] = j * prices[i - 1];
				}
				else {
					if (i > j) {
						mat[i][j] = mat[i - 1][j];
					}
					else {
						mat[i][j] = max(prices[i - 1]
											+ mat[i][j - i],
										mat[i - 1][j]);
					}
				}
			}
		}
	}

	return mat[n][n];
}

int main()
{
	int prices[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int n = sizeof(prices) / sizeof(prices[0]);

	cout << "Maximum obtained value is "
		<< cutRod(prices, n) << endl;
}
