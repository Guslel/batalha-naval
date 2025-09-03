#include <stdio.h>

//constantes
#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3 // fiz com 1 pois achei mais fácil a visualização

//funções
void iniciarJogo();
void inicializarTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]);
void imprimirTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]);
void imprimirCoordenadasX();
void adicionarNavio(int tabuleiro[][TAMANHO_TABULEIRO], int linha_inicial, int col_inicial, int tamanho, char orientacao);


int main() {
  iniciarJogo();
  return 0;
}

//função inicial
void iniciarJogo() {
  int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

  //colocar tudo água
  inicializarTabuleiro(tabuleiro);

  //Cadastro de navios
  adicionarNavio(tabuleiro, 6, 8, 3, 'V');
  adicionarNavio(tabuleiro, 4, 4, 3, 'H');
  adicionarNavio(tabuleiro, 8, 1, 3, 'D');
  adicionarNavio(tabuleiro, 6, 6, 3, 'I');
  
  //mostrar tabuleiro
  imprimirTabuleiro(tabuleiro);
}

//tabuleiro inicial com apenas água
void inicializarTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]) {
  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
      tabuleiro[i][j] = AGUA;
    }
  }
}

//função de adicionar navio
void adicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int col_inicial, int tamanho, char orientacao) {
  for (int i = 0; i < tamanho; i++) {
    //coloquei com -1 pra poder definir corretamente a fileira na chamada da função
    int linha_atual = linha_inicial - 1;
    int coluna_atual = col_inicial - 1;

    // Define a posição da peça atual do navio com base na orientação
    if (orientacao == 'D') { // Diagonal
      linha_atual += i;
      coluna_atual += i;
    }else if (orientacao == 'I') { // Diagonal invertida
      linha_atual += i;
      coluna_atual -= i;
    }else if (orientacao == 'H') { // Horizontal
      coluna_atual += i;
    } else if (orientacao == 'V') { // Vertical
      linha_atual += i;
    }

    // Validação para não desenhar fora dos limites do tabuleiro
    if (linha_atual < TAMANHO_TABULEIRO && coluna_atual < TAMANHO_TABULEIRO) {
      tabuleiro[linha_atual][coluna_atual] = NAVIO;
    }
  }
}

// Função para imprimir o tabuleiro final.
void imprimirTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]) {
  imprimirCoordenadasX();
  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
    printf("%-4d", i + 1); // Alinha os números à esquerda
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
      printf("%-4d", tabuleiro[i][j]);
    }
    printf("\n");
  }
}

// Função dedicada a imprimir as letras das colunas.
void imprimirCoordenadasX() {
  printf("    "); // Espaço para alinhar com os números
  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
    printf("%-4c", 'A' + i);
  }
  printf("\n\n");
}