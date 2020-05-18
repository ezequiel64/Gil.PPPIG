#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int id;
    char procesador[10];
    char marca[20];
    float precio;
}eNotebook;


float aplicarDescuento(float precio);
int contarCaracter(char cadena[10],char caracter);
void mostrarNotebooks(eNotebook notebook[],int tam);

int main()
{
eNotebook notebook[3]={{1000,"i3","Asus",30000},{1001,"AMD","Lenovo",32000},{1002,"i5","Asus",35000}};


printf("Descuento: %.2f\n\n",aplicarDescuento(100));
printf("Cantidad de caracteres: %d\n\n",contarCaracter("holaa",'o'));
mostrarNotebooks(notebook,3);

    return 0;
}

float aplicarDescuento(float precio)
{
   float total = precio;

 return total-=(precio*0.05);
}



int contarCaracter(char cadena[10],char caracter)
{
  int tam=strlen(cadena),cont=0;
  for(int i=0;i<=tam;i++)
  {
      if(cadena[i]==caracter)
      {
          cont++;
      }
  }

 return cont;
}

void mostrarNotebooks(eNotebook notebook[],int tam)
{

eNotebook auxNote;
int flag=0;
    for(int i=0;i<tam-1;i++)
    {
       for(int j=i+1;j<tam;j++)
       {
            if(0<strcmp(notebook[i].marca,notebook[j].marca))
            {
              auxNote=notebook[i];
              notebook[i]=notebook[j];
              notebook[j]=auxNote;
            }
            if(!strcmp(notebook[i].marca,notebook[j].marca)&&notebook[i].precio<notebook[j].precio)
            {
                auxNote=notebook[i];
              notebook[i]=notebook[j];
              notebook[j]=auxNote;

            }
       }
    }
    for(int i=0;i<tam;i++)
    {
        if(!flag)
        {
            printf("Id    procesador     marca     precio\n");
            flag = 1;
        }
    printf("%d    %5s     %10s     $%.2f\n",notebook[i].id,notebook[i].procesador,notebook[i].marca,notebook[i].precio);
    }

}
