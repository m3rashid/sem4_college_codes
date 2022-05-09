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
}

void FirstFit() {
  for (int i = 0; i < processCount; i++) {
    for (int j = 0; j < blocksCount; j++) {
      if (!memoryBlocks[j].isFree) {
        continue;
      } else if (memoryBlocks[j].size >= process[i].size) {
        memoryBlocks[j].isFree = false;
        process[i].assigned = true;
        process[i].blockID = j;
        memoryBlocks[j].processID = process[i].ID;
        memoryBlocks[j].internalFragmentation = memoryBlocks[j].size - process[i].size;
        break;
      }
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
  FirstFit();

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
