#include <iostream>

using namespace std;

int n;

int arr[1000001];
int tmp[1000001];

void Input();
void MergeSort(int p, int q);
void Merge(int p, int q);
void Output();

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  Input();
  MergeSort(0, n-1);

  Output();
}

void Input()
{
  
  cin >> n;

  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }
}

void MergeSort(int p, int q)
{
  if(p < q)
  {
    int k = (p+q)/2;
    MergeSort(p, k);
    MergeSort(k+1, q);
    Merge(p, q);
  }
}

void Merge(int p, int q)
{
  int k = (p+q)/2;
  int low = p;
  int high = k+1;
  for(int i=p; i<=q; i++)
  {
    if(low == k+1)
      tmp[i] = arr[high++];
    else if(high == q+1)
      tmp[i] = arr[low++];
    else if(arr[low] <= arr[high])
      tmp[i] = arr[low++];
    else
      tmp[i] = arr[high++];
  }

  for(int i=p; i<=q; i++)
    arr[i] = tmp[i];
}

void Output()
{
  for(int i =0; i<n; i++)
  {
    cout << arr[i] << '\n';
  }
}