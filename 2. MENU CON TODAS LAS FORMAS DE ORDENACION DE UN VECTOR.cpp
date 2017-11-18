/*2. REALIZAR UN MENU CON TODAS LAS FORMAS DE ORDENACION DE UN VECTOR*/
#include<iostream>
#define MAX 1000
using namespace std;
void burbuja();
void insercion();
void seleccion();
void shell();
void QuickSort();

int main ()
{
    int op;
    do
    {
            cout<<"  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°        "<<endl;
            cout<<"  °°°°°°°     MENU DE ORDENACION       °°°°°°°        "<<endl;
            cout<<"  °°°°°°° 1. ORDENACION POR BURBUJA    °°°°°°°        "<<endl;
            cout<<"  °°°°°°° 2. ORDENACION POR INSERCION  °°°°°°°        "<<endl;
            cout<<"  °°°°°°° 3. ORDENACION POR SELECCION  °°°°°°°        "<<endl;
            cout<<"  °°°°°°° 4. ORDENACION POR SHELL      °°°°°°°        "<<endl;
            cout<<"  °°°°°°° 5. ORDENACION POR QUICKSORT  °°°°°°°        "<<endl;
            cout<<"  °°°°°°° 6. SALIR                     °°°°°°°        "<<endl;
            cout<<"  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°        "<<endl;
            cout<<"ELIGE UNA OPCION DEL <1-6> :";
            cin>>op;
        switch(op)
        {
           case 1:burbuja();break;
           case 2:insercion();break;
           case 3:seleccion();break;
           case 4:shell();break;
           case 5:QuickSort();break;
           default: cout<<"FIN DE LA OPERACION ADIOS";
        }
        cout<<endl;
    }while(op!=6);
    return 0;
}
void burbuja()
{
    int n,aux,j,opcion;
    int v[11];
    int i;
    cout<<"Ingrese el tamaño del vector, maximo 10:";
    cin>>n;
    for(i=0; i<n; i++)
        {
            cout<<"Ingrese un numero en la posicion "<<i+1<<":";
            cin>>v[i];
        }
        for (i=0; i<n-1; i++)
            for (j=0; j<(n-1)-i; j++)
                if (v[j]>v[j+1])
                {
                    aux=v[j];
                    v[j]=v[j+1];
                    v[j+1]=aux ;
                }
        cout<<"Los numeros del vector en forma ordenada es:";
            for(i=0; i<n; i++)
            {
                cout<<"[ "<<v[i]<<" ]";
            }
}
void insercion()
{
    int n,aux,j,sw;
    int v[10];
    int i;
    cout<<"Ingrese el tamaño del vector, maximo 10:";
    cin>>n;
        for(i=0; i<n; i++)

            {
                cout<<"Ingrese un numero en la posicion "<<i+1<<":";
                cin>>v[i];
            }
            for (i=1; i<n;i++)
            {
                aux=v[i];
                j=i-1;
                sw=1;
            while (sw&&j>=0)
            {
                if (aux<v[j])
                {
                        v[j+1]=v[j];
                        j--;
                }
                else
                    sw=0;
                }
                v[j+1]=aux;
            }
            cout<<"Los numeros del vector en forma ordenada es:";
                for(i=0; i<n; i++)
                    {
                        cout<<"[ "<<v[i]<<" ]";
                    }
}
void seleccion()
{
    int j,i,n,k;
    int v[10];
    int sw;
    int aux;
    cout<<"Ingrese el tamaño del vector, maximo 10:";
    cin>>n;
       for(i=0;i<n;i++)
        {
            cout<<"Ingrese un numero en la posicion "<<i+1<<":";
            cin>>v[i];
        }
            for(i=0;i<n-1;i++)
            {
                k=i;
                for (j=i+1;j<n;j++)
                    if (v[j]<v[k])
                        k=j;
                        aux=v[i];
                        v[i]=v[k];
                        v[k]=aux;
            }
            cout<<"Los numeros del vector en forma ordenada es:";
                for(i=0; i<n; i++)
                    {
                        cout<<"[ "<<v[i]<<" ]";
                    }
}
void shell()
{
    int j,i,n,k,inc,tmp;
    int v[10];
    int sw;
    int aux;
    cout<<"Ingrese el tamaño del vector, maximo 10:";
    cin>>n;
        for(i=0;i<n;i++)
        {
            cout<<"Ingrese un numero en la posicion "<<i+1<<":";
            cin>>v[i];
        }
            inc=n/2;
            do {
                for(i=inc;i<n;i++)
                {
                    tmp=v[i];
                    j=i-inc;
                while ((j>=0)&&(tmp<v[j]))
                {
                    v[j+inc]=v[j];
                    j-=inc;
                }
                    v[j+inc]=tmp;
                }
                    inc/=2;
                }
                while(inc!=0);

                cout<<"Los numeros del vector en forma ordenada es:";
                    for(i=0; i<n; i++)
                    {
                        cout<<"[ "<<v[i]<<" ]";
                    }
}
void QuickSort()
{
    int n ;
    cout<<"Ingrese el tamaño del vector:"<<endl;
    cin>>n;
    int i;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Ingrese un numero en la posicion "<<i+1<<":";
        cin>>a[i];
    }
    int tope, ini, fin , pos;
            int may[MAX],menor[MAX];
            tope=0;
            menor[tope]=0;
            may[tope]=n-1;
            while(tope>=0)
            {
                ini = menor[tope];
                fin = may[tope];
                tope--;
            int izq,der,aux;
            bool band;
            izq=ini;
            der=fin;
            pos=ini;
            band=true;
            while(band==true)
            {
                while((a[pos]<a[der]) && ( pos!=der ))
                    der--;
                if(pos==der)
                    band=false;
                else
                {
                    aux=a[pos];
                    a[pos]=a[der];
                    a[der]=aux;
                    pos=der;
                }
                while((a[pos]>a[izq]) && ( pos!=izq ))
                    izq++;
                 if(pos==izq)
                    band=false;
                else
                {
                    aux=a[pos];
                    a[pos]=a[izq];
                    a[izq]=aux;
                    pos=izq;
                }
            }
                if(ini<=(pos-1))
                {
                    tope++;
                    menor[tope]=ini;
                    may[tope]=pos-1;
                }
                if(fin>=(pos+1))
                {
                    tope++;
                    menor[tope]=pos+1;
                    may[tope]=fin;
                }
            }
      cout<<"Los numeros del vector en forma ordenada es:";
            for(i=0; i<n; i++)
            {
                cout<<"[ "<<a[i]<<" ]";
            }
}
