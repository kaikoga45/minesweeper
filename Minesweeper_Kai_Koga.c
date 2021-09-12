#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void proses_restart(int matriks[100][100], int bom_matriks[100][100], int jumlah_dimatikan[100]){
	
	int i,j, nol;
	
	nol = 0;
	
	for(i=0;i<=100;i++){
		for(j=0;j<=100;j++){
			matriks[i][j] = nol;
			bom_matriks[i][j] = nol;
			jumlah_dimatikan[i] = nol;
		}
	}
	
}

void tampilan(int baris, int kolom, int matriks[100][100]){
	
	int a=0;
    int b=0;
	
	printf("===============================================\n");
	printf("=             Program MiniSweeper              =\n");
	printf("==============================================\n");
	
    printf(" y\\x");
    while(b<baris){
        if(b<9){
			printf("_%i__",b+1);
		}else{
		printf("%i__",b+1);
		}
        b=b+1;
    }
    printf("\n");
	while(a<kolom){
    b=0;
        if(a<9){
			printf(" %i",a+1);
		}else{
			printf("%i",a+1);
		}
        while(b<kolom){
			printf(" | %i",matriks[a][b]);b=b+1;
		}
        printf(" |\n");
        a=a+1;
    }
    printf("\n");
}

void penaruhbom(int matriks[100][100], int baris, int kolom, int bom_matriks[100][100], int pilihan){
	
	int i, j, bom;
	
	srand((unsigned)time(NULL));
	
	if  (pilihan == 1){
		bom = 3;
	}else if(pilihan == 2){
		bom = 15;
	}else if (pilihan == 3){
		bom = 29;
	}else if (pilihan == 4){
		printf("Ket : Jumlah bom yang dimasukkan, bukan berarti semua jumlah tersebut akan ada dalam tabel.\n");
		printf("      Maksimal bom yang dimasukkan adalah 98\n");
	ulang:	
		printf("Jumlah : ");scanf("%d", &bom);
		if (bom > 98){
			printf("\nKet : Anda telah melebihi batas maksimal. Silahkan masukkan ulang\n");
			goto ulang;
		}
	}
	
	for (i=1;i<=bom;i++){
		int row = (rand() % i);
		int col = (rand() % i);
		bom_matriks[row][col] = 9;
	}	
}

void klik(int y, int x, int matriks[100][100], int bom_matriks[100][100], int baris, int kolom){
	
	 // Y = Baris
	 // X = Kolom
	
	int i,j;
	
	y = y-1;
	x = x-1;
	

	for(i=0;i<=y;i++){
		for(j=0;j<=x;j++){
			if (bom_matriks[i][j]==9){
				if (y==i && x==(j-1) || y==(i-1) && x==j || y==i && x==(j+1) || y==(i+1) && x==j){
					matriks[y][x] = 4;
				}else if(y == i || x == j){
					matriks[y][x] = 3;
				}else if(y && x != i && j){
					matriks[y][x] = 2;
				}
			}
		}
	}
}

void flag(int y,int x, int matriks[100][100], int bom_matriks[100][100], int baris, int kolom, int jumlah_dimatikan[100], int opsi){
	
	x = x-1;
	y = y-1;
	 
	int i=1;
	
	int status = 0;
	 
	if (opsi == 2){
		if (bom_matriks[y][x] == 9){
			matriks[y][x] = 7;
			while(status == 0){
				if (jumlah_dimatikan[i]>0){
					i++;
				}else{
					jumlah_dimatikan[i]= 1;
					status = 1;
				}
			}
			
		}else {
		matriks[y][x] = 7;
		}
    }
	if(opsi == 3){
		matriks[y][x] = 0;
	}
	
	system("cls");
	
}

void pengenalan(){
	
	printf("================================================================\n");
	printf("=             Program MiniSweeper                              =\n");
	printf("================================================================\n");	
	printf("                        Penjelasan                         \n");
	printf("Tujuan :untuk membersihkan lahan permainan tanpa mengenai bom");
	printf("\nCara bermain : klik dengan masukkan baris dan kolom yang\n"); 
	printf("sesuai dengan tabel tersebut\n");
	
	printf("\nJika merasa di posisi tersebut ada sebuah bomb, maka letakkan\n");
	printf("sebuah flag yaitu angka 7 untuk mengamankan.\n");
	
	printf("\nUntuk mengetahui posisi bom dengan lihat angka yang muncul setelah\n");
	printf("klik, yaitu: \n");
	printf("4 = posisi tersebut sangat dekat dengan bom\n");
	printf("3 = posisi tersebut berada di baris atau kolom bom yang sama\n");
	printf("2 = posisi tersebut sangat aman\n");
	
	printf("\nAnda menang jika berhasil flag semua posisi bom dan tabel tersebut\n");
	printf("tidak ada angka 0\n");
}

int main(){
	
	int i,j, matriks[100][100], bom_matriks[100][100], pilihan;
	int baris, kolom;
	int opsi;
	int jumlah_bom;	
	int x, y;
	int jumlah_dimatikan[100], hasil_cek_status;
	int pilihan1, pilihan_t;

restart:
	
	system("cls");
	
	proses_restart(matriks, bom_matriks, jumlah_dimatikan);
	
	pengenalan();
	
	printf("\nPilih levelnya :\n");
	printf("1. Pemula\n");
	printf("2. Menengah\n");
	printf("3. Master\n");
	printf("4. Kustom\n");
	printf("Level : ");
	scanf("%d", &pilihan);
	
	system("cls");
	
	if (pilihan == 1){
		baris = 3;
		kolom = 3;
	}else if (pilihan == 2){
		baris = 16;
		kolom = 16;
	}else if(pilihan == 3){
		baris = 30;
		kolom = 30;
	}else if(pilihan== 4){
		printf("Ket : Maksimal baris dan kolom adalah 99\n");
	ulang:	
		printf("Baris : ");scanf("%d",&baris);
		printf("Kolom : ");scanf("%d",&kolom);
		if (baris && kolom > 99){
			printf("\nKet : Anda telah melebihi batas maksimal. Silahkan masukkan ulang\n");
			goto ulang;
		}
	}
	
	penaruhbom(matriks, baris, kolom, bom_matriks, pilihan);
	cek_jumlahbom(bom_matriks, baris, kolom);
	jumlah_bom = cek_jumlahbom(bom_matriks, baris, kolom);

tampilan:
	
    tampilan(baris, kolom, matriks);
	
	printf("\nJumlah Bom = %d\n", jumlah_bom);
	printf("\nPilihan : 1.Klik, 2.Flag, 3.Cabut Flag, 4.Stop\n");
	printf("Pilihan : ");scanf("%d",&opsi);
    
	if (opsi==1){
	ulang_klik:	
		printf("Y : ");scanf("%d", &y); //Y = Baris
		printf("X : ");scanf("%d", &x); //X = Kolom
		if (y < 0 || x < 0 || y > baris || x > kolom){
			printf("\nKet : Maaf, jumlah yang dinputkan melebih dari yang dibataskan oleh baris dan kolom\n");
			printf("Silahkan masukkan ulang\n");			
			goto ulang_klik;
		}
		
		if (matriks[y-1][x-1] == 7){
			system("cls");
			printf("Ket : Maaf anda harus cabut flag di posisi tersebut untuk bisa klik\n");
		}else if(bom_matriks[y-1][x-1]==9){
			
			printf("\nKet : Anda telah nyalakan sebuah bom\n");
			printf("Apakah ingin ulang?\n");
			printf("1. Ya\n");
			printf("2. Tidak\n");
			scanf("%d", &pilihan1);
			
			if(pilihan1 == 1){
				goto restart;
			}else{
				printf("\nTerima kasih telah bermain");
				exit(0);
			}
		}else{
			klik(y,x, matriks, bom_matriks, baris, kolom);
			system("cls");
		}
	}else if(opsi == 2){
	ulang_flag:	
		printf("Y : ");scanf("%d", &y); //Y = Baris
		printf("X : ");scanf("%d", &x); //X = Kolom
		if (y < 0 || x < 0 || y > baris || x > kolom){
			printf("\nKet : Maaf, jumlah yang dinputkan melebih dari yang dibataskan oleh baris dan kolom\n");
			printf("Silahkan masukkan ulang\n");			
			goto ulang_flag;
		}
		if (matriks[y-1][x-1]==7){
			system("cls");
			printf("Maaf, tujuan yang anda ingin flag, sudah tertandai flag\n");
			goto tampilan;
		}else{
			flag(y,x, matriks, bom_matriks, baris, kolom, jumlah_dimatikan, opsi);
		}
	}else if(opsi == 3){
	ulang_flag1:	
		printf("Y : ");scanf("%d", &y); //Y = Baris
		printf("X : ");scanf("%d", &x); //X = Kolom
		if (y < 0 || x < 0 || y > baris || x > kolom){
			printf("\nKet : Maaf, jumlah yang dinputkan melebih dari yang dibataskan oleh baris dan kolom\n");
			printf("Silahkan masukkan ulang\n");
			goto ulang_flag1;
		}
		if (matriks[y-1][x-1]!=7){
			system("cls");
			printf("Maaf, tujuan yang anda ingin cabut, tidak terdapat flag\n");
			goto tampilan;
		}else{
			flag(y,x, matriks, bom_matriks, baris, kolom, jumlah_dimatikan, opsi);
		}
	}else if(opsi == 4){
		printf("\nProgram Telah Berhenti\n");
		exit(0);
	}
	
	cek_status (jumlah_dimatikan, matriks, baris, kolom, jumlah_bom);
	hasil_cek_status = cek_status (jumlah_dimatikan, matriks, baris, kolom, jumlah_bom);
	
	if (hasil_cek_status == 1){
		printf("Congratulation, Anda menang!!\n");
		printf("\nApakah ingin ulang?\n");
		printf("1. Ya\n");
		printf("2. Tidak\n");
		printf("Pilihan : ");
		scanf("%d", &pilihan_t);
		if(pilihan_t == 1){
			goto restart;
		}else{
			printf("\nTerima Kasih telah bermain");
			exit(0);
		}
	}else{
		goto tampilan;
	}
	
}

int cek_jumlahbom(int bom_matriks[100][100], int baris, int kolom){
	
	int i,j,hasil;
	
	hasil = 0;
	
	for(i=0;i<=baris;i++){
		for(j=0;j<=kolom;j++){
			if (bom_matriks[i][j] > 0){
				hasil = hasil + 1;
			}
		}
	}
	
	return(hasil);	
}



int cek_status (int jumlah_dimatikan[100], int matriks[100][100], int baris, int kolom, int jumlah_bom){
	
	int i,j, nampung,nampung1, status;
	
	nampung = 0;
	nampung1 = 0;
	status = 0;
	
	
	for(i=0;i<=jumlah_bom;i++){
		nampung = nampung + jumlah_dimatikan[i];	
	}
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			if (matriks[i][j] == 0){
				status = 1;
			}
		}
	}	
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			if (matriks[i][j] == 7){
				nampung1 = nampung1 + 1;
			}
		}
	}	
	
	if (nampung1 > jumlah_bom){
		status = 1;
	}
	
	if (status == 0 && nampung == jumlah_bom){
		return(1);
	}else{
		return(0);
	}
	
}
