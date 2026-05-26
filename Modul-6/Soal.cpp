#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

using namespace std;

int random(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

void sequentialSearching()
{
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++)
    {
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");

    for (int i = 0; i < 100; i++)
    {
        if (data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1)
    {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d", save);
    }
    else
    {
        printf("Data tidak ada!\n");
    }
}

void binarySearching()
{
    clrscr();
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data? ";
    cin >> n;
    int angka[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "------------------------------------------------------------------------\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    }
    cout << "\n------------------------------------------------------------------------\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if (key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }
    if (ketemu == true)
    {
        cout << "Angka ditemukan! ";
    }
    else
    {
        cout << "Angka tidak ditemukan!";
    }
    return;
}

int main()
{
    int pilih;
    do
    {
        clrscr();
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching?" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            sequentialSearching();
            break;
        case 2:
            binarySearching();
            break;
        case 3:
            clrscr();
            cout << "Perbedaan Sequential Searching dan Binary Searching:" << endl;
            cout << endl;
            cout << "Sequential Searching:" << endl;
            cout << "- Mencari data dengan menelusuri satu per satu dari awal hingga akhir" << endl;
            cout << "- Kelebihan: Dapat digunakan pada data yang tidak terurut" << endl;
            cout << "- Kekurangan: Lambat untuk data yang besar (O(n))" << endl;
            cout << endl;
            cout << "Binary Searching:" << endl;
            cout << "- Mencari data dengan membagi array menjadi dua bagian" << endl;
            cout << "- Kelebihan: Lebih cepat dari sequential searching (O(log n))" << endl;
            cout << "- Kekurangan: Data harus dalam keadaan terurut terlebih dahulu" << endl;
            break;
        case 4:
            cout << "Keluar dari program..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
        if (pilih != 4)
        {
            cout << endl;
            system("pause");
        }
    } while (pilih != 4);

    return 0;
}