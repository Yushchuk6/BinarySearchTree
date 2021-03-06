#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>
#include "BSTree.h"
using namespace std;

void ShowVector(vector<int> arr) {
	for (auto i = arr.begin(); i != arr.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
}

bool multiple(int data, int N) {
	if (fmod(data, N) == 0) return true;
	else return false;
}
bool aboveNumber(int data, int N) {
	if (data > N) return true;
	else return false;
}
bool belowNumber(int data, int N) {
	if (data < N) return true;
	else return false;
}


bool oddNumber(int data) {
	if ((fmod(data, 2) == 1 || fmod(data, 2) == -1) && data != 1 && data != -1) return true;
	else return false;
}
bool primeNumber(int data) {
	for (int i = 2; i <= abs(data) / 2; ++i) {
		if (fmod(data, i) == 0) return false;
	}
	return true;
}
bool сompositeNumber(int data) {
	for (int i = 2; i <= abs(data) / 2; ++i) {
		if (fmod(data, i) == 0) return true;
	}
	return false;
}
bool intFormRootNumber(int data) {
	int var = sqrt(data);
	if (floor(var) == var) return true;
	return false;
}


bool selectedNumbers(int data, vector<int> N) {
	for (int i : N) {
		if (data == i) return true;
	}
	return false;
}
bool intervalNumber(int data, vector<int> N) {
	if (data >= N[0] && data <= N[1]) return true;
	return false;
}


int sumOfNumber(int data) {
	int sum = 0;
	data = abs(data);
	while (data != 0) {
		sum = sum + (fmod(data, 10));
		data = data / 10;
	}
	return sum;
}

bool aboveSumOfDigits(int data, int N) {
	if (sumOfNumber(data) > N) return true;
	else return false;
}
bool belowSumOfDigits(int data, int N) {
	if (sumOfNumber(data) < N) return true;
	else return false;
}
bool intervalSumOfDigits(int data, vector<int> N) {
	data = sumOfNumber(data);
	if (data >= N[0] && data <= N[1]) return true;
	return false;
}


int main() {
	Tree *tree = new Tree();
	srand(time(nullptr));
	for (int i = 0; i < 15; i++) {
		tree->Add(rand() % 199 - 99);
	}
	vector<int> arr = { 12,6,36,23,76,-34,-27 };
	vector<int> arr2 = { -20,50 };
	tree->Add(50);
	tree->Add(60);
	tree->Add(70);
	tree->Add(65);
	tree->Add(55);
	tree->Add(80);
	tree->Add(20);
	tree->Add(30);

	cout << tree->MaxNumber() << endl;
	cout << tree->MinNumber() << endl;
	ShowVector(tree->AllLeaves());
	ShowVector(tree->FindByFunc(multiple, 4));
	ShowVector(tree->FindByFunc(oddNumber));
	ShowVector(tree->FindByFunc(aboveNumber, 12));
	ShowVector(tree->FindByFunc(belowNumber, 12));
	ShowVector(tree->FindByFunc(selectedNumbers, arr));
	ShowVector(tree->FindByFunc(primeNumber));
	ShowVector(tree->FindByFunc(сompositeNumber));
	ShowVector(tree->FindByFunc(intervalNumber, arr2));
	ShowVector(tree->FindByFunc(aboveSumOfDigits, 6));
	ShowVector(tree->FindByFunc(belowSumOfDigits, 6));
	ShowVector(tree->FindByFunc(intervalSumOfDigits, {3,7}));
	ShowVector(tree->FindByFunc(intFormRootNumber));
}