#include <stdio.h>
#include <stdlib.h>
//#include <termios.h>
//#include "EasyPIO.h"
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
//#include <ncurses.h>

// Declaracion de funciones
void retardo(unsigned long int a);//ya esta
void autoFantastico(unsigned long int);
void choque(unsigned long int);
void carrera();
void pulso_expansivo();
void loading();

void mostrar(unsigned char);
//void mostrarPassword();
int verificarPassword(const char *clave);
void controlarVelocidad();
void disp_binary(unsigned char valor);

const char led[] = {14,15,18,23,24,25,8,7};

unsigned char TablaAf []= {0x01, 0x02, 0x04,0x08,0x10, 0x20, 0x40, 0x80};
unsigned char TablaCh []= {0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81};
unsigned char TablaCa []= {0x01, 0x01 ,0x03, 0x03, 0x05, 0x05, 0x09, 0x09, 0x11,0x12,0x24,0x28,0x50,0x60,0x40,0x80};
unsigned char TP[] = {0x88, 0x48, 0x28, 0x18, 0x14, 0x12, 0x12, 0x14, 0x18,0x28,0x48,0x48, 0x28,0x18,0x14,0x14,0x18,0x28,0x28,0x18,0x18,0x18};


void disp_binary(unsigned char valor) {
    int t;
    const char led[] = {14, 15, 18, 23, 24, 25, 8, 7};

    //system("cls");
    for (t = 128; t > 0; t = t/2) {
        if ( valor & t) {
            printf("1");
            //digitalWrite(led[i], 1);
        } else {
            printf("0");
            //digitalWrite(led[i], 0);
        }
    }
     printf("\n");
} 


//funciones
void retardo(unsigned long int a){
    while (a)
    a--;
}

void choque (unsigned long int speed){


     while(1){
         for (int i = 0; i<8; i++ ){
            printf("Delay: %lu\n", speed);
            LS(TablaCh[i]);
            retardo(speed);
            system("clear");



         }



     }

}


void autoFantastico(unsigned long int speed) {
    unsigned int pos = 0x80;
    
    while (1) {
        for (int i = 0; i < 8; ++i) {
            printf("Presione ESC para volver al menú principal\n");
            printf("Delay: %lu\n", speed);
            
            // Mostrar la posición actual en los LEDs
            disp_binary(pos);
            
            pos >>= 1;
            retardo(speed);
            system("clear");
        }
        
        for (int i = 6; i >= 0; --i) {
            printf("Presione ESC para volver al menú principal\n");
            printf("Delay: %lu\n", speed);
            
            // Mostrar la posición actual en los LEDs
            disp_binary(pos);
            
            pos <<= 1;
            retardo(speed);
            system("clear");
        }
    }
}
void carrera(){}

void pulso_expansivo(){}

void loading(){}


void mostrarPassword() {
    printf("\nIngrese su password de 5 digitos: ");
}


int main() {
    unsigned long int speedini = 150000000;
    unsigned long int speed = speedini;
		
    char opcion;
    
    do {

        printf("---- MENU ----\n");
		printf("1. Auto Fantastico\n");
		printf("2. Choque\n");
		printf("3. Carrera\n");
		printf("4. Pulso Expansivo 1\n");
		printf("5. Loading 2\n");
		printf("6. Salir\n");
		printf("Ingrese una opcion: ");

        scanf("%d", &opcion);
        
        switch (opcion) {
        case 1:
			printf("Auto Fantastico\n");
			system("clear");
			autoFantastico(speed);
			break;
		case 2:
			printf("Choque\n");
			system("clear");
			choque(speed);
			break;
		case 3:
            printf("Arco Iris\n");
			system("clear");
			//sistema propio
			break;
		case 4:
            printf("Intermitente\n");
			system("clear");
			//sistema propio
			break;
		case 5:
			system("clear");
			printf("Adios\n");
			break;
		default:
			system("clear");
			printf("Has seleccionado una opcion no disponible en el menu, intentalo de nuevo.\n");
		}
    } while (opcion != 5);
    
    return 0;
}