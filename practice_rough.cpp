#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int solve(vector<vector<int>> &mat, int i, int j, int &n, int &m)
// {
// 	if ((i < 0 || i >= n) || (j < 0 || j >= m))
// 	{
// 		return -1;
// 	}
// 	if (mat[i][j] == 0)
// 	{
// 		return 0;
// 	}
// 	int left = 1 + solve(mat, i, j, n, m);
// 	int right = 1 + solve(mat, i + 1, j, n, m);
// 	int up = 1 + solve(mat, i, j - 1, n, m);
// 	int down = 1 + solve(mat, i, j + 1, n, m);

// 	int ans = max(max(left, right), max(up, down));
// 	return ans;
// }
// vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
// {
// 	int n = mat.size();
// 	int m = mat[0].size();
// 	vector<vector<int>> ans(n, vector<int>(m));
// 	for (int i = 0; i < n; i++)
// 	{
// 		for (int j = 0; j < m; j++)
// 		{
// 			if (mat[i][j] == 0)
// 			{
// 				ans[i][j] = 0;
// 			}
// 			else
// 			{
// 				ans[i][j] = solve(mat, i, j, n, m);
// 			}
// 		}
// 	}
// 	return ans;
// }

// int main()
// {
// 	vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
// 	vector<vector<int>> ans = updateMatrix(grid);
// 	for (int i = 0; i < 3; i++)
// 	{
// 		for (int j = 0; j < 3; j++)
// 		{
// 			cout << ans[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }
vector<int> solve(int n)
{
	vector<int> ans;
	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			ans.push_back(i);
			n /= i;
		}
	}
	if (n > 1)
	{
		ans.push_back(n);
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	vector<int> ans = solve(n);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}