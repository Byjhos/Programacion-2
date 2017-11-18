/*2. REALIZAR UN MENU CON TODAS LAS OPERACIONES SOBRE MATRICES*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#define FILA 100
#define COLUMNA 100
#define M 2
#define N 1
#define P 3
using namespace std;
void generar_matriz(int mat[FILA][COLUMNA], int fil, int col);
void mostrar_matriz(int mat[FILA][COLUMNA], int fil, int col);
void sumar_matriz(int mat1[][COLUMNA],int mat2[][COLUMNA],int mat3[][COLUMNA],int fil,int col);
void resta_matriz(int mat1[][COLUMNA],int mat2[][COLUMNA],int mat3[][COLUMNA],int fil,int col);
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
    cout<<"Matriz B \n"<< "De:" <<P<< " filas y "<<N<<" columnas. "<<endl;
    for(int f=0;f<P;f++)
     for(int c=0;c<N;c++)
     {
       cout<<"ingrese datos en la fila "<<f+1<<" y la columna "<< c+1<<endl;
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
    cout<<"Matriz C Resultante: "<<endl;
    for(int f=0;f<M;f++)
    {
        for(int c=0;c<N;c++)
            cout<<Matriz[f][c]<<"\t";
        cout<<"\n";
    }
}
void invermat(int n, double **a, double **ainv, double &determ);
void iniciar_matriz(int numeros[3][3], int i, int j);
void transpuesta(int numeros[3][3], int i, int j);
int DETERMINANTE(int a[][100],int orden);
int main ()
{
    ifstream label1 ("datos//datos.in");
    int A[FILA][COLUMNA],B[FILA][COLUMNA],C[FILA][COLUMNA];
    int fila, columna,op;
    int Matriz1 [M][P]={{0}};
    int Matriz2 [P][N]={{0}};
    int Matriz3 [M][N]={{0}};
    do
    {
            cout<<"  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  "<<endl;
            cout<<"  °°°°°°°   MENU DE OPERACIONES CON MATRICES            °°°°°°°  "<<endl;
            cout<<"  °°°°°°° 1. INVERSA DE UNA MATRIZ                      °°°°°°°  "<<endl;
            cout<<"  °°°°°°° 2. RESTA DE MATRICES                          °°°°°°°  "<<endl;
            cout<<"  °°°°°°° 3. MULT. DE MATRICES DE 2x3 CON MATRIZ DE 2x1 °°°°°°°  "<<endl;
            cout<<"  °°°°°°° 4. SUMA DE MATRICES                           °°°°°°°  "<<endl;
            cout<<"  °°°°°°° 5. MATRIZ TRANSPUESTA                         °°°°°°°  "<<endl;
            cout<<"  °°°°°°° 6. DETERMINANTE DE UNA MATRIZ                 °°°°°°°  "<<endl;
            cout<<"  °°°°°°° 7. SALIR                                      °°°°°°°  "<<endl;
            cout<<"  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  "<<endl;
            cout<<"ELIGE UNA OPCION DEL <1-7> :";
            cin>>op;
        switch(op)
        {
           case 1:
               int i, j, n;
                label1 >> n;
                double **a, **ainv, determ;
                a = new double* [n], ainv = new double* [n];
                for(j=0; j<n; j++){
                a[j] = new double [n], ainv[j] = new double [n];
                }
                for(i=0; i<n; i++){
                        for(j=0; j<n; j++){
                                 label1 >> a[i][j];
                        }
                }
                    cout << "Imprime la matriz de origen\n\n";
                        for(i=0; i<n; i++){
                            for(j=0; j<n; j++){
                                 cout <<  a[i][j] << " ";
                            }
                cout << endl;
                }
                cout << endl;
                invermat (n, a, ainv, determ);
                if (determ != 0) {
                cout << "Imprime la matriz inversa\n\n";
                    cout.setf(ios::fixed);
                cout.precision(6);
                for(i=0; i<n; i++){
                        for(j=0; j<n; j++){
                                 cout << setw(10) << ainv[i][j] << " ";
                        }
                    cout << endl;
                    }
                    }
                    else cout << "La matriz no tiene inversa\n\n";
                    delete a;break;

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
               cout<<"La Resta de la Matriz A - B = C ;\n";
               resta_matriz(A, B, C, fila, columna);
               mostrar_matriz(C, fila, columna);break;
           case 3:
              recibe_entradas1(Matriz1);
              recibe_entradas2(Matriz2);
              multiplicacion(Matriz1,Matriz2,Matriz3);
              imprimir(Matriz3);break;
           case 4:
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
               cout<<"La Suma de la  Matriz A + B = C ;\n";
               sumar_matriz(A, B, C, fila, columna);
               mostrar_matriz(C, fila, columna);break;
            case 5:
                int numeros[3][3];
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                      cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
                      cin>>numeros[i][j];
                        }
                    }
                    iniciar_matriz(numeros,3,3);
                    transpuesta(numeros,3,3 );
                    getch();break;
              case 6:
                    int mat[100][100];
                    srand(time(NULL));
                    cout<<"Ingrese el orden de la matriz:";cin>>n;
                    for(int j=0;j<n;j++)
                        for(int i=0;i<n;i++)
                            mat[i][j]=rand()%11;
                            cout<<"La matriz aleatoria es:"<<endl;
                        for(int j=0;j<n;j++)
                        {for(int i=0;i<n;i++)
                            cout<<mat[i][j]<<" ";
                            cout<<endl;
                        }
                        cout<<"Su determinante es: "<<DETERMINANTE(mat,n)<<endl;
                         system("pause");break;

                        default: cout<<"FIN DE LA OPERACION ADIOS";
        }
        cout<<endl;
    }while(op!=7);
    return 0;
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
void sumar_matriz(int mat1[][COLUMNA],int mat2[][COLUMNA],int mat3[][COLUMNA],int fil,int col)
{
    for(int f=0;f<fil;f++)
        for(int c=0;c<col;c++)
            mat3[f][c] = mat1[f][c]+mat2[f][c];
}
void resta_matriz(int mat1[][COLUMNA],int mat2[][COLUMNA],int mat3[][COLUMNA],int fil,int col)
{
    for(int f=0;f<fil;f++)
        for(int c=0;c<col;c++)
            mat3[f][c] = mat1[f][c]-mat2[f][c];
}
void invermat(int n, double **a, double **ainv, double &determ) {
	int i, j, k;
	double factor;
	double **L, *D, *X;
	X = new double [n]; D = new double [n];
	L = new double* [n];
	for (j = 0; j < n; j++)
		L[j] = new double [n];
	for (k = 0; k < n - 1; k++) {
		for (i = k+1; i < n;  i++) {
			factor = a[i][k]/a[k][k];
			for (j = k+1; j < n + 1; j++) {
				a[i][j] = a[i][j] - factor * a[k][j];
			}
		}
	}
        determ = 1.;
	for (i = 0; i < n; i++) {
		determ = determ * a[i][i];
	}
if (determ != 0) {
        for (i = 0; i < n; i++) {
               for (j = 0; j < n; j++) {
                  if (i > j) {
                      L[i][j] = a[i][j]/a[j][j];
                      a[i][j] = 0;
                   }
               }
        }
       for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                  L[j][j] = 1;
            }
        }
 for (k = 0; k < n; k++) {
          for (i = 0; i < n; i++) {
               if (i == k) L[i][n] = 1;
               else  L[i][n] = 0;
           }
  double sum;
  D[0] = L[0][n];
  for (i = 1; i < n; i++) {
       sum = 0;
       for (j = 0; j < i; j++) {
            sum = sum + L[i][j]*D[j];
       }
        D[i] = L[i][n] - sum;
   }
  for (i = 0; i < n; i++) {
          a[i][n] = D[i];
  }
 X[n-1] = a[n-1][n]/a[n-1][n-1];
  for (i = n - 2; i > -1; i--) {
        sum = 0;
        for (j = i+1; j < n; j++) {
              sum = sum + a[i][j]*X[j];
         }
         X[i] = (a[i][n] - sum)/a[i][i];
   }
  for (i = 0; i < n; i++) {
         ainv[i][k] = X[i];
  }
 }
}
	delete L, D, X;
}
void iniciar_matriz(int numeros[3][3],int i, int j )
{

    cout<<"\nMatriz Normal\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<numeros[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void transpuesta(int numeros[3][3], int i, int j)
{
    cout<<"\nMatriz Transpuesta\n";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<numeros[j][i]<<" ";
		}
		cout<<"\n";
	}
}
int DETERMINANTE(int a[][100],int orden)
{
   int det=0;
	int aux1[100][100];
   int aux2[100][100];
	if(orden==1)
   	return a[0][0];
   for(int i=0;i<orden;i++)
     {
      if(i%2==0)
       {for(int y=0;y<orden;y++)
       	 for(int x=0;x<orden;x++)
          	if(x<i)
      	 		aux1[x][y]=a[x][y+1];
            else
               aux1[x][y]=a[x+1][y+1];
      	 det=det+a[i][0]*DETERMINANTE(aux1,orden-1);
       }
      else
       {for(int y=0;y<orden;y++)
       	 for(int x=0;x<orden;x++)
          	if(x<i)
      	 		aux2[x][y]=a[x][y+1];
            else
               aux2[x][y]=a[x+1][y+1];
      	det=det-a[i][0]*DETERMINANTE(aux2,orden-1);
       }
      }
   return det;
}
