#include <stdio.h>
#include <limits.h>

int a[100][100];

int floyd(int n)
{
	int i, j, k;
	int ans = 0;

	for (k = 0; k < n; k++)
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		if (a[i][k] != INT_MAX &&
			a[k][j] != INT_MAX &&
			a[i][k] + a[k][j] < a[i][j])
			a[i][j] = a[i][k] + a[k][j];
	for (i = 0; i < n; i++)
	for (j = 0; j < i; j++)
	{
		if (a[i][j] == INT_MAX)
			return -1;
		if (a[i][j] > ans)
			ans = a[i][j];
	}
	return ans;
}

int main(int argc, char* argv[])
{
	int n, i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	{
		scanf("%d", &a[i][j]);
		if (i == j)
			a[i][j] = 0;
		else if (!a[i][j])
			a[i][j] = INT_MAX;
	}
	printf("%d\n", floyd(n));

	return 0;
}
