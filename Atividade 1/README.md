# Atividade 1

Dado um conjunto de intervalos, determinar a quantidade de intervalos distintos. Supondo os intervalos: (1,3), (2,5) e (7,9) o output esperado seria 2, uma vez que existem 2 conjuntos que são (1,5) e (7,9). 

A entrada está formatada da seguinte maneira: primeiramente, um natural **N** representando o número de casos teste desejados, após isso, os **N casos de teste** seguirão da seguinte forma: um natural **C** representando a quantidade de intervalos seguido de **C pares** de inteiros separados pela barra
de espaço representando o **início e o fim** de cada intervalo, respectivamente. 

## Exemplo

### Input
```
3
4
1 3
4 7
2 5
6 8
3
1 3
7 9
2 5
3
1 5
999 1001
6 998
```
### Output
```
1
2
1
```

## Execução

Para executar, digite em um terminal linux:
```
$ g++ atividade2.cpp -o exec 
$ ./exec
```
