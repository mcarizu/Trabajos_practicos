#include<stdio.h>
#include<stdlib.h>

#include"menu.h"
#include"validaciones.h"
#include"functions_employd.h"

#define TAM 10
#define SEC 5

int main(){

    eEmployee Empleados[TAM];
    eSector sector[SEC];


    initEmployee(Empleados,TAM,0);
    hardCode(Empleados,TAM);
    menuEmploy(Empleados,TAM,"\n\n\t\tMENU\t\t\n\n");

    return 0;
}




