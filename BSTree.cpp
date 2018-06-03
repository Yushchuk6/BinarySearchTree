#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "BSTree.h"

Tree::Tree() {
	head = nullptr;
}

Node* Tree::findNode(Node *node, int _data) {
	if (node != nullptr) {

		if (node->data > _data) {
			findNode(node->left, _data);
		}
		else if (node->data < _data) {
			findNode(node->right, _data);
		}
		else {
			return node;
		}
	}
	else return nullptr;
}

bool Tree::Add(int _data) {
	if (head == nullptr) {
		head = new Node(_data);
		return true;
	}
	else return addRecursively(head, _data);
}
bool Tree::addRecursively(Node *node, int _data) {
	if (node->data > _data) {
		if (node->left != nullptr)  return addRecursively(node->left, _data);
		else node->left = new Node(_data, node);
		return true;
	}
	else if (node->data < _data) {
		if (node->right != nullptr)  return addRecursively(node->right, _data);
		else node->right = new Node(_data, node);
		return true;
	}
	else return false;
}

void Tree::Show() {
	if (head != nullptr) {
		showRecursively(head);
		std::cout << std::endl;
	}
}
void Tree::showRecursively(Node *node) {
	if (node != nullptr) {
		showRecursively(node->left);
		std::cout << node->data << " ";
		showRecursively(node->right);
	}
}

void Tree::Delete(int _data) {
	Node *nodeToRemove = findNode(head, _data);
	if (nodeToRemove == nullptr) return;

	if (nodeToRemove->right == nullptr) {

		deleteHelp(nodeToRemove, nodeToRemove->left);
	}
	else if (nodeToRemove->right->left == nullptr) {

		Node *replaceNode = nodeToRemove->right;

		if (nodeToRemove->left != nullptr) {
			replaceNode->left = nodeToRemove->left;
			nodeToRemove->left->parent = replaceNode;
		}

		deleteHelp(nodeToRemove, replaceNode);

	}
	else {
		Node *replaceNode = nodeToRemove->right->left;

		while (replaceNode->left != nullptr) {// finding the new node
			replaceNode = replaceNode->left;
		}

		replaceNode->parent->left = replaceNode->right; // removing new node
		if (replaceNode->right != nullptr) {
			replaceNode->right->parent = replaceNode->parent;
		}

		replaceNode->left = nodeToRemove->left; // replacing nodeToRemove with new node
		if (nodeToRemove->left != nullptr) {
			nodeToRemove->left->parent = replaceNode;
		}
		replaceNode->right = nodeToRemove->right;
		nodeToRemove->right->parent = replaceNode;

		deleteHelp(nodeToRemove, replaceNode);
	}
}
void Tree::deleteHelp(Node *nodeToRemove, Node *replaceNode) {

	if (nodeToRemove == head) {
		head = replaceNode;
	}
	else if (nodeToRemove->parent->data > nodeToRemove->data) {
		nodeToRemove->parent->left = replaceNode;
	}
	else if (nodeToRemove->parent->data < nodeToRemove->data) {
		nodeToRemove->parent->right = replaceNode;
	}

	if (replaceNode != nullptr) {
		replaceNode->parent = nodeToRemove->parent;
	}
	delete nodeToRemove;
}

void Tree::searchByFunc(Node *node, std::vector<int> &arr, bool(condition)(int, int), int N) {
	if (node != nullptr) {

		searchByFunc(node->left, arr, (condition), N);
		if ((condition)(node->data, N)) {
			arr.push_back(node->data);
		}
		searchByFunc(node->right, arr, (condition), N);
	}
}
void Tree::searchByFunc(Node *node, std::vector<int> &arr, bool(condition)(int)) {
	if (node != nullptr) {

		searchByFunc(node->left, arr, (condition));
		if ((condition)(node->data)) {
			arr.push_back(node->data);
		}
		searchByFunc(node->right, arr, (condition));
	}
}
void Tree::searchByFunc(Node *node, std::vector<int> &arr, bool(condition)(int, std::vector<int>), std::vector<int> N) {
	if (node != nullptr) {

		searchByFunc(node->left, arr, (condition), N);
		if ((condition)(node->data, N)) {
			arr.push_back(node->data);
		}
		searchByFunc(node->right, arr, (condition), N);
	}
}

std::vector<int> Tree::FindByFunc(bool(condition)(int, int), int N) {
	std::vector<int> arr;
	if (head != nullptr) {
		searchByFunc(head, arr, (condition), N);
	}
	return arr;
}
std::vector<int> Tree::FindByFunc(bool(condition)(int)) {
	std::vector<int> arr;
	if (head != nullptr) {
		searchByFunc(head, arr, (condition));
	}
	return arr;
}
std::vector<int> Tree::FindByFunc(bool(condition)(int, std::vector<int>), std::vector<int> N) {
	std::vector<int> arr;
	if (head != nullptr) {
		searchByFunc(head, arr, (condition), N);
	}
	return arr;
}

void Tree::RotateLeft(int data) {
	Node *nodeToRotate = findNode(head, data);

	if (nodeToRotate == nullptr) return;
	rotateLeft(nodeToRotate);
}
void Tree::rotateLeft(Node *node) {
	if (node != nullptr) {
		if (node->parent->right == node) {
			node->parent->right = node->right;
		}
		else if (node->parent->left == node) {
			node->parent->left = node->right;
		}
		node->right->parent = node->parent;

		Node *temp = node->right->left;
		node->right->left = node;
		node->parent = node->right;

		if (temp != nullptr) temp->parent = node;
		node->right = temp;
	}
}

void Tree::RotateRight(int data) {
	Node *nodeToRotate = findNode(head, data);

	if (nodeToRotate == nullptr) return;
	rotateRight(nodeToRotate);
}
void Tree::rotateRight(Node *node) {
	if (node != nullptr) {
		if (node->parent->right == node) {
			node->parent->right = node->left;
		}
		else if (node->parent->left == node) {
			node->parent->left = node->left;
		}
		node->left->parent = node->parent;

		Node *temp = node->left->right;
		node->left->right = node;
		node->parent = node->left;

		if (temp != nullptr) temp->parent = node;
		node->left = temp;
	}
}

int Tree::MaxNumber() {
	return maxNumRecursively(head);
}
int Tree::maxNumRecursively(Node *node) {
	if (node != nullptr) {
		if (node->right != nullptr) {
			return maxNumRecursively(node->right);
		}
		else return node->data;
	}
	else return -1;
}

int Tree::MinNumber() {
	return minNumRecursively(head);
}
int Tree::minNumRecursively(Node *node) {
	if (node != nullptr) {
		if (node->left != nullptr) {
			return minNumRecursively(node->left);
		}
		else return node->data;
	}
	else return -1;
}

std::vector<int> Tree::AllLeaves() {
	std::vector<int> leaves;

	allLeavesRecursively(head, leaves);
	return leaves;
}
void Tree::allLeavesRecursively(Node *node, std::vector<int> &leaves) {
	if (node != nullptr) {
		if (node->left != nullptr || node->right != nullptr) {
			allLeavesRecursively(node->left, leaves);
			allLeavesRecursively(node->right, leaves);
		}
		else leaves.push_back(node->data);
	}
}

std::vector<int> Tree::ToVector() {
	std::vector<int> vect;

	if (head != nullptr) {
		toVectorRecursively(head, vect);
		std::cout << std::endl;
	}
	return vect;
}
void Tree::toVectorRecursively(Node *node, std::vector<int> &vect) {
	if (node != nullptr) {
		toVectorRecursively(node->left, vect);
		vect.push_back(node->data);
		toVectorRecursively(node->right, vect);
	}
}

void Tree::deleteRecursively(Node *&node) {
	if (node != nullptr) {
		deleteRecursively(node->left);
		deleteRecursively(node->right);
		delete node;
		node = nullptr;
	}
}
Tree::~Tree() {
	deleteRecursively(head);
}