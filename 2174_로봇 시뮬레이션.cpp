#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int n, m, robotNum, cmdNum;
vector <pair<int, pair<int, int>>>v;
int check[101][101];
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
int main(void) {
	cin.tie(0);
	int i, j;
	scanf("%d %d", &m, &n);
	scanf("%d %d", &robotNum, &cmdNum);
	v.resize(103);
	for (i = 1; i <= robotNum; i++) {
		int x = 0, y = 0;
		char dir = 0;
		cin >> x >> y >> dir;
		y = n - y + 1;
		check[y][x] = i;//로봇의 번호를 저장
		if (dir == 'E')v[i] = { y,{x,0} };
		else if (dir == 'S')v[i] = { y,{x,1} };
		else if (dir == 'W')v[i] = { y,{x,2} };
		else if (dir == 'N')v[i] = { y,{x,3} };
	}
	for (i = 1; i <= cmdNum; i++) {
		int num = 1, rep = 0;
		char op = 0;
		cin >> num >> op >> rep;
		int startY = v[num].first;
		int startX = v[num].second.first;
		int key = v[num].second.second;//우하좌상, 0123
		int newKey = key;
		int cnt = 0;
		if (op == 'F') {
			int curX = startX, curY = startY;
			while (cnt < rep) {
				curX += dx[key];
				curY += dy[key];
				if (curY > n || curX > m || curX <= 0 || curY <= 0) {//벽과 충돌
					printf("Robot %d crashes into the wall", num);
					goto AllBreak;
				}
				if (check[curY][curX] != 0) {//로봇과 충돌
					printf("Robot %d crashes into robot %d", num, check[curY][curX]);
					goto AllBreak;
				}
				cnt++;
			}
			check[startY][startX] = 0;
			check[curY][curX] = num;
			v[num] = { curY,{curX,key} };
			continue;
		}
		else if (op == 'L') {
			rep %= 4;
			for (int T = 0; T < rep; T++) {
				newKey--;
				if (newKey == -1)newKey = 3;
			}
			v[num] = { startY,{startX,newKey} };
			continue;
		}
		else if (op == 'R') {
			rep %= 4;
			for (int T = 0; T < rep; T++) {
				newKey = (newKey + 1) % 4;
			}
			v[num] = { startY,{startX,newKey} };
			continue;
		}
	}
	printf("OK\n");
AllBreak:
	return 0;
}