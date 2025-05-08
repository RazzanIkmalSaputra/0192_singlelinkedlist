#include <iostream>
#include<string.h>
using namespace std;

class node
{
 public:
    int noMhs;
    node *next;
};

class list
{
    node *START;
 
 public:
    list()
    {
        START = NULL;
    }  

    void addnode()
    {
        int nim;
        cout << "\n masukan nomor mahasiswa: ";
        cin >> nim;

        node *nodebaru = new node;
        nodebaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }

            nodebaru->next = START;
            START = nodebaru;
            return;
        }

        node *previous = START;
        node *current = START;

        while ((current !=NULL) && (nim >=current->noMhs))
        {
            if (nim ==current->noMhs)
            {
                cout <<"\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodebaru->next = current;
        previous->next = nodebaru;
    }

    bool listempty()
    {
        return (START == NULL);
    }
    
    bool sreach(int nim, node **previous, node **current)
    {
        *previous = START;
        *current = START;

        while ((*current !=NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }
        return(*current != NULL);
    }
    bool delnode(int nim)
    {
        node *current, *previous;
        if (!sreach(nim, &previous, &current))
            return false;

        if (current = START)
           START = START->next;
        else 
            previous->next = current->next;
        delete current;
        return true;
    }

    void traverse()
    {
        if (listempty())
        {
            cout << "\nlist kosong\n";           
        }
        else
        {
            cout << "\ndata didalam list adalah:\n";
            node *currentnode = START;
            while (currentnode != NULL)
            {
                cout << currentnode->noMhs << endl;
                currentnode = currentnode->next;
            }
            cout<< endl;

           
            
        }
    }

};

int main()
{
   list mhs;
    int nim;
    char ch;
     while (1)
     {
        cout << endl
             << "menu";
        cout <<endl
             << "1. menambahkan data ke dalam list" <<endl;
        cout << "2menghapus data dari dalam list " <<endl;
        cout << "3.menampilkan semua data di dalam list" << endl;
        cout << "4.mencari data dalam list " << endl;
        cout << "5.keluar" <<endl;
        cout << endl
             << "masukan pilihan (1-5): ";
        cin >> ch;
        switch (ch)
        {
        case '1':
         {
            mhs.addnode();
         } 
         break;

        case '2':
        {
            if (mhs.listempty())
            {
                cout << endl
                     << "list kosong" << endl;
                break;
            }
            cout << endl
                 << "\nmasukan no mahasiswa yang akan di hapus : ";
            cin >> nim;
            if (mhs.delnode(nim) == false)
                cout << endl
                     << "data dengan nomor mahasiswa " << nim << "berhasil di hapus " <<endl;
        {
        break;
         case '3':
        {
            mhs.traverse();
        }
        }
        }
        break;
        case '4':
        {
            if (mhs.listempty() == true)
            {
                cout << "\nlist kosong\n";
                break;
            }
            node *provious, *current;
            cout << endl
                 <<"masukan no mahasiswa yang dicari :";
            cin >> nim;
            if (mhs.search(nim, &previous, &current) == false)
                cout << endl
                     << "data di temukan" << endl;
            else
            {
                cout << endl    
                     << "data ditemukan " << endl;
                cout << "\nno mahasiswa " << current->noMhs << endl;
                cout << "\n";
            }
        }
        break;
        case '5':
        {
            exit(0);  
        }
        break;
        default:
        {
            cout << "pilihan salah !." << endl;
        }
        break;
     }

 
}



bool listempty() {
    return (START == NULL);
}



