#include "student.hpp"
#include "questions.hpp"
#include "Tree.hpp"
//#include "iostream"


int main() {
    string name;
    StudentList namelist;
    QuestionList ql;
    QuestionList discardDeck;
    int choice;
    Student* student = nullptr;

    ql.getAllQs("questions.csv");
    ql.shuffleQuestions();
    namelist.getAllStudents("students.csv");

    for (int roundNum = 1; roundNum <= 3; roundNum++) {
        cout << string(106, '-') << endl;
        cout << "Round: " << roundNum << endl << endl;

        
        for (int j = 1; j <= namelist.size; j++)
        { 
            do {
                student = namelist.getStudent(j);
                
                cout <<endl <<  "Name: " << student->name << endl;
                
                discardDeck.printDiscardedQs();
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == (discardDeck.size + 1)) { //draw card
                    student->drawCard(roundNum, &ql, &discardDeck);
                }
                else if (choice <= discardDeck.size) { //discarded deck
                    student->selectDiscardedQuestion(roundNum, &discardDeck, choice);
                }
                else { //input validation
                    cout << endl << "Invalid option, please try again!" << endl << endl;
                    cin.clear(); // Clear the error flag set by invalid input
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (choice < 1 || choice > discardDeck.size + 1 || cin.fail());
            cout << endl << string(106, '-') << endl;
            cout << "Id: " << student->studentID << ", Name: " << student->name << ", total score: " << student->totalScore << endl;
        }


        //ql.printList();
        //discardDeck.printDiscardedQs();
        /*cout << string(106, '-') << endl;
        cout << "Your name: " << student->name << endl;
        cout << "Your ID: " << student->studentID << endl;
        cout << "Question 1: " << student->q1Question << endl;
        cout << "Your score: " << student->q1Score << endl;
        cout << "Question 2: " << student->q2Question << endl;
        cout << "Your score: " << student->q2Score << endl;
        cout << "Question 3: " << student->q3Question << endl;
        cout << "Your score: " << student->q3Score << endl;
        cout << "Your final score: " << student->totalScore << endl;
        cout << string(106, '#') << endl;  */
        namelist.InsertionSortLinkedList();
        namelist.LeaderBoardshow(); // Display the leaderboard

    }

    Tree* studentTree = new Tree();
    studentTree->buildCompleteBinaryTree(namelist.getHead());
    studentTree->preorder();

    studentTree->displayStudentWithBFS();
    return 0;
}