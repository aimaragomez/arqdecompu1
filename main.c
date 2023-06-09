#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Declaracin de funciones
void retardo(unsigned long int);
void mostrar(unsigned char);
void autoFantastico(unsigned long int);
void carrera(unsigned long int);
void choque(unsigned long int);
void mostrarPassword();
int verificarPassword(const char *clave);
void imprimirMensajeBienvenida();
void imprimirMensajePasswordInvalida();
void controlarVelocidad();

// Variables globales
const char clave[] = "12345"; // Clave de acceso al sistema
int intentos = 0; // Contador de intentos de acceso

int main() {
    unsigned long int speedini = 150000000;
    unsigned long int speed = speedini;
		
    char opcion;
    
    do {

        printf("---- MENU ----\n");
		printf("1. Auto Fantastico\n");
		printf("2. Choque\n");
		printf("3. Carrera\n");
		printf("4. Secuencia Propia 1\n");
		printf("5. Secuencia Propia 2\n");
		printf("6. Salir\n");
		printf("Ingrese una opcion: ");

        scanf("%d", &opcion);

        mostrarMenu();
        opcion = getch();
        
        switch (opcion) {
            case '1':
                autoFantastico();
                break;
            case '2':
                carrera();
                break;
            case '3':
                // Secuencia propia con algoritmo
                break;
            case '4':
                // Secuencia propia con tabla de datos
                break;
            case '0':
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion no valida. Intente nuevamente.\n");
                break;
        }
        
    } while (opcion != '0');
    
    return 0;
}

void retardo(unsigned long int a){
    while (a)
    a--;
}

void choque(unsigned long int speed){



}


void autoFantastico (unsigned long int F) {
    printf("\nEjecutando secuencia: Auto fantastico\n");
    printf("Presione cualquier tecla para volver al menu principal.\n");
    
    controlarVelocidad();
    
    // C�digo para la secuencia "Auto fantastico"
    
    getch(); // Esperar a que se presione una tecla para volver al men� principal
}

void carrera(unsigned long int c) {
    printf("\nEjecutando secuencia: La carrera\n");
    printf("Presione cualquier tecla para volver al menu principal.\n");
    
    controlarVelocidad();
    
    // C�digo para la secuencia "La carrera"
    
    getch(); // Esperar a que se presione una tecla para volver al men� principal
}


void mostrarPassword() {
    printf("\nIngrese su password de 5 digitos: ");
}

int verificarPassword(const char *clave) {
    char password[6];
    int i;
    
    mostrarPassword();
    
    for (i = 0; i < 5; i++) {
        password[i] = getch();
        printf("*");
    }
    password[5] = '\0'; // Terminador de cadena
    
    if (strcmp(password, clave) == 0) {
        return 1; // Password correcta
    } else {
        return 0; // Password incorrecta
    }
}

void imprimirMensajeBienvenida() {
    printf("\nBienvenido al Sistema.\n");
}

void imprimirMensajePasswordInvalida() {
    printf("\nPassword no valida.\n");
}

void controlarVelocidad() {
    int velocidad = 5; // Valor inicial de la velocidad
    
    while (1) {
        int tecla = getch();
        
        if (tecla == 224) { // Tecla de funci�n especial
            tecla = getch();
            
            if (tecla == 72) { // Flecha hacia arriba
                velocidad++;
                printf("\nVelocidad incrementada: %d\n", velocidad);
            } else if (tecla == 80) { // Flecha hacia abajo
                velocidad--;
                printf("\nVelocidad reducida: %d\n", velocidad);
            }
        } else {
            break; // Salir del bucle si se presiona otra tecla
        }
    }
}


