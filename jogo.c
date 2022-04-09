#include <stdio.h>

char verificar_vitoria(char* tabuleiro){
  for(int i = 0; i < 3; i++){
    if(tabuleiro[i] == tabuleiro[i+3] && tabuleiro[i] == tabuleiro[i+6]){
      return tabuleiro[i];
    }
  }

  for(int i = 0; i < 7; i+=3){
    if(tabuleiro[i] == tabuleiro[i+1] && tabuleiro[i] == tabuleiro[i+2]){
      return tabuleiro[i];
    }
  }

  if(tabuleiro[0] == tabuleiro[4] && tabuleiro[0] == tabuleiro[8]) return tabuleiro[0];
  if(tabuleiro[2] == tabuleiro[4] && tabuleiro[2] == tabuleiro[6]) return tabuleiro[2];

  return 'N';
}

void imprimir_tabuleiro(char* tabuleiro){
  printf("%c | %c | %c\n%c | %c | %c\n%c | %c | %c\n\n",
    tabuleiro[0], tabuleiro[1], tabuleiro[2],   tabuleiro[3], tabuleiro[4], tabuleiro[5], tabuleiro[6], tabuleiro[7], tabuleiro[8]);
  
  return;
}

int main() {
  printf("Bem-vindo ao jogo da velha!\n\n");

  char tabuleiro[9];
  int jogador = 1;
  int casas_preenchidas = 0;

  for(int i = 0; i < 9; i++) tabuleiro[i] = i+1 + '0';

  imprimir_tabuleiro(tabuleiro);

  while(casas_preenchidas != 9){
    printf("Jogador %d, escolha uma posição no tabuleiro.\n", jogador);

    int pos;
    scanf("%d", &pos);

    while(tabuleiro[pos-1] == 'X' || tabuleiro[pos-1] == 'O'){
      printf("Posição já preenchida, escolha outra posição no tabuleiro.\n");

      scanf("%d", &pos);
    }

    char simbolo;

    if(jogador == 1){
      simbolo = 'X';
      jogador = 2;
    }
    else{
      simbolo = 'O';
      jogador = 1;
    }

    tabuleiro[pos-1] = simbolo;

    casas_preenchidas++;

    imprimir_tabuleiro(tabuleiro);

    char vitoria = verificar_tabuleiro(tabuleiro);

    if(vitoria != 'N'){
      if(vitoria == 'X') printf("Vitória do jogador 1!\n");
      else printf("Vitória do jogador 2!\n");

      break;
    }
  }

  return 0;
}
