#define N 4
#include <stdbool.h>
#include <stdio.h>

/*
 * Funcion para imprimir la tabla
 * */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");

    }
    printf("-------------""\n");
}

/*
 * Funcion que prueba si es seguro poner una reina en determinado espacio
 * */
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    printSolution(board);
    return true;
}

/*
 * Funcion para resolver el problema de las n reinas
 * */
bool solveNQUtil(int board[N][N], int col)
{
    // Si todas les reinas estan entonces devuelve True
    if (col >= N)
        return true;

    // Se considera la columna actual y prueba si se puede poner en cada fila
    for (int i = 0; i < N; i++) {
        // Prueba si le reina se puede poner en board[i][col]
        if (isSafe(board, i, col)) {
            // Se pone la reina en dicha posicion
            board[i][col] = 1;

            // Se pone el resto de las reinas recursivamente
            if (solveNQUtil(board, col + 1))
                return true;

            //Si no se llega a ninguna solucion se quita a la reina
            //Aqui se hace el backtracking
            board[i][col] = 0;
        }
    }

    // Si no se puede poner en ninguna fila retorna falso
    return false;
}

/*
 * Funcion base para resolver el problema
 * */
bool solveNQ()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    printSolution(board);
    return true;
}


int main()
{
    solveNQ();
    return 0;
}
