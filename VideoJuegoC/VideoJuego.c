#include <stdlib.h>
#include <stdio.h>

#define CANT 50

//Prototipos
int  guardarDatos(int poderH, int poderR, char ganador, int *poderHV, int *poderRV, char *ganadorV, int *contador); //Guarda los datos en los vectores

void resultado(int *poderHV, int *poderRV, char *ganadorV, int *contador); //muestra los resultados

int main(){
int opc=0; 
int contador=0; //Cuenta los espacios en los vectores
int poderH=0; //Sé útiliza para ingresar el poder de un monstruo de la protagonista la "Hechicera".
int poderR=0; //Lo mismo que el primero pero del rival.
char ganador;//se utiliza para guardar el ganador de  uno de los enfrentamientos

//vectores donde se guardan las variables.
int poderHV[CANT]={0};
int poderRV[CANT]={0};
char ganadorV[CANT];


do{
    //menú de opciones 

printf("\nIngrese una de las opciones\n");
printf("1- Ingresar datos de un efrentamiento al videojuego.\n");
printf("2- Calcular resultados del videojuego.\n");
printf("3- Salir.\n");

scanf("%d",&opc);

switch(opc){

    case 1: 

        if(contador>=CANT){ 
            //Sí los vectores estan llenos con 50 elementos termina el programa y vuelve al menú.
            
            printf("\nEspacio insuficiente para guardar datos\n");
            
            break;
        }
        else{

             printf("\nIngrese nivel de poder del monstruo de la hechicera\n");

        scanf("%d",&poderH);

        printf("\nIngrese nivel de poder del monstruo del rival\n");
        scanf("%d",&poderR);


        /*Dependiendo el nivel de los monstruos gana uno o otro, pero si  es empate, gana la hechicera, 
        por que utiliza su magia, para el golpe final */

         if(poderH> poderR || poderH == poderR){

            printf("El ganadora del enfrentamiento es la hechicera\n");

            ganador='h';
                                                                        
        }
        else{
            printf("\nEl ganador del enfrentamiento es el rival\n");

            ganador='r';
        }

        //Llama a la función para guardar los datos.
        guardarDatos(poderH,poderR,ganador,poderHV,poderRV,ganadorV,&contador); 
    

        }
    break;

    case 2: 
    //Si no hay datos manda un mensaje en consola.
    if(contador==0){

        printf("\n\nNo hay datos para calcular\n\n");
        break;

    }
    else{

        resultado(poderHV, poderRV, ganadorV, &contador);
        /*Llama o invoca a la función resultado que muestra los resultados totales de la partida, utilizando los vectores cargados en
        la función guardarDatos. */


    }
     
    
    break;

    case 3: 
        printf("\nSaliendo del programa...\n");
    
    break;

    default: printf("\nIngrese una opcion valida\n"); break;



}




}while(opc!=3);

}


int guardarDatos(int poderH, int poderR, char ganador, int *poderHV, int *poderRV, char *ganadorV, int *contador){
//Guarda los datos en vectores utilizando aritmetica de punteros y aumenta el contador.

*(poderHV + *contador)=poderH;
*(poderRV + *contador)=poderR;
*(ganadorV + *contador)=ganador;

(*contador)++;

return 0;

}


void resultado(int *poderHV, int *poderRV, char *ganadorV, int *contador){

//guarda las batallas ganadas de la hechicera y el rival, el que tenga mas gana la partida.
int ganadasH=0; 
int ganadasR=0;

//Guarda el monstruo con mayor poder del enfrentamiento, utilizando como referencia el poder de ataque en la posicion 0 de uno de los contricantes.
int mayorPoder=*(poderHV);

//Saca el promedio de nivel de monstruos de los dos contricantes
int promedioR=0;
int promedioH=0;

//Se guarda el promedio del ganador y lo muestra por consola.
float promedioGanador=0;

for(int i=0; i <= *(contador); i++){
/*acumula desde los vectores, los diferentes enfrentamientos, para elegir un ganador, además 
compara el monstruo con mayor poder, y suma dentro de variables el promedio de cada uno, al finalizar se pasa el contador a una variable
para facilitar el sacar promedio de los monstruos del ganador*/

char ganador=*(ganadorV + i);
int poderR=*(poderRV + i);
int poderH=*(poderHV + i);
    switch(ganador){
        case 'h': ganadasH=ganadasH+1; break;

        case 'r': ganadasR=ganadasR+1; break;


    }


        if(poderR > mayorPoder ){

            mayorPoder=poderR;

        }

        if(mayorPoder < poderH ){

            mayorPoder=poderH;

        }

promedioR+=poderR;

promedioH+=poderH;




}
int cont=*(contador);
if(ganadasH>ganadasR){

promedioGanador= promedioH / cont;

printf("\nEl ganadora de la partida es la hechicera y el promedio de poder de sus monstruos es de: %.2f\n",promedioGanador);

}
else{ 

promedioGanador=promedioR / cont;
printf("\nEl ganador de la partida es el rival y el promedio de poder de sus monstruos es de: %.2f\n",promedioGanador);

}


}