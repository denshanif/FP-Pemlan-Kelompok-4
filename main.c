#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct data_barang
{
    char nama[50], kategori[50];
    int harga, kode;
} tukar;

struct data_beli
{
    char nama[50], kategori[50];
    int harga, kode, jumlah;
};

struct data_kategori
{
    char *nama, *kategori;
    int harga, kode;
} tukar1;

int z = 0, b = 0, n = 0, totalHarga = 0;

typedef struct data_kategori kategori_barang;
typedef struct data_beli barang_beli;
typedef struct data_barang barang;

barang data['0'];
barang_beli keranjang['0'];
kategori_barang filter_kategori['0'];

FILE *file_data;

void tampilBarang();
void cariBarang();
void konfirmasi();
void tampilKategori();
void listKategori();
void bacaData();
void bacaDataBeli();
void hapusData();

int main()
{
    int i, menu;
    char kembali;

    bacaData();

    file_data=fopen("Beli.txt","w+");
    fclose(file_data);
    remove("Beli.txt");
    file_data=fopen("Beli.txt","a+");

    up:
        system("cls");
        printf("===================================================\n");
        printf("========== PROGRAM MANAJEMEN SUPERMARKET ==========\n");
        printf("===================================================\n");

        printf("\n=== SILAHKAN PILIH MENU YANG DI BAWAH INI ===\n");
        printf("1. MENAMPILKAN SEMUA DATA BARANG.\n");
        printf("2. MENAMPILKAN BARANG BERDASARKAN KATEGORI. \n");
        printf("3. PENCARIAN DATA BARANG.\n");
        printf("4. KONFIRMASI PEMBELIAN (MELIHAT KERANJANG BELANJA).\n");
        printf("5. HAPUS BARANG DI KERANJANG BELANJA.\n");

        printf("6. KELUAR PROGRAM.\n");

        printf("Masukkan pilihan anda: ");
        scanf("%d", &menu);

        printf("\n");

        // Switch case untuk masing-masing menu
        switch (menu)
        {
        case 1:
            tampilBarang();
            printf("\n");
            printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
            getch();
            goto up;
        case 2:
            tampilKategori();
            printf("\n");
            printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
            getch();
            goto up;
        case 3:
            cariBarang();
            printf("\n");
            printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
            getch();
            goto up;
        case 4:
            bacaDataBeli();
            konfirmasi();

            printf("\n");
            printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
            getch();
            goto up;
        case 5:
            hapusData();
            printf("\n");
            printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
            getch();
            goto up;
        case 6:
            exit(0);
        default:
            printf("Maaf, input yang anda masukkan salah/invalid.");
            printf("\n");
            printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
            getch();
            goto up;
        }
        printf("\n");

    fclose(file_data);

    return 0;
}

void listNama()
{
    int i;
    for (i = 1; i < z; i++)
    {
        printf("Nama Barang : %s\n", data[i].nama);
        printf("Kode Barang : %d\n", data[i].kode);
        printf("Kategori Barang : %s\n", data[i].kategori);
        printf("Harga Barang : %d\n\n", data[i].harga);
    }
}

void beli_barang(char *judul, int banyakData)
{
    int a, c, i, beli, banyak;
up:
    system("cls");
    c = 0;

    if (banyakData == z) {
        printf("=========================== %s =============================\n\n", judul);
        listNama();

        printf("Jumlah barang: %d\n", banyakData);

        printf("\nMasukkan kode barang yang ingin dibeli: ");
        scanf("%d", &beli);

        printf("Masukkan jumlah barang yang ingin dibeli: ");
        scanf("%d", &banyak);

        for (i=0; i<banyakData ;i++) {
            if (data[i].kode == beli) {
                fprintf(file_data,"Kode : %d\nKategori : %s#\nNama Barang : %s#\nHarga : %d\nJumlah : %d\n", data[i].kode, data[i].kategori, data[i].nama, data[i].harga, banyak);
                break;
            } else {
                c++;
            }
        }

    } else {
        printf("====================== Kategori %s ========================\n\n", judul);
        listKategori();

        printf("Jumlah barang kategori %s : %d\n", judul, n);

        printf("\nMasukkan kode barang yang ingin dibeli: ");
        scanf("%d", &beli);

        printf("Masukkan jumlah barang yang ingin dibeli: ");
        scanf("%d", &banyak);

        for (i=0; i<banyakData ;i++) {
            if (filter_kategori[i].kode == beli) {
                fprintf(file_data,"Kode : %d\nKategori : %s#\nNama Barang : %s#\nHarga : %d\nJumlah : %d\n", filter_kategori[i].kode, filter_kategori[i].kategori, filter_kategori[i].nama, filter_kategori[i].harga, banyak);
                break;
            } else {
                c++;
            }
        }

        printf("\nBarang yang anda beli telah berhasil dimasukkan ke keranjang belanja.\n");
    }

    b = 2;

    if (c==banyakData) {
        printf("\nMaaf Kode yang anda masukkan salah/tidak tersedia di daftar barang.");
    }

ulangi:

    printf("\nTekan 1 untuk membeli barang dari kategori lain, 2 untuk lanjut membeli barang di kategori ini: ");
    scanf("%d", &a);

    switch(a) {
    case 1:
        printf("\n");
        break;
    case 2:
        goto up;
    default:
        printf("Maaf, input yang anda masukkan salah/invalid.");
        printf("\n");
        goto ulangi;
    }
}

void urutNamaAscen()
{
    int i, j;

	// Looping bubble sort
	for (i = z - 1; i > 0; i--) {
		for (j = z - 1; j >= z - i; j--) {
			if (strcmp(data[j].nama, data[j-1].nama) < 0) {
				tukar = data[j];
				data[j] = data[j-1];
				data[j-1] = tukar;
			}
		}
	}
}

void urutNamaDescen()
{
    int i, j;

	// Looping bubble sort
	for (i = z - 1; i > 0; i--) {
		for (j = z - 1; j >= z - i; j--) {
			if (strcmp(data[j].nama, data[j-1].nama) > 0) {
				tukar = data[j];
				data[j] = data[j-1];
				data[j-1] = tukar;
			}
		}
	}
}

void tampilNama()
{
    int menu;

// Menu
up:
    system("cls");
    printf("================= Menampilkan Data Barang Menurut Nama Barang ===================\n\n");
    printf("\n======================= SILAHKAN PILIH OPSI DI BAWAH INI ======================\n");

    printf("1. TAMPILKAN NAMA BARANG URUT ASCENDING (A-Z).\n");
    printf("2. TAMPILKAN NAMA BARANG URUT DESCENDING (Z-A).\n\n");

    printf("3. KEMBALI KE MENU UTAMA.\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    printf("\n");

    // Switch case pemilihan menu
    switch (menu)
    {
    case 1:
        urutNamaAscen();
        beli_barang("LIST NAMA BARANG URUT ASCENDING (A-Z)", z);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        urutNamaDescen();
        beli_barang("LIST NAMA BARANG URUT DESCENDING (Z-A)", z);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 3:
        break;
    default:
        printf("Maaf, input yang anda masukkan salah/invalid.");
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    }
}

void urutHargaAscen()
{
    int i, j;

	// Looping bubble sort
	for (i = z - 1; i > 0; i--) {
		for (j = z - 1; j >= z - i; j--) {
			if (data[j].harga < data[j-1].harga) {
				tukar = data[j];
				data[j] = data[j-1];
				data[j-1] = tukar;
			}
		}
	}
}

void urutHargaDescen()
{
    int i, j;

	// Looping bubble sort
	for (i = z - 1; i > 0; i--) {
		for (j = z - 1; j >= z - i; j--) {
			if (data[j].harga > data[j-1].harga) {
				tukar = data[j];
				data[j] = data[j-1];
				data[j-1] = tukar;
			}
		}
	}
}

void tampilHarga()
{
    int menu;

// Menu
up:
    system("cls");
    printf("================ Menampilkan Data Barang Menurut Harga Barang ===================\n\n");
    printf("\n======================= SILAHKAN PILIH OPSI DI BAWAH INI ======================\n");

    printf("1. TAMPILKAN HARGA BARANG URUT ASCENDING (Murah - Mahal).\n");
    printf("2. TAMPILKAN HARGA BARANG URUT DESCENDING (Mahal - Murah).\n\n");

    printf("3. KEMBALI KE MENU UTAMA.\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    printf("\n");

    // Switch case pemilihan menu
    switch (menu)
    {
    case 1:
        urutHargaAscen();
        beli_barang("LIST HARGA BARANG URUT ASCENDING (Murah - Mahal)", z);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        urutHargaDescen();
        beli_barang("LIST HARGA BARANG URUT ASCENDING (Murah - Mahal)", z);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 3:
        break;
    default:
        printf("Maaf, input yang anda masukkan salah/invalid.");
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    }
}

void tampilBarang()
{
    int menu;

// Menu
up:
    system("cls");
    printf("=========================== Menampilkan Data Barang =============================\n\n");
    printf("\n======================= SILAHKAN PILIH OPSI DI BAWAH INI ======================\n");

    printf("1. TAMPILKAN DATA BARANG URUT SESUAI NAMA BARANG.\n");
    printf("2. TAMPILKAN DATA BARANG URUT SESUAI HARGA BARANG.\n\n");

    printf("3. KEMBALI KE MENU UTAMA.\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    printf("\n");

    // Switch case pemilihan menu
    switch (menu)
    {
    case 1:
        tampilNama();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        tampilHarga();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 3:
        break;
    default:
        printf("Maaf, input yang anda masukkan salah/invalid.");
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    }
}

void urutKodeAscen()
{
    int i, j;

	// Looping bubble sort
	for (i = z - 1; i > 0; i--) {
		for (j = z - 1; j >= z - i; j--) {
			if (data[j].kode < data[j-1].kode) {
				tukar = data[j];
				data[j] = data[j-1];
				data[j-1] = tukar;
			}
		}
	}
}

void cariKode() {
    urutKodeAscen();

    ulangi:

    system("cls");

    int a, cari;
    printf("=================== Pencarian Data Barang Berdasarkan Kode Barang ===================\n\n");

	printf("Masukkan Kode Barang Yang Ingin Dicari: ");
	scanf("%d", &cari);

	// Interpolation Search

	int low = 0, high = z - 1, match, ketemu = 0;
    float mid;
    int posisi;

    while (cari >= data[low].kode && cari <= data[high].kode)
    {
        mid = (cari - data[low].kode) / (data[high].kode - data[low].kode) * (high - low) + low;
        posisi = mid;
        if (data[posisi].kode == cari){
            match = posisi;
            ketemu = 1;
            break;
        }
        if (data[posisi].kode > cari)
            high = posisi - 1;
        else if (data[posisi].kode < cari)
            low = posisi + 1;
    }

    if (ketemu == 0)
    {
        printf ("Data Tidak Ditemukan\n");
        printf("\nTekan 1 untuk berhenti, 2 untuk melanjutkan: ");
    	scanf("%d", &a);

    	switch(a) {
    	case 1:
        	printf("\n");
        	break;
    	case 2:
        	goto ulangi;
  		}
	}
    else
    {
            printf("Data barang ditemukan!\n\n");

            printf("Nama Barang : %s\n", data[match].nama);
            printf("Kode Barang : %d\n", data[match].kode);
            printf("Kategori Barang : %s\n", data[match].kategori);
            printf("Harga Barang : %d\n\n", data[match].harga);
    }
}

void cariNama() {
    urutNamaAscen();

    ulangi:

    system("cls");

    int a;
    char cari[25];
    printf("=================== Pencarian Data Barang Berdasarkan Nama Barang ==================\n\n");

	printf("Masukkan Nama Barang Yang Ingin Dicari: ");
	gets(cari);
	scanf("%[^\n]", &cari);

	// Interpolation Search

	int low = 0, high = z - 1, match, ketemu = 0;
    float mid;
    int posisi;

    while ((strcmp(cari, data[low].nama) >= 0) && (strcmp(cari, data[high].nama) <= 0))
    {
        mid = (float) strcmp(cari, data[low].nama) / strcmp(data[high].nama, data[low].nama) * (high - low) + low;
        posisi = floor(mid);
        if (strcmp(data[posisi].nama, cari) == 0){
            match = posisi;
            ketemu = 1;
            break;
        }
        if (strcmp(data[posisi].nama, cari) > 0)
            high = posisi - 1;
        else if (strcmp(data[posisi].nama, cari) < 0)
            low = posisi + 1;
    }

    if (ketemu == 0)
    {
        printf ("Data Tidak Ditemukan\n");
	 	printf("\nTekan 1 untuk berhenti, 2 untuk melanjutkan: ");
    	scanf("%d", &a);

    	switch(a) {
    	case 1:
        	printf("\n");
        	break;
    	case 2:
        	goto ulangi;
  		}
    }
    else
    {
            printf("Data barang ditemukan!\n\n");

            printf("Nama Barang : %s\n", data[match].nama);
            printf("Kode Barang : %d\n", data[match].kode);
            printf("Kategori Barang : %s\n", data[match].kategori);
            printf("Harga Barang : %d\n\n", data[match].harga);
    }
}

void cariBarang()
{
    int menu;

up:
    system("cls");
    printf("============================ Pencarian Data Barang ==============================\n\n");
    printf("\n======================= SILAHKAN PILIH OPSI DI BAWAH INI ======================\n");

    printf("1. CARI DATA BARANG BERDASARKAN KODE BARANG.\n");
    printf("2. CARI DATA BARANG BERDASARKAN NAMA BARANG.\n\n");

    printf("3. KEMBALI KE MENU UTAMA.\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    printf("\n");

    // Switch case pemilihan menu
    switch (menu)
    {
    case 1:
        cariKode();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        cariNama();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 3:
        break;
    default:
        printf("Maaf, input yang anda masukkan salah/invalid.");
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    }
}

void listKeranjang()
{
    int i;
    totalHarga = 0;
    for (i = 1; i < b; i++)
    {
        printf("Kode Barang : %d\n", keranjang[i].kode);
        printf("Nama Barang : %s\n", keranjang[i].nama);
        printf("Kategori Barang : %s\n", keranjang[i].kategori);
        printf("Harga Barang : %d\n", keranjang[i].harga);
        printf("Jumlah Barang : %d\n\n", keranjang[i].jumlah);

        totalHarga = totalHarga + (keranjang[i].harga*keranjang[i].jumlah);
    }
}

void pembayaran()
{
    int kembalian, uang;

    printf("\nMasukkan jumlah pembayaran: Rp.");
    scanf("%d", &uang);

    kembalian = uang - totalHarga;

    if (uang >= totalHarga) {
        system("cls");
        printf("===================================================\n");
        printf("        ========== NOTA BELANJA ==========         \n");
        printf("===================================================\n\n");

        printf("Daftar belanja anda:\n");
        printf("=========================================\n");
        listKeranjang();
        printf("=========================================\n");
        printf("Total harga\t: Rp. %d\n", totalHarga);
        printf("Pembayaran\t: Rp. %d\n", uang);
        printf("Kembalian\t: Rp. %d\n\n", kembalian);

        printf("===================================================\n");
        printf("      ========== TRANSAKSI SELESAI ==========      \n");
        printf("===================================================\n");
    } else {
        printf("MAAF UANG ANDA TIDAK CUKUP UNTUK MELAKUKAN PEMBAYARAN\n");
    }
}

void konfirmasi()
{
    int a;

    system("cls");
    printf("=========================== Keranjang Belanja =============================\n\n");

    if (b < 2) {
        printf("KERANJANG BELANJA ANDA MASIH KOSONG\n");
    } else {
        listKeranjang();
        printf("TOTAL HARGA: Rp.%d\n", totalHarga);

        printf("Tekan 1 untuk lanjut ke pembayaran, 2 untuk kembali: ");
        scanf("%d", &a);

        switch(a)
        {
        case 1:
            pembayaran();
            b = 0, z = 0;

            fclose(file_data);
            remove("Beli.txt");

            bacaData();

            file_data=fopen("Beli.txt","a+");

            getch();
            break;
        case 2:
            printf("\n");
            break;
        }
    }
}

void urutKategori()
{
    int i, j;

	// Looping bubble sort
	for (i = z - 1; i > 0; i--) {
		for (j = z - 1; j >= z - i; j--) {
			if (strcmp(data[j].kategori, data[j-1].kategori) < 0) {
				tukar = data[j];
				data[j] = data[j-1];
				data[j-1] = tukar;
			}
		}
	}
}

void filter(char *judul)
{
    urutKategori();

    int i;
    n = 0;

    char k[50];
    strcpy(k, judul);

    printf("====================== Kategori %s ========================\n\n", k);

    for (i = 0; i < z; i++)
    {
        if (strcmp(data[i].kategori, k) == 0)
        {
            filter_kategori[n].nama = data[i].nama;
            filter_kategori[n].kode = data[i].kode;
            filter_kategori[n].kategori = data[i].kategori;
            filter_kategori[n].harga = data[i].harga;

            n++;
        }
    }
}

void tampilKategori()
{
    int menu;

// Menu
up:
    system("cls");
    printf("================= Menampilkan Data Barang Berdasarkan Kategori ===================\n\n");
    printf("\n======================= SILAHKAN PILIH OPSI DI BAWAH INI =======================\n");

    printf("1. TAMPILKAN BARANG KATEGORI SAYURAN.\n");
    printf("2. TAMPILKAN BARANG KATEGORI BUAH.\n");
    printf("3. TAMPILKAN BARANG KATEGORI MINUMAN.\n");
    printf("4. TAMPILKAN BARANG KATEGORI MAKANAN RINGAN.\n");
    printf("5. TAMPILKAN BARANG KATEGORI BAHAN DAPUR MASAKAN.\n");
    printf("6. TAMPILKAN BARANG KATEGORI KECANTIKAN.\n");
    printf("7. TAMPILKAN BARANG KATEGORI ALAT RUMAH TANGGA.\n");
    printf("8. TAMPILKAN BARANG KATEGORI OBAT-OBATAN.\n");
    printf("9. TAMPILKAN BARANG KATEGORI ALAT TULIS.\n");
    printf("10. TAMPILKAN BARANG KATEGORI KEBUTUHAN HEWAN.\n\n");

    printf("11. KEMBALI KE MENU UTAMA.\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    printf("\n");

    // Switch case pemilihan menu
    switch (menu)
    {
    case 1:
        filter("Sayuran");
        beli_barang("Sayuran", n);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        filter("Buah");
        beli_barang("Buah", n);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 3:
        filter("Minuman");
        beli_barang("Minuman", n);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 4:
        filter("Makanan Ringan");
        beli_barang("Makanan Ringan", n);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 5:
        filter("Bahan Dapur Masakan");
        beli_barang("Bahan Dapur Masakan", n);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 6:
        filter("Kecantikan");
        beli_barang("Kecantikan", n);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 7:
        filter("Alat Rumah Tangga");
        beli_barang("Alat Rumah Tangga", n);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 8:
        filter("Obat-obatan");
        beli_barang("Obat-obatan", n);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 9:
        filter("Alat Tulis");
        beli_barang("Alat Tulis", n);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 10:
        filter("Kebutuhan Hewan");
        beli_barang("Kebutuhan Hewan", n);
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 11:
        break;
    default:
        printf("Maaf, input yang anda masukkan salah/invalid.");
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    }
}

void listKategori()
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Nama Barang : %s\n", filter_kategori[i].nama);
        printf("Kode Barang : %d\n", filter_kategori[i].kode);
        printf("Kategori Barang : %s\n", filter_kategori[i].kategori);
        printf("Harga Barang : %d\n\n", filter_kategori[i].harga);
    }
}

void bacaData() {
    file_data = fopen("Data.txt", "r");

    while (!feof(file_data))
        {
            fscanf(file_data, "\nKode : %d\nKategori : %[^#]#\nNama Barang : %[^#]#\nHarga : %d", &data[z].kode, &data[z].kategori, &data[z].nama, &data[z].harga);
            z++;
        }

    fclose(file_data);
}

void bacaDataBeli() {
    fclose(file_data);
    file_data=fopen("Beli.txt","a+");

    if (b > 1) {
        b = 1;

        while (!feof(file_data))
        {
            fscanf(file_data, "Kode : %d\nKategori : %[^#]#\nNama Barang : %[^#]#\nHarga : %d\nJumlah : %d\n", &keranjang[b].kode, &keranjang[b].kategori, &keranjang[b].nama, &keranjang[b].harga, &keranjang[b].jumlah);
            b++;
        }
    }
}

void hapusData() {
    int cari, i, j = 0, k;

    system("cls");
    printf("=========================== Hapus Data =============================\n\n");


    bacaDataBeli();
    listKeranjang();

    if (b < 2) {
        printf("KERANJANG BELANJA ANDA MASIH KOSONG\n");
    } else {

        printf("Masukkan Kode Barang yang ingin anda hapus dari keranjang belanja: ");
        scanf("%d", &cari);

        for (i=1; i<b; i++) {
            if(keranjang[i].kode == cari) {
                printf("\nBarang dengan Kode %d telah berhasil dihapus dari keranjang belanja anda\n", cari);

                for (k=i; k<b; k++) {
                    keranjang[k] = keranjang[k+1];
                }

                fclose(file_data);
                remove("Beli.txt");

                file_data=fopen("Beli.txt","a+");

                b--;
                break;
            } else {
                j++;
            }
        }

        if (j == b) {
            printf("Data yang ingin anda hapus tidak ditemukan\n\n");
        }

        for (i=1; i<b; i++) {
            fprintf(file_data,"Kode : %d\nKategori : %s#\nNama Barang : %s#\nHarga : %d\nJumlah : %d\n", keranjang[i].kode, keranjang[i].kategori, keranjang[i].nama, keranjang[i].harga, keranjang[i].jumlah);
        }
    }
}




