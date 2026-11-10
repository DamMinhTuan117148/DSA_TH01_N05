#include<stdio.h>
#include<stdlib.h>
int main(){
	printf("Nhap vao so n can nhap\n");
	int n ;
	scanf("%d",&n);
	float *arr = (float *) malloc ( n * sizeof(float));
	if( (*arr) == NULL){
		printf("Mang khong co phan tu");
		return 1;
	}
	else{
		for(int i = 0 ; i < n; i++){
		scanf("%f",&(arr[i]));	
		}
	
		for(int i = 0 ; i < n ;i++){
			printf("%f ", arr[i]);
		}
	
	}
	free(arr);
	return 0;
	
}
