#include "IBBT.h"

IBBT::IBBT(int n) : n(n)
{
	root = nullptr;
	createtree(root, n);
}

void IBBT::createtree(Node*& T, int n)
{
	int nl, nr;
	if (n != 0)
	{
		T = new Node;
		T->left = 0;
		T->right = 0;

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> distribution(32, 126);

		T->data = static_cast<char>(distribution(gen));

		nl = n / 2;
		nr = n - nl - 1;
		createtree(T->left, nl);
		createtree(T->right, nr);
	}
}

void IBBT::print() {
	printTree(root, 0);
}

void IBBT::printTree(Node* node, int level) {
	if (node == nullptr) {
		return;
	}

	printTree(node->right, level + 1);

	for (int i = 0; i < level; i++) {
		cout << "    ";
	}

	cout << node->data << std::endl;

	printTree(node->left, level + 1);
}

char IBBT::maxLeftNode()
{		
	Node* node = root->left;
	while (node->left != nullptr)
		node = node->left;
	return node->data;
}

int IBBT::findPathLength(Node* node, char targetValue, int currentDepth) {
	if (node == nullptr) {
		return -1;  // Узел не найден
	}

	if (node->data == targetValue) {
		return currentDepth;  // Узел с заданным значением найден
	}

	int leftPathLength = findPathLength(node->left, targetValue, currentDepth + 1);
	int rightPathLength = findPathLength(node->right, targetValue, currentDepth + 1);

	// Если узел не найден в левом и правом поддеревьях
	if (leftPathLength == -1 && rightPathLength == -1) {
		return -1;
	}

	// Если узел найден в одном из поддеревьев
	if (leftPathLength != -1 && rightPathLength == -1) {
		return leftPathLength;
	}
	else if (leftPathLength == -1 && rightPathLength != -1) {
		return rightPathLength;
	}

	// Если узел найден в двух поддеревьях
	
	return min(leftPathLength, rightPathLength);
	

}

int IBBT::getShortestPathLengthToValue(char targetValue) {
	int pathLength = findPathLength(root, targetValue, 0);

	return pathLength;
}

char IBBT::findMaxLeafValue(Node* node) {
	if (node == nullptr) {
		return '-1';  
	}

	if (node->left == nullptr || node->right == nullptr) {
		return node->data;  // Это лист, возвращаем его значение
	}

	char leftMax = findMaxLeafValue(node->left);
	char rightMax = findMaxLeafValue(node->right);

	// Находим максимум из значений листьев
	return max(leftMax, rightMax);
}

char IBBT::getMaxLeafValue() {
	char maxLeafValue = findMaxLeafValue(root);

	return maxLeafValue;
}
