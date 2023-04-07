#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Jumlah maksimal antrian
int queue[MAX_SIZE]; // Array untuk menyimpan antrian
int front = -1; // Inisialisasi indeks awal antrian
int rear = -1; // Inisialisasi indeks akhir antrian

// Fungsi untuk mengecek apakah antrian penuh
bool isFull() {
    if (rear == MAX_SIZE - 1) {
        return true;
    }
    return false;
}

// Fungsi untuk mengecek apakah antrian kosong
bool isEmpty() {
    if (front == -1 || front > rear) {
        return true;
    }
    return false;
}

// Prosedur untuk menambahkan pelanggan ke antrian
void enqueue(int customer) {
    if (isFull()) {
        cout << "Antrian penuh. Tidak bisa menambah pelanggan." << endl;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = customer;
        cout << "Pelanggan " << customer << " telah ditambahkan ke antrian." << endl;
    }
}

// Prosedur untuk menghapus pelanggan dari antrian
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong. Tidak ada pelanggan yang bisa dihapus." << endl;
    } else {
        cout << "Pelanggan " << queue[front] << " telah dihapus dari antrian." << endl;
        front++;
    }
}

// Prosedur untuk menampilkan seluruh antrian
void display() {
    if (isEmpty()) {
        cout << "Antrian kosong." << endl;
    } else {
        cout << "Isi antrian:" << endl;
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << endl;
        }
    }
}

int main() {
    int choice, customer;

    do {
        cout << "=== Antrian Bank ===" << endl;
        cout << "1. Tambah pelanggan ke antrian" << endl;
        cout << "2. Hapus pelanggan dari antrian" << endl;
        cout << "3. Tampilkan seluruh antrian" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nomor pelanggan: ";
                cin >> customer;
                enqueue(customer);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan layanan kami." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
