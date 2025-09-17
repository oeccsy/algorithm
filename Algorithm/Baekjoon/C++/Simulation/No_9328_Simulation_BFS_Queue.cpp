#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int h;
	int w;
};

struct Door
{
	int h;
	int w;

	char value;
};

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

int h, w;
char building[100][100];
bool isVisit[100][100];
bool hasKey[26];

int answer = 0;

void Init()
{
	cin >> h >> w;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> building[i][j];
			isVisit[i][j] = false;
		}
	}

	for (int i = 0; i < 26; ++i)
	{
		hasKey[i] = false;
	}

	string keyInput;
	cin >> keyInput;

	if (keyInput != "0")
	{
		for (int i = 0; i < keyInput.size(); ++i)
		{
			int index = keyInput[i] - 'a';
			hasKey[index] = true;
		}
	}

	answer = 0;
}

void InitQueues(queue<Node>& bfsQueue, queue<Door>& doorQueue)
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (building[i][j] == '*') continue;

			if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
			{
				isVisit[i][j] = true;

				if ('A' <= building[i][j] && building[i][j] <= 'Z')
				{
					Door door;
					door.h = i;
					door.w = j;
					door.value = building[i][j];

					doorQueue.push(door);
				}
				else
				{
					bfsQueue.push({ i, j });
				}

				if (building[i][j] == '$') ++answer;

				if ('a' <= building[i][j] && building[i][j] <= 'z')
				{
					char key = building[i][j];
					int index = key - 'a';
					hasKey[index] = true;
				}
			}
		}
	}
}

void BFS(queue<Node>& bfsQueue, queue<Door>& doorQueue)
{
	while (!bfsQueue.empty())
	{
		Node curNode = bfsQueue.front();
		bfsQueue.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextH = curNode.h + dr[i];
			int nextW = curNode.w + dc[i];

			if (nextH < 0 || nextW < 0 || nextH >= h || nextW >= w) continue;
			if (building[nextH][nextW] == '*') continue;
			if (isVisit[nextH][nextW]) continue;

			isVisit[nextH][nextW] = true;

			if ('A' <= building[nextH][nextW] && building[nextH][nextW] <= 'Z')
			{
				Door door;
				door.h = nextH;
				door.w = nextW;
				door.value = building[nextH][nextW];

				doorQueue.push(door);
			}
			else
			{
				bfsQueue.push({ nextH, nextW });
			}

			if (building[nextH][nextW] == '$')
				++answer;

			if ('a' <= building[nextH][nextW] && building[nextH][nextW] <= 'z')
			{
				char key = building[nextH][nextW];
				int index = key - 'a';
				hasKey[index] = true;
			}
		}
	}
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--)
	{
		Init();

		queue<Door> doorQueue;
		queue<Node> bfsQueue;
		InitQueues(bfsQueue, doorQueue);

		do
		{
			BFS(bfsQueue, doorQueue);

			queue<Door> doorQueueCopy = queue<Door>(doorQueue);

			while (!doorQueueCopy.empty())
			{
				Door curDoor = doorQueueCopy.front();
				doorQueueCopy.pop();
				doorQueue.pop();

				if (hasKey[curDoor.value - 'A'])
				{
					bfsQueue.push({ curDoor.h, curDoor.w });
				}
				else
				{
					doorQueue.push(curDoor);
				}
			}

		} while (!bfsQueue.empty());

		cout << answer << '\n';
	}
}