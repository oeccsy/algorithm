#include <iostream>
#include <string>

using namespace std;

struct Member
{
    int age;
    int index;
    string name;
};

Member arr[100000];
Member temp[100000];

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
        else if(arr[index_l].age < arr[index_r].age)
        {
            temp[i] = arr[index_l];
            index_l++;
        }
        else if(arr[index_l].age > arr[index_r].age)
        {
            temp[i] = arr[index_r];
            index_r++;
        }
        else if(arr[index_l].index < arr[index_r].index)
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
        int input_age;
        string input_name;
        cin >> input_age >> input_name;

        Member new_member = {input_age, i, input_name};
        arr[i] = new_member;
    }

    MergeSort(0, n-1);

    for(int i=0; i<n; i++)
    {
        cout << arr[i].age << " " << arr[i].name << '\n';
    }
}