#include "pch.h"
#include "../BinarySearchTree/BNode.cpp"
#include "../BinarySearchTree/BSTree.cpp"
#include <vector>
#include <windows.h>
using namespace std;

vector<int> numbers = { 50,60,70,65,55,80,20,30 };
vector<int> sortedNumbers = { 20,30,50,55,60,65,70,80 };

void fillTree(Tree &tree, vector<int> vect) {
	for (int m : vect) {
		tree.Add(m);
	}
}

TEST(MaxMinNumber, Max—orrectness) {

	Tree tree;
	fillTree(tree, numbers);

	EXPECT_EQ(sortedNumbers.back(), tree.MaxNumber());
}
TEST(MaxMinNumber, Min—orrectness) {

	Tree tree;
	fillTree(tree, numbers);

	EXPECT_EQ(*sortedNumbers.begin(), tree.MinNumber());
}
TEST(MaxMinNumber, NullTree) {

	Tree tree;
	int data = -1;

	EXPECT_EQ(data, tree.MaxNumber());
	EXPECT_EQ(data, tree.MinNumber());
}
TEST(MaxMinNumber, OneElemTree) {

	Tree tree;
	int data = 50;
	tree.Add(data);

	EXPECT_EQ(data, tree.MaxNumber());
	EXPECT_EQ(data, tree.MinNumber());
}

TEST(AllLeaves, Correctness) {

	Tree tree;
	fillTree(tree, numbers);

	vector<int> vect = { 30,55,65,80 };

	vector<int> vect2 = tree.AllLeaves();

	auto i = vect2.begin();
	for (auto data : vect) {
		EXPECT_EQ(data, *i);
		i++;
	}
}
TEST(AllLeaves, NullTree) {

	Tree tree;

	EXPECT_EQ(0, tree.AllLeaves().size());
}

TEST(Delete, NullTree) {

	Tree tree;

	EXPECT_NO_FATAL_FAILURE(tree.Delete(50));
}
TEST(Delete, NoSuchElement) {

	Tree tree;
	fillTree(tree, numbers);

	EXPECT_NO_FATAL_FAILURE(tree.Delete(45));
}
TEST(Delete, DeleteElementCase1) {

	Tree tree;
	fillTree(tree, numbers);

	EXPECT_NO_FATAL_FAILURE(tree.Delete(80));
	vector<int> vect = { 20,30,50,55,60,65,70 };
	vector<int> vect2 = tree.ToVector();

	auto i = vect2.begin();
	for (auto data : vect) {
		EXPECT_EQ(data, *i);
		i++;
	}
}
TEST(Delete, DeleteElementCase2) {

	Tree tree;
	fillTree(tree, numbers);

	EXPECT_NO_FATAL_FAILURE(tree.Delete(70));
	vector<int> vect = { 20,30,50,55,60,65,80 };
	vector<int> vect2 = tree.ToVector();

	auto i = vect2.begin();
	for (auto data : vect) {
		EXPECT_EQ(data, *i);
		i++;
	}
}
TEST(Delete, DeleteElementCase3) {

	Tree tree;
	fillTree(tree, numbers);

	EXPECT_NO_FATAL_FAILURE(tree.Delete(60));
	vector<int> vect = { 20,30,50,55,65,70,80 };
	vector<int> vect2 = tree.ToVector();

	auto i = vect2.begin();
	for (auto data : vect) {
		EXPECT_EQ(data, *i);
		i++;
	}
}
TEST(Delete, DeleteHeadCase1) {

	Tree tree;
	tree.Add(50);
	tree.Add(40);

	tree.Delete(50);

	EXPECT_EQ(tree.ToVector().size(), 1);
}
TEST(Delete, DeleteHeadCase2) {

	Tree tree;
	vector<int> numbers2 = { 50,60,70,65,80,20,30 };
	fillTree(tree, numbers2);

	EXPECT_NO_FATAL_FAILURE(tree.Delete(50));
	vector<int> vect = { 20,30,60,65,70,80 };
	vector<int> vect2 = tree.ToVector();

	auto i = vect2.begin();
	for (auto data : vect) {
		EXPECT_EQ(data, *i);
		i++;
	}
}
TEST(Delete, DeleteHeadCase3) {

	Tree tree;
	fillTree(tree, numbers);

	EXPECT_NO_FATAL_FAILURE(tree.Delete(50));
	vector<int> vect = { 20,30,55,60,65,70,80 };
	vector<int> vect2 = tree.ToVector();

	auto i = vect2.begin();
	for (auto data : vect) {
		EXPECT_EQ(data, *i);
		i++;
	}
}

TEST(Delete, DeleteTree) {

	Tree tree;
	tree.Add(50);
	tree.Add(70);


	tree.~Tree();

	EXPECT_EQ(tree.ToVector().size(), 0);
}

TEST(Add, SameElement) {

	Tree tree1;

	tree1.Add(50);

	EXPECT_FALSE(tree1.Add(50));


	Tree tree2;

	EXPECT_TRUE(tree2.Add(30));

	tree2.Add(50);

	EXPECT_FALSE(tree2.Add(50));
}
TEST(Add, AddElement) {

	Tree tree;

	EXPECT_TRUE(tree.Add(50));
}

bool oddNumber(int data) {
	if ((fmod(data, 2) == 1 || fmod(data, 2) == -1) && data != 1 && data != -1) return true;
	else return false;
}
bool aboveNumber(int data, int N) {
	if (data > N) return true;
	else return false;
}
bool selectedNumbers(int data, vector<int> N) {
	for (int i : N) {
		if (data == i) return true;
	}
	return false;
}
TEST(FindByFunc, ZeroParameters) {

	Tree tree;
	fillTree(tree, numbers);

	vector<int> vect = { 55 };

	vector<int> vect2 = tree.FindByFunc(oddNumber);

	auto i = vect2.begin();
	for (auto data : vect) {
		EXPECT_EQ(data, *i);
		i++;
	}
}
TEST(FindByFunc, OneParameter) {

	Tree tree;
	fillTree(tree, numbers);

	vector<int> vect = { 60,65,70,80 };

	vector<int> vect2 = tree.FindByFunc(aboveNumber, 55);

	auto i = vect2.begin();
	for (auto data : vect) {
		EXPECT_EQ(data, *i);
		i++;
	}
}
TEST(FindByFunc, ManyParameters) {

	Tree tree;
	fillTree(tree, numbers);

	vector<int> vect = { 80,43,-12, 55,60,10,20 };
	vector<int> vect2 = { 20,55,60,80 };

	vector<int> vect3 = tree.FindByFunc(selectedNumbers, vect);

	auto i = vect3.begin();
	for (auto data : vect2) {
		EXPECT_EQ(data, *i);
		i++;
	}
}