class MyListNode {
  public:
	MyListNode *next;
	MyListNode *prev;
	int val;

	MyListNode(MyListNode *next, MyListNode *prev, int val) {
		this->next = next;
		this->prev = prev;
		this->val = val;
	}
};

class MyCircularDeque {
	MyListNode *dummyHead;
	MyListNode *tail;
	int size;
	int k;

  public:
	MyCircularDeque(int k) {
		dummyHead = new MyListNode(nullptr, nullptr, -1);
		tail = nullptr;
		this->size = 0;
		this->k = k;
	}

	bool insertFront(int value) {
		if (size == k) {
			return false;
		}

		MyListNode *node = new MyListNode(dummyHead->next, dummyHead, value);
		if (dummyHead->next) {
			dummyHead->next->prev = node;
		}
		dummyHead->next = node;

		if (!tail) {
			tail = node;
		}

		size++;
		return true;
	}

	bool insertLast(int value) {
		if (size == k) {
			return false;
		}

		if (!tail)
			return insertFront(value);

		MyListNode *node = new MyListNode(nullptr, tail, value);
		tail->next = node;
		tail = node;

		size++;
		return true;
	}

	bool deleteFront() {
		if (size == 0) {
			return false;
		}

		MyListNode *node = dummyHead->next;
		dummyHead->next = node->next;

		if (dummyHead->next) {
			dummyHead->next->prev = dummyHead;
		}

		if (node == tail) {
			tail = nullptr;
		}

		delete node;
		size--;
		return true;
	}

	bool deleteLast() {
		if (size == 0) {
			return false;
		}

		if (tail == dummyHead->next) {
			return deleteFront();
		}

		MyListNode *node = tail;
		tail = tail->prev;
		tail->next = nullptr;

		delete node;
		size--;
		return true;
	}

	int getFront() {
		if (size == 0) {
			return -1;
		}
		return dummyHead->next->val;
	}

	int getRear() {
		if (size == 0) {
			return -1;
		}
		return tail->val;
	}

	bool isEmpty() { return size == 0; }

	bool isFull() { return size == k; }
};

// Time Complexity : O(1)
// Space Complexity : O(k)