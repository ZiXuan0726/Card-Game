#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Question {
    int discardID;
    string question;
    string answer;
    int score;
};

struct QuestionNode {
    Question* data = new Question();
    QuestionNode* prev = nullptr;
    QuestionNode* next = nullptr;
};

class QuestionList {

public:
    QuestionNode* head;
    QuestionNode* tail;
    int size;

    QuestionList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    QuestionNode* createNewNode(string question, string answer, int score) {
        QuestionNode* node = new QuestionNode();
        node->data->discardID = 0;
        node->data->question = question;
        node->data->answer = answer;
        node->data->score = score;
        node->prev = nullptr;
        node->next = nullptr;
        return node;
    }

    QuestionNode* createNewDiscardedNode(QuestionNode* qsToDiscard, int id) {
        QuestionNode* discardedNode = new QuestionNode();
        discardedNode->data->discardID = id;
        discardedNode->data->question = qsToDiscard->data->question;
        discardedNode->data->answer = qsToDiscard->data->answer;
        discardedNode->data->score = qsToDiscard->data->score * 0.8;
        discardedNode->prev = nullptr;
        discardedNode->next = nullptr;
        return discardedNode;
    }

    void insertFront(string question, string answer, int score) {
        QuestionNode* newQ = createNewNode(question, answer, score);
        if (head == nullptr) {
            head = newQ;
            tail = newQ;
        }
        else {
            newQ->next = head;
            head->prev = newQ;
            head = newQ;
        }
        size++;
    }

    void insertBack(string question, string answer, int score) {
        QuestionNode* newQ = createNewNode(question, answer, score);
        if (tail == nullptr) {
            head = newQ;
            tail = newQ;
        }
        else {
            newQ->prev = tail;
            tail->next = newQ;
            tail = newQ;
        }
        size++;
    }

    void insertFront(QuestionNode* newQ) {
        if (head == nullptr) {
            head = newQ;
            tail = newQ;
        }
        else {
            newQ->next = head;
            head->prev = newQ;
            head = newQ;
        }
        size++;
    }

    void insertBack(QuestionNode* newQ) {
        if (tail == nullptr) {
            head = newQ;
            tail = newQ;
        }
        else {
            newQ->prev = tail;
            tail->next = newQ;
            tail = newQ;
        }
        size++;
    }

    void deleteQuestionNode(QuestionNode* delNode) {
        if (delNode == head) {
            if (head == tail) {
                head = nullptr;
                tail == nullptr;
            }
            else {
                head = head->next;
                head->prev = nullptr;
            }
        }
        else if (delNode = tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            QuestionNode* prevNode = delNode->prev;
            QuestionNode* nextNode = delNode->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        size--;
    }

    //for question deck use only, delete question from question list, add question to discard deck
    void discard(QuestionNode* nodeToDiscard, QuestionList* discardDeck) {
        deleteQuestionNode(nodeToDiscard);
        nodeToDiscard->data->discardID = discardDeck->size + 1;
        nodeToDiscard->data->score = nodeToDiscard->data->score * 0.8;
        discardDeck->insertBack(nodeToDiscard);
    }

    //retrieve question from discarded deck via id
    QuestionNode* getDiscardedQs(int ID) {
        QuestionNode* current = head;
        while (current->data->discardID != ID) {
            current = current->next;
        }
        return current;
    }

    //Format question
    void printFormatedQuestion(string question) {
        stringstream ss(question);
        string line;
        while (getline(ss, line, '|')) {
            cout << line << endl;
        }
    }

    //process line read from file and create new node
    QuestionNode* getNodeFromLine(const string& line) {
        vector<string> lineVector;
        bool inQuote = false;
        stringstream ss;
        for (char c : line) {
            if (c == '"' && (ss.str().empty() || ss.str().back() != '\\')) {
                inQuote = !inQuote;
            }
            else if (c == ',' && !inQuote) {
                lineVector.push_back(ss.str());
                ss.str("");
                ss.clear();
            }
            else {
                ss << c;
            }
        }

        return createNewNode(lineVector[1], lineVector[2], stoi(lineVector[4]));
    }

    //add all questions into linked list
    void getAllQs(const string& fileName) {
        vector<string> row;
        string line;
        ifstream f(fileName);
        while (getline(f, line)) {
            QuestionNode* newQuestion = getNodeFromLine(line);
            insertBack(newQuestion);
        }
    }

    // shuffle linked list
    void shuffleQuestions() {
        if (size > 2) {
            srand(time(0));
            for (int k = 0; k < size * 2; k++) {
                QuestionNode* current = head;
                QuestionNode* swap = head;
                int steps = rand() % size;
                for (int i = 0; i <= steps; i++) {
                    if (current->next) {
                        current = current->next;
                    }
                }
                int swapStep = rand() % size;
                while (swapStep == steps) { swapStep = rand() % size; }
                for (int j = 0; j <= swapStep; j++) {
                    if (swap->next) {
                        swap = swap->next;
                    }
                }
                Question* tempData = current->data;
                current->data = swap->data;
                swap->data = tempData;
            }
        }
    }

    //for testing use
    void printList() {
        QuestionNode* current = head;
        while (current != nullptr) {
            cout << "Question " << current->data->discardID << ":" << endl;
            printFormatedQuestion(current->data->question);
            cout << ", Answer: " << current->data->answer << ", Score: " << current->data->score << endl << endl;
            current = current->next;
        }
    }

    void printDiscardedQs() {
        if (size == 0) { cout << "There is no question discarded currently, please draw a new question" << endl; }
        else {
            QuestionNode* current = head;
            cout << "Discarded Questions: " << endl;
            for (int i = 0; i < size; i++) {
                cout << "[" << i + 1 << "] ";
                printFormatedQuestion(current->data->question);
                cout << endl << endl;

                current = current->next;
            }
        }
        cout << "[" << size + 1 << "] DRAW NEW QUESTION" << endl;
    }

    // Function to check if the answer is correct
    bool isAnswerCorrect(const string& answer, const string& correctAnswer) {
        return (answer == correctAnswer);
    }

};

