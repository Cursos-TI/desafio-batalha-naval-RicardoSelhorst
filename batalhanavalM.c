#include <stdio.h>
#define TAM 10
#define HABILIDADE 5
#define NAVIO 3
#define AGUA 0

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA; 
        }
    }
    tabuleiro[4][4] = NAVIO;
    tabuleiro[5][4] = NAVIO;
    tabuleiro[6][4] = NAVIO;
}


void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int matriz[5][5], int x, int y) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int tabX = x + i - 2; 
            int tabY = y + j - 2;
            if (tabX >= 0 && tabX < TAM && tabY >= 0 && tabY < TAM && matriz[i][j] == 1) {
                tabuleiro[tabX][tabY] = HABILIDADE;
            }
        }
    }
}

// Matrizes de habilidades
int cone[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

int cruz[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

int octaedro[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);
    printf("Tabuleiro Inicial:\n");
    imprimirTabuleiro(tabuleiro);

    printf("Habilidade Cone:\n");
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    imprimirTabuleiro(tabuleiro);

    inicializarTabuleiro(tabuleiro);
    printf("Habilidade Cruz:\n");
    aplicarHabilidade(tabuleiro, cruz, 4, 4);
    imprimirTabuleiro(tabuleiro);

    inicializarTabuleiro(tabuleiro); 
    printf("Habilidade Octaedro:\n");
    aplicarHabilidade(tabuleiro, octaedro, 4, 4);
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}
