//#pragma once
//#include <iostream>
//#include <string>
//#include "student.hpp"
//#include "Tree.hpp"
//
//using namespace std;
//
//
//string students[10][9] = {
//	{"1001", "Student 1001", "What is your favorite subject?", "30", "What is your hobby?", "20", "What is your goal?", "15", "65"},
//	{"1002", "Student 1002", "What is your favorite subject?", "20", "What is your hobby?", "10", "What is your goal?", "20", "50"},
//	{"1003", "Student 1003", "What is your favorite subject?", "10", "What is your hobby?", "20", "What is your goal?", "15", "45"},
//	{"1004", "Student 1004", "What is your favorite subject?", "30", "What is your hobby?", "20", "What is your goal?", "15", "65"},
//	{"1005", "Student 1005", "What is your favorite subject?", "20", "What is your hobby?", "10", "What is your goal?", "20", "50"},
//	{"1006", "Student 1006", "What is your favorite subject?", "10", "What is your hobby?", "20", "What is your goal?", "15", "45"},
//	{"1007", "Student 1007", "What is your favorite subject?", "30", "What is your hobby?", "20", "What is your goal?", "15", "65"},
//	{"1008", "Student 1008", "What is your favorite subject?", "20", "What is your hobby?", "10", "What is your goal?", "20", "50"},
//	{"1009", "Student 1009", "What is your favorite subject?", "10", "What is your hobby?", "20", "What is your goal?", "15", "45"},
//	{"1010", "Student 1010", "What is your favorite subject?", "30", "What is your hobby?", "20", "What is your goal?", "15", "65"}
//};
//
//
//int main() {
//	//for (int i = 0; i < 10; i++) {
//	//	cout << "Student ID: " << students[i][0] << endl;
//	//	cout << "Student Name: " << students[i][1] << endl;
//	//	cout << "Total Points: " << stoi(students[i][3]) + stoi(students[i][5]) + stoi(students[i][7]) << endl;
//	//	cout << endl;
//	//}
//
//	// convert the 2D array into linkedlist
//	// create a linkedlist of students
//
//	//StudentLinkedList* studentList= new StudentLinkedList();
//
//	//for (int i = 0; i < 10; i++) {
//	//	studentList->insertStudentToTail(stoi(students[i][0]), students[i][1], students[i][2], stoi(students[i][3]), students[i][4], stoi(students[i][5]), students[i][6], stoi(students[i][7]));
//	//}
//
//
//	//studentList->displayOnlyStudents();
//	StudentList* studentList = new StudentList();
//	for (int i = 0; i < 10; i++) {
//		Student* stNode = new Student(stoi(students[i][0]), students[i][1], students[i][2], stoi(students[i][3]), students[i][4], stoi(students[i][5]), students[i][6], stoi(students[i][7]), stoi(students[i][8]));
//		studentList->insertBack(stNode);
//	}
//	
//	//cout << "Not Sorted List: " << endl;
//	//studentList->printname();
//
//	cout << endl << endl << "SOrted List: " << endl;
//	studentList->InsertionSortLinkedList();
//	studentList->printname();
//
//	
//	Tree* studentTree = new Tree();
//
//	// create a tree of students
//	//cout << "1" << endl; 
//	studentTree->buildCompleteBinaryTree(studentList->getHead());
////cout << "2" << endl;
//	// studentTree->displayAllStudents();
//	studentTree->preorder();
//	//cout << "3" << endl;
//
//
//	// write a funtion display binary Tree by BFS
//	studentTree->displayStudentWithBFS();
//	
//
//
//return 0;
//
//}