#include <stdio.h>

//constantes
#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3
#define TRIANGULO 5
#define CRUZ 7
#define OCTAEDRO 2

//funções
void iniciarJogo();
void inicializarTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]);
void imprimirTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]);
void imprimirCoordenadasX();
void adicionarNavio(int tabuleiro[][TAMANHO_TABULEIRO], int linha_inicial, int col_inicial, int tamanho, char orientacao);
void adicionarAtaques(int tabuleiro[][TAMANHO_TABULEIRO], int linha_inicial, int col_inicial, char ataque);


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
  adicionarAtaques(tabuleiro, 1, 3, 'T');
  adicionarAtaques(tabuleiro, 4, 3, 'C');
  adicionarAtaques(tabuleiro, 1, 8, 'O');
  
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

//função dedicada a imprimir ataques
void adicionarAtaques(int tabuleiro[][TAMANHO_TABULEIRO], int linha_inicial, int col_inicial, char ataque) {
  // ataque triângulo
  if (ataque == 'T') {
    const int alguraTriangulo = 3;
    
    linha_inicial = linha_inicial - 1;
    col_inicial = col_inicial - 1;

    for (int i = 0; i < alguraTriangulo; i++) {
      int linha_atual = linha_inicial + i;

      for (int j = -i; j <= i; j++) {
        int coluna_atual = col_inicial + j;
        tabuleiro[linha_atual][coluna_atual] = TRIANGULO;
      }
    }
  }

  // ataque cruz
  if (ataque == 'C'){
   int alturaCruz = 5;

    linha_inicial = linha_inicial - 1;
    col_inicial = col_inicial - 1;

    for (int i = 0; i < alturaCruz; i++){
      tabuleiro[linha_inicial][col_inicial] = CRUZ;
      if (i == 2){
        int col_atual = col_inicial-2;
        for (int j = 0; j < 5 ; j++){
          tabuleiro[linha_inicial][col_atual] = CRUZ;
          col_atual++;
        }
      }
      linha_inicial++;
    }
  }

  if (ataque == 'O'){
    const int alturaForma = 5;

    int linha_vertice = linha_inicial - 1;
    int col_centro = col_inicial - 1;
    int linha_meio = alturaForma / 2;

    for (int i = 0; i < alturaForma; i++) {
        
        int propagacao;
        if (i <= linha_meio) {
          propagacao = i;
        } else {
          propagacao = (alturaForma - 1) - i;
        }

        int linha_atual = linha_vertice + i;

        for (int j = -propagacao; j <= propagacao; j++) {
          int coluna_atual = col_centro + j;      
          tabuleiro[linha_atual][coluna_atual] = OCTAEDRO;
        }
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