#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct data_barang
{
    char nama[25], kategori[25];
    int harga, kode;
} tukar;

struct data_beli
{
    char *nama, *kategori;
    int harga, kode;
};

int z = 0, b = 0, totalHarga = 0;

typedef struct data_beli barang_beli;
typedef struct data_barang barang;

barang data['0'];
barang_beli keranjang['0'];

FILE *file_data;

void tampilBarang();
void cariBarang();
void konfirmasi();

int main()
{
    int i, menu;

    char kembali;

    file_data = fopen("Data.txt", "r");

    while (!feof(file_data))
    {
        fscanf(file_data, "\nKode : %d\nKategori : %s\nNama Barang : %s\nHarga : %d", &data[z].kode, &data[z].kategori, &data[z].nama, &data[z].harga);
        z++;
    }

    do
    {
        system("cls");
        printf("===================================================\n");
        printf("========== PROGRAM MANAJEMEN SUPERMARKET ==========\n");
        printf("===================================================\n");

        printf("\n=== SILAHKAN PILIH MENU YANG DI BAWAH INI ===\n");
        printf("1. MENAMPILKAN SEMUA DATA BARANG.\n");
        printf("2. PENCARIAN DATA BARANG.\n");
        printf("3. KONFIRMASI PEMBELIAN. \n");
        printf("4. KELUAR PROGRAM.\n");

        printf("Masukkan pilihan anda: ");
        scanf("%d", &menu);

        printf("\n");

        // Switch case untuk masing-masing menu
        switch (menu)
        {
        case 1:
            tampilBarang();
            printf("\n");
            break;
        case 2:
            cariBarang();
            printf("\n");
            break;
        case 3:
            konfirmasi();
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Maaf, input yang anda masukkan salah/invalid.");
            printf("\n");
            break;
        }
        printf("\n");

        // Pilihan kembali ke menu utama
        printf("Ingin kembali ke menu utama? (Y/T): ");
        scanf("%c", &kembali);
        scanf("%c", &kembali);
    } while (kembali == 'y' || kembali == 'Y');

    fclose(file_data);

    return 0;
}

void listNama()
{
    int i;
    for (i = 0; i < z; i++)
    {
        printf("Nama Barang : %s\n", data[i].nama);
        printf("Kode Barang : %d\n", data[i].kode);
        printf("Kategori Barang : %s\n", data[i].kategori);
        printf("Harga Barang : %d\n\n", data[i].harga);
    }
}

void beli_barang(char *judul)
{
    int a, c=0, i, beli;
    b++;

up:
    system("cls");
    printf("=========================== %s =============================\n\n", judul);
    listNama();
    printf("\n");

    printf("Masukkan kode barang yang ingin dibeli: ");
    scanf("%d", &beli);

    for (i=0; i<z ;i++) {
        if (data[i].kode == beli) {
            keranjang[b].nama = data[i].nama;
            keranjang[b].kode = data[i].kode;
            keranjang[b].kategori = data[i].kategori;
            keranjang[b].harga = data[i].harga;
        } else {
            c=c+1;
        }
    }

    if (c==z) {
        printf("\nMaaf Kode yang anda masukkan salah/tidak tersedia di list");
    }

    printf("\nTekan 1 untuk berhenti, 2 untuk melanjutkan: ");
    scanf("%d", &a);

    switch(a) {
    case 1:
        break;
    case 2:
        b++;
        goto up;
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
    printf("2. TAMPILKAN NAMA BARANG URUT DESCENDING (Z-A).\n");
    printf("3. KEMBALI KE MENU UTAMA.\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    printf("\n");

    // Switch case pemilihan menu
    switch (menu)
    {
    case 1:
        urutNamaAscen();
        beli_barang("LIST NAMA BARANG URUT ASCENDING (A-Z)");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        urutNamaDescen();
        beli_barang("LIST NAMA BARANG URUT DESCENDING (Z-A)");
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

void listHarga()
{
    int i;
    for (i = 0; i < z; i++)
    {
        printf("Harga Barang : %d\n", data[i].harga);
        printf("Kode Barang : %d\n", data[i].kode);
        printf("Kategori Barang : %s\n", data[i].kategori);
        printf("Nama Barang : %s\n\n", data[i].nama);
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
    printf("2. TAMPILKAN HARGA BARANG URUT DESCENDING (Mahal - Murah).\n");
    printf("3. KEMBALI KE MENU UTAMA.\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    printf("\n");

    // Switch case pemilihan menu
    switch (menu)
    {
    case 1:
        urutHargaAscen();
        beli_barang("LIST HARGA BARANG URUT ASCENDING (Murah - Mahal)");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        urutHargaDescen();
        beli_barang("LIST HARGA BARANG URUT ASCENDING (Murah - Mahal)");
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
    printf("2. TAMPILKAN DATA BARANG URUT SESUAI HARGA BARANG.\n");
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

    int x;
    printf("=================== Pencarian Data Barang Berdasarkan Kode Barang ===================\n\n");

	printf("Masukkan Kode Buku Yang Ingin Dicari: ");
	scanf("%d", &x);

	// Jump Search

	int n = z, jump = sqrt(n), prev = 0, i = 0;

    while (data[jump].kode <= x && jump < n) {
        prev = jump;
        jump += sqrt(n);
        if (prev >= n + 1) {
            printf("Data tidak ditemukan\n");
            printf("Tekan enter untuk mengulangi input kode buku.\n");
            getch();
            goto ulangi;
        }
        i++;
    }

    int ketemu = 0;
    int j;
    for (j = prev; j <= jump; j++) {
        if (data[j].kode == x) {
            ketemu = 1;
            printf("Data barang ditemukan!\n\n");

            printf("Kode Barang : %d\n\n", data[i].kode);

            printf("Kategori Barang : %s\n", data[i].kategori);
            printf("Nama Barang : %s\n", data[i].nama);
            printf("Harga Barang : %d\n\n", data[i].harga);
            break;
        }
    }

    if (i == 0 && ketemu == 0) {
        printf("Data tidak ditemukan\n");
        printf("Tekan enter untuk mengulangi input kode barang.\n");
        getch();
        goto ulangi;
    }
}

void cariNama() {
    urutNamaAscen();

    ulangi:

    system("cls");

    char cari[25];
    printf("=================== Pencarian Data Barang Berdasarkan Nama Barang ==================\n\n");

	printf("Masukkan Judul Buku Yang Ingin Dicari: ");
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
        printf("Tekan enter untuk mengulangi input nama barang.\n");
        getch();
        goto ulangi;
    }
    else
    {
            printf("Data barang ditemukan!\n\n");

            printf("Nama Barang : %s\n\n", data[match].nama);

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
    printf("2. CARI DATA BARANG BERDASARKAN NAMA BARANG.\n");
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
    for (i = 1; i <= b; i++)
    {
        printf("Kode Barang : %d\n", keranjang[i].kode);
        printf("Nama Barang : %s\n", keranjang[i].nama);
        printf("Kategori Barang : %s\n", keranjang[i].kategori);
        printf("Harga Barang : %d\n\n", keranjang[i].harga);

        totalHarga = totalHarga + keranjang[i].harga;
    }
}

void pembayaran()
{
    int kembalian, uang;

    printf("\nMasukkan jumlah pembayaran: Rp.");
    scanf("%d", &uang);

    kembalian = uang - totalHarga;

    if (uang > totalHarga) {
        system("cls");
        printf("===================================================\n");
        printf("        ========== NOTA BELANJA ==========         \n");
        printf("===================================================\n\n");

        printf(" Daftar belanja anda:\n");
        printf("=========================================\n");
        listKeranjang();
        printf("=========================================\n");
        printf(" Total harga\t: Rp. %d\n", totalHarga);
        printf(" Pembayaran\t: Rp. %d\n", uang);
        printf(" Kembalian\t: Rp. %d\n\n", kembalian);

        printf("===================================================\n");
        printf("      ========== TRANSAKSI SELESAI ==========      \n");
        printf("===================================================\n");
        b = 0;
        totalHarga = 0;
    } else {
        printf("MAAF UANG ANDA TIDAK CUKUP UNTUK MELAKUKAN PEMBAYARAN\n");
    }
}

void konfirmasi()
{
    int a;

    if (b == 0) {
        system("cls");
        printf("=========================== Menampilkan Data =============================\n\n");
        printf("KERANJANG MASIH KOSONG");
    } else {
        system("cls");
        printf("=========================== Menampilkan Data =============================\n\n");
        listKeranjang();
        printf("TOTAL HARGA: Rp.%d\n", totalHarga);

        printf("Tekan 1 untuk lanjut ke pembayaran, 2 untuk kembali: ");
        scanf("%d", &a);

        switch(a)
        {
        case 1:
            pembayaran();
            getch();
            break;
        case 2:
            printf("\n");
            break;
        }
    }
}