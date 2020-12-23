#include "stdafx.h"
#include "BNode.h"

Node::Node(int _data, Node *_parent) {
	data = _data;
	parent = _parent;
	left = nullptr;
	right = nullptr;
}

Node::~Node() {
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}
