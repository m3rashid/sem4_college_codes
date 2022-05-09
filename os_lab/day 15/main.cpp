#include <iostream>
#include <vector>
using namespace std;

void display(const int *tracks, int size, int head, int totalMovement);

void FCFS(int tracks[], int size, int head) {
    int totalMovement = 0;
    int distance, currentTrack;
    int tempHead = head;
    for (int i = 0; i < size; i++) {
        currentTrack = tracks[i];
        distance = abs(currentTrack - tempHead);
        totalMovement += distance;
        tempHead = currentTrack;
    }
    display(tracks, size, head, totalMovement);
}
int smallest(vector<int> &tracks, int size, int head) {
    int smallest = tracks[0];
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (abs(head - tracks[i]) < smallest) {
            smallest = abs(head - tracks[i]);
            index = i;
        }
    }
    smallest = tracks[index];
    tracks.erase(tracks.begin() + index);
    tracks.push_back(smallest);
    return smallest;
}

void SSTF(int tracks[], int size, int head) {
    int totalMovement = 0;
    int distance, currentTrack;
    vector<int> Tracks(tracks, tracks + size);
    int tempHead = head;
    for (int i = size; i > 0; i--) {
        tempHead = smallest(Tracks, i, tempHead);
    }
    tempHead = head;
    for (int Track : Tracks) {
        currentTrack = Track;
        // distance is always positive
        distance = abs(currentTrack - tempHead);
        totalMovement += distance;
        tempHead = currentTrack;
    }
    for (int i = 0; i < size; i++) {
        tracks[i] = Tracks[i];
    }
    display(tracks, size, head, totalMovement);
}
// function for displaying the results
void display(const int *tracks, int size, int head, int totalMovement) {
    cout << "Seek Sequence is:-" << endl;
    printf("|%3d| ---> |%3d|\n", head, tracks[0]);
    for (int i = 0; i < size - 1; i++) {
        printf("|%3d| ---> |%3d|\n", tracks[i], tracks[i + 1]);
    }
    cout << "\nTotal number of seek operations = "
         << totalMovement << endl;
    cout << "Average Head Movement = " << totalMovement * 1.0 / size
         << endl;
}
int main() {
    cout << "20BCS033 MD Rashid Hussain" << endl;
    int n;
    cout << "Enter Number of Tracks: ";
    cin >> n;
    int tracks[n];
    cout << "Request Sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> tracks[i];
    }
    int head;
    cout << "Initial Head Position: ";
    cin >> head;
    cout << "\n**** FCFS Disk Scheduling Algorithm ****\n"
         << endl;
    FCFS(tracks, n, head);
    cout << "\n**** SSTF Disk Scheduling Algorithm ****\n"
         << endl;
    SSTF(tracks, n, head);
}