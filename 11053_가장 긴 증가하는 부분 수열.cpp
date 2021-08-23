#include<stdio.h>
#include<algorithm>
using namespace std;
int main(void) {
	int a[1001] = { 0 }, n, i, j, dp[1001] = { 0 };
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		dp[i] = 1;
	}
	for (i = 1; i <= n - 1; i++) {
		for (j = i + 1; j <= n; j++) {
			if (a[i] < a[j]) {
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
	}
	int max = 0;
	for (i = 1; i <= n; i++) {
		if (max < dp[i])
			max = dp[i];
	}
	if (max == 0)max = 1;
	printf("%d", max);
	return 0;
}