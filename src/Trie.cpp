#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 前缀树节点定义
struct TrieNode
{
    TrieNode *children[26]; // 26个小写字母对应的子节点
    bool isEnd;             // 标记是否为单词的结尾
    TrieNode() : isEnd(false)
    {
        // 初始化所有子节点为 nullptr
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root; // 前缀树根节点

public:
    // 初始化前缀树对象
    Trie()
    {
        root = new TrieNode();
    }

    // 向前缀树中插入字符串 word
    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int idx = c - 'a'; // 计算字符对应的数组下标
            if (!node->children[idx])
            {
                // 子节点不存在，创建新节点
                node->children[idx] = new TrieNode();
            }
            // 把 node 指针移动到当前节点的第 idx 个子节点
            node = node->children[idx];
        }
        // 标记单词结尾
        node->isEnd = true;
    }

    // 查找完整单词 word 是否存在
    bool search(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (!node->children[idx])
            {
                return false; // 字符路径不存在，直接返回 false
            }
            node = node->children[idx];
        }
        // 路径存在，需检查是否为单词结尾
        return node->isEnd;
    }

    // 查找是否存在以 prefix 为前缀的单词
    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char c : prefix)
        {
            int idx = c - 'a';
            if (!node->children[idx])
            {
                return false; // 前缀路径不存在
            }
            node = node->children[idx];
        }
        // 前缀路径存在，无需检查 isEnd
        return true;
    }
};

// 主函数示例
int main()
{
    Trie trie;

    // 插入单词
    trie.insert("apple");
    cout << "search(\"apple\"): " << (trie.search("apple") ? "true" : "false") << endl;     // true
    cout << "search(\"app\"): " << (trie.search("app") ? "true" : "false") << endl;         // false（只是前缀，不是完整单词）
    cout << "startsWith(\"app\"): " << (trie.startsWith("app") ? "true" : "false") << endl; // true

    trie.insert("app");
    cout << "search(\"app\"): " << (trie.search("app") ? "true" : "false") << endl; // true（现在 "app" 是完整单词）

    return 0;
}