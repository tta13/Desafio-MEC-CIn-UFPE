#include <cstdio>
using namespace std;

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b) == 2){
        int countA = 0, countB = 0;
        if(((2*a) + 2) < b || ((2*b) + 2) < a)
            printf("Impossível encontrar sequencia");
        else{
            while(a != 0 || b != 0){
                int dif = b - a;
                if((dif > 0 || countA == 2) && (countB < 2)){
                    printf("b");
                    b--;
                    countB++;
                    countA = 0;
                }
                else{
                    printf("a");
                    a--;
                    countA++;
                    countB = 0;
                }
            }
        }
        printf("\n");
    }
	return 0;
}