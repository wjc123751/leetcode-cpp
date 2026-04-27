#include <iostream>
#include <vector>

using namespace std;

// DFS 深度优先搜索 + 回溯

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, i, j, word, 0) == true)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int index)
    {
        if (index == word.size())
        {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        {
            return false;
        }
        if (board[i][j] != word[index])
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool res = dfs(board, i + 1, j, word, index + 1) ||
                   dfs(board, i - 1, j, word, index + 1) ||
                   dfs(board, i, j + 1, word, index + 1) ||
                   dfs(board, i, j - 1, word, index + 1);
        board[i][j] = temp;
        return res;
    }
};

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution s;
    string str = "ABCCED";
    bool res = s.exist(board, str);
    cout << res;

    return 0;
}
