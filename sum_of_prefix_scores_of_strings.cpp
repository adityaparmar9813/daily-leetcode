class TrieNode {
  public:
	unordered_map<char, TrieNode *> children;
	int visitCount;

	TrieNode() { visitCount = 0; }
};

class Trie {
	TrieNode *root;

  public:
	Trie() { root = new TrieNode(); }

	void addWord(string word) {
		TrieNode *curr = root;

		for (char ch : word) {
			if (curr->children.find(ch) == curr->children.end()) {
				curr->children[ch] = new TrieNode();
			}
			curr = curr->children[ch];
			curr->visitCount++;
		}
	}

	int checkPrefix(string word) {
		int ans = 0;
		TrieNode *curr = root;

		for (char ch : word) {
			curr = curr->children[ch];
			ans += curr->visitCount;
		}
		return ans;
	}

	~Trie() { deleteTrie(root); }

  private:
	void deleteTrie(TrieNode *node) {
		for (auto &[key, child] : node->children) {
			deleteTrie(child);
		}
		delete node;
	}
};

class Solution {
  public:
	vector<int> sumPrefixScores(vector<string> &words) {
		Trie *trie = new Trie();
		vector<int> ans;

		for (string word : words) {
			trie->addWord(word);
		}

		for (string word : words) {
			ans.push_back(trie->checkPrefix(word));
		}

		delete trie;
		return ans;
	}
};

// Time Complexity : O(n * m)
// Space Complexity : O(n * m)