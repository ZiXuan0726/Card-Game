#pragma once
#include <string>
#include <iostream>
#include <limits>
#include "questions.hpp"
using namespace std;

struct StudentNode
{
    
};

class Student {
public:
    
    Student* prev = nullptr;
    Student* next = nullptr;
    int studentID;
    string name;
    string q1Question;
    int q1Score;
    string q2Question;
    int q2Score;
    string q3Question;
    int q3Score;
    int totalScore = 0;

    Student(string name, int studentId) {
        this->name = name;
        this->studentID = studentId;
    }

    void recordQs(int i, string question, int score) {
        if (i == 1) {
            this->q1Question = question;
            this->q1Score = score;
        }
        if (i == 2) {
            this->q2Question = question;
            this->q2Score = score;
        }
        if (i == 3) {
            this->q3Question = question;
            this->q3Score = score;
        }
    }

    void drawCard(int i, QuestionList* ql, QuestionList* discardDeck) {
        int choice = 0;
        int score = 0;
        string question;
        QuestionNode* drewQuestion = ql->tail;
        do {
            cout << endl << "Question: (marks: " << drewQuestion->data->score << ")" << endl;
            ql->printFormatedQuestion(drewQuestion->data->question);
            question = drewQuestion->data->question;
            cout << endl << "Do you wish to answer the question (1) or discard it (2)? (1/2): ";
            cin >> choice;

            //discard
            if (choice == 2) {
                score = 0;
                ql->discard(drewQuestion, discardDeck);
                cout << "Question discarded" << endl;
                recordQs(i, "Question Discarded", 0);
            }
            //answer
            else if (choice == 1) {
                string ans;
                cout << "Please enter your answer: ";
                cin >> ans;
                //answer correct, add score, delete question from question deck
                if (ans == drewQuestion->data->answer) {
                    score = drewQuestion->data->score;
                    totalScore = totalScore + score;
                    cout << endl << "Correct answer! You earned: " << score << "points" << endl;
                    ql->deleteQuestionNode(drewQuestion);
                }
                //answer wrong, move question to answered question
                else {
                    score = 0;
                    cout << endl << "Incorrect answer! You earned 0 points." << endl;
                    ql->deleteQuestionNode(drewQuestion);
                }
                recordQs(i, question, score);
            }
            //input validation
            else {
                cout << endl << "Invalid option, please try again!" << endl << endl;
                cin.clear(); // Clear the error flag set by invalid input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while ((choice != 1 && choice != 2) || cin.fail());
    }

    void selectDiscardedQuestion(int i,QuestionList* discardDeck, int choice) {
        int score = 0;
        string question;
        QuestionNode* selDiscardQuestion = discardDeck->getDiscardedQs(choice);
        question = selDiscardQuestion->data->question;
        string ans;
        cout << endl << "Question: (marks: " << selDiscardQuestion->data->score << ")" << endl;
        discardDeck->printFormatedQuestion(selDiscardQuestion->data->question);
        cout << "Please enter your answer: ";
        cin >> ans;

        //answer correct, add score, delete question from discarded deck
        if (ans == selDiscardQuestion->data->answer) {
            cout << endl << "Correct answer! You earned: " << selDiscardQuestion->data->score << "points" << endl;
            score = selDiscardQuestion->data->score;
            totalScore = totalScore + selDiscardQuestion->data->score;
            discardDeck->deleteQuestionNode(selDiscardQuestion);
        }
        //answer wrong, question remains in answered deck
        else {
            cout << endl << "Incorrect answer! You earn 0 points." << endl;
            score = 0;
            discardDeck->deleteQuestionNode(selDiscardQuestion);
        }
        recordQs(i, question, score);
    }

 


};

class StudentList {
public:
    int size = 0;
    Student* head;
    Student* tail;
    Student* createNewNode(string name) {
        Student* node = new Student(name, size + 1);
 
        return node;
    }

    

    void insertFront(string name) {
        Student* nextStu = createNewNode(name);
        if (head == nullptr) {
            head = nextStu;
            tail = nextStu;
        }
        else {
            nextStu->next = head;
            head->prev = nextStu;
            head = nextStu;
        }
        size++;
    }

    void insertFront(Student* nextStu) {
        if (head == nullptr) {
            head = nextStu;
            tail = nextStu;
        }
        else {
            nextStu->next = head;
            head->prev = nextStu;
            head = nextStu;
        }
        size++;
    }

    void insertBack(string name) {
        Student* nextStu = createNewNode(name);
        if (tail == nullptr) {
            head = nextStu;
            tail = nextStu;
        }
        else {
            nextStu->prev = tail;
            tail->next = nextStu;
            tail = nextStu;
        }
        size++;
    }
};