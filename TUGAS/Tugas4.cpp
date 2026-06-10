#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru)
{
    if (*root == NULL)
    {
        Node *baru;
        baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        (*root) = baru;
        (*root)->kiri = NULL;
        (*root)->kanan = NULL;
    }
    else if (databaru < (*root)->data)
        tambah(&(*root)->kiri, databaru);
    else if (databaru > (*root)->data)
        tambah(&(*root)->kanan, databaru);
}

int tinggi(Node *root)
{
    if (root == NULL)
        return 0;

    int kiriTinggi = tinggi(root->kiri);
    int kananTinggi = tinggi(root->kanan);

    if (kiriTinggi > kananTinggi)
        return kiriTinggi + 1;
    else
        return kananTinggi + 1;
}

int diameter(Node *root, int *hasil)
{
    if (root == NULL)
        return 0;

    int kiriTinggi = diameter(root->kiri, hasil);
    int kananTinggi = diameter(root->kanan, hasil);

    int jarakSekarang = kiriTinggi + kananTinggi;

    if (jarakSekarang > *hasil)
        *hasil = jarakSekarang;

    if (kiriTinggi > kananTinggi)
        return kiriTinggi + 1;
    else
        return kananTinggi + 1;
}

int main()
{
    int n, data;
    Node *pohon;
    pohon = NULL;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> data;
        tambah(&pohon, data);
    }

    int hasil = 0;
    diameter(pohon, &hasil);

    cout << hasil << endl;

    return 0;
}