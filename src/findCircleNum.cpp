#include <iostream>
#include <vector>

using namespace std;

// 这道题就是求无向图的连通分量个数

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            // 如果当前城市没被访问过：说明找到了一个全新的省份，省份数量 +1
            if (!visited[i])
            {
                count++;
                dfs(isConnected, visited, i);
            }
        }
        return count;
    }

    // 把这个城市所有直接间接连通的城市全部标记为已访问
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int cur)
    {
        for (int j = 0; j < isConnected.size(); ++j)
        {
            if (isConnected[cur][j] == 1 && !visited[j])
            {
                visited[j] = true;
                dfs(isConnected, visited, j);
            }
        }
    }
};

int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0},
                                       {1, 1, 0},
                                       {0, 0, 1}};
    Solution s;
    int res = s.findCircleNum(isConnected);
    cout << res;

    return 0;
}