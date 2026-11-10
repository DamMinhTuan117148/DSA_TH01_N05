#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char hoTen[50];
	int ma;
	float diem1,diem2,diem3;
}SV;

int main(){
	int n;
	printf("Nhap vao so luong sinh vien cho toi \n");
	scanf("%d",&n);
	while (getchar() != '\n'); // RAT QUAN TRONG vi khi nhap so n se thua \n gay anh huong toi phan nhap ho ten co sau
	SV *pointer = (SV *) malloc( n * sizeof(SV));
	if(pointer == NULL){
		printf("mang khong co phan tu nao ");
		return 1;
	}
	else{
		for(int i = 0 ; i < n ; i ++){	
			SV *pointer2 = pointer + i ;
				printf("Nhap vao lan luot ho ten , ma sinh vien , diem 1, diem 2 , diem 3 cua sinh vien thu %d\n",i+1);
				fgets(pointer2->hoTen,sizeof(pointer2->hoTen),stdin);
				pointer2->hoTen[strcspn(pointer2->hoTen,"\n")] = 0;
				scanf("%d",&pointer2->ma);
				scanf("%f %f %f",&(pointer2->diem1),&(pointer2->diem2),&(pointer2->diem3));
			
		}
		for(int i = 0 ; i < n; i ++){
			SV *pointer2 = pointer + i;
			printf("%s %d %.2f %.2f %.2f",pointer2->hoTen,pointer2->ma,pointer2->diem1,pointer2->diem2,pointer2->diem3);
		}
	}
	free(pointer);
	return 0;
	
}
