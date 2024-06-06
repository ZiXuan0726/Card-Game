#pragma once
#include <iostream>
#include "queue.hpp"
#include "student.hpp"
#include "Struct.hpp"

using namespace std;



class Tree {
	TreeNode* root;
public:
	Tree() {
		root = NULL;
	}

	TreeNode* createNode(string name, int totalScore) {
		TreeNode* newNode = new TreeNode();
		newNode->name = name;
		newNode->totalScore = totalScore;
		return newNode;
	}

	void insertNode(string name, int totalScore) {
		TreeNode* newNode = createNode(name, totalScore);
		if (root == NULL) {
			root = newNode;
		}
		else {
			TreeNode* current = root;
			TreeNode* parent = NULL;
			while (current != NULL) {
				parent = current;
				if (totalScore < current->totalScore) {
					current = current->left;
				}
				else {
					current = current->right;
				}
			}
			if (totalScore < parent->totalScore) {
				parent->left = newNode;
			}
			else {
				parent->right = newNode;
			}
		}
	}

	TreeNode* createTreeNode(Student* studentNode) {
		TreeNode* newNode = new TreeNode();
		newNode->name = studentNode->name;
		newNode->totalScore = studentNode->q1Score + studentNode->q2Score + studentNode->q3Score;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}


	void buildCompleteBinaryTree(Student* head) {
		if (!head) return;


		// Initialize the root of the binary tree

		TreeNode* newRoot = createTreeNode(head);
		Queue* queue = new Queue();
		queue->enqueue(newRoot);
		//cout << "6" << endl;
		// Pointer to iterate through the linked list
		Student* current = head->next;

		while (current) {
			// Get the front node from the queue
			TreeNode* parent = queue->dequeue();
			// Assign the left child
			parent->left = createTreeNode(current);
			queue->enqueue(parent->left);

			// Move to the next element
			current = current->next;
			if (!current) break; // Check if there are more nodes in the list

			// Assign the right child
			parent->right = createTreeNode(current);
			queue->enqueue(parent->right);

			cout << "Parent Node:" << parent->name << endl;
			cout << "Left Child:" << parent->left->name <<endl;
			cout << "Right Child:" << parent->right->name << endl;
			cout <<"-------------------"<<endl;

			current = current->next;
		}
		//cout << "7" << endl;

		cout << "Root Node:" << newRoot->name << endl;
		cout << "Left Child:" << newRoot->left->name << endl;
		cout << "Right Child:" << newRoot->right->name << endl;
		cout << "-------------------" << endl;
		cout << "8" << endl;
		this->root = newRoot;
	}

	// wrapper function for displayAllStudents
	void displayAllStudents() {
		TreeNode* current = root;
		displayAllStudents(current);
	}

	void displayAllStudents(TreeNode* current) {
		if (current != NULL) {
			cout << "Student Name: " << current->name << endl;
			cout << "Total Points: " << current->totalScore << endl;
			cout << endl;
			displayAllStudents(current->left);
			displayAllStudents(current->right);
		}
	}
	//wrapper BFS
	void displayStudentWithBFS() {
		TreeNode* current = root;
		displayStudentWithBFS(current);
	}

	void printCentered(const string& text, int totalWidth) {
		int padding = (totalWidth - text.size()) / 2;
		cout << setw(padding + text.size()) << text << endl;
	}

	void displayStudentWithBFS(TreeNode* current) {
		Queue* queue = new Queue();
		queue->enqueue(current);
		string name, line;
		for (int i = 1; i <= 30; i++) {
			TreeNode* current = queue->dequeue();
			
			for (int i = 1; i <= 30; i++) {
				name = "";
				name = to_string(i) + ": " + current->name;
				if (i == 1 || i == 3 || i == 7 || i == 15 || i == 30) {
					line += name;
					cout << endl;
					printCentered(line, 110);
					line = "";
					//cout << "name" << endl;
				}
				else {
					//cout << "name" << "\t";
					line += name;
					line += "    ";
				}
			}

			//cout << "Student Name: " << current->name << endl;
			//cout << "Total Points: " << current->totalScore << endl;
			//cout << endl;
			if (current->left != NULL) {
				queue->enqueue(current->left);
			}
			if (current->right != NULL) {
				queue->enqueue(current->right);
			}
		}
	
	}

	void preorder() {
		preorder(root);
	}

	void preorder(TreeNode* current) {
		if (current == nullptr) {
			return;
		}

		cout << "Student Name: " << current->name << endl;
		cout << "Total Points: " << current->totalScore << endl;
		preorder(current->left);//L
		preorder(current->right);//R
	}
	
	// get root
TreeNode* getRoot() {
		return root;
	}

};