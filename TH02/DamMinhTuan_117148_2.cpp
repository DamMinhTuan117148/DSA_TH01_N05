#include<stdio.h>
#include<stdlib.h>
int main(){
	printf("Nhap vao so n  va mcan nhap\n");
	int n,m;
	scanf("%d %d",&n,&m);
	float **arr = (float **) malloc ( n * sizeof(float) );
	if( (*arr) == NULL){
		printf("Mang khong co phan tu");
		return 1;
	}
	else{
		for(int i = 0 ; i < n ; i ++){
		arr[i] = (float *) malloc (m * sizeof(float));
		}
		for(int i = 0 ; i < n; i++){
			for(int j = 0 ; j < m ; j ++){
				scanf("%f",&arr[i][j]);
			}
		}
	printf("Ma tran cac phan tu la \n");
		for(int i = 0 ; i < n; i++){
			for(int j = 0 ; j < m ; j ++){
				printf("%f ",arr[i][j]);
			}
			printf("\n");
		}
	
	}
	for(int i= 0 ; i < m;i++){
		free(arr[i]);
	}
	free(arr);
	return 0;
	
}
