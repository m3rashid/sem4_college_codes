#include <bits/stdc++.h>
using namespace std;

struct Node
{
  string process;
  int priority;
  Node *next;
};

Node *head = NULL;
int pending = 0;

void Display();
void Insert();
void Execute();
void Menu();

int main()
{
  Menu();
  int choice;

  while (true)
  {
    cout << endl
         << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 0:
      Menu();
      cout << endl;
      break;
    case 1:
      Insert();
      cout << endl;
      break;
    case 2:
      Execute();
      cout << endl;
      break;
    case 3:
      cout << "Total number of pending processes: " << pending << endl
           << endl;
      break;
    case 4:
      Display();
      cout << endl;
      break;
    case 5:
      return 0;
    default:
      cout << "Invalid choice" << endl;
    }
  }
  return 0;
}

void Insert()
{
  Node *temp = new Node;
  cout << "Enter the process name: ";
  cin.ignore();
  getline(cin, temp->process);
  cout << "Enter the priority: ";
  cin >> temp->priority;
  temp->next = NULL;
  pending++;

  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL && curr->priority <= temp->priority)
    {
      prev = curr;
      curr = curr->next;
    }
    if (prev == NULL)
    {
      temp->next = head;
      head = temp;
    }
    else
    {
      prev->next = temp;
      temp->next = curr;
    }
  }
  Display();
}

void Display()
{
  if (head == NULL)
  {
    cout << "No processes in the queue" << endl;
    return;
  }
  cout << "The current priority schedule:" << endl;
  cout << "| " << head->process << "|" << head->priority << " |";
  Node *temp = head->next;
  while (temp != NULL)
  {
    cout << " ==> | " << temp->process << "|" << temp->priority << " |";
    temp = temp->next;
  }
  cout << endl;
}

void Execute()
{
  if (head == NULL)
  {
    Display();
    return;
  }
  Node *temp = head;
  head = head->next;
  delete temp;
  pending--;
  Display();
}

void Menu()
{
  // system("clear");
  cout << "This program is submitted by MD Rashid Hussain, 20BCS033" << endl;
  cout << "===============MENU===============" << endl;
  cout << "Enter 0 to show this menu again" << endl;
  cout << "Enter 1 to insert a process" << endl;
  cout << "Enter 2 to execute the process" << endl;
  cout << "Enter 3 to display total number of pending processes" << endl;
  cout << "Enter 4 to display the processes" << endl;
  cout << "Enter 5 to exit" << endl;
}