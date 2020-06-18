#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
typedef struct{
	char state[10];
}may;
void input(char player[10]){
	while(1){
		fgets(player,10,stdin);
		if(player[strlen(player)-1] == '\n'){
		player[strlen(player)-1] = '\0';
		}
		if(strcmp(player,"Keo") != 0 && strcmp(player,"Bua") != 0 && strcmp(player,"Bao") != 0 ){
			printf("Nhap khong dung quy dinh! Nhap lai!\n");
		}
		if(strcmp(player,"Keo") == 0 || strcmp(player,"Bua") == 0 || strcmp(player,"Bao") == 0 ){
			break;
		}
	}
}
void Compare(char player[10], char compare[10], may *computer){
	strcpy(compare,computer[rand()%3].state);
	if( strcmp(player,compare) == 0){
			 printf("May tinh ra: %s\n", compare);
			 printf("HOA`");
	}else{
		if( strcmp(compare,"Bao") == 0 && strcmp(player,"Keo") == 0 ){
			printf("May tinh ra: %s\n", compare);
			printf("Thang roi do! Chiu chua :> ");
		}
		if( strcmp(compare,"Bao") == 0 && strcmp(player,"Bua") == 0 ){
			printf("May tinh ra: %s\n", compare);
			printf("Thua roi, ahuhu do ngok! :< ");
		}
		if( strcmp(compare,"Bua") == 0 && strcmp(player,"Bao") == 0 ){
			printf("May tinh ra: %s\n", compare);
			printf("Thang roi do! Chiu chua :> ");
		}
		if( strcmp(compare,"Bua") == 0 && strcmp(player,"Keo") == 0 ){
			printf("May tinh ra: %s\n", compare);
			printf("Thua roi, ahuhu do ngok! :< ");
		}
		if( strcmp(compare,"Keo") == 0 && strcmp(player,"Bua") == 0 ){
			printf("May tinh ra: %s\n", compare);
			printf("Thang roi do! Chiu chua :> ");
		}
		if( strcmp(compare,"Keo") == 0 && strcmp(player,"Bao") == 0 ){
			printf("May tinh ra: %s\n", compare);
			printf("Thua roi, ahuhu do ngok! :< ");
		}
	}
}
int main(){
	printf("Source code: fb.com\\leephan2001 \n \n");
	printf("OANH TU TI VOI MAY TINH : <(\") \n\n");
	srand(time(NULL));
	char player[10];
	may computer[3];
	strcpy(computer[0].state ,"Keo");
	strcpy(computer[1].state ,"Bua");
	strcpy(computer[2].state ,"Bao");
	char compare[10];
	char choice[10];
	while(1){
		printf("Nhap 'Keo', 'Bua' hoac 'Bao': ");
		input(player);
		Compare(player,compare,computer);
		printf("\n\nChoi tiep go~: Yes, thoat thi go~ gi cung duoc \n");
		fgets(choice,10,stdin);
		if(choice[strlen(choice)-1] == '\n'){
		choice[strlen(choice)-1] = '\0';
		}
		if(strcmp(choice,"Yes") != 0) break;
	}
	getch();
return 0;
}

