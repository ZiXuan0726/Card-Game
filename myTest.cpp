#include "student.hpp"
#include "questions.hpp"


int main() {
    string name;
    StudentList namelist;
    QuestionList ql;
    QuestionList discardDeck;
    int choice;

    ql.getAllQs("questions.csv");
    ql.shuffleQuestions();

    for (int j = 0; j < 100; j++)
    {
        cout << "Enter your name: " << endl;
        cin.ignore();
        getline(cin, name);
        Student* student = namelist.createNewNode(name);

        for (int i = 1; i <= 3; i++) {
            cout << string(106, '-') << endl;
            cout << "Round: " << i << endl << endl;

            do {
                discardDeck.printDiscardedQs();
                cout << "Enter your choice: ";
                cin >> choice;
                if (choice == (discardDeck.size + 1)) { //draw card
                    student->drawCard(i, &ql, &discardDeck);
                }
                else if (choice <= discardDeck.size) { //discarded deck
                    student->selectDiscardedQuestion(i, &discardDeck, choice);
                }
                else { //input validation
                    cout << endl << "Invalid option, please try again!" << endl << endl;
                    cin.clear(); // Clear the error flag set by invalid input
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (choice < 1 || choice > discardDeck.size + 1 || cin.fail());

        }
        namelist.insertFront(student);

        //ql.printList();
        //discardDeck.printDiscardedQs();
        cout << string(106, '-') << endl;
        cout << "Your name: " << student->name << endl;
        cout << "Your ID: " << student->studentID << endl;
        cout << "Question 1: " << student->q1Question << endl;
        cout << "Your score: " << student->q1Score << endl;
        cout << "Question 2: " << student->q2Question << endl;
        cout << "Your score: " << student->q2Score << endl;
        cout << "Question 3: " << student->q3Question << endl;
        cout << "Your score: " << student->q3Score << endl;
        cout << "Your final score: " << student->totalScore << endl;
        cout << string(106, '#') << endl;  

        namelist.LeaderBoardshow(); // Display the leaderboard
    }
    

    return 0;
}