UNIVERSIDADE DE BRASILIA - FACULDADE DO GAMA

Estrutura de Dados e Algoritmos - codigo 193704
Turma B - 2/2018
Professor Matheus Mendelson Esteves da Silva

EQUIPE (em ordem alfabetica):
Caio Vinicius Fernandes de Araujo - 170138798
Erick Giffoni - 170141161
Leonardo dos Santos Silva Barreiros - 150135521

TRABALHO 6 - IMPLEMENTACAO DE UMA REDE NEURAL EM LINGUAGEM C PARA CLASSIFICACAO DE IMAGENS NAS CLASSES GRAMA OU ASFALTO

1) GitHub onde se encontra o trabalho : https://github.com/ErickGiffoni/Data_Structures_n_Algorithms/tree/projeto_6/projeto_6

2) Organizacao dos arquivos
  Esse trabalho esta dividido em 4 pastas: lib; projeto2; references; src .
  IMPORTANTE : mantenha a organizacao de pastas proposta para que a execucao do trabalho nao fique comprometida.
  2.1) lib
    Essa e a pasta na qual se encontram a biblioteca feita para a realizacao do trabalho, neuron.h , e a implementacao
      dela, neuron.c .
  2.2) projeto2
    Aqui temos todos os codigos fonte do trabalho 2, bem como a biblioteca dele, e o mais importante: vetores_normalizados.txt ,
      arquivo utilizado pelo codigo do trabalho 6 para ler os resultados das metricas geradas para cada imagem do DataSet. Esse
      arquivo e um dos mais importantes, uma vez que o trabalho 6 nao funciona sem a leitura desse arquivo.
    Vale lembrar que nao e necessario executar o codigo do projeto 2, projeto2.c , para que o trabalho 6 seja executado. Essa
    execucao ja foi feita pela equipe, e os resultados dela estao no vetores_normalizados.txt .
  2.3) references
    Essa pasta apenas guarda as informacoes a respeito do contexto do trabalho 6, que sao o pdf do trabalho, Projeto\ 06.pdf,
      e o pdf da dissertacao de mestrado do professor Matheus, 2018_MatheusMendelsonEstevesdaSilva.pdf , na qual e possivel
      encontrar a base teorica sobre redes neurais feed-foward, que fazem parte do contexto desse trabalho.
  2.4) src
    O codigo fonte desse trabalho, main.c , o codigo de teste, teste.c , bem como os executaveis do trabalho 6 encontram-se
      nessa pasta.

    COMO COMPILAR O TRABALHO 6 :

      $ gcc main.c ../lib/neuron.c -o main

      E de profunda importancia que main.c e ../lib/neuron.c sejam compilados juntos, no formato acima, para o perfeito
        funcionamento do trabalho 6.

    COMO EXECUTAR O TRABALHO 6 :

      $ ./main <numero de neuronios na camada oculta>

      Execute o trabalho conforme o exposto acima e substitua " <numero de neuronios na camada oculta> " por um numero inteiro
      e maior que zero.

3) Contexto do trabalho 6
  Vide pasta references.
