class MyHashMap {
public:
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            this->next = NULL;
        }
    };
    vector<Node*> bucket{769};
    MyHashMap() {}

    void put(int key, int value) {
        int index = key % 769;
        if (bucket[index] == NULL) {
            Node* temp = new Node(key, value);
            bucket[index] = temp;
        } else {
            Node* temp = bucket[index];
            while (temp && temp->next) {
                if (temp->key == key) {
                    temp->value = value;
                    return;
                }
                temp = temp->next;
            }
            if (temp->key == key) {
                temp->value = value;
                return;
            }

            temp->next = new Node(key, value);
            return;
        }
    }

    int get(int key) {
        int index = key % 769;
        if (bucket[index] == NULL)
            return -1;
        Node* temp = bucket[index];
        while (temp) {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return -1;
    }

    void remove(int key) {
        int index = key % 769;
        if (bucket[index] == NULL)
            return;
        Node* temp = bucket[index];
        Node* prev = NULL;
        while (temp) {
            if (temp->key == key) {
                if (prev == NULL) {
                    bucket[index] = temp->next;
                    temp->next = NULL;
                    delete temp;
                    return;
                } else {
                    prev->next = temp->next;
                    delete temp;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */