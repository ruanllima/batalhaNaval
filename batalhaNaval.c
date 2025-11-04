#include <stdio.h>


// função para solicitar ao usuário a posição inicial dos barcos
int* askPosition(char ship[], int pos[], int lim){
    // solicita ao usuario a posição do barco
    // verifica se a entrada é maior que 0 e menor que 10
    // verifica se a entrada da coluna/linha é maior que o limite que o barco pode assumir
    do{
    printf("%s position: \n", ship);
    scanf("%d %d", &pos[0], &pos[1]);
} while ((pos[0] > 10 || pos[0] <= 0) || (pos[1] > 10 
    || pos[1] <= 0) || pos[0] > (lim+1));
    pos[0]--;
    pos[1]--;
}

// função para verificar se já existe um barco em uma determinada posição
int checkPosition(int pos[], int tamanho, int board[10][10]){
    int test;
    // percorre a posição horizontal desejada e verifica se algum ponto já está marcado, se estiver pelo menos um, atribue um valor a uma variavel de controle
    // que identifica a posição como inválida
    for (int i = pos[1], j = 0; j < tamanho; i++, j++){
        // fixa a posição da linha pois o barco está horizontal
        if (board[pos[0]][i] == 0){
            test += 0;
        } else{
            test += 1;
        }
}   return test;
}

int main() {

int board[10][10] = {0};
int ship1[3] = {1, 1, 1};
int ship2[3] = {2, 2, 2};
// vetor posição de cada barco
int pos_ship1[2] = {3, 3}; // horizontal
int pos_ship2[2] = {7, 7}; // vertical
// calcula o tamanho dos barcos (array)
int tamanho_ship1 = sizeof(ship1) / sizeof(ship1[0]);
int tamanho_ship2 = sizeof(ship2) / sizeof(ship2[0]);
// variaveis para verificar a linha/coluna máxima que o barco pode ser incluido
int lim1 = 10 - tamanho_ship1;
int lim2 = 10 - tamanho_ship2;
int test = 0;

printf("\nWELCOME TO THE BATTLESHIP\n\n");
printf("IMPORTANT:\n");
printf("To play BATTLESHIP, first enter two numbers for each ship (e.g., 1 2) to start them in the desired position;\n");
printf("The board is 10x10, so the number must be less than or equal then 10;\n");
printf("Enter numbers between 1 and 10;\n");
printf("Horizontal ships (H) can only be placed up to the 8th column;\n");
printf("Vertical ships (S) can only be placed up to the 8th row.\n\n");


askPosition("Ship1's (H)",pos_ship1, lim1);
//decresce 1 do vetor posição de cada barco (para se adequar ao array que inicia do 0)

// atribue o barco 1 ao tabuleiro
for (int i = pos_ship1[1], j = 0; j < tamanho_ship1; i++, j++){
    // fixa a posição da linha pois o barco está horizontal
    board[pos_ship1[0]][i] = 1;
}

do {
    // chama a função para pedir a posição inicial do barco 2
    askPosition("Ship2's (V)",pos_ship2, lim2);
    // verifica se em algum dos pontos que o barco 2 seria colocado já está ocupado, se estiver, emite um aviso e pede outra posição
    test = checkPosition(pos_ship2, tamanho_ship2, board);
    if (test == 0){
        break;
    } else{
        printf("There's a boat there already!\n");
    }

} while(test!=0);



// atribue o barco 2 na posição desejada
for (int i = pos_ship2[0], j = 0; j < tamanho_ship2; i++, j++){
    // fixa a posição da coluna pois o barco está vertical
    board[i][pos_ship2[1]] = 2;
}


// imprime o tabuleiro
for (int i = 0; i < 10; i++){
    printf("\n");
    for (int j = 0; j < 10; j++){
        printf("%d  ", board[i][j]);
    }
}

return 0;

}