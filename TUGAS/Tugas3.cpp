#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

bool binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {
    int n, x;
    cin >> n >> x;

    srand(time(0));
    int arr[100];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 25 + 1; 
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, n);

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int complement = x - arr[i];
        if (complement < arr[i]) break;   
        if (complement == arr[i]) {       
            if (i + 1 < n && arr[i + 1] == arr[i]) count++;
            break;
        }
        if (binarySearch(arr, i + 1, n - 1, complement))
            count++;
    }

    cout << count << endl;
    return 0;
}