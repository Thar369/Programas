/*Programa que mide la altura y distancia de diez puntos de un sendero, donde se ingresa la altura y distancia, se almacenan
en arrays, y luego se pasan a funciones donde reciben como parametros punteros que apuntan a los arrays, el programa despues
de ingresar los valores informa cual es la distancia total del sendero, la exigencia de cada uno de los puntos, y hace una exigencia
general donde si el numero de exigencias altas es mayor, aparece por consola que el sendero es de exigencia alta*/








#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Prototipos
int menu();
void alturaDistancia(int *alturaP, int *distanciaP);
void exigenciaRiesgo(int *alturaProto, int *distanciaProto);

int main(){

int opcion;
//variable de una array de 10 elementos simulando 10 posiciones de un sendero a medir la altura
int altura[10]={0};
//variable para saber la distancia de cada uno de esos puntos del sendero 
int distancia[10]={0};





do//bucle para que funcione minimo una vez
{

 opcion=menu();//variable opcion recibe a traves de la funcion menu la opcion seleccionada


switch (opcion)
{
case 1:
    alturaDistancia(altura, distancia);

    break;
case 2: 
exigenciaRiesgo(altura, distancia);

break;

case 3: 
printf("Saliendo");

break;

default:
printf("\nIngrese una opcion valida");
   
    break;

}

} while (opcion!=3);


}


int menu(){//Funcion menu, muestra opciones y el usuario ingresa un valor.

int opc;

printf("\n\nSeleccione una de las opciones:\n");
printf("1-Ingresar alturas y distancias de puntos principales del sendero\n");
printf("2-Evaluacion de nivel de exigencia del sendero\n");
printf("3-Salir\n");

scanf("%d", &opc);

return opc;
}


void alturaDistancia(int *alturaF, int *distanciaF){//una funcion que recibe dos punteros, y devuelven por un bucle a traves de consola, la altura y distancia

for(int i=0; i<10; i++){

printf("Ingrese la altura de la posicion %d\n", i+1);
scanf("%d",&alturaF[i]);

printf("Ingrese la distancia de la posicion %d\n", i+1);
scanf("%d",&distanciaF[i]);
}


}

void exigenciaRiesgo(int *alturaFuncion, int *distanciaFuncion){
/*Una funcion que recibe 2 punteros, acumula la distancia total del sendero,
imprime en consola el nivel general de exigencia que pide el sendero(solamente si es alto), imprime tambien en consola cada
uno de los puntos del sendero y dice su nivel de exigencia
*/

int exigenciaAlta=0;
int exigenciaBaja=0;
int acumDistancia=0;
for(int i=0; i<10; i++){

if (alturaFuncion[i] > 500 && distanciaFuncion[i] > 2000  )
{
    exigenciaAlta++;
    printf("\n¡¡EL NIVEL DE EXIGENCIA DE LA POSICION  %d ES ALTA!!\n" ,i+1);
    
}
else{
printf("El nivel de exigencia de la posicion %d es baja\n",i+1);
exigenciaBaja++;
}
acumDistancia+=distanciaFuncion[i];




}
printf("La distancia del sendero es de: %d\n ",acumDistancia);

if(exigenciaAlta>exigenciaBaja){

    printf("El sendero es de exigencia alta");

  }
  else{ 
    
    printf("El sendero es de exigencia baja");
  
  }

}