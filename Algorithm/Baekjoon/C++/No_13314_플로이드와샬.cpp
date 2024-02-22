/*
#include<stdio.h>
#include<algorithm>

#include<stdlib.h>
#define WRONG { printf("WA"); exit(1); }
#define CORRECT {printf("AC"); exit(0); }
using namespace std;

const int MX = 105;

int D[MX][MX], E[MX][MX];

int main()
{
	int N;
	scanf_s("%d", &N);
	if( N < 1 || N > 100 ) WRONG;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf_s("%d", D[i] + j);
			if( D[i][j] < 0 ) WRONG;
			if( i == j && D[i][j] != 0 || D[i][j] > 10000) WRONG;
			E[i][j] = D[i][j];
		}
	}
	for(int k = 1; k < N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
			}
		}
	}
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				E[i][j] = min(E[i][k] + E[k][j], E[i][j]);
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if( D[i][j] != E[i][j] ) cnt++;
		}
	}
	if( cnt >= 9700 ) CORRECT
	else WRONG;
}
*/

#include <iostream>

using namespace std;

int main()
{
	cout << 100 << '\n';
	for(int i=1; i<=100; i++)
	{
		for(int j=1; j<=100; j++)
		{
			if(i==j)
			{
				cout << 0 << ' ';
				continue;
			}
            
			if(i==100 || j==100)
			{
				cout << 1 << ' ';
				continue;
			}
            
			cout << 3 << '\n';
		}
	}
}