#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"validaciones.h"
#include"functions_employd.h"


void initEmployee(eEmployee list[] ,int len, int valor)
{

    for(int i=0;i<len;i++){

        list[i].isEmpty=valor;
   }

}
void hardCode(eEmployee list[],int len)
{


            int hardID[10]={1,2,3,4,5,6,7,8,9,10};
            char hardName[10][51]={"luz","toto","yael","luna","more","ana","tito","gonzalo","vito","pez"};
            char hardLastName[10][51]={"mazon","arganiaraz","carizu","carrizo","cabrera","carizu","albornoz","corleone","arganiaraz","zalmon"};
            float hardSalary[10]={100.0,200.0,300.0,400.0,500.0,600.0,700.0,800.0,1000.0,10000.65};
            int hardSector[10]={1,2,3,4,5,5,4,2,1,1};
            int hardIsEmpty[10]={1,1,1,1,1,1,1,1,1,1};
            char hardSectorDesc[10][20]={"RRHH","CALL","OPERARIOS","SISTEMAS","RRHH","CALL","OPERARIOS","PROFECIONALES","SISTEMAS","RRHH"};

    for(int i=0;i<len;i++)
    {

        list[i].id=hardID[i];
        strcpy(list[i].name,hardName[i]);
        strcpy(list[i].lastName,hardLastName[i]);
        strcpy(list[i].descripSector,hardSectorDesc[i]);
        list[i].salary=hardSalary[i];
        list[i].sector=hardSector[i];
        list[i].isEmpty=hardIsEmpty[i];


    }

}
void sectores(eEmployee list[],int len){

    int num;
    int index;
    int idSec [5]={1,2,3,4,5};
    char lugar[5][20]={"RRHH","CALL","OPERARIOS","PROFECIONALES","SISTEMAS"};

     printf("\nSeleccione un Sector\n");
     printf("RRHH -1\n CALL-2\n OPERARIOS -3\n PROFECIONALES -4\nSISTEMAS-5\n");

     num=findIdEmployee(list,len,num);
     num=validarNumero(num,1,5);

    for(int i=0;i<len;i++){
      if(index==num){
        strcpy(list[i].descripSector,lugar[i]);
        list[i].sector=idSec[i];
        }
      }

}
int findIdEmployee(eEmployee list[],int len,int id){
    for(int i=0;i<len;i++){
        if(list[i].id == id && list[i].isEmpty==1){
            return i;
        }

    }return -1;
}


int listsEmployees(eEmployee list[],int len){
    for(int i=0;i<len;i++){
        if(list[i].isEmpty==1){
            listarEmployee(list[i]);

        }
    }

}
void listarEmployee(eEmployee list)
{
     printf("\n ID: %d ", list.id);
     printf("\n\t Nombre: %s ",list.name);
     printf("\n\t Apellido: %s ",list.lastName);
     printf("\n\t Sueldo: %2.f  ", list.salary);
     printf("\n\t Nro. Sector: %d", list.sector);
     printf("\n\t Sector: %s", list.descripSector);

     printf("\n-------------------------------------------------------------------\n");



}



int findEmptyPlace(eEmployee list[], int len){

    sortEmployees(list,len);
        for(int i=0;i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printf("libre:%d",i);

                return i;
            }
        }
        return -1;

}


int removeEmployee(eEmployee list[],int len, char mensaje[]){

    int index;
    int ID;

    //printf("\n%s\n",mensaje);
    ID=getInt(mensaje);
    printf("\nID:%d\n",ID);
    //scanf("%d",&ID);
   // ID=getInt(mensaje);
    index=findIdEmployee(list,len,ID);
    printf("index:%d\n",index);

    do{


    index=findIdEmployee(list,len,ID);
    printf("%d\n",index);

        if(index!=-1)
        {
            list[index].isEmpty=0;
            list[index].id=-1;
            printf("Empleado Borrado\n");

        }
        else
        {

           printf("\nNo se encuentra el ID, Reigreselo\n");
            system("pause");

        }


    }while(index==ID);


    return 0;
}

int sortEmployees(eEmployee list[], int len)
{
    eEmployee aux[len];

    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(list[i].isEmpty == 1)
            {
                if((strcmp(list[i].lastName,list[j].lastName))> 0)
                {
                    aux[i]=list[i];
                    list[i]=list[j];
                    list[j]=aux[i];

                }
            }
        }
    }
    return 0;
}

void addEmployee(eEmployee list[],int len)
{

        int index=0;
        int sueldoAux;

    index=findEmptyPlace(list,len);
    if(index==-1)
    {
        printf("\n¡¡¡ NO HAY ESPACIO LIBRE !!!\n");
        //break;
    }
    printf("\nALTAS\n");
    printf("\nIngrese el Nombre:");
    gets(list[index].name );
    fflush(stdin);
    printf("\nIngrese el Apellido:\n");
    gets(list[index].lastName);
    fflush(stdin);
    list[index].isEmpty=1;

    fflush(stdin);
    printf("\nIngrese el Sector:\n");
    sectores(list[index].descripSector,len);
    printf("\nIngrese \n");
    fflush(stdin);
     sueldoAux=getFloat("Sueldo\n");
     list[index].salary=sueldoAux;

     list[index].id=1+index;

}



int salaryEmployee(eEmployee* list, int len){

    float sum=0;
    float prom=0;
    int i;
    int flag=0;
    int countEmployee=0;
    int countProm=0;

    if(list!=NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(list[i].isEmpty == 1)
            {
                sum = sum + list[i].salary;
                countEmployee ++;
                prom= sum / countEmployee;
            }
        }


        for( i=0; i<len ; i++)
        {
            if(list[i].isEmpty == 1)
            {
                if(list[i].salary> prom)
                {
                   countProm ++;
                }
            }

        }
        printf("\nLa suma de los salarios es: %.2f\n", sum);
        printf("\nEl promedio de los salarios es: %.2f\n", prom);
        printf("\nLos que superan el salario promedio son: %d\n", countProm);
        flag=1;
    }

    return flag;
}




int modifiEmployee(eEmployee* list,int len)
{

        int index=0;
        int sueldoAux;
        int id;


    printf("\nIngrese ID:\n");
    scanf("%d", &id);

    index=findIdEmployee(list,len,id);
    if(index==-1)
    {
        printf("\n¡¡¡ NO HAY ESPACIO LIBRE !!!\n");
        //break;
    }
    printf("\nALTAS\n");
    printf("\nIngrese el Nombre:");
    fflush(stdin);
    gets(list[index].name);
    printf("\nIngrese el Apellido:\n");
    fflush(stdin);
    gets(list[index].lastName);
    list[index].isEmpty=1;
    printf("\nIngrese el Apellido:\n");
    fflush(stdin);
    sectores(list[index].descripSector,len);

    printf("\nIngrese \n");
    fflush(stdin);
     sueldoAux=getFloat("Sueldo\n");
     list[index].salary=sueldoAux;

     list[index].id=0+index;

}






