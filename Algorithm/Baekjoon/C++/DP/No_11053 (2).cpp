#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int d[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		d[i] = 1;
	}

	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<i; j++)
		{
			if(a[i] > a[j])
			{
				d[i] = max(d[i], d[j] + 1);	
			}	
		}
	}
	
	int max = 0;
	for(int i=1; i<=n; i++)
	{
		if(d[i] > max) max = d[i];
	}
	
	cout << max;
}