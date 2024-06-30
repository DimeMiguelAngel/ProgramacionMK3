// SISTEMA DE INVENTARIOS MARK 9

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256
//Maximo de caracteres en una linea
#define MAX_PRODUCTS 100
//limite de productos

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
                printf("Ingrese el precio del producto: ");
                scanf("%f", &productos[num_productos].precio);
                getchar(); // Agarra el '\n' después del scanf del precio
                num_productos++;
                tablita_entxt(file, productos, num_productos);
                printf("Producto agregado al inventario.\n");
                break;
            case 2:
                char editar_nombre[50];
                printf("Ingrese el nombre del producto a editar:\n");
                fgets(editar_nombre, 50, stdin);
                cambiando_saltolinea(editar_nombre);
                int encontrado = 0;
                for (int i = 0; i < num_productos; i++) {
                    if (strcmp(productos[i].nombre, editar_nombre) == 0) {
                        printf("Ingrese la nueva cantidad del producto:\n");
                        scanf("%d", &productos[i].cantidad);
                        printf("Ingrese el nuevo precio del producto:\n");
                        scanf("%f", &productos[i].precio);
                        getchar();
                        encontrado = 1;
                        tablita_entxt(file, productos, num_productos);
                        printf("Producto editado correctamente.\n");
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Producto no encontrado.\n");
                }
                break;
            case 3:
                char eliminar_nombre[50];
                printf("Ingrese el nombre del producto a eliminar:\n");
                fgets(eliminar_nombre, 50, stdin);
                cambiando_saltolinea(eliminar_nombre);
                int eliminado = 0;
                for (int i = 0; i < num_productos; i++) {
                    if (strcmp(productos[i].nombre, eliminar_nombre) == 0) {
                        for (int j = i; j < num_productos - 1; j++) {
                            productos[j] = productos[j + 1];
                        }
                        num_productos--;
                        tablita_entxt(file, productos, num_productos);
                        printf("Se eliminó el producto correctamente.\n");
                        eliminado = 1;
                        break;
                    }
                }
                if (!eliminado) {
                    printf("Producto no encontrado.\n");
                }
                break;
            case 4:
                printf("Opción 4: Ver lista de productos.\n");
                printf("Nombre           | Cantidad   | Precio\n");
                printf("---------------------------------------------\n");
                for (int i = 0; i < num_productos; i++) {
                    printf("%-17s| %-10d| %.2f\n", productos[i].nombre, productos[i].cantidad, productos[i].precio);
                }
                break;
            case 5:
                printf("Saliendo del sistema, se han guardado todos los cambios.\n");
                fclose(file);
                return 0;
            default:
                printf("Opción no válida.\n");
                break;
        }
    }

    return 0;
}

