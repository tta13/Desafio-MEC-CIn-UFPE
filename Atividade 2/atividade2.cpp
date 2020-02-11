#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b) == 2){
        int countA = 0, countB = 0;//usados para contar quantas vezes seguidas escrevi determinado caractere
        if(((2*a) + 2) < b || ((2*b) + 2) < a)//caso o numero de um seja maior que 2 vezes o numero do outro mais 2, é impossivel
            cout << "Impossível encontrar sequencia";
        else{
            while(a != 0 || b != 0){
                int dif = b - a;//computa a diferença entre os dois
                if((dif > 0 || countA == 2) && (countB < 2)){
                    cout << 'b';
                    b--; //diminui a quantidade de b's disponiveis
                    countB++;
                    countA = 0;
                }
                else{
                    cout << 'a';
                    a--; //diminui os a's
                    countA++;
                    countB = 0;
                }
            }
        }
        cout << endl;
    }
	return 0;
}
