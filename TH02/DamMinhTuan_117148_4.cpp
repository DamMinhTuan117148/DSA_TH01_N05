#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char hoTen[50];
	int ma;
	float diem1,diem2,diem3;
}SV;
typedef struct{
	Node *pHead;
	Node *pTail;
}LList;
typedef struct tagNode{
	SV info;
	struct tagNode *link;
}Node;
int main(){
	int n;
	printf("Nhap vao so luong sinh vien\n");
	scanf("%d" , &n);
	while(getchar() != '\n');
	for(int i = 0 ; i < n ; i ++ ){
		
		
	}
	
}
