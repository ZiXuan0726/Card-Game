#include "student.hpp"

void printCentered(const string& text, int totalWidth) {
	int padding = (totalWidth - text.size()) / 2;
	cout << setw(padding + text.size()) << text << endl;
}

int main()
{
	/*QuestionList ql;
	QuestionList discardDeck;
	ql.getAllQs("questions.csv");
	ql.shuffleQuestions();

	StudentList list1;
	list1.getAllStudents("students.csv");
	Student* st = list1.getStudent(1);
	cout << st->name << endl << st->totalScore;
	for (int i = 1; i <= 3; i++) {
		st->drawCard(i, &ql, &discardDeck);
	}
	cout << st->q1Question << endl << st->q1Score << endl << st->totalScore;*/

	/*StudentList list;
	Student* st1 = new Student(1, "WOng", 10);
	Student* st2 = new Student(2, "QOIYAN", 13);
	Student* st3 = new Student(3, "SAM", 20);
	Student* st4 = new Student(4, "JOE", 11);

	list.insertBack(st1);
	list.insertBack(st2);
	list.insertBack(st3);
	list.insertBack(st4);

	list.InsertionSortLinkedList();
	list.LeaderBoardshow();*/
	string line;
	string name = "name";

	for (int i = 1; i <= 30; i++) {
		name = "";
		name = to_string(i) + ": " + "name";
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

};



