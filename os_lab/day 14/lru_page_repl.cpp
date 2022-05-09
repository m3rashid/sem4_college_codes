#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<string> result;
vector<int> leastFrame;

vector<int> split(const string &refString, char delimiter) {
    vector<int> pageNumbers;
    int currentNum = 0;
    for (char i : refString) {
        if (i == delimiter) {
            pageNumbers.push_back(currentNum);
            currentNum = 0;
        } else {
            currentNum = currentNum * 10 + (i - '0');
        }
    }
    pageNumbers.push_back(currentNum);
    return pageNumbers;
}

void removeFromLeastFrame(int value) {
    int index = find(leastFrame.begin(), leastFrame.end(), value) - leastFrame.begin();
    leastFrame.erase(leastFrame.begin() + index);
}

int leastUsedPage(int pageSize) {
    if (leastFrame.size() < pageSize) {
        return -1;
    }
    int min = leastFrame[0];
    leastFrame.erase(leastFrame.begin());
    return min;
}

void lru_page_repl(vector<vector<int>> &blocks, const vector<int> &pageNumbers, int pageSize) {
    string pageType;
    for (int i = 0; i < pageNumbers.size(); i++) {
        pageType = "---";
        if (i != 0) {
            for (int j = 0; j < blocks.size(); j++) {
                blocks[j][i] = blocks[j][i - 1];
            }
        }
        for (int j = 0; j < blocks.size(); j++) {
            if (blocks[j][i] == pageNumbers[i]) {
                pageType = "HIT";
                removeFromLeastFrame(pageNumbers[i]);
                break;
            }
        }
        if (pageType == "---") {
            int LUP = leastUsedPage(pageSize);
            int index;
            if (LUP != -1) {
                for (index = 0; index < blocks.size(); index++) {
                    if (blocks[index][i] == LUP) {
                        blocks[index][i] = pageNumbers[i];
                        break;
                    }
                }
            } else {
                blocks[leastFrame.size()][i] = pageNumbers[i];
            }
        }
        leastFrame.push_back(pageNumbers[i]);
        result.push_back(pageType);
    }
}

int pageFault() {
    int pageFaults = 0;
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == "---") {
            pageFaults++;
        }
    }
    return pageFaults;
}

void display(const string &refString, const vector<int> &pageNumber, vector<vector<int>> &blocks, int pageSize) {
    cout << "\nReference String: " << refString << endl
         << "Page Frames: " << pageSize << endl
         << endl
         << " ";
    for (int page : pageNumber) {
        cout << " " << page << "  ";
    }
    cout << endl;
    for (int i = pageSize - 1; i >= 0; i--) {
        cout << "|";
        for (int j = 0; j < blocks[0].size(); j++) {
            if (blocks[i][j] != INT32_MAX) {
                printf(" %d |", blocks[i][j]);
            } else {
                printf(" - |");
            }
        }
        cout << endl;
    }
    for (int i = 0; i < blocks[0].size(); i++) {
        printf(" %3s", result[i].c_str());
    }
    cout << endl;
    int pageFaults = pageFault();
    cout << "\nTotal Page Faults: " << pageFaults << endl;
    cout << "Average Page Fault: " << (float)pageFaults / result.size() << endl;
}

int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;
    string refString;
    int pageFrames;
    cout << "Enter reference string comma separated: ";
    cin >> refString;
    cout << "Enter number of page frames: ";
    cin >> pageFrames;

    vector<int> pageNumbers = split(refString, ',');
    vector<vector<int>> blocks(pageFrames, vector<int>(pageNumbers.size(), INT32_MAX));
    lru_page_repl(blocks, pageNumbers, pageFrames);
    display(refString, pageNumbers, blocks, pageFrames);
    return 0;
}
