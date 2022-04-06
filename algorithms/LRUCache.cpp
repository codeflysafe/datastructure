#include <unordered_map>

using namespace  std;

class LRUCache {
public:

    // 采用一个双链表结构
    struct ListNode{
        int val;
        struct ListNode *prev;
        struct ListNode *next;
        ListNode(int v): val(v){};
    };

    ListNode *head, *tail;

    int len = 0;
    int cap = 0;

    // 更快的获取索引
    unordered_map<int, ListNode *> indexes;

    LRUCache(int capacity) {
        cap = capacity;
        len = 0;
    }

    void del_node(ListNode *node){
        if(!node) return;
        ListNode *prev = node->prev;
        ListNode *next = node->next;
        if(!prev && !next){
            head = tail = nullptr;
        }else if(!prev){
            head = next;
            next->prev = nullptr;
        }else if(!next){
            // 尾节点
            tail = prev;
            tail->next = nullptr;
        }else{
            prev->next = next;
            next->prev = prev;
        }
        len --;
    }

    void insert_back(int val){
        ListNode *node = new ListNode(val);
        if(len == 0){
            head = tail = node;
            len ++;
            return;
        }
        node->prev = tail;
        tail->next = node;
        tail = node;
        len ++;
    }

    int get(int key) {
        int val = -1;
        if(indexes.count(key)){
            // 获取存储的 val 值
            val = indexes[key]->val;
        }
        return val;
    }

    void put(int key, int value) {
        // 存在
        if(indexes.count(key)){
            // 更新
            indexes[key]->val = value;
            del_node(indexes[key]);
        }else{
            // 不存在
            // 满了，删掉头
            if(len == cap){
                del_node(head);
            }
            insert_back(value);
        }
        // 更新到队尾
        indexes[key] = tail;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */