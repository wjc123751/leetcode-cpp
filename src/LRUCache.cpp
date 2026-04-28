#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 双向链表：头节点代表最近使用，尾节点代表最久未使用
// 哈希表：存 key → 链表节点 的映射，实现 O (1) 查找
// 每次 get/put 命中节点时，都把该节点移到链表头部；缓存满时删除链表尾部节点

struct DLinkedNode
{
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

    // 辅助函数：添加节点到头部
    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // 辅助函数：移除链表中的节点
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 辅助函数：将节点移到头部（标记为最近使用）
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    // 辅助函数：移除并返回尾部节点（淘汰）
    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    // this 是 指针常量 指针的指向不能改变
    // 每创建一个对象，就有属于这个对象的一个 this 指针
    // static 静态成员函数属于类：没有 this 指针
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        // 虚头部和虚尾部，简化边界处理
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node); // 访问后标记为最近使用
        return node->value;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            // 已存在：更新值并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            // 不存在：创建新节点
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            // 超出容量：淘汰尾部节点
            if (size > capacity) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed; // 释放内存
                size--;
            }
        }
    }
};

// 主函数示例
int main() {
    // 初始化容量为2的LRU缓存
    LRUCache lru(2);

    // 按题目示例顺序执行操作
    lru.put(1, 1);
    lru.put(2, 2);

    cout << "get(1) = " << lru.get(1) << endl; // 返回1，缓存变为 [1, 2]

    lru.put(3, 3); // 缓存满，淘汰最久未使用的2，缓存变为 [3, 1]

    cout << "get(2) = " << lru.get(2) << endl; // 返回-1（已被淘汰）

    lru.put(4, 4); // 缓存满，淘汰最久未使用的1，缓存变为 [4, 3]

    cout << "get(1) = " << lru.get(1) << endl; // 返回-1（已被淘汰）
    cout << "get(3) = " << lru.get(3) << endl; // 返回3，缓存变为 [3, 4]
    cout << "get(4) = " << lru.get(4) << endl; // 返回4，缓存变为 [4, 3]

    return 0;
}
