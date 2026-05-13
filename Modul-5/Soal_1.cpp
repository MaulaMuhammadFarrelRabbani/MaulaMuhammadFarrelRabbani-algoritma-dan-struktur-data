#include <iostream>
#include <string>

using namespace std;

void tukar(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

void insertionSort(string data) {
    int n = data.length();
    for (int i = 1; i < n; i++) {
        char temp = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > temp) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
    cout << "Hasil Insertion Sort : " << data << "\n\n";
}

void merge(string &data, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    string L = data.substr(l, n1);
    string R = data.substr(m + 1, n2);
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { data[k] = L[i]; i++; k++; }
    while (j < n2) { data[k] = R[j]; j++; k++; }
}

void mergeSortHelper(string &data, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(data, l, m);
        mergeSortHelper(data, m + 1, r);
        merge(data, l, m, r);
    }
}

void mergeSort(string data) {
    mergeSortHelper(data, 0, data.length() - 1);
    cout << "Hasil Merge Sort     : " << data << "\n\n";
}

void shellSort(string data) {
    int n = data.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
    }
    cout << "Hasil Shell Sort     : " << data << "\n\n";
}

int partition(string &data, int low, int high) {
    char pivot = data[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (data[j] < pivot) {
            i++;
            tukar(data[i], data[j]);
        }
    }
    tukar(data[i + 1], data[high]);
    return (i + 1);
}

void quickSortHelper(string &data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quickSortHelper(data, low, pi - 1);
        quickSortHelper(data, pi + 1, high);
    }
}

void quickSort(string data) {
    quickSortHelper(data, 0, data.length() - 1);
    cout << "Hasil Quick Sort     : " << data << "\n\n";
}

void bubbleSort(string data) {
    int n = data.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                tukar(data[j], data[j + 1]);
            }
        }
    }
    cout << "Hasil Bubble Sort    : " << data << "\n\n";
}

void selectionSort(string data) {
    int n = data.length();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        tukar(data[min_idx], data[i]);
    }
    cout << "Hasil Selection Sort : " << data << "\n\n";
}

int main() {
    string nama, nim;
    int pilihan;

    do {
        cout << "===============================\n";
        cout << "            SORTING            \n";
        cout << "===============================\n";
        cout << "1. Insertion Sort (Nama)\n";
        cout << "2. Merge Sort (Nama)\n";
        cout << "3. Shell Sort (Nama)\n";
        cout << "4. Quick Sort (NIM)\n";
        cout << "5. Bubble Sort (NIM)\n";
        cout << "6. Selection Sort (NIM)\n";
        cout << "7. Exit\n";
        cout << "===============================\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();            
            cin.ignore(10000, '\n');
            cout << "\nInput tidak valid. Harap masukkan angka!\n\n";
            continue;               
        }

        cin.ignore(10000, '\n');
        cout << "\n";

        if (pilihan >= 1 && pilihan <= 3) {
            cout << "Masukkan Nama Anda : ";
            getline(cin, nama);
            cout << "\n";
        } else if (pilihan >= 4 && pilihan <= 6) {
            cout << "Masukkan NIM Anda  : ";
            cin >> nim;
            cin.ignore();
            cout << "\n";
        }

        switch (pilihan) {
            case 1: insertionSort(nama); break;
            case 2: mergeSort(nama);     break;
            case 3: shellSort(nama);     break;
            case 4: quickSort(nim);      break;
            case 5: bubbleSort(nim);     break;
            case 6: selectionSort(nim);  break;
            case 7:
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi!\n\n";
        }
    } while (pilihan != 7);

    return 0;
}