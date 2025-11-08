#include <stdio.h>
#include <ctype.h>


int verifyLimitPositionV(char ship[], int pos[]){
    do{
    printf("%s position: \n", ship);
    scanf("%d %d", &pos[0], &pos[1]);
    } while ((pos[0] > 8 || pos[0] <= 0) || (pos[1] > 10 
    || pos[1] <= 0));
}

int verifyLimitPositionH(char ship[], int pos[]){
    do{
    printf("%s position: \n", ship);
    scanf("%d %d", &pos[0], &pos[1]);
    } while ((pos[0] > 10 || pos[0] <= 0) || (pos[1] > 8 
    || pos[1] <= 0));
}

int verifyLimitPositionD(char ship[], int pos[]){
    do{
    printf("%s position: \n", ship);
    scanf("%d %d", &pos[0], &pos[1]);
    } while ((pos[0] > 8 || pos[0] <= 0) || (pos[1] > 8 
    || pos[1] <= 0));
}

int putBoatV(int pos_ship[], int tamanho_ship, int nShip, int board[10][10]){
    for (int i = pos_ship[0], j = 0; j < tamanho_ship; i++, j++){
    // fixa a posição da coluna pois o barco está vertical
    board[i][pos_ship[1]] = nShip;
    }
}

int putBoatH(int pos_ship[], int tamanho_ship, int nShip, int board[10][10]){
    for (int i = pos_ship[1], j = 0; j < tamanho_ship; i++, j++){
    // fixa a posição da coluna pois o barco está vertical
    board[pos_ship[0]][i] = nShip;
    }
}

int putBoatD(int pos_ship[], int tamanho_ship, int nShip, int board[10][10]){
    for (int i = pos_ship[0], j = pos_ship[1], k = 0; k < tamanho_ship; i++, j++, k++){
    board[i][j] = nShip;
    }
}

int askOrientation(int i){
    char orientation;
    do{
        printf("Enter the orientation of your ship (%d) (V, H, D): \n", i);
        scanf(" %c", &orientation);
        orientation = toupper(orientation);

    }
    while ((orientation != 'V') && (orientation != 'H') && (orientation != 'D'));

    return orientation;
}

// função para solicitar ao usuário a posição inicial dos barcos
int* askPosition(char ship[], int pos[], char orientation){
    // solicita ao usuario a posição do barco
    // verifica se a entrada é maior que 0 e menor que 10
    // verifica se a entrada da coluna/linha é maior que o limite que o barco pode assumir
    if (orientation == 'V'){
        verifyLimitPositionV(ship, pos);
    } else if (orientation == 'H'){
        verifyLimitPositionH(ship, pos);
    } else if (orientation == 'D'){
        verifyLimitPositionD(ship, pos);
    }
    pos[0]--;
    pos[1]--;
}

// função para verificar se já existe um barco em uma determinada posição
int checkPosition(int pos[], int tamanho, int board[10][10], char orientation){
    int test = 0;

    if (orientation == 'V')
    {
        for (int i = pos[0], j = 0; j < tamanho; i++, j++)
        {
        if (board[i][pos[1]] == 0)
        {
            test += 0;
        } else
        {
            test += 1;
        };
        }
    }
    else if (orientation == 'H')
    {
        for (int i = pos[1], j = 0; j < tamanho; i++, j++)
        {
        if (board[pos[0]][i] == 0){
            test += 0;
        } else{
            test += 1;
        };
        }
    }
    else if (orientation == 'D')
    {
        for (int i = pos[0], j = pos[1], k = 0; k < tamanho; i++, j++, k++){
        if (board[i][j] == 0)
        {
            test += 0;
        } else
        {
            test += 1;
        };
    }
    }


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
int ship3[3] = {3, 3, 3};
int ship4[4] = {4, 4, 4};
// vetor posição de cada barco
int pos_ship1[2];
int pos_ship2[2];
int pos_ship3[2];
int pos_ship4[2];
// calcula o tamanho dos barcos (array)
int tamanho_ship1 = sizeof(ship1) / sizeof(ship1[0]);
int tamanho_ship2 = sizeof(ship2) / sizeof(ship2[0]);
int tamanho_ship3 = sizeof(ship3) / sizeof(ship3[0]);
int tamanho_ship4 = sizeof(ship4) / sizeof(ship4[0]);
// variaveis para verificar a linha/coluna máxima que o barco pode ser incluido
int lim1 = 10 - tamanho_ship1;
int lim2 = 10 - tamanho_ship2;
int lim3 = 10 - tamanho_ship3;
int lim4 = 10 - tamanho_ship4;
int test = 0;

printf("\nWELCOME TO THE BATTLESHIP\n\n");
printf("IMPORTANT:\n");
printf("To play BATTLESHIP, first enter two numbers for each ship (e.g., 1 2) to start them in the desired position;\n");
printf("The board is 10x10, so the number must be less than or equal then 10;\n");
printf("Enter numbers between 1 and 10;\n");
printf("Horizontal ships (H) can only be placed up to the 8th column;\n");
printf("Vertical ships (S) can only be placed up to the 8th row.\n\n");

int qtd_ships;
printf("How ship's do you will enter: ");
scanf("%d", &qtd_ships);


for (int i = 1; i <= qtd_ships; i++){
    do {
        char nameShip[8];
        sprintf(nameShip, "Ship%d%s", i, "'s");
        int pos_ship[2];
        int tamanho_ship = 3;
        char orientation = askOrientation(i);
        // chama a função para pedir a posição inicial do barco 2
        askPosition(nameShip, pos_ship, orientation);
        // verifica se em algum dos pontos que o barco 2 seria colocado já está ocupado, se estiver, emite um aviso e pede outra posição
        test = checkPosition(pos_ship, tamanho_ship, board, orientation);
        
        if (test == 0){
            ;
        } else{
            printf("There's a boat there already!\n");
            continue;
        }
        if (orientation == 'V'){
            putBoatV(pos_ship, tamanho_ship, i, board);
        } else if (orientation == 'H'){
            putBoatH(pos_ship, tamanho_ship, i, board);
        } else if (orientation == 'D'){
            putBoatD(pos_ship, tamanho_ship, i, board);
        } else{
            printf("Algo deu errado");
        }
    } while(test!=0);

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