#include<stdio.h>
#include<stdlib.h>


#include"menu.h"
#include"validaciones.h"
#include"functions_employd.h"


void menuEmploy(eEmployee list[], int tamanio, char mensaje[])
{

   int op=0;

   system("clear");

    do{


        printf("%s",mensaje);
        printf(" Alta-1\n Baja-2\n Modificar-3\n Informar-4\n Salir-5\n\n");

        scanf("%d",&op);
        fflush(stdin);

        op=validarNumero(op,1,5);

        switch(op){
            case 1: printf("ingrese un Empleado");
                    addEmployee(list,tamanio);
                    break;
            case 2: printf("Dar de baja a un Empleado");
                    removeEmployee(list,tamanio,"\nIngrese el ID a Borrar\n");
                    break;
            case 3: printf("Modificar un Empleado");
                    modifiEmployee(list,tamanio);

                    break;
            case 4: printf("Informe de  Empleados");
                system("clear");
                            listsEmployees(list,tamanio);
                            salaryEmployee(list,tamanio);


                system("pause");
                    break;
            case 5 : printf("SALiR");
                    break;
        }

     }while(op!=5);

}
