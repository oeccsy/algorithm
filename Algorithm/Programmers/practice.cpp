#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

int main()
{
    unordered_map<int, int> u_map;
    unordered_set<int> u_set;
    unordered_multimap<int, int> u_mmap;
    unordered_multiset<int> u_mset;
    map<int, int> map;
    set<int> set;
    multimap<int, int> mmap;
    multiset<int> mset;

    cout << u_map[10] << endl;
    //cout << u_set[10] << endl;
    //cout << u_mmap[10] << endl;
    //cout << u_mset[10] << endl;
    cout << map[10] << endl;
    //cout << set[10] << endl;
    //cout << mmap[10] << endl;
    //cout << mset[10] << endl;
}