#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10], b[10], n, ans = -12345;
bool check[10];
void f(int depth) {
	int i, score;
	if (depth == n) {
		score = 0;
		for (i = 1; i < n; i++) {
			score += (abs(b[i] - b[i - 1]));
		}
		ans = max(score, ans);
		return;
	}
	for (i = 0; i < n; i++) {
		if (check[i] == false) {
			check[i] = true;
			b[depth] = a[i];
			f(depth + 1);
			check[i] = false;
		}
	}
}
int main(void) {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	f(0);
	printf("%d", ans);
	return 0;
}