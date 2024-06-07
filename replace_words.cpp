class Node {
private:
    vector<Node*> edges;
    bool flag;

public:
    Node() {
        edges.resize(26, nullptr);
        flag = false;
    } 

    void addEdge(char ch, Node* node) {
        edges[ch - 'a'] = node;
    }

    Node* findEdge(char ch) {
        return edges[ch - 'a'];
    }

    bool checkEdge(char ch) {
        return edges[ch - 'a'] != nullptr;
    }

    void setLeaf() {
        flag = true;
    }

    bool isALeaf() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node -> checkEdge(ch)) {
                node -> addEdge(ch, new Node());
            }
            node = node -> findEdge(ch);
        }
        node->setLeaf();
    }

    string findRoot(string str) {
        Node* node = root;
        string rootWord = "";

        for (char ch: str) {
            if (!node -> checkEdge(ch)) {
                return str;
            }
            rootWord += ch;
            node = node -> findEdge(ch);

            if (node -> isALeaf()) {
                return rootWord;
            }
        }
        return str;
    }
};

class Solution {
private:
    vector<string> getWords(string str) {
        vector<string> ans;
        string word = "";

        for (char ch: str) {
            if (ch == ' ') {
                if (!word.empty()) {
                    ans.push_back(word);
                    word = "";
                }
            } else {
                word += ch;
            }
        }
        if (!word.empty()) {
            ans.push_back(word);
        }
        return ans;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& word: dictionary) {
            trie.insert(word);
        }

        vector<string> words = getWords(sentence);
        string result = "";

        for (const string& word: words) {
            if (!result.empty()) {
                result += " ";
            }
            result += trie.findRoot(word);
        }
        return result;
    }
};


// Time Complexity : O(n*m)
// Space Complexity : O(n*m)
