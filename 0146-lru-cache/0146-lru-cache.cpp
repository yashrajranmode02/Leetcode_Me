class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
    };
    unordered_map<int, Node*> mpp;
    int size;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;
        int ans = mpp[key]->value;
        Node* temp = mpp[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        head->next->prev = temp;
        temp->next = head->next;
        head->next = temp;
        temp->prev = head;

        return ans;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            temp->value = value;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            head->next->prev = temp;
            temp->next = head->next;
            head->next = temp;
            temp->prev = head;

        } else {
            if (mpp.size() == size) {
                Node* temp =tail->prev;
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                mpp.erase(temp->key);
            }
            Node* temp = new Node(key, value);
            head->next->prev = temp;
            temp->next = head->next;
            head->next = temp;
            temp->prev = head;
            mpp[key] = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */