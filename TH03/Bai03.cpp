#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct    {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}Data;
typedef struct tagNode    {
    	Data infor; // luu thong tin cua sinh vien
    	struct tagNode *link; // luu thong cua node ke tiep
}Node;
typedef struct    {
    	Node *pHead;  // luu dia chi dau
    	Node *pTail; // Luu dia chi cuoi
    	int spt;
}LList;
/////////////////////////////////////
void initList(LList *L) // Khoi tao danh sach cua cac node
    {
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->spt = 0;
    }
/////////////////////////////////////
int emptyList(LList L)
 {
    	return (L.spt == 0); 
}
/////////////////////////////////////
void insert_Head(LList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp; // cho danh sach dia chi cua ca dau va cuoi
    			L->pTail = pp;
    		}  	
        else {
    		pp->link = L->pHead; // cap nhat dia chi cua node tiep theo la dia chi cua dau
    		L->pHead = pp;// cap nhat lai dia chi pHead
    		}
    	L->spt++;
    }
///////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ma hoten: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(LList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor); //in d? li?u trong node 
        	pp = pp->link;// dia chi cua node tiep theo
    	}
}
/////////////////////////////////////////
void insert_Custom(LList *L ,Node *q,Data x){
	Node *pp;
	pp = (Node *) malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if(emptyList(*L)){
		L->pHead = pp;
		L->pTail = pp;
	}
	else{
		pp->link = q->link; // dia chi tiep theo cua pp la dia chi tiep theo cua q(pp va q cung chi mot noi)
		q->link = pp; // dia chi tiep theo q la dia chi cua p
		
	}
	L->spt++;
}
Node* searchNode(LList L,char name[30]){
	Node *pp = L.pHead;
	while(pp != NULL && !strstr(pp->infor.hoten,name)){
		pp = pp->link;
	}
	return pp;
}
////////////////////////////////////////////////
void insert_Tail(LList *L ,Data x){
	Node *pp;
	pp = (Node *) malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if(emptyList(*L)){
		L->pHead = pp;
		L->pTail = pp;
	}
	else{
		L->pTail -> link = pp; // dia chi tiep theo cua node pTail la pp 
		L->pTail = pp;// cap nhat dia chi pTail trong danh sach thanh node cuoi cung cua hien tai
	}
	L->spt++;
}

////////////////////////////////////////////////
void chen_tang(LList *L,Data x){
	Node *pp = L->pHead,*q;
	while(pp != NULL && pp->infor.masv <x.masv){
		q = pp;
		pp = pp -> link;
	}
	if(pp == L->pHead){
		insert_Head(L,x);
	}
	else{
		insert_Custom(L,q,x);
	}
}
////////////////////////////////////////////////
void tach(LList L , LList *L1, LList *L2){
	initList(L1);// khoi tao danh sach
	initList(L2);
	Node *pp = L.pHead;
	while(pp != NULL){
		if(pp->infor.d1 < 8){
			insert_Head(L1,pp->infor);
		}
		else{
			insert_Head(L2,pp->infor);
		}
		pp = pp->link;
	}
}
////////////////////////////////////////////////
void ghep(LList L1,LList L2,LList *L){
	initList(L);
	Node *p1 = L1.pHead;
	Node *p2 = L2.pHead;
	if(L1.spt < L2.spt){
		while(p1 != NULL){
			insert_Head(L,p1->infor);
			insert_Head(L,p2->infor);
			p1=p1->link;
			p2=p2->link;
		}
	}
}
////////////////////////////////////////////////
void del_Head(LList *L){
	Node* pp;
	if(emptyList(*L)){
		return;
	}
	else{
		pp = L->pHead;
		L->pHead = pp->link;
		free(pp);
		L->spt--;
		if(L->pHead==NULL){
			L->pTail = NULL;
		}
	}
}
////////////////////////////////////////////////
void del_After(LList *L, Node *q){
	Node *pp;
	if(NULL == q){
		return;
	}
	else{
		pp = q->link;
		if(q->link == L->pTail){
			L->pTail = q;
			q->link = pp->link;
			free(pp);
			L->spt--;
		}
	}
}
int main(){
    LList L;
	int kt = 0;
	Data x;
	initList(&L); //tao ra 1 ds rong
	LList L1,L2;
	char name[30];
	scanf("%s",name);
	Node *q;
	q = (Node *) malloc(sizeof(Node));
	q = searchNode(L,name);	
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
	    printf("\n4: Them nut tang vao trong danh sach");
	    printf("\n5: Tach danh sach thanh nhieu danh sach");
	    printf("\n6: Ghep cac danh sach  thanh mot danh sach");
	    printf("\n7: Xoa node danh sach dau ");
	    printf("\n8: Xoa node tu chon sau");
	    printf("\n9: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1: 
	            printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Tail(&L, x);
            	break;
            case 3:
	           	printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            printf("Nhap thong tin nut ho ten node them vao sau\n");
	            if(x.masv > 0) 
                	insert_Custom(&L,q, x);
            	break;
            case 4:
            	printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            chen_tang(&L,x);
	            break;
	        case 5:
	        	printf("Tach mot danh sach thanh hai danh sach\n");
					        	
	        	tach(L,&L1,&L2);
	        case 6:
	        	printf("Ghep mot danh sach thanh hai danh sach\n");

	        	ghep(L1,L2,&L);
	        case 7:
	        	printf("Xoa node dau cua danh sach\n");
	        	del_Head(&L);
	        case 8:
	        	printf("Xoa node tu chon cua danh sach\n");
	        	del_After(&L,q);
            case 9:	 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
}




