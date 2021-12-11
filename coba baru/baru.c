#include <stdio.h>
#include <stdlib.h>

typedef struct barang
{
  int kode;
  char nama[20];
  char kategori[20];
  int harga;
}barang;

int jumlahData = 0;

void buat();
void tampil();
void tambah();
void cariKode();
void edit();

int main()
{
  int menu;

  do{
    printf("\n1. Buat Data Barang Baru");
    printf("\n2. Tampilkan Data Barang");
    printf("\n3. Tambah Data Barang");
    printf("\n4. Cari Data Barang Berdasarkan Kode Barang");
    printf("\n5. Edit Data Barang Yang Sudah Ada");
    printf("\n0. Keluar Program");

    printf("\n Masukkan pilihan anda: ");
    scanf("%d", &menu);

    switch(menu)
    {
      case 1:
        buat();
        break;
      case 2:
        tampil();
        break;
      case 3:
        tambah();
        break;
      case 4:
        cariKode();
        break;
      case 5:
        edit();
        break;
    }

  } while (menu != 0);

  return 0;
}

void hitungJumlah()
{
  barang b1;
  FILE *fp;
  fp = fopen("data_barang.txt", "r");
  fseek(fp, 0, SEEK_END);

  jumlahData = ftell(fp) / sizeof(barang);
}

void buat()
{
  barang *b;
  FILE *fp;
  int n, i;

  printf("Berapa banyak data yang ingin anda buat: ");
  scanf("%d", &n);

  b = (barang *)calloc(n, sizeof(barang));
  fp = fopen("data_barang.txt", "w");

  for (i = 0; i < n; i++)
  {
    printf("\nMasukkan kode barang: ");
    scanf("%d", &b[i].kode);
    fflush(stdin);
    printf("Masukkan nama barang: ");
    scanf("%[^\n]s", b[i].nama);
    fflush(stdin);
    printf("Masukkan kategori barang: ");
    scanf("%[^\n]s", b[i].kategori);
    fflush(stdin);
    printf("Masukkan harga barang: ");
    scanf("%d", &b[i].harga);

    fwrite(&b[i], sizeof(barang), 1, fp);
  }

  fclose(fp);
}

void tampil()
{
  barang b1;
  FILE *fp;
  fp = fopen("data_barang.txt", "r");

  hitungJumlah();

  printf("\nKode\tNama Barang\t\t\tKategori Barang\t\t\t\tHarga Barang");
  while(fread(&b1, sizeof(barang), 1, fp))
  {
    printf("\n\n%-4d\t%-20s\t\t%-20s\t\t\t%-6d\n", b1.kode, b1.nama, b1.kategori, b1.harga);
  }
  printf("\nBanyak Data Barang : %d\n", jumlahData);

  fclose(fp);
}

void tambah()
{
  barang *b;
  FILE *fp;
  int n, i;

  printf("Berapa banyak data yang ingin anda tambahkan: ");
  scanf("%d", &n);

  b = (barang *)calloc(n, sizeof(barang));
  fp = fopen("data_barang.txt", "a");

  for (i = 0; i < n; i++)
  {
    printf("\nMasukkan kode barang: ");
    scanf("%d", &b[i].kode);
    fflush(stdin);
    printf("Masukkan nama barang: ");
    scanf("%[^\n]s", b[i].nama);
    fflush(stdin);
    printf("Masukkan kategori barang: ");
    scanf("%[^\n]s", b[i].kategori);
    fflush(stdin);
    printf("Masukkan harga barang: ");
    scanf("%d", &b[i].harga);

    fwrite(&b[i], sizeof(barang), 1, fp);
  }

  fclose(fp);
}

/*
void urutKode()
{
  int i, j;

  barang *b, b1;
  FILE *fp;
  fp = fopen("data_barang.txt", "r");
  fseek(fp, 0, SEEK_END);
  

  fclose(fp);

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
*/

void cariKode()
{
  int kode, ketemu = 0;

  barang b1;
  FILE *fp;
  fp = fopen("data_barang.txt", "r");

  hitungJumlah();

  printf("Masukkan kode barang yang ingin anda cari: ");
  scanf("%d", &kode);

  printf("\nKode\tNama Barang\tKategori Barang\t\tHarga Barang");
  while(fread(&b1, sizeof(barang), 1, fp))
  {
    if (b1.kode == kode)
    {
      ketemu = 1;
      printf("\n\n%.4d\t%.25s\t\t%.25s\t\t\t%d\n", b1.kode, b1.nama, b1.kategori, b1.harga);
    }
  }
  if (!ketemu)
    printf("\n\nData barang tidak ditemukan\n");

  fclose(fp);
}

void edit()
{
  int kode, ketemu = 0;

  barang b1;
  FILE *fp, *fp1;
  fp = fopen("data_barang.txt", "r");
  fp1 = fopen("data_sementara.txt", "w");

  hitungJumlah();

  printf("Masukkan kode barang yang ingin anda edit: ");
  scanf("%d", &kode);

  while(fread(&b1, sizeof(barang), 1, fp))
  {
    if (b1.kode == kode)
    {
      ketemu = 1;
      
      fflush(stdin);
      printf("Masukkan nama barang: ");
      scanf("%[^\n]s", b1.nama);
      fflush(stdin);
      printf("Masukkan kategori barang: ");
      scanf("%[^\n]s", b1.kategori);
      fflush(stdin);
      printf("Masukkan harga barang: ");
      scanf("%d", &b1.harga);
    }
    fwrite(&b1, sizeof(barang), 1, fp1);
  }
  fclose(fp);
  fclose(fp1);

  if (ketemu)
  {
    fp1 = fopen("data_sementara.txt", "r");
    fp = fopen("data_barang.txt", "w");

    while(fread(&b1, sizeof(barang), 1, fp1))
    {
      fwrite(&b1, sizeof(barang), 1, fp);
    }

    fclose(fp);
    fclose(fp1);
  }
  else
    printf("\n\nData barang tidak ditemukan\n");
}