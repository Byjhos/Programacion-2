/*7. Desarrollar un menu con matrices*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define FILA 100
#define COLUMNA 100
#define M 2
#define N 1
#define P 3
using namespace std;

void generar_matriz(int mat[FILA][COLUMNA], int fil, int col);
void mostrar_matriz(int mat[FILA][COLUMNA], int fil, int col);
void sumar_matriz(int mat1[][COLUMNA],
                  int mat2[][COLUMNA],
                  int mat3[][COLUMNA],
                  int fil,
                  int col);
void recibe_entradas1(int Matriz[][P])
{
    cout<<"Matriz A \n"<<"De: "<<M<<" filas y "<<P<<" columnas. "<<endl;
    for(int f=0;f<M;f++)
     for(int c=0;c<P;c++)
     {
       cout<<"ingrese datos en la fila "<<f+1<<" y la columna "<< c+1 <<endl;
       cin>>Matriz[f][c];
     }
}
void recibe_entradas2(int Matriz[][N])
{
    cout<<"Matriz 2\n"<<"De:"<<P<<"flas y "<<N<<"columnas. "<<endl;
    for(int f=0;f<P;f++)
     for(int c=0;c<N;c++)
     {
       cout<<"ingrese datos en la fila"<<f+1<<"y la columna"<<c+1<<endl;
       cin>>Matriz[f][c];
     }
}
void multiplicacion(int Matriz1[][P],int Matriz2[][N],int Matriz3[][N])
{
    for(int k=0;k<M;k++)
     {
         for(int c=0;c<N;c++)
         {
             for(int f=0;f<P;f++)
             {
                 Matriz3[k][c]+= Matriz1[k][f]*Matriz2[f][c];
             }
         }
     }
}
void imprimir(int Matriz[][N])
{
    cout<<"Matriz 3 Resultante: "<<endl;
    for(int f=0;f<M;f++)
    {
        for(int c=0;c<N;c++)
            cout<<Matriz[f][c]<<"\t";
        cout<<"\n";
    }
}
int main ()
{
    int A[FILA][COLUMNA],B[FILA][COLUMNA],C[FILA][COLUMNA];
    int fila,columna,op;
    int Matriz1 [M][P]={{0}};
    int Matriz2 [P][N]={{0}};
    int Matriz3 [M][N]={{0}};
    cout<<"                MENU                    "<<endl;
    cout<<"         1 generar matriz               "<<endl;
    cout<<"         2 suma de matrices             "<<endl;
    cout<<"         3 multiplicacion de matrices   "<<endl;
    cout<<"         4 salir                        "<<endl;
    cout<<"elige una opcion ";
    cin>>op;
    switch(op)
    {
        case 1:
        cout<<"ingrese el tamaño de la fila y columna:\n";
        cin>>fila;
        cin>>columna;
        srand(time(NULL));
        cout<<"Matriz Generada es:\n";
        generar_matriz(A, fila, columna);
        mostrar_matriz(A, fila, columna);
        return 0;
        case 2:
        cout<<"ingrese el tamaño de la fila y columna:\n";
        cin>>fila;
        cin>>columna;
        srand(time(NULL));
        cout<<"Matriz A:\n";
        generar_matriz(A, fila, columna);
        mostrar_matriz(A, fila, columna);
        cout<<"Matriz B:\n";
        generar_matriz(B, fila, columna);
        mostrar_matriz(B, fila, columna);
        cout<<"La Suma De La Matriz A y Matriz B es:\n";
        sumar_matriz(A, B, C, fila, columna);
        mostrar_matriz(C, fila, columna);
        return 0;
        case 3:
        recibe_entradas1(Matriz1);
        recibe_entradas2(Matriz2);
        multiplicacion(Matriz1,Matriz2,Matriz3);
        imprimir(Matriz3);
        return 0;
        default:cout<<"Opcion no valida";
    }
}
void generar_matriz(int mat[FILA][COLUMNA], int fil, int col)
{
    for(int f=0;f<fil;f++)
        for(int c=0;c<fil;c++)
            mat[f][c] = 1 + rand () % (10-1);
}
void mostrar_matriz(int mat[FILA][COLUMNA], int fil, int col)
{
    for(int f=0;f<fil;f++)
    {
        for(int c=0;c<col;c++)
            cout<<mat[f][c]<<"\t";
        cout<<"\n\n";
    }
}
void sumar_matriz(int mat1[][COLUMNA],
                  int mat2[][COLUMNA],
                  int mat3[][COLUMNA],
                  int fil,
                  int col)
{
    for(int f=0;f<fil;f++)
        for(int c=0;c<col;c++)
            mat3[f][c] = mat1[f][c]+mat2[f][c];
}
