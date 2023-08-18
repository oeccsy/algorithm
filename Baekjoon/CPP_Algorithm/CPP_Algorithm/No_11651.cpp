#include <iostream>
#include <string>

using namespace std;

struct Point
{
    int x;
    int y;
};

Point arr[100000];
Point temp[100000];

void Merge(int start, int end)
{
    int mid = (start+end)/2;
    int index_l = start;
    int index_r = mid+1;

    for(int i=start; i<=end; i++)
    {
        if(index_l > mid)
        {
            temp[i] = arr[index_r];
            index_r++;
        }
        else if(index_r > end)
        {
            temp[i] = arr[index_l];
            index_l++;
        }
        else if(arr[index_l].y < arr[index_r].y)
        {
            temp[i] = arr[index_l];
            index_l++;
        }
        else if(arr[index_l].y > arr[index_r].y)
        {
            temp[i] = arr[index_r];
            index_r++;
        }
        else if(arr[index_l].x < arr[index_r].x)
        {
            temp[i] = arr[index_l];
            index_l++;
        }
        else
        {
            temp[i] = arr[index_r];
            index_r++;
        }
    }

    for(int i=start; i<=end; i++)
    {
        arr[i] = temp[i];
    }
}

void MergeSort(int start, int end)
{
    if(start >= end) return;

    MergeSort(start, (start+end)/2);
    MergeSort((start+end)/2 + 1, end);
    Merge(start, end);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int input_x;
        int input_y;
        cin >> input_x >> input_y;

        Point new_point = {input_x, input_y};
        arr[i] = new_point;
    }

    MergeSort(0, n-1);

    for(int i=0; i<n; i++)
    {
        cout << arr[i].x << " " << arr[i].y << '\n';
    }
}