#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include"Funciones.h"
#include"Validaciones.h"


//brief ingresan dos variables para calcular la suma
//param entero para calcular
//param segundo entero para calcular
//retorna el resultado
int sumar(int x, int y)
{
    int resultado;


    resultado = x + y;
    return resultado;
}
//brief ingresan dos variables para calcular la resta
//param entero para calcular
//param segundo entero para calcular
//retorna el resultado

int restar(int x, int y)
{
    int resultado;
    resultado = x-y;
    return resultado;
}
//brief ingresan dos variables para calcular la multiplicacion
//param entero para calcular
//param segundo entero para calcular
//retorna el resultado

int multiplicar(int x, int y)
{
    int resultado;

    resultado = x*y;
    return resultado;
}
//brief ingresan dos variables para calcular la divicion, valida que el segundo parametro no sea 0
//param entero para calcular
//param segundo entero para calcular
//retorna la divicion

float dividir(int x, int y)
{


    float resultado;
    float resto;



    while(y==0){
       y=ingresarNumeros("\nre Ingrese un dato mayor a cero\n",y,1,99999999);
    }
    resultado=(float)x/y;
    resto=x%y;
    printf("\n\t\tEl resultado de la divicion es :%2.f\n\t\tEl resto es : %2.f\n", resultado,resto);

    return 0;

}

//brief ingresa una variable para calcular el factorial
//param entero para calcular elfactorial
//retorna el factorial

void factorial(int x, int y)
{
    int factx=1;
    int facty=1;
    int valorx=x;
    int valory=y;
    int n;
    int m;

    if ( x <= 0 )
    {
        printf("\nerror- solo admite positivos\n");
    }
    else {
        for( n=valorx; n>=1; n--)
        {
            factx=factx*n;
        }
        for( m=valory; m>=1; m--)
        {
            facty=facty*m;
        }
    }
    printf("\n\t\tEl factorial de A:%d es :%d\n\n",valorx,factx);
    printf("\n\t\tEl factorial de B:%d es :%d\n\n",valory,facty);

    //return fact;
}
//brief ingresan dos variables y llama a todas las funciones
//param entero para calcular
//param segundo entero para calcular
//


void todasLasFunciones(int x, int y)
{
    int suma=0;
    int resta=0;
    int multi=0;

    //int fact=0;



                    suma = sumar(x, y);
                    printf("\n\t\tEl Resultado de la Suma es : %d\n",suma);
                    resta=restar(x, y);
                    printf("\n\t\tEl Resultado de la Resta es : %d\n",resta);
                    multi=multiplicar(x, y);
                    printf("\n\t\tEl Resultado de la Multiplicaion : %d\n", multi);
                    dividir(x, y);
                    factorial(x,y);

}

//brief
void menu(void){

    int x=0;
    int y=0;
    int total=0;
    int op=0;
    int flagA=0;
    int flagB=0;

    fflush(stdout);
    while(op<'1'||op>'9')
    {

        printf("\t\t\tIngrese un valor 1-9\n1)Ingresar 1er operando A=x\n2)Ingresar 2do operando B=y\n3)Calcular todas las operciones\n4)Ver los resultados\n5) Salir\n");
        op=pedirDatos("\nIngrese una opcion\n",1,5);
        system("pause");
        system("clear");

        switch(op)
        {

            case 1 :x=ingresarNumeros("Ingrese un Valor para A\n",x,0,99999999);// numero maximo que permite una calculadora
                    flagA=1;
                    printf("\nEl valor de A :%d\n",x);
                    break;
            case 2 :y=ingresarNumeros("Ingrese un Valor para B\n",y,0,99999999);
                    flagB=1;
                    printf("\nEl valor de B :%d\n",y);
                    break;
            case 3: printf("Calcular todas las operaciones\n\n");
                    break;
            case 4: printf("Mostrar todas las operaciones\n\n");
                    todasLasFunciones(x,y);
                    break;
            case 5 : printf("Salir");
                    op='5';
                break;
            default: printf("Ingrese un valor valido\n");
        }

    }
    //return 0;
}
