#include <iostream>
using namespace std;

void Menu();

struct Node
{
  string process_name;
  int arrival_time;
  int burst_time;
};

int main()
{
  int choice;
  Menu();
  
  while (true) {
	cout << "\nEnter choice: ";
	cin >> choice;
   
	if(choice == 0) {
		break;
	}

	Node *process = new Node;
    cout << "\nEnter process name: ";
    cin.ignore();
    getline(cin, process->process_name);

    cout << "Enter arrival time: ";
    cin >> process->arrival_time; // process is coming into the ready state

    cout << "Enter burst time: ";
    cin >> process->burst_time;
  };

  return 0;
}

void Menu()
{
  cout << "\nEnter 0 to end the program and view the report";
  cout << "\nEnter any other integer to add process\n";
}
