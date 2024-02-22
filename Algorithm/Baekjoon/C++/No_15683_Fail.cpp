#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class CCTV;
class Map;

class CCTV
{
public:
    int pos_row;
    int pos_col;
    int type_num;

    deque<pair<int,int>> include_directions;
    deque<pair<int,int>> exclude_directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void Observe()
    {
        for(auto direction : include_directions)
        {
            while(true)
            {
                int next_row = pos_row + direction.first;
                int next_col = pos_col + direction.second;
            }
        }
    }

    void Rotate()
    {
        if(type_num == 2)
        {
            for(int i=0; i<type_num; i++)
            {
                exclude_directions.push_back(include_directions.front());
                include_directions.pop_front();
                
                include_directions.push_back(exclude_directions.front());
                exclude_directions.pop_front();
            }
        }
        else
        {
            exclude_directions.push_back(include_directions.front());
            include_directions.pop_front();
            
            include_directions.push_back(exclude_directions.front());
            exclude_directions.pop_front();
        }
    }

    CCTV(int row, int col, int type)
    {
        pos_row = row;
        pos_col = col;
        type_num = type;

        if(type_num == 2)
        {
            include_directions.push_back(exclude_directions.front());
            exclude_directions.pop_front();
            
            exclude_directions.push_back(exclude_directions.front());
            exclude_directions.pop_front();

            include_directions.push_back(exclude_directions.front());
            exclude_directions.pop_front();
        }
        else
        {
            for(int i=0; i<type_num; i++)
            {
                include_directions.push_back(exclude_directions.front());
                exclude_directions.pop_front();
            }
        }
    }
};



class Map
{
public:
    int map[8][8];
    int blind_count = 0;

    vector<CCTV> cctvs;

    void AddCCTV(CCTV new_cctv)
    {
        cctvs.push_back(new_cctv);
        new_cctv.Observe();
    }
    
    void CheckCCTV()
    {
        for(auto cctv : cctvs)
        {
            
        }
    }
};

int n,m;
Map map;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int input;
            cin >> input;
            map.map[i][j] = input;

            if(input == 0)
            {
                map.blind_count++;
            }
            else if(input < 6)
            {
                CCTV new_cctv = {i, j, input};
                map.AddCCTV(new_cctv);
            }
        }
    }
}