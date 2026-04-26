#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int sub = 0;
        int fresh = 0;
        vector<pair<int, int>> locate;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                else if (grid[i][j] == 2)
                {
                    locate.push_back({i, j});
                }
            }
        }
        if (fresh == 0)
        {
            return 0;
        }
        int res = dfs(locate, fresh, grid);
        if (res < 0)
        {
            return -1;
        }
        return res;
    }

    int dfs(vector<pair<int, int>> locate, int fresh, vector<vector<int>> &grid)
    {
        if (fresh == 0)
        {
            return 0;
        }
        if (locate.empty())
        {
            return -1;
        }

        vector<pair<int, int>> newLocate;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < locate.size(); ++i)
        {
            for (auto d : dir)
            {
                int x = locate[i].first + d[0];
                int y = locate[i].second + d[1];
                if (x >= 0 && x < grid.size())
                {
                    if (y >= 0 && y < grid[0].size())
                    {
                        if (grid[x][y] == 1)
                        {
                            grid[x][y] = 2;
                            fresh--;
                            newLocate.push_back({x, y});
                        }
                    }
                }
            }
        }
        int sub = dfs(newLocate, fresh, grid);
        if (sub < 0)
        {
            return -1;
        }
        return sub + 1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};
    int res = s.orangesRotting(grid);
    cout << res;

    return 0;
}
