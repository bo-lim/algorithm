#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define size 50

int main() {
	int n = 0, m = 0, t = 0;
	int x[size] = { 0, }, d[size] = { 0, }, k[size] = { 0, };
	int s = 0;//t-1까지

	//입력
	scanf(" %d", &n);
	scanf(" %d", &m);
	scanf(" %d", &t);

	int disk[size][size] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &disk[i][j]);
		}
	}

	for (int i = 0; i < t; i++) {
		scanf("%d", &x[i]);
		scanf("%d", &d[i]);
		scanf("%d", &k[i]);
	}


	//회전
	int a = 1;//곱
	int i = 0;
	int j = 0;
	int num = 1;//지금 회전할 원판번호
	int disk2[size][size] = { 0, };
	int disk3[size][size] = { 0, };
	while (s <= t-1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				disk2[i][j] = disk[i][j];
			}
		}
		a = 1;
		while (x[s] * a <= n) {

			num = x[s] * a-1;
			if (d[s] == 0) {//시계방향
				//printf("1");
				for (j = 0; j < m; j++) {
					if (j - k[s] < 0) {
						disk2[num][j] = disk[num][j - k[s]+m];
					}
					else {
						disk2[num][j] = disk[num][j - k[s]];
					}
				}
				//disk2[num][0] = disk[num][m - k[s]];
			}
			else if (d[s] == 1) {//반시계방향
				//printf("2");
				for (int j = 0; j < m; j++) {
					if (j + k[s] > m-1) {
						disk2[num][j] = disk[num][j + k[s]-m];
					}
					else {
						disk2[num][j] = disk[num][j + k[s]];
					}
				}
			}

			a++;
		
		}
		s++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				disk3[i][j] = disk2[i][j];
			}
		}

		//중복 검사
		for (i = 0; i < n; i++) {
			for (j = 1; j < m - 1; j++) {

				if (disk2[i][j] == disk2[i][j + 1]) {
					disk3[i][j] = 0;
					disk3[i][j + 1] = 0;
				}
				if (disk2[i][j] == disk2[i][j - 1]) {
					disk3[i][j] = 0;
					disk3[i][j - 1] = 0;
				}
			}
			if (disk2[i][0] == disk2[i][1]) {
				disk3[i][0] = 0;
				disk3[i][1] = 0;
			}
			if (disk2[i][0] == disk2[i][m - 1]) {
				disk3[i][0] = 0;
				disk3[i][m - 1] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				disk[i][j] = disk3[i][j];
			}
		}
		for (int i = 1; i < n - 1; i++) {
			for (j = 0; j < m; j++) {
				if (disk3[i][j] == disk3[i + 1][j]) {
					disk[i][j] = 0;
					disk[i + 1][j] = 0;
				}
				if (disk3[i][j] == disk3[i - 1][j]) {
					disk[i][j] = 0;
					disk[i - 1][j] = 0;
				}
			}
			if (disk3[0][j] == disk3[1][j]) {
				disk[0][j] = 0;
				disk[1][j] = 0;
			}
			if (disk3[0][j] == disk3[n - 1][j]) {
				disk[0][j] = 0;
				disk[n - 1][j] = 0;
			}
		}
		//s++;
	}

		
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//printf("%d ", disk[i][j]);
			total += disk[i][j];
		}
	}
	printf("%d", total);
}
