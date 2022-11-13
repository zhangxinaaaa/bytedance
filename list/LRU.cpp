//
// Created by 张新 on 2022/9/7.
//
#include <unordered_map>
using namespace std;
struct linkedNode
{
    int key, val;
    struct linkedNode* next;
    struct linkedNode* prev;
    linkedNode(): key(0), val(0), next(nullptr), prev(nullptr) {}
    linkedNode(int _key, int _val): key(_key), val(_val), next(nullptr), prev(nullptr) {}
};


class LRUCache {
private:
    int cap, size;
    unordered_map<int, linkedNode*> cache;
    linkedNode* head;
    linkedNode* tail;
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new linkedNode();
        tail = new linkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.count(key) == 0) {
            return -1;
        } else {
            auto node = cache[key];
            moveToHead(node);
            return node->val;
        }
    }

    void put(int key, int value) {
        if (cache.count(key) > 0) {
            auto node = cache[key];
            node->val = value; // 更新value
            moveToHead(node);
        } else {
            auto node = new linkedNode(key, value);
            cache[key] = node;  // 添加至cache
            addToHead(node); // 添加至双向链表
            size++;
            if (size > cap) {
                auto nodeToDelete = removeTail();  // 从链表中删除
                cache.erase(nodeToDelete->key);  // 从cache中删除
                delete nodeToDelete;  // 释放内存
                size--;
            }
        }

    }

    void addToHead(linkedNode* node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void removeNode(linkedNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void moveToHead(linkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    linkedNode* removeTail() {
        auto node = tail->prev;
        node->next->prev = node->prev;
        node->prev->next = node->next;
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */