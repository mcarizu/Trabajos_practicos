#ifndef FUNCTIONS_EMPLOYD_H_INCLUDED
#define FUNCTIONS_EMPLOYD_H_INCLUDED

typedef struct{

int id;
char name[51];
char lastName[51];
float salary;
int isEmpty;
int sector;
char descripSector[20];
}eEmployee;

typedef struct{

    int idSector;
    char descripSector[20];

}eSector;

void sectores(eEmployee [],int len);
void hardCode(eEmployee [],int len);
void initEmployee(eEmployee [] ,int len, int value);
void listarEmployee(eEmployee );
int listsEmployees(eEmployee [],int len);
int findEmptyPlace(eEmployee [], int len);
void addEmployee(eEmployee [],int len);
int findIdEmployee(eEmployee [],int len,int id);
int removeEmployee(eEmployee [],int len, char mensaje[]);
int sortEmployees(eEmployee  [], int len);
int salaryEmployee(eEmployee* , int) ;
int modifiEmployee(eEmployee* ,int);

#endif // FUNCTIONS_EMPLOYD_H_INCLUDED
