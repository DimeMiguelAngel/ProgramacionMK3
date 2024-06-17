//EstructuraFacturaPunteroMK1
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define IVA 0.15

struct direccion {
  char ciudad[40];
  char area[40];
  char direccion[40];
  char postal[5];
};

struct header {
  char compania[40];
  char ruc[15];
  char numerofact[100];
  char fecha[10];
  char agente[40];
  char cliente[40];
  char cedula[15];
  struct direccion direccion;
  char telefono[10];
  char correo[40];
};

struct detalles {
  char postal[5];
  char producto[40];
  int cantidad;
  float precio;
  float valor;
};

struct factura {
  struct header header;
  struct detalles detalles;
  float subtotal;
  float iva; 
  float total; 
};

int main(void) {

  struct factura factura = {{"Stark Industries" , "1722248216" , "005" , "09/08/2024" , "Anthony Stark" , "Steve Rogers" , "16485973" , {"New York" , "Manhattan" , "Midtown" , "506"} , "0984211783" , "steve@avengers.com"} , { "050" , "Escudo de Vibranium" , 1 , 105000.00 , (105000.00 * 1)} , (105000.00 * 1) , (105000.00 * 1) * IVA , (105000.00 * 1) + ((105000.00 * 1) * IVA) } ; 

  printf("\e[1;34m-----------------------------------------------------------------------\e[0m\n");
  printf("\e[1;34m                               FACTURA                            \e[0m\n");
  printf("\e[1;34m-----------------------------------------------------------------------\e[0m\n");
  printf("COMPAÑIA: %s\t\t\tRUC: %s\n\nNo.FACTURA: %s\n\nFECHA DE EMISIÓN: %s\n\nNOMBRE VENDEDOR: %s\n",factura.header.compania, factura.header.ruc, factura.header.numerofact, factura.header.fecha, factura.header.agente );

  printf("-----------------------------------------------------------------------\n");
  printf("\e[1;34m                          DATOS DEL AGENTE                           \e[0m\n");
  printf("-----------------------------------------------------------------------\n");
  printf("NOMBRE: %s\n\nNo.CEDULA: %s\n\nDIRECCION:\n\t\tCIUDAD: %s\n\n\t\tAREA: %s\n\n\t\tCALLE: %s\n\n\t\tCODIGO POSTAL: %s\n\nCELULAR: %s\n\nCORREO ELECTRONICO: %s\n",factura.header.cliente, factura.header.cedula, factura.header.direccion.ciudad, factura.header.direccion.area, factura.header.direccion.direccion, factura.header.direccion.postal, factura.header.telefono, factura.header.correo  );

  printf("-----------------------------------------------------------------------\n");
  printf("\e[1;34m                          DETALLE DE LA COMPRA                            \e[0m\n");
  printf("-----------------------------------------------------------------------\n");
  printf("CODIGO: %s\t\t\tNOMBRE DEL PRODUCTO: %s\n\nCANTIDAD: %d\t\t\tPRECIO UNITARIO: %.2f\n\n\t\t\t\tVALOR TOTAL: %.2f\n\n\n-----------------------------------------------------------------------\nSUBTOTAL: %.2f\n\nIVA (15%%): %.2f\n\nTOTAL A PAGAR: %.2f\n\n", factura.detalles.postal, factura.detalles.producto, factura.detalles.cantidad, factura.detalles.precio, factura.detalles.valor, factura.subtotal, factura.iva, factura.total );
  printf("-----------------------------------------------------------------------\n");

  return 0;
}
