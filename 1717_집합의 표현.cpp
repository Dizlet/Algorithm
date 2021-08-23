#include<stdio.h>
int n, m;
int a[1000001];
void _union(int x, int y);
int _find(int x);
void _union(int x, int y) {
	int px, py;
	px = _find(x);
	py = _find(y);
	if (px > py)a[px] = py;
	else if (px < py)a[py] = px;
}
int _find(int x) {
	if (x == a[x])return x;
	return a[x] = _find(a[x]);
}
int main(void) {
	int i;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		a[i] = i;
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)_union(b, c);
		else {
			if (_find(b) == _find(c))printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}