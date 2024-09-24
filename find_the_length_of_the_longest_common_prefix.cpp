class TrieNode {
  public:
	vector<TrieNode *> children;

	TrieNode() { children.resize(10, nullptr); }
};

class Trie {
	TrieNode *root;

  public:
	Trie() { root = new TrieNode(); }

	void insert(int num) {
		TrieNode *curr = root;
		string numStr = to_string(num);

		for (char ch : numStr) {
			int n = ch - '0';
			if (curr->children[n] == nullptr) {
				curr->children[n] = new TrieNode();
			}
			curr = curr->children[n];
		}
	}

	int checkDepth(int num) {
		string numStr = to_string(num);
		TrieNode *curr = root;
		int ans = 0;

		for (char ch : numStr) {
			int n = ch - '0';

			if (curr->children[n] == nullptr) {
				return ans;
			}
			curr = curr->children[n];
			ans++;
		}
		return ans;
	}
};

class Solution {
  public:
	int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
		Trie *trie = new Trie();
		int ans = 0;

		for (int num : arr1) {
			trie->insert(num);
		}

		for (int num : arr2) {
			ans = max(ans, trie->checkDepth(num));
		}
		return ans;
	}
};

// Time Complexity : O(n)
// Space Complexity : O(n)