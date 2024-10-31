#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Menambahkan variabel dengan struct
struct node {
	int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void hapusAwal(node **head);
void hapusData(node **head);
void totalData(node **head);
void totalValue(node **head);
void cariData(node **head);
void tranverse(node *head);


//Data utama
int main() {
  node *head; //kepala dari linked list
  char pilih; //untuk memasukan pilihannya

  head = NULL;
  do{
     system("cls");
     printf("=================//========================\n");
     printf("Masukkan Apa Yang Ingin Tambahkan\n");
     printf("1. Tambah data diawal\n");
     printf("2. Tambah data ditengah list\n");
     printf("3. Hapus data diawal\n");
     printf("4. Hapus data ditengah list\n");
     printf("5. Total jumlah data\n");
     printf("6. Total value link list\n");
     printf("7. Mencari data didalam link list\n");
     printf("8. cetak isi list\n");
     printf("MASUKKAN PILIHAN (tekan q untuk logout) : ");
     fflush(stdin); scanf("%c", &pilih);
     if (pilih == '1')
     		tambahAwal(&head);
     else if (pilih == '2')
			tambahData(&head);
	 else if (pilih == '3')
			hapusAwal(&head);
	 else if (pilih == '4')
			hapusData(&head);
	 else if (pilih == '5')
			totalData(&head);
	 else if (pilih == '6')
			totalValue(&head);
	 else if (pilih == '7')
			cariData(&head);
     else if (pilih == '8'){
     		tranverse(head);
            getch();
     }
  } while (pilih != 'q');
  
  return 0;
}

//Menambah linked list diawal/akhir
void tambahAwal(node **head){
    int bil;
    node *pList = (node *)malloc(sizeof(node));
    node *temp = *head;

    system("cls"); // unutuk membersikan layar terminal dari semua output sebelum
    fflush(stdin); //menghapus input buffer input/output
    printf("Masukkan bilangan : ");
    fflush(stdin); scanf("%d", &bil);

    pList->data = bil; // Tetapkan nilai input ke node baru

    if (*head == NULL) { // Jika daftar kosong
        *head = pList; // Node baru menjadi kepala
        pList->next = *head; // Pointer ke dirinya sendiri (melengkung)
    } else {
        while (temp->next != *head) { // *temp untuk node akhir
            temp = temp->next;
        }
        temp->next = pList; // Node terakhir mengarah ke node baru
        pList->next = *head; // Node baru mengarah ke kepala
        *head = pList; // Perbarui kepala ke node baru
    }
}
    
//Menambah data ditengah
void tambahData(node **head){
    int pos, bil;
    node *pCur = *head;
    node *pList = (node *)malloc(sizeof(node));
    
    
    system("cls");
    tranverse(*head); //menampilkan linked lisst yang telah dimasukan
    printf("\nLetak penyisipan setelah data bernilai: ");
    fflush(stdin); scanf("%d", &pos); //menyimpan posisi target
    printf("Masukkan bilangan: ");
    fflush(stdin); scanf("%d", &bil);
    
    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->next;
    }
    
    if (pCur == NULL){
		printf("\nnode tidak ditemukan");
		getch();
	} else if (pList == NULL){
	    printf("\nalokasi memeori gagal");
	    getch();
    } else {
        // Menyisipkan node baru pada posisi yang diinginkan
        pList->data = bil; // Masukkan data ke dalam node baru
        pList->next = pCur->next; // Menghubungkan node baru
        pCur->next = pList; // Menyambungkan node sebelumnya dengan node baru
        printf("\nData berhasil ditambahkan di urutan ke-%d.\n", pos);
    }
}

//Menghapuskan data awal
void hapusAwal(node **head) {
	node *pCur, *pTemp;
	
	if (*head == NULL) { // pemeriksaan list kosong
      printf("List kosong, tidak ada yang dihapus.\n"); 
	  getch();
      return;
    }
    
	system("cls");
    tranverse(*head);
    
    pCur = *head; // memasukan pointer ke node pertama
    pTemp = *head; //untuk list akhir
    
    while (pTemp->next != *head) {
        pTemp = pTemp->next;
    }

    pTemp->next = pCur->next;
    *head = pCur -> next;
    free(pCur);
    printf("\nData telah dihapus!"); 
	getch();
	
}

// Hapus data di tengah
void hapusData(node **head) {
    int pos;
    node *pPrev = NULL;
    node *pCur = *head;
    node *pTemp = *head;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan data yang bernilai: ");
    fflush(stdin); 
    scanf("%d", &pos);
    

    while (pCur != NULL && pCur->data != pos) {
        pPrev = pCur; // Simpan pointer ke node sebelumnya
        pCur = pCur->next; // pCur berjalan
    }
    
    if (pCur == NULL) {
        printf("\nData tidak ditemukan!");
        getch();
        return;
    }
    // Jika pCur adalah head
    if (pCur == *head) {
    	while (pTemp->next != *head) {
            pTemp = pTemp->next;
        }
        *head = pCur->next; //menggeser kepala
        pTemp->next = *head; //menggeser akhir kekepala
    } else {
        pPrev->next = pCur->next; // Menghapus node di tengah
    }

    free(pCur); // Menghapus node yang ditemukan
    printf("\nData telah dihapus!"); 
    getch();
}

//Total data yang dimiliki
void totalData(node **head) {
	int count = 0;
	node *pWalker = *head;
	node *pTemp = *head;
	
	system("cls");
	tranverse(*head);
	
	if (*head == NULL) {
        printf("List kosong, tidak ada data.\n");
        getch();
        return;
    }
    while (pTemp->next != *head) {
        pTemp = pTemp->next;
    }
	
	do {
		count++;
	    pWalker = pWalker->next; // Pindah ke node berikutnya
	} while (pWalker != *head); // Teruskan sampai kembali ke kepala
	
	printf("\nJumlah data dalam linked list: %d\n", count);
    getch();
}

//Total value yang dimiliki
void totalValue(node **head) {
	int total = 0;
	node *pWalker = *head;
	node *pTemp = pWalker;
	
	system("cls");
	tranverse(*head);
	
	if (*head == NULL) {
        printf("List kosong, tidak ada data.\n");
        getch();
        return;
    }
	
	printf("\nData: "); // agar menampilkan data dengan, ex data: 1+2+3+4...
	do {
	    total += pWalker->data; // Tambahkan nilai dari node saat ini ke total
	    printf("%d", pWalker->data);
	    if (pWalker->next != pTemp) {
	        printf(" + ");
	    }
	    pWalker = pWalker->next;
	} while (pWalker != pTemp);
    
	printf("\nJumlah total value linked list: %d\n", total);
    getch();
}

// Mencari data di dalam linked list
void cariData(node **head) {
    int target;
    node *pWalker = *head;
    int found = 0; // mencari data

    system("cls");
    printf("Masukkan nilai yang ingin dicari: ");
    fflush(stdin);
    scanf("%d", &target);
    
    if (*head == NULL) {
        printf("List kosong, tidak ada data.\n");
        getch();
        return;
    }
    do {
        if (pWalker->data == target) {
            found = 1; // Tandai bahwa data ditemukan
            break; // Hentikan pencarian
        }
        pWalker = pWalker->next; // Pindah ke node berikutnya
    } while (pWalker != *head);

    if (found) {
        printf("Data %d ditemukan dalam linked list.\n", target);
    } else {
        printf("Data %d tidak ditemukan dalam linked list.\n", target);
    }
    getch();
}


//Menampilkan linked list
void tranverse(node *head) {
    node *pWalker;
    
    system("cls");
    pWalker = head;
    
    if (head == NULL) { // Cek jika daftar kosong
        printf("NULL\n");
        return;
    }
    
    // menggunakan do agar data terus tercetak tanpa ada persayaratan
    do {
	    printf("%d -> ", pWalker->data); // Cetak data
	    pWalker = pWalker->next; // Pindah ke node berikutnya
	} while (pWalker != head); // Teruskan sampai kembali ke kepala
    
    printf("\nkembali kenilai awal: %d\n", head->data);
}
