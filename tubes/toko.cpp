#include "toko.h"

Node::Node(int h, string nama, string m, int stok) {
    harga = h;
    namaBarang = nama;
    merk = m;
    sisaStok = stok;
    jumlahWarna = 0;
    left = NULL;
    right = NULL;
}

TokoAlatTulis::TokoAlatTulis() {
    root = NULL;
}

Node* TokoAlatTulis::insert(Node* node, int harga, string nama, string merk, int stok) {
    if (node == NULL) {
        return new Node(harga, nama, merk, stok);
    }
    
    if (harga < node->harga) {
        node->left = insert(node->left, harga, nama, merk, stok);
    } else if (harga > node->harga) {
        node->right = insert(node->right, harga, nama, merk, stok);
    }
    
    return node;
}

void TokoAlatTulis::inorder(Node* node) {
    if (node != NULL) {
        inorder(node->left);
        cout << "\n=========================\n";
        cout << "Harga: Rp " << node->harga << endl;
        cout << "Nama: " << node->namaBarang << endl;
        cout << "Merk: " << node->merk << endl;
        cout << "Stok: " << node->sisaStok << endl;
        cout << "Warna: ";
        for (int i = 0; i < node->jumlahWarna; i++) {
            cout << node->warna[i];
            if (i < node->jumlahWarna - 1) cout << ", ";
        }
        cout << endl;
        inorder(node->right);
    }
}

Node* TokoAlatTulis::search(Node* node, int harga) {
    if (node == NULL || node->harga == harga) {
        return node;
    }
    
    if (harga < node->harga) {
        return search(node->left, harga);
    }
    
    return search(node->right, harga);
}

void TokoAlatTulis::tambahBarang(int harga, string nama, string merk, int stok) {
    root = insert(root, harga, nama, merk, stok);
    cout << "Barang berhasil ditambahkan!\n";
}

/*void TokoAlatTulis::tambahWarna(int harga, string warna) {
    Node* barang = search(root, harga);
    if (barang != NULL && barang->jumlahWarna < 10) {
        barang->warna[barang->jumlahWarna] = warna;
        barang->jumlahWarna++;
        cout << "Warna berhasil ditambahkan!\n";
    } else {
        cout << "Barang tidak ditemukan atau warna sudah penuh!\n";
    }
}*/


void TokoAlatTulis::tampilkanSemua() {
    cout << "\n===== DAFTAR BARANG =====";
    inorder(root);
    cout << "\n=========================\n";
}

void TokoAlatTulis::cariBarang(int harga) {
    Node* hasil = search(root, harga);
    if (hasil != NULL) {
        cout << "\nBarang ditemukan!\n";
        cout << "Harga: Rp " << hasil->harga << endl;
        cout << "Nama: " << hasil->namaBarang << endl;
        cout << "Merk: " << hasil->merk << endl;
        cout << "Stok: " << hasil->sisaStok << endl;
        cout << "Warna: ";
        for (int i = 0; i < hasil->jumlahWarna; i++) {
            cout << hasil->warna[i];
            if (i < hasil->jumlahWarna - 1) cout << ", ";
        }
        cout << endl;
    } else {
        cout << "\nBarang tidak ditemukan!\n";
    }
}

// DATA DUMMY WOY
void TokoAlatTulis::isiDataDummy() {
    
    root = insert(root, 5000, "Pulpen Gel", "Pilot", 150);
    tambahWarna(5000, "Hitam");
    tambahWarna(5000, "Biru");
    tambahWarna(5000, "Merah"); 

    root = insert(root, 2500, "Pensil 2B", "Faber Castell", 200);
    tambahWarna(2500, "Hitam");
    
    root = insert(root, 8000, "Spidol Whiteboard", "Snowman", 80);
    tambahWarna(8000, "Hitam");
    tambahWarna(8000, "Biru");
    tambahWarna(8000, "Merah");
    tambahWarna(8000, "Hijau");

    root = insert(root, 1500, "Penghapus", "Steadtler", 300);
    tambahWarna(1500, "Putih");
    tambahWarna(1500, "Biru");

    root = insert(root, 12000, "Buku Tulis", "Sinar Dunia", 120);
    tambahWarna(12000, "Merah");
    tambahWarna(12000, "Biru");
    tambahWarna(12000, "Hijau");
    tambahWarna(12000, "Kuning");

    root = insert(root, 3500, "Penggaris 30cm", "Butterfly", 100);
    tambahWarna(3500, "Transparan");
    tambahWarna(3500, "Biru");

    root = insert(root, 15000, "Kertas HVS A4", "Paperline", 50);
    tambahWarna(15000, "Putih");

    root = insert(root, 7000, "Lem Cair", "UHU", 60);
    tambahWarna(7000, "Putih");

    root = insert(root, 4000, "Correction Tape", "Kenko", 90);
    tambahWarna(4000, "Putih");
    tambahWarna(4000, "Biru");

    root = insert(root, 10000, "Stabilo Highlighter", "Stabilo Boss", 75);
    tambahWarna(10000, "Kuning");
    tambahWarna(10000, "Hijau");
    tambahWarna(10000, "Pink");
    tambahWarna(10000, "Orange");
    
    cout << "Data dummy ditambahkan\n";
    cout << "================================\n";
}