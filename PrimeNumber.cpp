#include <stdio.h>
// Kiem tra so nguyen to voi do phuc tap O(sqrt(N))
// Kiem tra boi cua so nguyen to co ban 2, 3, 5, 7 co dang 6k+1
int isPrime(int n){ 
	if(n <= 1) return 0;
	if(n <= 3) return 1;
	if(n%2 == 0 || n%3 == 0) return 0;
	for(int i=5;i*i<=n;i=i+6){
		if(n%i == 0 || n%(i+2) == 0){
			return 0;
		}
	}
	return 1;
}
int main() {
	int N;
	scanf("%d", &N);
	if(isPrime(N)) printf("YES");
	else printf("NO");
	return 0;
}
