- Erick Giffoni
- 170141161
- 02/10/2020

## T1

A estabilidade de um algoritmo de ordenação leva em conta a posição relativa de elementos</br>
de mesmo "valor" dentro de um vetor, por exemplo. Ou seja, antes do vetor ser ordenado,</br>
aqueles elementos de mesmo "valor" (suponha e1, e2) estão posicionados de tal forma que</br>
e1 está em um índice anterior a e2. Após a ordenação pode ser que essa posição relativa entre</br>
e1 e e2 seja mantida, nesse caso o algoritmo é estável. Caso contrário (se e2 aparecer antes de e1)</br>
o algoritmo é dito não estável.

Exemplo usando insertion sort:

```
1 void insertionSort(int *v, int esq, int dir){
2    for(int i=dir; i>esq; i--){
3        if(v[i]<v[i-1]){
4           int tmp = v[i];
5            v[i] = v[i-1];
6            v[i-1] = tmp;
7        }
8    }
9    for(int i=esq+2; i<=dir; i++){
10        int j=i;
11        int tmp = v[j];
12        while(tmp<v[j-1]){
13            v[j] = v[j-1];
14            j--;
15        }
16        v[j] = tmp;
17    }
18 }
```
No algoritmo acima, no laço `for` da linha 2 até a 8, acontecem algumas trocas de posições.</br>
Note que a comparação feita na linha 3 observa se um elemento é menor que outro. Dessa forma</br>
isso é um exemplo em que a estabilidade é mantida no algoritmo de ordenação insertion sort.

## T2

Caso o vetor de entrada tenha a metade de seus elementos sendo negativos e a outra metade como positivos,</br>
a função não retorna o esperado.</br>
Pode-se verificar isso com um vetor assim: 0 1 2 3 4 5 -1 -2 -3 -4 -5.</br>
Nesse caso, o índice retornado é 6, e o vetor fica assim:</br>
0 1 2 3 4 -5 -1 -2 -3 -4 5</br>
O índice 6 é o elemento -1, porém os elementos à esquerda dele não são menores que ele.

Se trocarmos return i por return i-1, o comportamento não é modificado, a não ser pelo índice retornado(i-1).</br>

No último loop `while`, substitua `i<=j` por `i<j`. Assim o problema será corrigido.</br>