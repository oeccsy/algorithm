#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 모든 원소 초기화
// c-style 배열은 함수에 매개변수로 전달하거나 반환하는데 주의가 필요함
// - 매개변수로 전달하는 경우 크기 정보가 같이 필요함
// - 함수 내에서 만들어진 경우 안전하게 반환할 수 없음 (stack에 할당하기 때문)

void Init(int* target, int size)
{
	for (int i = 0; i < size; ++i)
	{
		target[i] = 2 * i;
	}
}

// 부분 배열 초기화
void Init(int* target, int* base, int st, int en)
{
	for (int i = 0; i < en - st; ++i)
	{
		target[i] = base[st + i];
	}
}


// 모든 원소 출력
void Print(int* target, int size)
{
	cout << "======== 1차원 배열 출력 ========" << '\n';
	for (int i = 0; i < size; ++i)
	{
		cout << target[i] << ' ';
	}
	cout << '\n';
}


// 원하는 Node를 복잡한 조건으로 정렬하기
struct Node
{
	int x;
	int y;
};

bool Compare(const Node& a, const Node& b)
{
	if (a.x != b.x)
	{
		return a.x < b.x;
	}
	else
	{
		return a.y > b.y;
	}
}

void Print(Node* target, int size);

void CustomSort(Node* target, int size)
{
	cout << "======== Node 커스텀 정렬 ========" << '\n';
	Print(target, size);
	sort(target, target + size, Compare);
	Print(target, size);
}

void Print(Node* target, int size)
{
	cout << "======== 1차원 배열 출력 ========" << '\n';
	for (int i = 0; i < size; ++i)
	{
		cout << '(' << target[i].x << ',' << target[i].y << ") ";
	}
	cout << '\n';
}

// 배열 라이브러리
bool operator==(const Node& a, const Node& b)
{
	return (a.x == b.x) && (a.y == b.y);
}

bool Find(Node* arr, int size, Node target)
{
	auto it = find(arr, arr + size, target);
	bool find = (it != arr + size);

	return find;
}
	
// 이분탐색
void ViewBinarySearch(int* arr, int size, int target)
{
	Print(arr, size);

	bool is_found = binary_search(arr, arr + size, target);
	cout << "binary_search : " << is_found << '\n';

	int* it_lower = lower_bound(arr, arr + size, target);
	cout << "lower_bound : " << it_lower - arr << '\n';

	int* it_upper = upper_bound(arr, arr + size, target);
	cout << "upper_bound : " << it_upper - arr << '\n';

	cout << "target보다 작은 원소 개수 : " << it_lower - arr << '\n';
	cout << "target과 같은 원소 개수 : " << it_upper - it_lower << '\n';
	cout << "target보다 큰 원소 개수 : " << arr + size - it_upper << '\n';
}

void ViewBinarySearchWithNode(Node* arr, int size, Node target)
{
	Print(arr, size);
	
	bool is_found = binary_search(arr, arr + size, target, Compare);
	cout << "binary_search : " << is_found << '\n';

	auto it_lower = lower_bound(arr, arr + size, target, Compare);
	cout << "lower_bound : " << it_lower - arr << '\n';

	auto it_upper = upper_bound(arr, arr + size, target, Compare);
	cout << "upper_bound : " << it_upper - arr << '\n';

	cout << "target보다 작은 원소 개수 : " << it_lower - arr << '\n';
	cout << "target과 같은 원소 개수 : " << it_upper - it_lower << '\n';
	cout << "target보다 큰 원소 개수 : " << arr + size - it_upper << '\n';
}

bool operator<(const Node& a, const Node& b)
{
	if (a.x != b.x)
	{
		return a.x < b.x;
	}
	else
	{
		return a.y > b.y;
	}
}

void ViewBinarySearchWithOperator(Node* arr, int size, Node target)
{
	Print(arr, size);

	bool is_found = binary_search(arr, arr + size, target);
	cout << "binary_search : " << is_found << '\n';

	auto it_lower = lower_bound(arr, arr + size, target);
	cout << "lower_bound : " << it_lower - arr << '\n';

	auto it_upper = upper_bound(arr, arr + size, target);
	cout << "upper_bound : " << it_upper - arr << '\n';

	cout << "target보다 작은 원소 개수 : " << it_lower - arr << '\n';
	cout << "target과 같은 원소 개수 : " << it_upper - it_lower << '\n';
	cout << "target보다 큰 원소 개수 : " << arr + size - it_upper << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// =============================

	int arr[10];
	
	Init(arr, 10);
	Print(arr, 10);

	// =============================

	Node nodes[10];

	nodes[0] = { 5, 0 };
	nodes[1] = { 1, 3 };
	nodes[2] = { 2, 5 };
	nodes[3] = { 2, 2 };
	nodes[4] = { 1, 2 };
	nodes[5] = { 4, 4 };
	nodes[6] = { 3, 7 };
	nodes[7] = { 4, 7 };
	nodes[8] = { 4, 7 };
	nodes[9] = { 4, 7 };

	CustomSort(nodes, 10);

	// =============================

	sort(arr, arr + 10);
	ViewBinarySearch(arr, 10, 5);

	// =============================

	ViewBinarySearchWithNode(nodes, 10, { 2, 2 });
	ViewBinarySearchWithOperator(nodes, 10, { 2, 2 });
}
