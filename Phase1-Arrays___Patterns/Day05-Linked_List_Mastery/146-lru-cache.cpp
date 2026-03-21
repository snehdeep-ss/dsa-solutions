/*
 * Problem:  146. LRU Cache
 * URL:       https://leetcode.com/problems/lru-cache/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   46 ms  (beats 97.5%)
 * Memory:    173236000  (beats 56.8%)
 * Date:      2026-03-21
 * Context:  Day 5 — Linked List Mastery
 */

class LRUCache {

    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;

    int maxSize;
    int currSize;

    unordered_map<int, Node*> hashMap;

private:
    void moveToLatest(Node* valNode) {
        removeNode(valNode);
        addToCache(valNode);
    }

    void addToCache(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* valNode) {
        Node* prevNode = valNode->prev;
        Node* nextNode = valNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) : maxSize(capacity), currSize(0) {

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (hashMap.find(key) == hashMap.end())
            return -1;

        Node* valNode = hashMap[key];
        moveToLatest(valNode);
        return valNode->val;
    }

    void put(int key, int value) {
        if (hashMap.find(key) != hashMap.end()) {
            Node* valNode = hashMap[key];
            valNode->val = value;
            moveToLatest(valNode);
        } else {
            if (currSize >= maxSize) {
                Node* nodeToDelete = tail->prev;
                hashMap.erase(nodeToDelete->key);
                removeNode(nodeToDelete);
                currSize--;
                delete nodeToDelete;
            }

            Node* newNode = new Node();
            newNode->key = key;
            newNode->val = value;

            addToCache(newNode);
            hashMap[key] = newNode;
            currSize++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */