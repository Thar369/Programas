
//Librerias
#include <stdlib.h>
#include <stdio.h>

//Prototipos
int menu();
int cargarMonto( float *mesV, float montoMes, int *contador);
int gastoEmpleado(int mes, float *mesV, float gastoEfectuar); 

int main(){
int contador=0;//La variable contador lo que hace es ser de guia para los espacios en el vector de mesV.

int mes=0;//Variable para determinar el mes, va de la mano de gastoEfectuar.

float mesV[12]={0};//almacena los presupuesto de los meses, y utiliza el espacio de 12 vectores como referencia a los 12 meses.

float montoMes=0;//Variable flotante/real que almacena el presupuesto del mes y luego se guarda en "mesV".

float gastoEfectuar=0; //Variable para que se ingrese por consola la cantidad que va a gastar un empleado en un mes determinado.
int opcion=0;



do{
opcion=menu(); //Se almacena lo que se ingresa en consola desde la funcion menu a la variable opcion

switch (opcion)
{
    case 1: 
        
    printf("\nIngrese presupuesto de cada mes\n");

    for(int i=0; i<12;i++){

        printf("\nIngrese el presupuesto del mes %d\n",i+1);

        scanf("%f",&montoMes);

        

        cargarMonto(mesV,montoMes,&contador); 
        
    }

    break;

            case 2: 

            printf("\nIngrese el gasto a efectuar por el empleado\n");
            scanf("%f",&gastoEfectuar);
            
            printf("\nIngrese el mes donde se hara el gasto\n");
            scanf("%d",&mes);
                    mes-=1;

                if (mes >= 0 && mes < 12){
                    gastoEmpleado(mes,mesV,gastoEfectuar); //Si el mes ingresado en consola esta entre los valores de 0 a 11(1 a 12 para el usuario), continua con el programa.

                }   
                else{

                printf("\nIngrese un mes valido\n");

                break;

                }

                break;

    case 3:

        printf("\nPresupuesto mes a mes actualizado\n");

        for(int i=0; i<12;i++){
            
            printf("\nEl Presupuesto del mes (%d) es de: %.2f\n",i+1,mesV[i]);
            



        }

    break;

    case 4:
            printf("Saliendo del programa....");
    break;


    default:
        printf("Ingrese una opcion valida");
        break;
}





}while(opcion!=4);



}


int menu(){ //Funcion menu, es la primera parte que se ve en consola y da la introdución al programa.

int opc=0;

printf("\nIngrese una opción\n");

printf(" 1- Ingresar presupuesto de cada mes\n");

printf(" 2- Ingresar gastos a efectuar por los empleados\n");

printf(" 3- Mostrar el presupuesto que quedó sin utilizar\n");

printf(" 4- Salir del programa\n");

scanf("%d",&opc);

return opc;



}

int cargarMonto( float *mesV, float montoMes, int *contador){ // Funcion cargarMonto, es donde se almacena los valores, del vector mesV del main(), y se incrementa contador.


*(mesV + *contador)=montoMes;

(*contador)++;

return 0;



}

int gastoEmpleado(int mes, float *mesV, float gastoEfectuar){ /*Funcion gastoEmpleado, verifica si el gasto a efectuar en el mes ingresado correspondientemente, cumple con el presupuesto para efectuar el gasto,
en caso contrario rechaza el gasto, además sí el mes cubre con el gasto del empleado, visualiza en consola el monto del gasto, el mes donde se efectuará el gasto, actualiza el vector mesV restando el gastoEfectuar
en la direccion donde apunta el puntero y visualiza el monto del presupuesto restante del mes*/

if(*(mesV + mes)>=gastoEfectuar){


    printf("\n\n++++Gasto aprobado++++\n\n");
    printf("El monto del gasto es de: %.2f",gastoEfectuar);
    printf("\nEl gasto se efectuara en el mes (%d)",mes+1);

    *(mesV + mes) -=gastoEfectuar;
    printf("\nEl monto del presupuesto restante del mes (%d) es de %.2f",mes+1,*(mesV+mes));



}
else{

    printf("\n\n----Gasto rechazado----\n\n");



}

return 0;

}

//Fin del programa