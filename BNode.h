#pragma once

class Node {
public:
	int data;
	Node *parent;
	Node *left;
	Node *right;

	Node(int = 0, Node* = nullptr);
	~Node();
};
