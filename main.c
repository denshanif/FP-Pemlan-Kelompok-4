#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data_barang
{
    char nama[25], kategori[25];
    int harga, kode;
} tukar;

int z = 0;

typedef struct data_barang barang;

barang data['0'];

FILE *file_data;

void tampilBarang();
void cariBarang();

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
        printf("3. KELUAR PROGRAM.\n");

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
        printf("Nama Barang : %s\n\n", data[i].nama);

        printf("Kode Barang : %d\n", data[i].kode);
        printf("Kategori Barang : %s\n", data[i].kategori);
        printf("Harga Barang : %d\n\n", data[i].harga);
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
        listNama();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        urutNamaDescen();
        listNama();
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

void listHarga()
{
    int i;
    for (i = 0; i < z; i++)
    {
        printf("Harga Barang : %d\n\n", data[i].harga);

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
        listHarga();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        urutHargaDescen();
        listHarga();
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

    int i, flag = 0;
    int cari;

up:
	printf("Masukkan kode barang yang ingin dicari: ");
	scanf("%d", &cari);

	for(i = 0; i < z; i++) {
		if (data[i].kode == cari) {
            flag = 1;

            break;
        }
	}

	if (flag == 1)
    {
        printf("Data barang ditemukan!\n\n");

        printf("Kode Barang : %d\n\n", data[i].kode);

        printf("Kategori Barang : %s\n", data[i].kategori);
        printf("Nama Barang : %s\n", data[i].nama);
        printf("Harga Barang : %d\n\n", data[i].harga);
    }
    else
    {
        printf("Data yang anda cari tidak ditemukan \n");
        getch();
        goto up;
    }
}

void cariNama() {
    urutNamaAscen();

    int i, flag = 0;
    char cari[25];

up:
	printf("Masukkan nama barang yang ingin dicari: ");
	scanf("%s", &cari);

	for(i = 0; i < z; i++) {
		if (strcmp(data[i].nama, cari) == 0) {
            flag = 1;

            break;
        }
	}

	if (flag == 1)
    {
        printf("Data barang ditemukan!\n\n");

        printf("Nama Barang : %s\n\n", data[i].nama);

        printf("Kode Barang : %d\n", data[i].kode);
        printf("Kategori Barang : %s\n", data[i].kategori);
        printf("Harga Barang : %d\n\n", data[i].harga);
    }
    else
    {
        printf("Data yang anda cari tidak ditemukan \n");
        getch();
        goto up;
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