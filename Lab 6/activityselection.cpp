#include <iostream>
using namespace std;

struct Activity {
    int start;
    int finish;
};

void sortActivities(Activity arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].finish > arr[j + 1].finish) {
                Activity temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void activitySelection(Activity arr[], int n) {
    sortActivities(arr, n);

    cout << "Selected activities are:\n";

    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")" << endl;

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")" << endl;
            i = j;
        }
    }
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    Activity arr[n];

    cout << "Enter start and finish time of each activity:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }

    activitySelection(arr, n);

    return 0;
}