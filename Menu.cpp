#include "Menu.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Faculty.h"
#include <stdlib.h>
#include "GenBST.h"

using namespace std;

//constructor/destructor=========================================================
Menu::Menu(GenBST<Student>* ms, GenBST<Faculty>* mf)
{
  masterStudent = ms;
  masterFaculty = mf;
}

Menu::~Menu()
{

}


void Menu::printMenu()
{
  cout << "\nMENU OPTIONS:\n"
  "1. Print all students and their information (1)\n"
  "2. Print all faculty and their information (2)\n"
  "\n"
  "3. Search for student and display information (3)\n"
  "4. Search for faculty and display information (4)\n"
  "\n"
  "5. Using student ID, print corresponding name and info of faculty advisor (5)\n"
  "6. Using faculty ID, print list of all names and info of their advisees (6)\n"
  "\n"
  "7. Add a new student (7)\n"
  "8. Delete a student (8)\n"
  "\n"
  "9. Add a new faculty member (9)\n"
  "10. Delete a faculty member (10)\n"
  "\n"
  "11. Change a student's advisor (11)\n"
  "12. Remove an advisee from a faculty member (12)\n"
  "13. Rollback, undo (13)\n"
  "14. EXIT (14)\n";
}

void Menu::prompt(int ans)
{
  int id, a;
  string n, l, m, d;
  switch(ans) {
    case 1:
      printStudents();
      break;

    case 2:
      printFaculty();
      break;

    case 3:
      cout << "What is the student's ID?: ";
      cin >> id;
      findStudent(id);
      break;

    case 4:
      cout << "What is the faculty member's ID?: ";
      cin >> id;
      findFaculty(id);
      break;

    case 5:
      cout << "What is the Student's ID?: ";
      printAdvisor(id);
      break;

    case 6:
      cout << "What is the faculty member's ID?: ";
      printAdvisees(id);
      break;

    case 7:
      cout << "ID: " << endl;
      cin >> id;
      cin.ignore();
      cout << "Name: " << endl;
      getline(cin, n);
      cout << "Level: " << endl;
      getline(cin, l);
      cout << "Major: " << endl;
      getline(cin, m);
      cout << "Advisor: " << endl;
      cin >> a;

      addStudent(id, n, l, m, a);
      break;

    case 8:
      cout << "Student's ID: ";
      cin >> id;
      deleteStudent(id);
      break;

    case 9:
      cout << "ID: " << endl;
      cin >> id;
      cin.ignore();
      cout << "Name: " << endl;
      getline(cin, n);
      cout << "Level: " << endl;
      getline(cin, l);
      cout << "Department: " << endl;
      getline(cin, d);
      cout << "How many advisees? " << endl;
      addFaculty(id, n, l, d);
      int idcount;
      cin >> idcount;
      int advisee;
      for(int i = 0; i < idcount; i++) {
        cout << "Advisee ID: " << endl;
        cin >> advisee;
        masterFaculty->search(id).adviseeList->insertFront(new int(advisee));
      }

      break;

    case 10:
      cout << "Faculty's ID: ";
      cin >> id;
      deleteFaculty(id);
      break;

    case 11:
      break;

    case 12:
      break;

    case 13:
      break;

    case 14:
      cout << "Exiting" << endl;
      break;

    default:
      cout << "INVALID INPUT" << endl;
      cout << "DID NOT EXECUTE" << endl;
      //exit(EXIT_FAILURE);
      break;
  }
}

//1
void Menu::printStudents()
{
  cout << "PRINTING STUDENTS" << endl;
  masterStudent->printTree();
}

//2
void Menu::printFaculty()
{
  cout << "PRINTING FACULTY" << endl;
  masterFaculty->printTree();
}

//3
void Menu::findStudent(int id)
{
  cout << "FINDING STUDENT" << endl;
  cout << masterStudent->search(id) << endl;
}

//4
void Menu::findFaculty(int id)
{
  cout << "FINDING FACULTY" << endl;
  cout << masterFaculty->search(id) << endl;
}

//5
void Menu::printAdvisor(int id)
{
  cout << "PRINTING ADVISOR" << endl;
}

//6
void Menu::printAdvisees(int id)
{
  cout << "PRINTING ADVISEES" << endl;
}

//7
void Menu::addStudent(int id, string n, string l, string m, int a)
{
  cout << "ADDING STUDENT" << endl;
  masterStudent->insert(*(new Student(id,n,l,m,a)));
}

//8
void Menu::deleteStudent(int id) {
  cout << "DELETING STUDENT" << endl;
  masterStudent->deleteRec(masterStudent->search(id));
}

//9
void Menu::addFaculty(int id, string n, string l, string d) {
  cout << "ADDING FACULTY" << endl;
  masterFaculty->insert(*(new Faculty(id,n,l,d)));
}


//10
void Menu::deleteFaculty(int id) {
  cout << "DELETING FACULTY" << endl;
  masterFaculty->deleteRec(masterFaculty->search(id));
}

//11
void changeAdvisor(int sid, int fid) {

}

//12
void removeAdvisee(int sid, int fid) {

}

//13
void rollBack() {
  
}
