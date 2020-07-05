// Nama     : Hanin Nafi'ah
// NIM      : 18101050
// Kelas    : S1 TT 06 B

/* ****************************** LEMBAGA SENSOR FILM REPUBLIK INDONESIA  ************************** */
/*                                PRESENT - MINI PROJECT PROGRAM
/* ************************************************************************************************* */
// ***Program ini dibuat secara damai sebagai Post Test Praktikum Pemrograman Lanjut 2020

#include <iostream>         // Library yang digunakan
#include <fstream>          // untuk menjalankan fungsi-fungsi program
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

class Movie // nama kelas induk program
{
    private :
        char nama[100];    // member data
        int age;           // dari kelas Movie
        char a;
        string ans;
    public :
        // member fungsi untuk input data
        void getData()
        {
            cin.ignore();
            cout<<"\n\n\tTuliskan nama Anda                             : "; cin.getline(nama,20);
            cout<<"\tBerapakah usia Anda saat ini       (tahun)     : "; cin>>age;
            cout<<"\tApakah Anda menyukai drama korea?  (iya/tidak) : "; cin>>ans;
        }
        // member fungsi untuk menampilkan seluruh data
        void showData()
        {
            cout<<"\t-------------------------------------------------------------------"<<endl;
            cout<<"\tNama       : "<<nama<<endl;
            cout<<"\tUsia       : "<<age<<endl;
            cout<<"\tSuka K-pop?: "<<ans<<endl;

        }
        // member fungsi untuk pemilihan kategori usia Anda
        void kategori()
        {
            if (age<=2){
                cout<<"\tDibawah batita sebaiknya jangan diajak untuk menonton film "<<endl;
            } else if (age>2 && age<=6) {
                cout<<"\tKategori film yang boleh ditonton              : (P) Anak Usia Prasekolah"<<endl;
            } else if (age>6 && age<=12) {
                cout<<"\tKategori film yang boleh ditonton              : (A) Anak-anak Usia Sekolah"<<endl;
            } else if (age>12 && age<=17) {
                cout<<"\tKategori film yang boleh ditonton              : (R/BO) Remaja dengan Bimbingan Orang Tua"<<endl;
            } else if (age>17 && age<21){
                cout<<"\tKategori film yang boleh ditonton              : (R) Remaja, Hindari menonton konten sensitif"<<endl;
            } else if (age>=21 && age<=60){
                cout<<"\tSemua kategori film boleh ditonton, pilih film Anda dengan bijak"<<endl;
            } else {
                cout<<"\tAnda sudah terlalu tua untuk menonton film, "<<endl;
                cout<<"\tcari hiburan lain yang lebih bermanfaat bagi kesehatan Anda"<<endl;
            }
        }
        // member fungsi untuk pemilihan kategori usia Anda
        void Hobby()
        {
            if (ans=="iya"){
                cout<<"\n\tBerikut 10 Rekomendasi Drama Korea yang wajib ditonton versi mimin "<<endl;
                cout<<"\n\t\t 1. Descendant of The Sun "<<endl;
                cout<<"\t\t 2. Vagabond "<<endl;
                cout<<"\t\t 3. When The Camellia Blooms "<<endl;
                cout<<"\t\t 4. Crash Landing On You "<<endl;
                cout<<"\t\t 5. Itaewon Class "<<endl;
                cout<<"\t\t 6. Hi Bye, Mama! "<<endl;
                cout<<"\t\t 7. The King Eternal Monarch "<<endl;
                cout<<"\t\t 8. The World of The Married "<<endl;
                cout<<"\t\t 9. Romantic Doctor, Teacher Kim 2 "<<endl;
                cout<<"\t\t 10. It's Okay To Be Not Okay "<<endl;
            }else if(ans=="tidak"){
                cout<<"\n\tBerikut 5 Rekomendasi Film Lokal versi mimin "<<endl;
                cout<<"\n\t\t 1. Habibie & Ainun "<<endl;
                cout<<"\t\t 2. Rudy Habibie "<<endl;
                cout<<"\t\t 3. Habibie & Ainun 3  "<<endl;
                cout<<"\t\t 4. Nanti Kita Cerita Tentang Hari Ini "<<endl;
                cout<<"\t\t 5. Imperfect "<<endl;
                cout<<"\n\tBerikut 5 Rekomendasi Film Barat terbaik versi mimin "<<endl;
                cout<<"\n\t\t 1. Dolittle "<<endl;
                cout<<"\t\t 2. Mulan "<<endl;
                cout<<"\t\t 3. Onward "<<endl;
                cout<<"\t\t 4. Avengers "<<endl;
                cout<<"\t\t 5. Fast & Furious "<<endl;
            } else {
                cout<<" \tOpsinya hanya iya/tidak, coba lagi"<<endl;
            }
        }
};

int main()
{
    // Deklarasi objek, variabel dan tipe data yang digunakan
    Movie M;
    fstream data;
    string pass,user;
    char ans;
    int i=1,posisi=0,pilih,ukuran;
    int start, end;

    start :

    cout<<"\n\n\t SELAMAT DATANG DALAM PROGRAM SENSOR FILM"<<endl;
    cout<<"\n\t ----------------------------------------------------- "<<endl;
    cout<<"\n\t 1. Cek Kategori Film Usia Anda"<<endl;
    cout<<"\t 2. Lihat Rekap Data"<<endl;
    cout<<"\t 3. Ubah Data"<<endl;
    cout<<"\t 4. Keluar"<<endl;
    cout<<"\n\t ----------------------------------------------------- "<<endl;
    cout<<"\n\t Pilih menu [1-4] : "; cin>>pilih;
    enum pilih{CREATE=1, READ, UPDATE, FINISH};
    while(pilih != FINISH){
         switch (pilih){
            case CREATE:
            system("cls");
            // membuat/membuka file disk untuk menyimpan data
            data.open("Rekap Data.txt", ios::app | ios::out | ios::in | ios::binary );
            cout<<"\n\n\n\t\t\t*** Silahkan cek kategori Film yang cocok untuk Anda ***"<<endl;
            do{
                // memanggil fungsi void inputan data
                M.getData();
                cout<<endl;
                // memanggil fungsi void untuk menunjukan kotegori film
                M.kategori();
                // memanggil fungsi void rekomendasi film
                M.Hobby();
                // menulis data baru untuk disimpan pada file disk
                data.write((char*)(&M), sizeof(M));
                cout<<endl;
                // pilihan perulangan apabila akan menginputkan data lagi
                cout<<"\tInput data lagi? (y/t)"; cin>>ans;
                }while(ans=='y');
                cout<<"\n\t\tData tersimpan . . . ."<<endl;
                data.close();
                cout<<"\n\t\t";system ("pause");
                system("cls");
                goto start;
                break;

            // melihat rekap data
            case READ:
                system("cls");
                // membuka disk file
                data.open("Rekap Data.txt", ios::app | ios::out | ios::in | ios::binary );
				// mencari ukuran data yang digunakan untuk mengetahui jumlah input data
                data.read((char*)(&M),sizeof(M));
				data.seekg(0,ios::beg);
                start = data.tellg();
                data.seekg(0,ios::end);
                end = data.tellg();
                ukuran = (end-start)/120;
                cout<<"\n\n\t\t\t\t*** Rekap Data ***"<<endl;
                cout<<endl;
                cout<<"\n\tJumlah Pencoba : "<<ukuran<<endl;
                // menutup disk file
                data.close();
				// membuka disk file
                data.open("Rekap Data.txt", ios::app | ios::out | ios::in | ios::binary );
                // meletakan pointer pada data 1 dan membacanya
				data.seekg(0);
                data.read((char*)(&M), sizeof(M));
				// perulangan untuk menampilkan data pertama sampai terakhir
					while(!data.eof()){
                	// menampilkan warga yang sudah terdaftar
                	M.showData();
                	// membaca data dalam disk file
                	data.read((char*)(&M), sizeof(M));
                }
                // menutup disk file
                data.close();
                cout<<"\n\t\t";system ("pause");
                system("cls");
                goto start;
                break;

            // mengubah data yang sudah diinput
            case UPDATE:
                system("cls");
				// membuka disk file
                data.open("Rekap Data.txt", ios::in | ios::binary | ios::out );
                cout<<"\n\t\tJumlah Pencoba : "<<ukuran<<endl;
                cout<<"\n\t\tPilih urutan data pencoba [nomor] : ";cin>>posisi;
                //mengetahui letak pointer
                int letak = (posisi-1)*sizeof(data);
                data.seekg(letak);
                //menulis kembali data yang diedit
                M.getData();
                M.kategori();
                M.Hobby();
                data.write((char*)(&M),sizeof(M));
                data.close();
                cout<<"\n\t\t";system ("pause");
                system("cls");
                goto start;
                break;
         }
         cout<<"\t Pilihan menu yang Anda masukan tidak tersedia"<<endl;
         cout<<"\n\t\t";system ("pause");
         system("cls");
         goto start ;

    }
    system("cls");
    cout<<"\n\n\t\t Matursuwun . . . . . . "<<endl;
	return 0;
}

