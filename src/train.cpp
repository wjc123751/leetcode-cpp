#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.empty())
        {
            return false;
        }
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        bool res = false;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    stack<pair<pair<int, int>, int>> st;
                    st.push({{i, j}, 0});
                    while (!st.empty())
                    {
                        auto cur = st.top();
                        int x = cur.first.first;
                        int y = cur.first.second;
                        int k = cur.second;
                        if (k == word.size() - 1)
                        {
                            return true;
                        }
                        if (board[x][y] == word[k])
                        {
                            char temp = board[x][y];
                            board[x][y] = '#';
                            for (auto dir : dirs)
                            {
                                int nx = x + dir.first;
                                int ny = y + dir.second;
                                if (nx >= 0 && nx < board.size() && ny >= 0 &&
                                    ny < board[0].size() && board[nx][ny] == word[k + 1])
                                {
                                    st.push({{nx, ny}, k + 1});
                                }
                            }
                        }
                        else
                        {
                            board[x][y] = word[k];
                            st.pop();
                        }
                    }
                }
            }
        }
        return false;
    }
};

// class Solution
// {
// public:
//     int numIslands(vector<vector<char>> &grid)
//     {
//         if (grid.empty())
//         {
//             return 0;
//         }
//         vector<vector<bool>> visited(grid.size(),
//                                      vector<bool>(grid[0].size(), false));
//         int res = 0;
//         for (int i = 0; i < grid.size(); ++i)
//         {
//             for (int j = 0; j < grid[0].size(); ++j)
//             {
//                 if (grid[i][j] == '1' && visited[i][j] == false)
//                 {
//                     res++;
//                     queue<pair<int, int>> q;
//                     q.push({i, j});
//                     visited[i][j] = true;
//                     vector<pair<int, int>> dirs = {
//                         {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//                     while (!q.empty())
//                     {
//                         auto [x, y] = q.front();
//                         q.pop();
//                         for (auto dir : dirs)
//                         {
//                             int nx = x + dir.first;
//                             int ny = y + dir.second;
//                             if (nx >= 0 && nx < grid.size() && ny >= 0 &&
//                                 ny < grid[0].size() && grid[nx][ny] == '1' &&
//                                 visited[nx][ny] == false)
//                             {
//                                 q.push({nx, ny});
//                                 visited[nx][ny] = true;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };

int main()
{
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    bool res = s.exist(board, word);

    return 0;
}