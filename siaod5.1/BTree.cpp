#include "BTree.h"
#include <fstream>
#include <iomanip>


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
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	Owner item;

	while (ifbin.read((char*)&item, sizeof(Owner)))
	{
		string s = item.address;

		if (s != "")
			cout << left << setw(4) << " " << item.key
			<< "  " << left << setw(20) << left << setw(30) << item.address << endl;
	}

	if (!ifbin.eof() && ifbin.fail()) {
		cout << "Ошибка чтения из файла." << endl;
	}

	ifbin.close();
}


void createTreeFromFile(ifstream& ifbin, BTree &tree)
{
	if (!ifbin.is_open()) {
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	Owner item;
	int i = 0;
	while (ifbin.read((char*)&item, sizeof(Owner)))
	{
		string s = item.address;

		if (s != "")
		{
			Node* newNode = new Node();
			newNode->key = item.key;
			newNode->position = i*sizeof(Owner);

			addNode(newNode, tree);
		}
		i++;
	}

	if (!ifbin.eof() && ifbin.fail()) {
		cout << "Ошибка чтения из файла." << endl;
	}

	ifbin.close();

}

void removeNode(BTree& tree, long long searchKey) {
	Node* root = tree.root;
	Node* parent = nullptr;
	Node* currentNode = root;

	// Поиск удаляемого узла
	while (currentNode != nullptr && currentNode->key != searchKey) {
		parent = currentNode;
		if (searchKey < currentNode->key)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}

	if (currentNode == nullptr) {
		// Узел не найден
		return;
	}

	// У узла нет детей или только один ребенок
	if (currentNode->left == nullptr) {
		if (parent == nullptr)
			tree.root = currentNode->right;
		else if (currentNode == parent->left)
			parent->left = currentNode->right;
		else
			parent->right = currentNode->right;
		delete currentNode;
	}
	else if (currentNode->right == nullptr) {
		if (parent == nullptr)
			tree.root = currentNode->left;
		else if (currentNode == parent->left)
			parent->left = currentNode->left;
		else
			parent->right = currentNode->left;
		delete currentNode;
	}
	else {
		// У узла два ребенка
		Node* successor = currentNode->right;
		Node* successorParent = nullptr;
		
		// ищем наименьший узел
		while (successor->left != nullptr) {
			successorParent = successor;
			successor = successor->left;
		}

		// мы не заходили в предыдущий цикл -> значит, succesorParent = currentNode
		if (successorParent != nullptr)
			successorParent->left = successor->right;
		else
			currentNode->right = successor->right;
		

		currentNode->key = successor->key;
		currentNode->position = successor->position;
		delete successor;
	}
}


Node* findNode(BTree& tree, long long searchKey)
{
	Node* root = tree.root;
	
	Node* currentNode = root;
	Node* parent;

	while (currentNode != nullptr)
		//parent = currentNode;
	{

		if (currentNode->key == searchKey)
			return currentNode;

		if (searchKey > currentNode->key)
			currentNode = currentNode->right;
		else
			currentNode = currentNode->left;
	} 
	
	return nullptr;
}

void addNode(Node* newNode, BTree& tree)
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

