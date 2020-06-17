#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_M 100
#define MAX_N 100
typedef struct {
	int m, n;
	int A[MAX_M][MAX_N];
	int r, c;
} State;
// LEE DA VIET CAI CODE NAY :)
// https://www.facebook.com/leephan2001
void print_state(State S){
	int i,j;
	for(i=0;i<S.m;i++){
		for(j=0;j<S.n;j++){
			if(j == 0 && S.m == 3) printf("----------------\n");
			if(j == 0 && S.m == 4) printf("---------------------\n");
			if(j == 0 && S.m == 5) printf("-------------------------\n");
			if(S.A[i][j] != S.A[S.r][S.c]){
				printf("|%2.d |", S.A[i][j]);
			}
			else{
				printf("|   |");
			}
		}
		printf("\n");
	}
    printf("\n[%d] [%d]", S.r, S.c);	
}
int is_finished(State S){
	int i,j,flag=1;
	for(i=0;i<S.m;i++){
		for(j=0;j<S.n;j++){
			if(S.A[i][j] != i*(S.n) +j+1 ){
				flag =0;
				break;
			}
		}
		if(flag == 0) break;
	}
	if(flag == 1 ) return 1;
	else return 0;
}
int up(State S, State *N ){
	*N=S;
	int temp;
	int i,j;
	if(S.r != 0){
		temp = N->A[S.r][S.c];
		N->A[S.r][S.c] = N->A[S.r-1][S.c];
		N->A[S.r-1][S.c] = temp;
		(char)N->A[S.r-1][S.c];
		N->r = S.r-1;
		return 1;
	}else return 0;
}
int down(State S, State *N){
	*N=S;
	int temp;
	if (S.r <= S.m-2 ){
		temp = N->A[S.r][S.c];
		N->A[S.r][S.c] = N->A[S.r+1][S.c];
		N->A[S.r+1][S.c] = temp;
		N->r = S.r+1;
		return 1;
	}else return 0;
}
int left(State S, State *N){
	*N=S;
	int temp;
	if (S.c != 0 ){
		temp = N->A[S.r][S.c];
		N->A[S.r][S.c] = N->A[S.r][S.c-1];
		N->A[S.r][S.c-1] = temp;
		N->c = S.c-1;
		return 1;
	}else return 0;
}
int right(State S, State *N){
	*N=S;
	int temp;
	if (S.c != S.n-1 ){
		temp = N->A[S.r][S.c];
		N->A[S.r][S.c] = N->A[S.r][S.c+1];
		N->A[S.r][S.c+1] = temp;
		N->c = S.c+1;
		return 1;
	}else return 0;
}
void generate(State *S, int choice){
	int i,j;
	int mau1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int mau2[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int mau3[5][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	int indexR, indexC;
	srand(time(NULL));
	if(choice == 1){
		S->m=3;
		S->n=3;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			indexR = rand()%9;
			indexC = rand()%9;
			while(indexR = indexR){
				indexR = rand()%9;
			}
			int tmp = mau1[i][j];
			mau1[i][j] = mau1[indexR][indexC];
			mau1[indexR][indexC] = tmp;
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				S->A[i][j] = mau1[i][j];
			}
		}
	}	
	if(choice == 2){
		S->m=4;
		S->n=4;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			indexR = rand()%4;
			indexC = rand()%4;
			int tmp = mau2[i][j];
			mau2[i][j] = mau2[indexR][indexC];
			mau2[indexR][indexC] = tmp;
			}
		}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				S->A[i][j] = mau2[i][j];
			}
		}
	}
	if(choice == 3){
		S->m=5;
		S->n=5;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			indexR = rand()%5;
			indexC = rand()%5;
			int tmp = mau3[i][j];
			mau3[i][j] = mau3[indexR][indexC];
			mau3[indexR][indexC] = tmp;
			}
		}
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				S->A[i][j] = mau3[i][j];
			}
		}
	}
	S->r = 0;
	S->c = 1;
}
int main(){
	int i,j;
	State S,N;
	char cmd[50];
	int choice;
	printf("Source code: fb.com/leephan2001\n");
	printf("TRO CHOI DAY O THEO DE SAP XEP TANG DAN\n");
	printf("\nNHAP MUC DO KHO: 1,2,3\n");
	printf("1 Nao~ be': ma tran 3x3 \n");
	printf("2 Nao~ vua`vua`: ma tran 4x4 \n");
	printf("3 Nao~ ballte vs Einstein: ma tran 5x5 \n");
	while(1){
		scanf("%d", &choice);
		if(choice > 3 || choice < 1) printf("nhap lai dum di Ahihi :) !\n");
		if(choice >= 1 && choice <=3) break;
	}
	generate(&S,choice);
	print_state(S);
	printf("\n");
	printf("\n");
	// thong tin huong dan.
	printf("--- DOC KI HUONG DAN TRUOC KHI SU DUNG ---\n");
	printf("Go~: 'UP' de chuyen .. di len\n");
	printf("Go~: 'DOWN' de chuyen .. di xuong\n");
	printf("Go~: 'RIGHT' de chuyen .. sang phai\n");
	printf("Go~: 'LEFT' de chuyen .. sang trai\n");
	printf("Go~: 'EXIT' neu thay bat luc ~.~ :)\n");
	printf("Illegal move: Di chuyen khong hop le!\n");
	printf("Unknown command: Day la dau? Ban la ai?\n");
	fflush(stdin);
	while(is_finished(S) != 1){
		//Doc lenh Len, Xuong, Qua Trai, Qua Phai
		fgets(cmd,50,stdin);
		if(cmd[strlen(cmd)-1] == '\n'){
		cmd[strlen(cmd)-1] = '\0';
		}
		//Kiem tra lenh up,down,right,left,exit
		if(strcmp(cmd,"UP") == 0){
			if(up(S,&N) == 1){
				S=N;
				print_state(S);
				printf("\n\n");
			}
			else{
				printf("Illegal move\n");
				print_state(S);
				printf("\n\n");
			}	
		}
		if(strcmp(cmd,"DOWN") == 0){
			if(down(S,&N) == 1){
				S=N;
				print_state(S);
				printf("\n\n");
			}
			else{
				printf("Illegal move\n");
				print_state(S);
				printf("\n\n");
				
			}	
		}
		if(strcmp(cmd,"LEFT") == 0){
			if(left(S,&N) == 1){
				S=N;
				print_state(S);
				printf("\n\n");
			}
			else{
				printf("Illegal move\n");
				print_state(S);
				printf("\n\n");
			}	
		}
		if(strcmp(cmd,"RIGHT") == 0){
			if(right(S,&N) == 1){
				S=N;
				print_state(S);
				printf("\n\n");
			}
			else{
				printf("Illegal move\n");
				print_state(S);
				printf("\n\n");
			}	
		}
		if(strcmp(cmd,"EXIT") == 0){
				printf("You lose!\n");
				break;
		}
		if(strcmp(cmd,"UP") != 0 && strcmp(cmd,"DOWN") != 0 && strcmp(cmd,"LEFT") !=0 && strcmp(cmd,"RIGHT") != 0 && strcmp(cmd,"EXIT") != 0){
			printf("Unknown command\n");
		}
		if(is_finished(S) == 1) printf("You win!");	
	}
return 0;
}

