#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
private:
	char value;
	Node* left;
	Node* right;
public:
	Node(char value) {
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
	}
	void setValue(char value) {
		this->value = value;
	}
	void setLeft(Node* left) {
		this->left = left;
	}
	void setRight(Node* right) {
		this->right = right;
	}
	char getValue() const {return this->value;}
	Node* getLeft() const { return this->left; }
	Node* getRight() const { return this->right; }
};

unordered_map<char, Node*> tree;

void preOrder(Node* node) {
	if (node != nullptr) {
		cout << node->getValue();
		preOrder(node->getLeft());
		preOrder(node->getRight());
	}
}

void inOrder(Node* node) {
	if (node != nullptr) {
		inOrder(node->getLeft());
		cout << node->getValue();
		inOrder(node->getRight());
	}
}

void postOrder(Node* node) {
	if (node != nullptr) {
		postOrder(node->getLeft());
		postOrder(node->getRight());
		cout << node->getValue();
	}
}

int main(void) {	
	int N = 0;
	cin >> N;
	char rootV;

	for (int i = 0; i < N; i++) {
		int j = 0;
		char root, left, right;
		cin >> root >> left >> right;
		if (j == i) {
			rootV = root;
		}
		if (tree.find(root) == tree.end()) {
			tree[root] = new Node(root);
		}
		if (left != '.') {
			tree[left] = new Node(left);
			tree[root]->setLeft(tree[left]);
		}
		if (right != '.') {
			tree[right] = new Node(right);
			tree[root]->setRight(tree[right]);
		}
	}

	Node* rootNode = tree[rootV];

	preOrder(rootNode);
	cout << endl;
	inOrder(rootNode);
	cout << endl;	
	postOrder(rootNode);
	cout << endl;

	for (auto& pair : tree) {
		delete pair.second;
	}
	return 0;
}