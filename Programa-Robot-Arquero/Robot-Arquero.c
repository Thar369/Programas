#include <stdlib.h>
#include <stdio.h>

#define ESPACIOS 50

int cargarVector(int *vcordenadaXp, int *vcordendaYp, int cordenadaXp, int cordenadaYp, int *contador);

void tirosArco(int *vcordenadaXp, int *vcordenadaYp, int contador);
int main (){

int vcordenadaX[ESPACIOS], vcordenadaY[ESPACIOS], cordenadaX,cordenadaY;
int contador=0;
int opcion=0;

do{
    system("CLS");
   printf("----------------------------------------------------------------------------------------------");
printf("\nSeleccione una opcion\n");

printf("1-Ingresa datos de tiros al arco.\n");

printf("2-Evaluar las habilidades del arquero robot.\n");

printf("3-Salir\n");
   printf("----------------------------------------------------------------------------------------------\n\n\n\n");
scanf("%d",&opcion);
system("CLS");
switch (opcion)
{

    case 1:
    if(contador<ESPACIOS){
    printf("Ingrese la cordenada x en centimetros\n");
    scanf("%d",&cordenadaX);

    printf("Igrese la cordeada Y en centimetros\n");

    scanf("%d",&cordenadaY);

    cargarVector(vcordenadaX,vcordenadaY,cordenadaX,cordenadaY,&contador);}
    else{printf("Espacio insuficiente en los vectores");}

        break;



    case 2:
    tirosArco(vcordenadaX,vcordenadaY,contador);
        break;

    case 3:
    printf("\nSaliendo del programa...\n"); break;

    default: printf("Opcion no valida\n"); break;

}





}
while(opcion!=3);





}

int cargarVector(int *vcordenadaXf, int *vcordenadaYf, int cordenadaXf, int cordenadaYf, int *contador)
{
int i;

*(vcordenadaXf+*contador)=cordenadaXf;
*(vcordenadaYf+*contador)=cordenadaYf;

(*contador)++;

}

void tirosArco(int *vcordenadaXf, int *vcordenadaYf, int contador){
int acumGol=0;
int acumAfuera=0;
for(int i=0; i<contador;i++){
int x =*(vcordenadaXf+i);
int y= *(vcordenadaYf+i);
printf("\nEl tiro numero: %d en las cordenadas X: %d y en las cordenadas Y: %d  fue: ",i+1,x,y);

if(x>=0 && x<=500 && y>=0 && y<=250)
{
    printf("¡¡GOOOOL!!");
acumGol++;
}
else{printf("¡¡AFUERAAA!!");

acumAfuera++;}


}

printf("\nLa cantidad de tiros que fueron Gol son de: %d ",acumGol);
printf("\nLa cantidad de tiros que fueron Afuera son de: %d \n",acumAfuera);


}