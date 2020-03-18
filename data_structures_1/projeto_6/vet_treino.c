/* Escolher, para cada classe, 25 vetores treino aleatorios, calcular a media e o vetor final caracteristico da classe */
    double vet_treino_grama[numero_de_imagens/4][qtd_neurons+1];
    double vet_teste_grama[numero_de_imagens/4][qtd_neurons+1];

  //CRIACAO ARRAY AUXILIAR COM NUMEROS ALEATORIOS DE 0 À 49.
      int array[numero_de_imagens/2];
        for(int i=0; i<numero_de_imagens/2; i++){
        array[i] = i; //fill the array from 0 up to 49 -> 50 numbers
    //printf("%d\n", array[i]);
    }

      for(int i=0; i<numero_de_imagens/2; i++){
          int temp = array[i];
          int random_index = rand() % (numero_de_imagens/2); //random number from 0 up to 49

          //printf("%d\n", random_index);
          array[i] = array[random_index];
          array[random_index] = temp;
        }
          //FIM DO ARRAY AUXILIAR

for(int i=0; i<(numero_de_imagens/4); i++){//pegar 25 de grama aleatorios p treino
  for(int j=0; j<qtd_neurons+1; j++){
    vet_treino_grama[i][j] = vetores_normalizados[array[i]][j];//linha array[i] e um nuemro aleatorio de 0 a 49
  }
}//end for pegar 25 de grama aleatorios p treino
for(int i=0; i<(numero_de_imagens/4); i++){//pegar 25 de asfalto aleatorios p treino
  for(int j=0; j<qtd_neurons+1; j++){
    vet_treino_asfalto[i][j] = vetores_normalizados[array[i+(numero_de_imagens/4)]+(numero_de_imagens/2)][j];//linha array[i+(numero_de_imagens/4)]+(numero_de_imagens/2) e um numero aleatorio de 50 a 99
  }
}//end for pegar 25 de asfalto aleatorios p treino

  for(int i=0; i<numero_de_imagens; i++){
    for(int j=0; j<qtd_neurons+1; j++){
      if(i<(numero_de_imagens/2)){
        vet_treino_grama[i][j] = vetores_normalizados[array[i]][j-1]
      }//preenche treino grama
      else{
        vet_treino_asfalto[i][j] = vetores_normalizados[array[i-(numero_de_imagens/2)]+(numero_de_imagens/2 )][j-1]
      }//preenche treino asfalto
    }
  }
