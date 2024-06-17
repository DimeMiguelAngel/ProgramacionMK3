//Punteros MK1

//Parametro por referencia -> Asignación de referencia de memoria
//* -> Declaración de puntero y almacenaje de memoria
//& -> Asignación del valor de variable solo eso. No se asigna el espacio de memoria. 
//& -> Utilizar en scanf para asignar un espacio de memoria. 
//%p -> Desplegamiento que muestra dirección de memoria una vez su asignación. 



#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num =10; 
    int *prt, **pprt;
    *prt=&num;
    //**pprt=&prt;

    printf("Los valores son %d - %p", num, &prt);
    return 0;
}


//Printeo de dirección de memoria
/*

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num =10; 
    int *prt, **pprt;
    *prt=&num;
    //**pprt=&prt;

    printf("Los valores son %d - %p", num, &prt); //Original 
    printf("Los valores son %d - %p", num, *prt); //Indica el espacio de memoria incluso sin &.
    
    // *: Asignación de dirección de memoria.
    // &: Asignación de valor para dirección de memoria.
    
    // Con archivo se declara un puntero tipo file y asigna a espacios de memoria. 
    printf("Los valores son %d - %d", num, prt); //Si se coloca %d y NI &,  No sirve de nada
    printf("Los valores son %d - %d", num, &prt); //Si se coloca %d y &,  No sirve de nada
}
*/

//Puntero Over Puntero

// Es una variable que tiene otra variable y esta otra variable es un puntero.. 

//Ejemplo de código.

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num =10; 
    int *prt, **pprt;
    *prt=&num;
    **pprt=&prt;

    printf("Los valores son %d - %p", num, &prt);
    return 0;
}
*/


