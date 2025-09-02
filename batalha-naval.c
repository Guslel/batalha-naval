#include <stdio.h>


int main() {
  //demarcações verticais
  char linha = 'A';
  for (int i = 0; i <=9 ; i++){ 
    // Ajuste do espaço do primeiro item
    if(i == 0) {
      printf("    ");
    }

    //contúdo
    printf("%c   ", linha);
    ++linha;
    
    //quebra de linha do último item
    if(i == 9) {
      printf("\n");
    }
  }
  printf("\n");
  
  //1. Criando uma matriz 10x10
  int tabuleiro[10][10];
  for (int i = 0; i <= 9; i++){
    //demarcações horizontais
    if(i == 9) {
      printf("%d  ", i+1);
    }else {
      printf("%d   ", i+1);
    }
    
    //conteúdo do tabuleiro
    for (size_t j = 0; j <= 9; j++){
      //cadastro navios
      if((i == 2 && (j >= 3 && j <= 5)) || (j == 7 && (i >= 5 && i <= 7))) {
        tabuleiro[i][j] = 3;
      }else {
        //cadastro "mar"
        tabuleiro[i][j] = 0;
      }
      
      printf("%d   ", tabuleiro[i][j]);
    }

    printf("\n");
  }
}