#include <iostream>
using namespace std;

struct Block {
  int ID;
  int size;
  int processID;
  int internalFragmentation;
  bool isFree = true;
};

struct Process {
  int ID;
  int size;
  int blockID;
  bool assigned = false;
};

int blocksCount = 0;
Block memoryBlocks[10];
int processCount = 0;
Process process[] = {};

void takeInputs() {
  cout << "\nEnter the number of memory blocks: ";
  cin >> blocksCount;
  cout << "\nEnter the size of each block: ";
  for (int i = 0; i < blocksCount; i++) {
    cin >> memoryBlocks[i].size;
    memoryBlocks[i].ID = i;
  }

  cout << "Enter the number of processes: ";
  cin >> processCount;
  cout << "\nEnter the size of each process: ";
  for (int i = 0; i < processCount; i++) {
    cin >> process[i].size;
    process[i].ID = i;
  }
  cout << "\n";
}

void WorstFit() {
  for(int i=0; i< processCount; i++){
    int lastMatch = -1;
    for(int j=0; j< blocksCount; j++){
      if(!memoryBlocks[j].isFree){
        continue;
      } else if(memoryBlocks[j].size >= process[i].size){
        if(lastMatch == -1){
          lastMatch = j;
        } else {
          if(memoryBlocks[j].size > memoryBlocks[lastMatch].size){
            lastMatch = j;
          }
        }
      }
    }
    if(lastMatch != -1){
      memoryBlocks[lastMatch].isFree = false;
      process[i].assigned = true;
      process[i].blockID = lastMatch;
      memoryBlocks[lastMatch].processID = process[i].ID;
      memoryBlocks[lastMatch].internalFragmentation = memoryBlocks[lastMatch].size - process[i].size;
    }
  }
}

int ExternalFragmentation() {
  int externalFragmentation = 0;
  for (int i = 0; i < blocksCount; i++) {
    if (memoryBlocks[i].isFree) {
      externalFragmentation += memoryBlocks[i].size;
    }
  }
  return externalFragmentation;
}

int InternalFragmentation() {
  int internalFragmentation = 0;
  for (int i = 0; i < blocksCount; i++) {
    if (!memoryBlocks[i].isFree) {
      internalFragmentation += memoryBlocks[i].internalFragmentation;
    }
  }
  return internalFragmentation;
}

int main() {
  cout << "\nThis program is submitted by 20BCS033, MD Rashid Hussain";
  takeInputs();
  WorstFit();

  cout << "Block ID\tBlock Size\tProcess ID\tProcess Size\tI.F.\n";

  for (int i = 0; i < blocksCount; i++) {
    cout << "   " << memoryBlocks[i].ID + 1 << "\t\t   ";
    cout << memoryBlocks[i].size << "\t\t";
    if (!memoryBlocks[i].isFree) {
      cout << "   (P" << memoryBlocks[i].processID + 1 << ")\t\t";
      cout << "   " << process[memoryBlocks[i].processID].size << "\t\t ";
    } else {
      cout << "   (NA)\t\t";
      cout << "      \t\t ";
    }
    cout << memoryBlocks[i].internalFragmentation;
    cout << "\n";
  }

  cout << "\nTotal Internal Fragmentation: " << InternalFragmentation();
  cout << "\nTotal External Fragmentation: " << ExternalFragmentation();
  cout << endl
       << endl;

  return 0;
}
