#include <iostream>
using namespace std;

struct Contact{
    string nama,nomor;
    Contact *next;
};

Contact *awal=NULL,*akhir=NULL,*bantu,*baru;

void addLast(string nama, string nomor){
    baru = new Contact;
    baru->next = NULL;
    baru->nama = nama;
    baru->nomor = nomor;
    if(awal == NULL){
        awal = akhir = baru;
    }else{
        akhir->next = baru;
        akhir = baru;
    }
}

int findPos(string nama){
    bantu=awal;
    int i = 0;
    int index = -1;
    while(bantu != NULL){
        if(bantu->nama == nama){
            index = i;
        }
        i++;
        bantu = bantu->next;
    }
    return index;
}

void searchByName(string nama){
    bantu=awal;
    int i = 0;
    int index = -1;
    string res[2];
    while(bantu != NULL){
        if(bantu->nama == nama){
            index = i;
            res[0] = bantu->nama;
            res[1] = bantu->nomor;
        }
        i++;
        bantu = bantu->next;
    }
    if(index == -1){
        cout << "Nama tidak ditemukan!" << endl;
    }else{
        cout << "-------------------------------" << endl;
        cout << "Nama: " << res[0] << endl;
        cout << "Nomor: " << res[1] << endl;
        cout << "-------------------------------" << endl;
    }
}

void deleteContact(Contact** awal_ref, int pos)
{
    if (*awal_ref == NULL){
        return;
    }
    Contact* temp = *awal_ref;
    if (pos == 0) {
        *awal_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < pos - 1; i++){
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL){
        return;
    }
    Contact* next = temp->next->next;
    free(temp->next); 
    temp->next = next;
}

void printData(){
    bantu=awal;
    cout << "-------------------------------" << endl;
    while(bantu != NULL){
        cout << "Nama: " << bantu->nama << "\n"; 
        cout << "Nomor: " << bantu->nomor << "\n-------------------------------" << endl; 
        bantu = bantu->next;
    }
}

int main(){
    char menu;
    do {
        cout << "Pilih menu dibawah: " << endl;
        cout << " a. Tambah Kontak Baru \n b. Tampilkan Semua Kontak \n c. Search Kontak \n d. Hapus Kontak " << endl;
        cout << "Pilih: ";
        cin >> menu;
        if(menu == 'a' || menu == 'A'){
            string new_nama,new_nomor;
            cout << "Masukan nama: ";
            cin >> new_nama;
            cout << "Masukan nomor: ";
            cin >> new_nomor;
            addLast(new_nama,new_nomor);
            menu = false;
        }else if(menu == 'b' || menu == 'B'){
            printData();
            menu = false;
        }else if(menu == 'c' || menu == 'C'){
            string find_nama;
            cout << "Masukan nama: ";
            cin >> find_nama;
            searchByName(find_nama);
            menu = false;
        }else if(menu == 'd' || menu == 'D'){
            string find_nama;
            cout << "Masukan nama: ";
            cin >> find_nama;
            if(findPos(find_nama) == -1){
                cout << "Nama tidak ditemukan!" << endl;
            }else{
                deleteContact(&awal,findPos(find_nama));
            }
            menu = false;
        }else{
            cout << "Menu tidak ditemukan!" << endl;
        }
    }while(true);
  return 0;
}
