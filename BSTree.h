#pragma once
#include "BNode.h"
#include <vector>

class Tree {
public:
	Tree();
	~Tree();

	bool Add(int);
	void Delete(int);
	void Show();

	std::vector<int> FindByFunc(bool(func)(int, int), int);
	std::vector<int> FindByFunc(bool(func)(int));
	std::vector<int> FindByFunc(bool(func)(int, std::vector<int>), std::vector<int>);

	int MaxNumber();
	int MinNumber();
	std::vector<int> AllLeaves();

	std::vector<int> ToVector();

private:
	Node *head;

	Node *findNode(Node*, int);

	bool addRecursively(Node*, int);
	void deleteRecursively(Node*&);
	void showRecursively(Node*);
	void deleteHelp(Node*, Node*);

	void searchByFunc(Node*, std::vector<int>&, bool(func)(int, int), int);
	void searchByFunc(Node*, std::vector<int>&, bool(func)(int));
	void searchByFunc(Node*, std::vector<int>&, bool(func)(int, std::vector<int>), std::vector<int>);

	int maxNumRecursively(Node*);
	int minNumRecursively(Node*);
	void allLeavesRecursively(Node*, std::vector<int>&);

	void rotateLeft(Node*);
	void rotateRight(Node*);

	void toVectorRecursively(Node*, std::vector<int>&);
};