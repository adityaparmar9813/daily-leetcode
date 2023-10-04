class Node {
public:
    int val;
    int key;
    Node* left;
    Node* right;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class MyHashMap {
private:
    Node* root;
    Node* putter(Node* root, int key, int val) {
        if (root == NULL) return new Node(key, val);

        if (root->key == key) root->val = val;
        else if (root->key > key) root->left = putter(root->left, key, val);
        else root->right = putter(root->right, key, val);

        return root;
    }

    int getter(Node* root, int key) {
        if (root == NULL) return -1;

        if (root->key == key) return root->val;
        else if (root->key > key) return getter(root->left, key);
        else return getter(root->right, key);
    }

    Node* remover(Node* root, int key) {
        if (root == NULL) return NULL;

        if (root->key > key) root->left = remover(root->left, key);
        else if (root->key < key) root->right = remover(root->right, key);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else {
                Node* temp = getMin(root->right);
                root->key = temp->key;
                root->val = temp->val;
                root->right = remover(root->right, temp->key);
            }
        }
        return root;
    }

    Node* getMin(Node* root) {
        while (root->left) root = root->left;
        return root;
    }

public:
    MyHashMap() {
        root = NULL;
    }

    void put(int key, int value) {
        root = putter(root, key, value);
    }

    int get(int key) {
        return getter(root, key);
    }

    void remove(int key) {
        root = remover(root, key);
    }
};

// Time Complexity :
// 1) void put(int key, int value) : O(n) worst case
// 2) int get(int key) : O(n) worst case
// 3) void remove(int key) : O(n) worst case

// Space Complexity : O(n) worst case