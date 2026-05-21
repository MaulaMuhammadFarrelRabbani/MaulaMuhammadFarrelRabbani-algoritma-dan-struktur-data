#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;
typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};
TNode *head, *tail;
int pil, menu;
char pilihan[2];
string dataBaru;
void initH();
void initHT();
int isEmpty();
int isEmptyHT();
void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();
void hapusTargetH();
void hapusTargetHT();
int main()
{
    menu:
    cout<<"Double Linked List Non Circular (DLLNC)"<<endl;
    cout<<"======================================="<<endl;
    cout<<"Silahkan pilih program DLLNC yang ingin dijalankan!"<<endl;
    cout<<"1. DLLNC dengan Head"<<endl;
    cout<<"2. DLLNC dengan Head dan Tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : ";
    cin>>menu;
    system("cls");
    if(menu==1){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head)"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Berdasarkan Target"<<endl;
            cout<<"7. Reset"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);
            switch(pil) {
                case 1:
                    tambahDepanH();
                    break;
                case 2:
                    tambahBelakangH();
                    break;
                case 3:
                    tampilkanH();
                    break;
                case 4:
                    hapusDepanH();
                    break;
                case 5:
                    hapusBelakangH();
                    break;
                case 6:
                    hapusTargetH();
                    break;
                case 7:
                    clearH();
                    break;
                case 8:
                    system("cls");
                    goto menu;
                default:
                    cout<<"\nPilihan tidak valid!"<<endl;
            }
            if(pil != 8) {
                cout<<"\npress any key to continue"<<endl;
                getch();
                system("cls");
            }
        } while (pil<8);
    } else if(menu==2) {
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head dan Tail)"<<endl;
            cout<<"======================================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang"<<endl;
            cout<<"6. Hapus Berdasarkan Target"<<endl;
            cout<<"7. Reset"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);
            switch(pil) {
                case 1:
                    tambahDepanHT();
                    break;
                case 2:
                    tambahBelakangHT();
                    break;
                case 3:
                    tampilkanHT();
                    break;
                case 4:
                    hapusDepanHT();
                    break;
                case 5:
                    hapusBelakangHT();
                    break;
                case 6:
                    hapusTargetHT();
                    break;
                case 7:
                    clearHT();
                    break;
                case 8:
                    system("cls");
                    goto menu;
                default:
                    cout<<"\nPilihan tidak valid!"<<endl;
            }
            if(pil != 8) {
                cout<<"\npress any key to continue"<<endl;
                getch();
                system("cls");
            }
        } while (pil<8);
    } else {
        cout<<"\nTERIMA KASIH"<<endl;
        cout<<"Program was made by Maula Muhammad Farrel Rabbani (2510817310008)."<<endl;
    }
    return 0;
}
void initH(){
    head = NULL;
}
void initHT(){
    head = NULL;
    tail = NULL;
}
int isEmpty(){
    if(head == NULL) return 1;
    else return 0;
}
int isEmptyHT(){
    if(tail==NULL) return 1;
    else return 0;
}
void tambahDepanH() {
    cout<<"Masukkan data (dipisahkan spasi): ";
    string inputLine;
    cin >> ws;
    getline(cin, inputLine);
    stringstream ss(inputLine);
    string arr[100];
    int count = 0;
    while(ss >> arr[count]) count++;
    for(int i = count - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmpty() == 1) {
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout << "Data berhasil dimasukkan di bagian depan.";
}
void tambahDepanHT() {
    cout<<"Masukkan data (dipisahkan spasi): ";
    string inputLine;
    cin >> ws;
    getline(cin, inputLine);
    stringstream ss(inputLine);
    string arr[100];
    int count = 0;
    while(ss >> arr[count]) count++;
    for(int i = count - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyHT()==1) {
            head = baru;
            tail = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
    }
    cout << "Data berhasil dimasukkan di bagian depan.";
}
void tambahBelakangH() {
    cout<<"Masukkan data (dipisahkan spasi): ";
    string inputLine;
    cin >> ws;
    getline(cin, inputLine);
    stringstream ss(inputLine);
    string arr[100];
    int count = 0;
    while(ss >> arr[count]) count++;
    for(int i = 0; i < count; i++) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmpty() == 1) {
            head = baru;
        } else {
            TNode *bantu = head;
            while(bantu->next != NULL){
                bantu = bantu->next;
            }
            bantu->next = baru;
            baru->prev = bantu;
        }
    }
    cout << "Data berhasil dimasukkan di bagian belakang.";
}
void tambahBelakangHT() {
    cout<<"Masukkan data (dipisahkan spasi): ";
    string inputLine;
    cin >> ws;
    getline(cin, inputLine);
    stringstream ss(inputLine);
    string arr[100];
    int count = 0;
    while(ss >> arr[count]) count++;
    for(int i = 0; i < count; i++) {
        TNode *baru = new TNode;
        baru->data = arr[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyHT()==1) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }
    cout << "Data berhasil dimasukkan di bagian belakang.";
}
void tampilkanH() {
    TNode *bantu;
    bantu = head;
    if(isEmpty() == 0) {
        while(bantu != NULL) {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}
void tampilkanHT() {
    TNode *bantu;
    bantu = head;
    if(isEmptyHT() == 0) {
        while(bantu != tail->next) {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}
void hapusDepanH() {
    if(isEmpty() == 0) {
        TNode *hapus;
        string data;
        hapus = head;
        data = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}
void hapusDepanHT() {
    TNode *hapus;
    string data;
    if(isEmptyHT() == 0) {
        hapus = head;
        data = hapus->data;
        if(head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}
void hapusBelakangH() {
    if(isEmpty() == 0) {
        int n;
        cout << "Masukkan node ke-N dari belakang: ";
        cin >> n;
        TNode *bantu = head;
        while(bantu->next != NULL) bantu = bantu->next;
        TNode *hapus = bantu;
        for(int i = 1; i < n; i++) {
            if(hapus->prev != NULL) hapus = hapus->prev;
            else break;
        }
        string data = hapus->data;
        if(hapus == head) {
            head = head->next;
            if(head != NULL) head->prev = NULL;
        } else {
            hapus->prev->next = hapus->next;
            if(hapus->next != NULL) hapus->next->prev = hapus->prev;
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di belakang telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}
void hapusBelakangHT() {
    if(isEmptyHT() == 0) {
        int n;
        cout << "Masukkan node ke-N dari belakang: ";
        cin >> n;
        TNode *hapus = tail;
        for(int i = 1; i < n; i++) {
            if(hapus->prev != NULL) hapus = hapus->prev;
            else break;
        }
        string data = hapus->data;
        if(hapus == head && hapus == tail) initHT();
        else if(hapus == head) {
            head = head->next;
            if(head != NULL) head->prev = NULL;
        } else if(hapus == tail) {
            tail = tail->prev;
            if(tail != NULL) tail->next = NULL;
        } else {
            hapus->prev->next = hapus->next;
            hapus->next->prev = hapus->prev;
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di belakang telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}
void clearH() {
    if(isEmpty() == 0) {
        int i = 1;
        while(head != NULL) {
            TNode *hapusDepan = head;
            cout << "Hapus ke-" << i++ << " data: " << hapusDepan->data << endl;
            if(head->next != NULL) {
                head = head->next;
                head->prev = NULL;
                delete hapusDepan;
                
                TNode *hapusBelakang = head;
                while(hapusBelakang->next != NULL) hapusBelakang = hapusBelakang->next;
                cout << "Hapus ke-" << i++ << " data: " << hapusBelakang->data << endl;
                if(hapusBelakang == head) head = NULL;
                else hapusBelakang->prev->next = NULL;
                delete hapusBelakang;
            } else {
                head = NULL;
                delete hapusDepan;
            }
        }
        initH();
    } else cout<<"Tidak terdapat data pada Linked List";
}
void clearHT() {
    if(isEmptyHT() == 0) {
        int i = 1;
        while(head != NULL && tail != NULL) {
            TNode *hapusDepan = head;
            cout << "Hapus ke-" << i++ << " data: " << hapusDepan->data << endl;
            if(head == tail) {
                delete hapusDepan;
                initHT();
                break;
            } else {
                head = head->next;
                head->prev = NULL;
                delete hapusDepan;
            }
            TNode *hapusBelakang = tail;
            cout << "Hapus ke-" << i++ << " data: " << hapusBelakang->data << endl;
            if(head == tail) {
                delete hapusBelakang;
                initHT();
                break;
            } else {
                tail = tail->prev;
                if(tail != NULL) tail->next = NULL;
                delete hapusBelakang;
            }
        }
    } else cout<<"Tidak terdapat data pada Linked List";
}
void hapusTargetH() {
    if(isEmpty() == 0) {
        string target;
        cout << "Masukkan target yang ingin dihapus: ";
        cin >> target;
        TNode *bantu = head;
        bool ditemukan = false;
        while(bantu != NULL) {
            if(bantu->data == target) {
                ditemukan = true;
                TNode *hapus = bantu;
                if(bantu == head) {
                    head = head->next;
                    if(head != NULL) head->prev = NULL;
                    bantu = head; 
                } else {
                    bantu->prev->next = bantu->next;
                    if(bantu->next != NULL) bantu->next->prev = bantu->prev;
                    bantu = bantu->next; 
                }
                delete hapus;
            } else bantu = bantu->next;
        }
        if(!ditemukan) cout << "Data tidak ditemukan." << endl;
        else cout << "Semua node dengan data \"" << target << "\" telah dihapus." << endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}
void hapusTargetHT() {
    if(isEmptyHT() == 0) {
        string target;
        cout << "Masukkan target yang ingin dihapus: ";
        cin >> target;
        TNode *bantu = head;
        bool ditemukan = false;
        while(bantu != NULL) {
            if(bantu->data == target) {
                ditemukan = true;
                TNode *hapus = bantu;
                if(bantu == head && bantu == tail) {
                    initHT();
                    bantu = NULL;
                } else if(bantu == head) {
                    head = head->next;
                    if(head != NULL) head->prev = NULL;
                    bantu = head;
                } else if(bantu == tail) {
                    tail = tail->prev;
                    if(tail != NULL) tail->next = NULL;
                    bantu = NULL;
                } else {
                    bantu->prev->next = bantu->next;
                    bantu->next->prev = bantu->prev;
                    bantu = bantu->next;
                }
                delete hapus;
            } else bantu = bantu->next;
        }
        if(!ditemukan) cout << "Data tidak ditemukan." << endl;
        else cout << "Semua node dengan data \"" << target << "\" telah dihapus." << endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}