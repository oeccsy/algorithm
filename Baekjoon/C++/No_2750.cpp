#include <iostream>

using namespace std;

int arr[1001];
int tmp[1001];
int n;

void MergeSort(int p, int q);
void Merge(int p, int q);

int main()
{
  cin >> n;
  
  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }
  
  MergeSort(0, n-1);

  for(int i=0; i<n; i++)
  {
    cout << arr[i] <<'\n';
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

void Merge(int p , int q)
{
  if(p < q)
  {
    int k = (p+q)/2;
    int low = p;
    int high = k+1;

    for(int i=p; i<=q; i++)
    {
      if(high == q+1)
        tmp[i] = arr[low++];
      else if(low == k+1)
        tmp[i] = arr[high++];
      else if(arr[low] < arr[high])
        tmp[i] = arr[low++];
      else
        tmp[i] = arr[high++];
    }

    for(int i=p; i<=q; i++)
      arr[i] = tmp[i];
  }
}