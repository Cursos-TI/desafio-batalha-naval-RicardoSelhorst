#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10
#define NAVIO 3
#define TAMANHO_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int x = linha + (diagonal ? i : (direcao == 1 ? i : 0));
        int y = coluna + (diagonal ? i : (direcao == 0 ? i : 0));
        
        if (x >= TAMANHO || y >= TAMANHO || tabuleiro[x][y] != 0) {
            return 0;
        }
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int diagonal) {
    int linha, coluna, direcao;
    do {
        linha = rand() % TAMANHO;
        coluna = rand() % TAMANHO;
        direcao = rand() % 2; // 0 para horizontal, 1 para vertical
    } while (!podePosicionar(tabuleiro, linha, coluna, direcao, diagonal));
    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int x = linha + (diagonal ? i : (direcao == 1 ? i : 0));
        int y = coluna + (diagonal ? i : (direcao == 0 ? i : 0));
        tabuleiro[x][y] = NAVIO;
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int tabuleiro[TAMANHO][TAMANHO];
    
    inicializarTabuleiro(tabuleiro);
    
    // Posicionar dois navios horizontais/verticais
    posicionarNavio(tabuleiro, 0);
    posicionarNavio(tabuleiro, 0);
    
    // Posicionar dois navios diagonais
    posicionarNavio(tabuleiro, 1);
    posicionarNavio(tabuleiro, 1);
    
    // Exibir tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
