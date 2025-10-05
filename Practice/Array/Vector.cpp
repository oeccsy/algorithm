#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 모든 원소 초기화
void Init(vector<int>& target)
{
	// vector<int> target(10, 10);
	target = vector<int>(10, 10);
}

void Init(vector<vector<int>>& target)
{
	// vector<vector<int>> target(5, vector<int>(10, 10));
	target = vector<vector<int>>(5, vector<int>(10, 10));
}

// 부분 배열 초기화
void Init(vector<int>& base, vector<int>& target)
{
	target = vector<int>(base.begin() + 1, base.end() - 1);
	// O(n)에 동작하는 로직이다.
	// O(1)에 수행하고 싶다면 투포인터로 참조하는 방법이 있다.
}


// 모든 원소 출력
void Print(vector<int>& target)
{
	cout << "======== 1차원 배열 출력 ========" << '\n';
	for (int i = 0; i < target.size(); ++i)
	{
		cout << target[i] << ' ';
	}
	cout << '\n';
}

void Print(vector<vector<int>>& target)
{
	cout << "======== 2차원 배열 출력 ========" << '\n';
	for (int i = 0; i < target.size(); ++i)
	{
		for (int j = 0; j < target[0].size(); ++j)
		{
			cout << target[i][j] << ' ';
		}
		cout << '\n';
	}
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

void Print(vector<Node>& target);
void Print(vector<Node*> target);

void CustomSort(vector<Node>& target)
{
	cout << "======== Node 커스텀 정렬 ========" << '\n';
	Print(target);
	sort(target.begin(), target.end(), Compare);
	Print(target);
}

void Print(vector<Node>& target)
{
	cout << "======== 1차원 배열 출력 ========" << '\n';
	for (int i = 0; i < target.size(); ++i)
	{
		cout << '(' << target[i].x << ',' << target[i].y << ") ";
	}
	cout << '\n';
}

void Print(vector<Node*> target)
{
	cout << "======== 1차원 배열 출력 ========" << '\n';
	for (int i = 0; i < target.size(); ++i)
	{
		cout << '(' << target[i]->x << ',' << target[i]->y << ") ";
	}
	cout << '\n';
}

// 배열 라이브러리
bool Find(vector<int>& vec, int target)
{
	auto it = find(vec.begin(), vec.end(), target);
	bool find = (it != vec.end());

	return find;
}

void ViewRemove()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);

	Print(vec);	// 1 2 3 2 4
	remove(vec.begin(), vec.end(), 2);
	Print(vec); // 1 3 4 2 4
}

// 이분탐색
void ViewBinarySearch(vector<int>& vec, int target)
{
	Print(vec);

	bool is_found = binary_search(vec.begin(), vec.end(), target);
	cout << "binary_search : " << is_found << '\n';

	auto it_lower = lower_bound(vec.begin(), vec.end(), target);
	cout << "lower_bound : " << it_lower - vec.begin() << '\n';

	auto it_upper = upper_bound(vec.begin(), vec.end(), target);
	cout << "upper_bound : " << it_upper - vec.begin() << '\n';

	cout << "target보다 작은 원소 개수 : " << it_lower - vec.begin() << '\n';
	cout << "target과 같은 원소 개수 : " << it_upper - it_lower << '\n';
	cout << "target보다 큰 원소 개수 : " << vec.end() - it_upper << '\n';
}

void ViewBinarySearchWithNode(vector<Node>& vec, Node target)
{
	Print(vec);

	bool is_found = binary_search(vec.begin(), vec.end(), target, Compare);
	cout << "binary_search : " << is_found << '\n';

	auto it_lower = lower_bound(vec.begin(), vec.end(), target, Compare);
	cout << "lower_bound : " << it_lower - vec.begin() << '\n';

	auto it_upper = upper_bound(vec.begin(), vec.end(), target, Compare);
	cout << "upper_bound : " << it_upper - vec.begin() << '\n';

	cout << "target보다 작은 원소 개수 : " << it_lower - vec.begin() << '\n';
	cout << "target과 같은 원소 개수 : " << it_upper - it_lower << '\n';
	cout << "target보다 큰 원소 개수 : " << vec.end() - it_upper << '\n';
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

void ViewBinarySearchWithOperator(vector<Node>& vec, Node target)
{
	Print(vec);

	bool is_found = binary_search(vec.begin(), vec.end(), target);
	cout << "binary_search : " << is_found << '\n';

	auto it_lower = lower_bound(vec.begin(), vec.end(), target);
	cout << "lower_bound : " << it_lower - vec.begin() << '\n';

	auto it_upper = upper_bound(vec.begin(), vec.end(), target);
	cout << "upper_bound : " << it_upper - vec.begin() << '\n';

	cout << "target보다 작은 원소 개수 : " << it_lower - vec.begin() << '\n';
	cout << "target과 같은 원소 개수 : " << it_upper - it_lower << '\n';
	cout << "target보다 큰 원소 개수 : " << vec.end() - it_upper << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// ========================

	vector<int> vec1;
	vector<int> vec2;

	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(5);
	vec1.push_back(6);
	vec1.push_back(7);
	vec1.push_back(8);

	Init(vec1, vec2);
	Print(vec1);
	Print(vec2);

	/// ========================

	vector<Node> vec3;
	vec3.push_back({ 5, 0 });
	vec3.push_back({ 1, 3 });
	vec3.push_back({ 2, 5 });
	vec3.push_back({ 2, 2 });
	vec3.push_back({ 1, 2 });
	vec3.push_back({ 4, 4 });
	vec3.push_back({ 3, 7 });
	vec3.push_back({ 4, 7 });

	CustomSort(vec3);

	/// ========================

	vector<int> vec4;
	vec4.push_back(1);
	vec4.push_back(1);
	vec4.push_back(1);
	vec4.push_back(2);
	vec4.push_back(2);
	vec4.push_back(2);
	vec4.push_back(3);
	vec4.push_back(3);
	vec4.push_back(3);
	vec4.push_back(4);
	vec4.push_back(4);
	vec4.push_back(4);

	ViewBinarySearch(vec4, 3);
	ViewBinarySearchWithNode(vec3, { 2, 2 });
	ViewBinarySearchWithOperator(vec3, { 3, 7 });
}
