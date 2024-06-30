//SISTEMA DE INVENTARIOS MARK 10
//ADICIÓN DE IVA AL INGRESAR PRODUCTO.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256
#define MAX_PRODUCTS 100

struct Sistema {
    char nombre[50];
    int cantidad;
    float precio;
};

void cambiando_saltolinea(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] == '\n') {
            string[i] = '\0';
            break;
        }
        i++;
    }
}

void tablita_entxt(FILE *file, struct Sistema productos[], int num_productos) {
    rewind(file);
    fprintf(file, "Nombre           | Cantidad   | Precio\n");
    fprintf(file, "---------------------------------------------\n");
    for (int i = 0; i < num_productos; i++) {
        fprintf(file, "%-17s| %-10d| %.2f\n", productos[i].nombre, productos[i].cantidad, productos[i].precio);
    }
    fflush(file);
}

int main() {
    struct Sistema productos[MAX_PRODUCTS];
    int num_productos = 0;
    FILE *file = fopen("Sistema_de_Inventarios.txt", "r+");

    if (file == NULL) {
        printf("Hubo un error al intentar abrir el archivo.\n");
        return 1;
    }

    char linea[MAX_LINE];
    fgets(linea, MAX_LINE, file); // Saltar el header
    fgets(linea, MAX_LINE, file); // Saltar la línea de separación
    while (fgets(linea, MAX_LINE, file) != NULL && num_productos < MAX_PRODUCTS) {
        sscanf(linea, "%49[^|]| %d | %f", productos[num_productos].nombre, &productos[num_productos].cantidad, &productos[num_productos].precio);
        num_productos++;
    }

    int opcion;

    while (1) {
        printf("\nBienvenido al sistema de inventarios.\n");
        printf("Seleccione cómo desea proceder:\n");
        printf("---------------------------------------------\n");
        printf("Opción 1: Ingresar un producto nuevo.\n");
        printf("Opción 2: Editar un producto existente.\n");
        printf("Opción 3: Eliminar un producto existente.\n");
        printf("Opción 4: Ver lista de productos.\n");
        printf("Opción 5: Salir del programa.\n");
        printf("---------------------------------------------\n");
        printf("Digite el número de la opción deseada: ");

        scanf("%d", &opcion);
        getchar(); // Captura el '\n' pendiente después del scanf de la opción

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del producto: ");
                fgets(productos[num_productos].nombre, 50, stdin);
                cambiando_saltolinea(productos[num_productos].nombre);
                printf("Ingrese la cantidad del producto: ");
                scanf("%d", &productos[num_productos].cantidad);
                printf("Ingrese el precio base del producto: ");
                scanf("%f", &productos[num_productos].precio);
                productos[num_productos].precio += productos[num_productos].precio * 0.15; // Para el 15% de IVA
                printf("Precio final con IVA: %.2f\n", productos[num_productos].precio);
                getchar(); // Captura el '\n' después del scanf del precio
                num_productos++;
                tablita_entxt(file, productos, num_productos);
                printf("Producto agregado al inventario con IVA incluido.\n");
                break;
            // El resto de casos sigue igual
            case 2:
            case 3:
            case 4:
            case 5:
                // Implementaciones similares para otros casos
                break;
        }
    }

    return 0;
}


