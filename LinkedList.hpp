//#pragma once
//#include <iostream>
//#include <string>
//#include "Struct.hpp"
//
//using namespace std;
//
//// Dummy data
//
//class StudentLinkedList {
//	Student* head;
//	Student* tail;
//public:
//	StudentLinkedList() {
//		head = NULL;
//		tail = NULL;
//	}
//
//	Student* createStudent(int studentID, string name, string q1Question, int q1Score, string q2Question, int q2Score, string q3Question, int q3Score) {
//		Student* newStudent = new Student();
//		newStudent->studentID = studentID;
//		newStudent->name = name;
//		newStudent->q1Question = q1Question;
//		newStudent->q1Score = q1Score;
//		newStudent->q2Question = q2Question;
//		newStudent->q2Score = q2Score;
//		newStudent->q3Question = q3Question;
//		newStudent->q3Score = q3Score;
//		newStudent->next = NULL;
//		return newStudent;
//	}
//
//	void insertStudentToTail(int studentID, string name, string q1Question, int q1Score, string q2Question, int q2Score, string q3Question, int q3Score) {
//		Student* newStudent = createStudent(studentID, name, q1Question, q1Score, q2Question, q2Score, q3Question, q3Score);
//		if (head == NULL) {
//			head = newStudent;
//			tail = newStudent;
//		}
//		else {
//			tail->next = newStudent;
//			tail = newStudent;
//		}
//	}
//
//	// Display all students in linked list use -> to separate the student
//	void displayAllStudents() {
//		Student* current = head;
//		while (current != NULL) {
//			cout << "Student ID: " << current->studentID << endl;
//			cout << "Name: " << current->name << endl;
//			cout << "Total:" << current->q1Score + current->q2Score + current->q3Score << endl;
//			cout << "-->" << endl;
//			current = current->next;
//		}
//	}
//
//	void displayOnlyStudents() {
//		Student* current = head;
//		while (current != NULL) {
//			cout << current->studentID << "==>";
//			current = current->next;
//		}
//	}
//
//	Student* getHead() {
//		return head;
//	}
//
//	// Insertion Sort
//	int getTotalScore(Student* student) {
//		return student->q1Score + student->q2Score + student->q3Score;
//	}
//
//	void InsertionSortLinkedList() {
//		Student* sortedList = nullptr;
//		Student* temp = head;
//		while (temp != nullptr) {
//			Student* next = temp->next;
//			if (sortedList == nullptr || getTotalScore(sortedList) < getTotalScore(temp)) {
//				temp->next = sortedList;
//				sortedList = temp;
//			}
//			else {
//				Student* cur = sortedList;
//				while (cur->next != nullptr && getTotalScore(cur->next) >= getTotalScore(temp)){
//					cur = cur->next;
//				}
//				temp->next = cur->next;
//				cur->next = temp;
//			}
//			temp = next;
//		}
//		head = sortedList;
//
//		// release the memory
//		delete temp;
//	}
//
//
//};