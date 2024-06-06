#pragma once
#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
	string name;
	int totalScore;
	TreeNode* left;
	TreeNode* right;
};

struct QueueNode {
	TreeNode* treeNode;
	QueueNode* next;
};


//struct Student {
//	int studentID;
//	string name;
//
//	string q1Question;
//	string q2Question;
//	string q3Question;
//
//	int q1Score;
//	int q2Score;
//	int q3Score;
//
//	Student* next;
//};
