#include <cstdio>
#include <iostream>
#include <list>
using namespace std;

class Intervalo{
public:
    int inicio, fim;
};

int main() {
    int N, C, qtd;
    bool trocaIt;
    Intervalo aux;
    list<Intervalo> ints;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> C;
        qtd = C;
        for(int j = 0; j < C; j++){//inicializa lista
            cin >> aux.inicio >> aux.fim;
            ints.push_back(aux);
        }

        for(list<Intervalo>::iterator it = ints.begin(); it != ints.end() && qtd > 1; ++it){//esse qtd > 1 é uma otimizacao, o numero minimo de intervalos é 1
            trocaIt = false;
            for(list<Intervalo>::iterator jt = ints.begin(); jt != ints.end() && qtd > 1; ++jt){
                if(jt != it){
                    if(jt->inicio <= (it->fim + 1) && jt->fim >= (it->inicio - 1)){
                        if((jt->inicio >= it->inicio && jt->fim <= it->fim)){//um it contem jt
                            jt = ints.erase(jt);
                            jt--;
                            qtd--;
                            trocaIt = true;
                        }
                        else{//estende o intervalo pois ele nao esta totalmente dentro do outro
                            it->fim = max(jt->fim, it->fim);
                            it->inicio = min(jt->inicio, it->inicio);
                            jt = ints.erase(jt);
                            jt--;
                            qtd--;
                            trocaIt = true;
                        }
                    }
                }
            }
            if(trocaIt)
                it = ints.begin();            
        }

        cout << qtd << endl;
        ints.clear();
    }

	return 0;
}