#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Intervalo{
    public:
        int inicio, fim;
};

int main() {
    int N, C, qtd;
    Intervalo aux;
    vector<Intervalo> ints;
    vector<bool> jaUnidos; //para marcar os conjuntos q ja foram unidos
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> C;
        qtd = C;
        for(int j = 0; j < C; j++){//inicializa vetores
            cin >> aux.inicio >> aux.fim;
            ints.push_back(aux);
            jaUnidos.push_back(false);
        }
        for(int j = 0; j < ints.size() && qtd > 1; j++){//esse qtd > 1 é uma otimizacao, o numero minimo de intervalos é 1
            for(int k = 0; k < ints.size() && qtd > 1; k++){
                if(k != j){
                    if((ints[k].inicio >= ints[j].inicio) && (ints[k].inicio <= (ints[j].fim + 1)) && !jaUnidos[k]){//o inicio esta dentro do ou logo apos o outro intervalo e ainda nao foi unido a outro
                        if((ints[k].fim >= ints[j].inicio && ints[k].fim <= ints[j].fim)){//um intervalo contem o outro
                            if(ints[k].inicio != ints[j].inicio && ints[j].fim != ints[k].fim)//nao une se forem conjuntos iguais
                                ints[k].inicio = ints[j].inicio;
                                ints[k].fim = ints[j].fim;
                                jaUnidos[k] = true;
                                qtd--;
                        }
                        else{//estende o intervalo pois ele nao esta totalmente dentro do outro
                            ints[k].inicio = ints[j].inicio;
                            ints[j].fim = ints[k].fim;
                            jaUnidos[j] = true;
                            jaUnidos[k] = true;
                            qtd--;
                        }
                    }
                }
            }
        }
        cout << qtd << endl;
        jaUnidos.clear();
        ints.clear();
    }
	return 0;
}