#include "SplayTree.h"
#include <fstream>
#include <iomanip>
using namespace std;

void createBinFile(ifstream& iftxt, ofstream& ofbin)
{
	Owner owner;
	int key;

	while (!iftxt.eof())
	{
		iftxt >> owner.key >> owner.address;
		ofbin.write((char*)(&owner), sizeof(Owner));
	}
	ofbin.close();
	iftxt.close();
}


void outputBinFile(ifstream& ifbin)
{
	if (!ifbin.is_open()) {
		std::cout << "�� ������� ������� ����" << endl;
		return;
	}
	Owner item;

	while (ifbin.read((char*)&item, sizeof(Owner)))
	{
		string s = item.address;

		if (s != "")
			std::cout << left << setw(4) << " " << item.key
			<< "  " << left << setw(20) << left << setw(30) << item.address << endl;
	}

	if (!ifbin.eof() && ifbin.fail()) {
		std::cout << "������ ������ �� �����." << endl;
	}

	ifbin.close();
}


void createTreeFromFile(SplayTree& tree, ifstream& ifbin)
{
	if (!ifbin.is_open()) {
		cout << "�� ������� ������� ����" << endl;
		return;
	}
	Owner item;
	int i = 0;
	int rotations = 0;
	while (ifbin.read((char*)&item, sizeof(Owner)))
	{
		string s = item.address;

		if (s != "")
		{
			Node* newNode = new Node();
			newNode->key = item.key;
			newNode->position = i * sizeof(Owner);

			//addNode(newNode, tree);
			insertRotations(tree, newNode, rotations);
		}
		i++;
	}

	if (!ifbin.eof() && ifbin.fail()) {
		cout << "������ ������ �� �����." << endl;
	}

	ifbin.close();
	cout << rotations;
}

Node* rightRotate(Node* P) {
	Node* X = P->left;
	P->left = X->right;
	X->right = P;
	return X;
}

Node* leftRotate(Node* P) {
	Node* X = P->right;
	P->right = X->left;
	X->left = P;
	return X;
}

Node* splay(Node* root, long long key)
{
	// ������� ������: root ����� NULL ���
	// ���� ��������� � �����
	if (root == NULL || root->key == key)
		return root;
	// ���� ����� ���������� � ����� ���������
	if (root->key > key)
	{
		// ����� ��� � ������, ����������
		if (root->left == NULL) return root;
		// Zig-Zig (�����-�����)
		if (root->left->key > key)
		{
			// ������� ���������� �������� ���� � �������� ����� left-left
			root->left->left = splay(root->left->left, key);
			// ������ ������� ��� root, ������ ������� ����������� ����� else (���� �������)
			root = rightRotate(root);
		}
		else if (root->left->key < key) // Zig-Zag (LeftRight)
		{
			// ������� ���������� ��������� ���� � �������� ����� left-right 
			root->left->right = splay(root->left->right, key);
			// ��������� ������ ������� ��� root->left (���� �������)
			if (root->left->right != NULL)
				root->left = leftRotate(root->left);
		}
		// ��������� ������ ������� ��� ����� (���� ����)
		return (root->left == NULL) ? root : rightRotate(root);
	}
	else // ���� ����� ���������� � ������ ���������
	{
		// ����� ��� � ������, ����������
		if (root->right == NULL) return root;
		if (root->right->key > key) // Zag-Zig (LeftRight)
		{
			// ������� ���� � �������� ����� right-left
			root->right->left = splay(root->right->left, key);
			// ��������� ������ ������� ��� root->right
			if (root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		else if (root->right->key < key) // Zag-Zag (������ ������)
		{
			// ��������� ���� � �������� ����� right-right
			root->right->right = splay(root->right->right, key);
			//��������� ������ �������
			root = leftRotate(root);
		}
		// ��������� ������ ������� ��� root
		return (root->right == NULL) ? root : leftRotate(root);
	}
}




void removeNode(SplayTree & tree, long long key) {
	if (tree.root == NULL) return; // ������ �����
	tree.root = splay(tree.root, key);

	
	if (tree.root->left == NULL) {
		tree.root = tree.root->right;
	}
	else {
		Node* x = tree.root->right;
		tree.root = tree.root->left;
		tree.root = splay(tree.root, key);
		tree.root->right = x;
	}
	
}

Node* splayRotations(Node* root, long long key, int& rotations)
{
	// ������� ������: root ����� NULL ���
	// ���� ��������� � �����
	if (root == NULL || root->key == key)
		return root;
	// ���� ����� ���������� � ����� ���������
	if (root->key > key)
	{
		// ����� ��� � ������, ����������
		if (root->left == NULL) return root;
		// Zig-Zig (�����-�����)
		if (root->left->key > key)
		{
			// ������� ���������� �������� ���� � �������� ����� left-left
			root->left->left = splayRotations(root->left->left, key, rotations);
			// ������ ������� ��� root, ������ ������� ����������� ����� else (���� �������)
			root = rightRotate(root);
			rotations++;
		}
		else if (root->left->key < key) // Zig-Zag (LeftRight)
		{
			// ������� ���������� ��������� ���� � �������� ����� left-right 
			root->left->right = splayRotations(root->left->right, key, rotations);
			// ��������� ������ ������� ��� root->left (���� �������)
			if (root->left->right != NULL) {
				root->left = leftRotate(root->left);
				rotations++;
			}
		}
		// ��������� ������ ������� ��� ����� (���� ����)
		if (root->left == NULL) 
			return root; 
		else{
			rotations++;
			return	rightRotate(root);
		}
	}
	else // ���� ����� ���������� � ������ ���������
	{
		// ����� ��� � ������, ����������
		if (root->right == NULL) return root;
		if (root->right->key > key) // Zag-Zig (LeftRight)
		{
			// ������� ���� � �������� ����� right-left
			root->right->left = splayRotations(root->right->left, key, rotations);
			// ��������� ������ ������� ��� root->right
			if (root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		else if (root->right->key < key) // Zag-Zag (������ ������)
		{
			// ��������� ���� � �������� ����� right-right
			root->right->right = splayRotations(root->right->right, key, rotations);
			//��������� ������ �������
			root = leftRotate(root);
		}
		// ��������� ������ ������� ��� root
		if (root->right == NULL)
			return root;
		else {
			rotations++;
			return leftRotate(root);
		}
	}
}

Node* findNode(SplayTree& tree, long long searchKey)
{
	tree.root = splay(tree.root, searchKey);

	if (tree.root->key == searchKey)
		return tree.root;
	
	return nullptr;
}

Owner getOwnerFromFile(int offset, ifstream&ifbin) {
	Owner owner;
	ifbin.read((char*)&owner, sizeof(owner));
	ifbin.seekg(offset, ios::beg);
	ifbin.close();
	return owner;
}

void insert(SplayTree& tree, Node* newNode) {
	if (tree.root == nullptr)
	{
		tree.root = newNode;
		return;
	}
	
	long long key = newNode->key;
	tree.root = splay(tree.root, key);

	if (tree.root->key == key) {
		return;
	}
	if (key < tree.root->key) {
		newNode->right = tree.root;
		newNode->left = tree.root->left;
		tree.root->left = nullptr;
	}
	else {
		newNode->left = tree.root;
		newNode->right = tree.root->right;
		tree.root->right = nullptr;
	}
	tree.root = newNode;
	return;
}

void insertRotations(SplayTree& tree, Node* newNode, int& rotations) {
	if (tree.root == nullptr)
	{
		tree.root = newNode;
		return;
	}

	long long key = newNode->key;
	tree.root = splayRotations(tree.root, key, rotations);

	if (tree.root->key == key) {
		return;
	}
	if (key < tree.root->key) {
		newNode->right = tree.root;
		newNode->left = tree.root->left;
		tree.root->left = nullptr;
	}
	else {
		newNode->left = tree.root;
		newNode->right = tree.root->right;
		tree.root->right = nullptr;
	}
	tree.root = newNode;
	return;
}
void printTree1(Node* node, int level) {
	if (node == nullptr) {
		return;
	}

	printTree1(node->right, level + 1);

	for (int i = 0; i < level; i++) {
		cout << "    ";
	}

	cout << node->key << std::endl;

	printTree1(node->left, level + 1);
}

void addNode(Node* newNode, SplayTree& tree)
{
	Node* root = tree.root;
	newNode->left = newNode->right = nullptr;

	if (root == nullptr) {
		tree.root = newNode;
		tree.n = 1;
		return;
	}

	Node* currentNode = root;
	Node* parent = nullptr;

	while (currentNode != nullptr) {
		parent = currentNode;

		if (newNode->key < currentNode->key) 
			currentNode = currentNode->left;
		else if (newNode->key > currentNode->key)
			currentNode = currentNode->right;
	}


	if (newNode->key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;

	tree.n++;
}




void showTrunks(Trunk* p)
{
	if (p == nullptr) {
		return;
	}

	showTrunks(p->prev);
	cout << p->str;
}

void printTree(Node* root, Trunk* prev, bool isLeft)
{
	if (root == nullptr) {
		return;
	}

	string prev_str = "    ";
	Trunk* trunk = new Trunk(prev, prev_str);

	printTree(root->right, trunk, true);

	if (!prev) {
		trunk->str = "---";
	}
	else if (isLeft)
	{
		trunk->str = ".---";
		prev_str = "   |";
	}
	else {
		trunk->str = "`---";
		prev->str = prev_str;
	}

	showTrunks(trunk);
	cout << " " << root->key << endl;

	if (prev) {
		prev->str = prev_str;
	}
	trunk->str = "   |";

	printTree(root->left, trunk, false);
}

