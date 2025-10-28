#include <stdio.h>


#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int validarPosicionamento(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int orientacao) {
    
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha;
        int c = coluna;
        if (orientacao == 0) {
            c += i;
        } else {  
            l += i;
        }
        if (l < 0 || l >= TAM_TABULEIRO || c < 0 || c >= TAM_TABULEIRO) {
            return 0;
        }
        if (tabuleiro[l][c] != 0) {
            return 0;
        }
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int navio[TAM_NAVIO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (orientacao == 0) {
            tabuleiro[linha][coluna + i] = navio[i];
        } else {
            tabuleiro[linha + i][coluna] = navio[i];
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

        inicializarTabuleiro(tabuleiro);

        int navio_horizontal[TAM_NAVIO] = {3, 3, 3};
    int navio_vertical[TAM_NAVIO] = {3, 3, 3};

        int linha_h = 2;
    int coluna_h = 1;
    
    int linha_v = 0;
    int coluna_v = 7;

        if (validarPosicionamento(tabuleiro, linha_h, coluna_h, 0)) {
        posicionarNavio(tabuleiro, navio_horizontal, linha_h, coluna_h, 0);
        printf("Navio horizontal posicionado com sucesso na linha %d, coluna %d.\n", linha_h, coluna_h);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal (limites ou sobreposição).\n");
        return 1;
    }

    if (validarPosicionamento(tabuleiro, linha_v, coluna_v, 1)) {
        posicionarNavio(tabuleiro, navio_vertical, linha_v, coluna_v, 1);
        printf("Navio vertical posicionado com sucesso na linha %d, coluna %d.\n", linha_v, coluna_v);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical (limites ou sobreposição).\n");
        return 1;  
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}