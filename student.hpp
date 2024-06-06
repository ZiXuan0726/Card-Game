#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>
#include <sstream>
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
    Student(int studentId, string name) {
        this->name = name;
        this->studentID = studentId;
        this->totalScore = 0;
    }
    Student(int studentId, string name,int totalScore) {
        this->name = name;
        this->studentID = studentId;
        this->totalScore = totalScore;
    }
    Student(int studentId, string name, string q1, int s1, string q2, int s2, string q3, int s3, int totalScore) {
        this->name = name;
        this->studentID = studentId;
        this->q1Question = q1;
        this->q1Score = s1;
        this->q2Question = q2;
        this->q2Score = s2;
        this->q3Question = q3;
        this->q3Score = s3;
        this->totalScore = totalScore;
    }
    void recordQs(int i, string questionID, int score) {

        if (i == 1) {
            this->q1Question = questionID;
            this->q1Score = score;
        }
        if (i == 2) {
            this->q2Question = questionID;
            this->q2Score = score;
        }
        if (i == 3) {
            this->q3Question = questionID;
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
            question = drewQuestion->data->questionID;
            cout << endl << "Do you wish to answer the question (1) or discard it (2)? (1/2): ";
            cin >> choice;

            //discard
            if (choice == 2) {
                score = 0;
                ql->discard(drewQuestion, discardDeck);
                cout << "Question discarded" << endl;
                recordQs(i, "N/A", 0);
                cout << discardDeck->head;
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

    void selectDiscardedQuestion(int i, QuestionList* discardDeck, int choice) {
        int score = 0;
        string question;
        QuestionNode* selDiscardQuestion = discardDeck->getDiscardedQs(choice);
        question = selDiscardQuestion->data->questionID;
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
        //answer wrong, question moved to answered deck
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
    int id;
    string name;

    Student* createNewNode(string name) {
        Student* node = new Student(name, size + 1);

        return node;
    }

    StudentList()
    {
    }
    StudentList(int id, string name)
    {
        this->id = id;
        this->name = name;
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

    void insertBack(Student* nextStu) {
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

    void sort() {
        bool swap = false;
        do {
            Student* current = head;
            Student* nextNode = current->next;
            swap = false;
            for (int i = 0; i < size; i++) {
                if (current->totalScore < nextNode->totalScore) {
                    
                    Student* temp = current;

                   /* current->next = temp->next;
                    current->prev = temp->prev;*/
                    
                    /*current->prev = nextNode->prev;
                    current->next = nextNode->next;

                    nextNode->prev = temp->prev;
                    nextNode->next = temp->next;
                    */
                    temp->prev = current->prev;

                    temp->next = nextNode->next;
                    
                    
                    nextNode->prev = current->prev;
                    current->prev = nextNode->next;
                    current->next = temp->next;

                }
            }
            if (swap == false) {
                break;
            }
        } while (swap = true);
    }
    

    void bubbleSorting() {
        bool swapped;
        Student* current = nullptr;
        Student* lastSorted = nullptr;
        if (size <= 1)
            return;
        else
        {

            do {
                swapped = false;
                Student* current = head;

                while (current != lastSorted) {
                    if (current->totalScore < current->next->totalScore) {
                        // Swap student data
                        int tempID = current->studentID;
                        string tempName = current->name;
                        int tempTotalScore = current->totalScore;
                        string tempQ1Question = current->q1Question;
                        int tempQ1Score = current->q1Score;
                        string tempQ2Question = current->q2Question;
                        int tempQ2Score = current->q2Score;
                        string tempQ3Question = current->q3Question;
                        int tempQ3Score = current->q3Score;
                        current->studentID = current->next->studentID;
                        current->name = current->next->name;
                        current->totalScore = current->next->totalScore;
                        current->q1Question = current->next->q1Question;
                        current->q1Score = current->next->q1Score;
                        current->q2Question = current->next->q2Question;
                        current->q2Score = current->next->q2Score;
                        current->q3Question = current->next->q3Question;
                        current->q3Score = current->next->q3Score;

                        current->next->studentID = tempID;
                        current->next->name = tempName;
                        current->next->totalScore = tempTotalScore;
                        current->next->q1Question = tempQ1Question;
                        current->next->q1Score = tempQ1Score;
                        current->next->q2Question = tempQ2Question;
                        current->next->q2Score = tempQ2Score;
                        current->next->q3Question = tempQ3Question;
                        current->next->q3Score = tempQ3Score;

                        swapped = true;
                    }
                    current = current->next;
                }
                lastSorted = current;

            } while (swapped);
        }
    }

    void displayLeaderboard() {
        bool setw ;
        int rank = 1;
        Student* current = head;
        while (current != nullptr) {
            cout << std::setw(11) << rank << "\t";
            cout << std::setw(11)  << current->name << "\t";
            cout << std::setw(11) << current->q1Question << "(" << current->q1Score << ")\t";
            cout << std::setw(11) << current->q2Question << "(" << current->q2Score << ")\t";
            cout << std::setw(11) << current->q3Question << "(" << current->q3Score << ")\t";
            cout << std::setw(11) << current->totalScore << "\t";
            cout << endl << string(106, '-') << endl;

            current = current->next;
            rank++;
            
        }
    }


    void LeaderBoardshow()
    {
        cout << endl << "\t\t\tLeaderboard" << endl;
        cout << string(106, '-') << endl;
        cout << "||" << "Ranking\t";
        cout << "||" << "Student\t";
        cout << "||" << "Round 1\t";
        cout << "||" << "Round 2\t";
        cout << "||" << "Round 3\t";
        cout << "||" << "Overall Score\t";
        cout << endl << string(106, '-') << endl;

        sort();
        displayLeaderboard();
    }

    void getAllStudents(const string& fileName) {
        string line,name;
        int id;
        ifstream f(fileName);
        while (getline(f, line)) {
         Student* studentname = getNodeFromLine(line);
         insertBack(studentname);         
        }
        
    }

    Student* getStudent(int id)
    {
        Student* current = head;
        while (current->studentID != id)
        {
            if (current->studentID == id)
            {
                return current;
            }
            current = current->next;  
        }
    }

    Student* getNodeFromLine(const string& line) {
        stringstream ss(line);
        string idStr, name;
        if (getline(ss, idStr, ',') && getline(ss, name)) {
            if (!name.empty() && name.back() == ',') {
                name.pop_back();
            }
            int id = stoi(idStr);
            Student* newStudent = new Student(id, name);
            return newStudent;
        }
        return nullptr;
    }
    void printname()
    {
        string name;
        int id;
        Student* current = head;

        while (current != nullptr)
        {
            cout << "Name: " << current->name << endl;
            cout << "ID: " << current->studentID << endl;
            current = current->next;
        }  
    }

    Student* getHead() {
    	return head;
    }

    void InsertionSortLinkedList() {
        Student* sortedList = nullptr;
        Student* temp = head;
        while (temp != nullptr) {
            Student* next = temp->next;
            if (sortedList == nullptr || sortedList->totalScore < temp->totalScore) {
                temp->next = sortedList;
                sortedList = temp;
            }
            else {
                Student* cur = sortedList;
                while (cur->next != nullptr && cur->next->totalScore >= temp->totalScore) {
                    cur = cur->next;
                }
                temp->next = cur->next;
                cur->next = temp;
            }
            temp = next;
        }
        head = sortedList;

        // release the memory
        delete temp;
    }

};