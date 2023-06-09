#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Declaración de funciones
void retardo(unsigned long int a);
void autoFantastico();
void laCarrera();
void mostrarMenu();
void mostrarPassword();
int verificarPassword(const char *clave);
void imprimirMensajeBienvenida();
void imprimirMensajePasswordInvalida();
void controlarVelocidad();

// Variables globales
const char clave[] = "12345"; // Clave de acceso al sistema
int intentos = 0; // Contador de intentos de acceso

int main() {
    char opcion;
    
    do {
        mostrarMenu();
        opcion = getch();
        
        switch (opcion) {
            case '1':
                autoFantastico();
                break;
            case '2':
                laCarrera();
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

void retardo(unsigned long int a) {
    while (a) {
        a--;
    }
}

void autoFantastico() {
    printf("\nEjecutando secuencia: Auto fantastico\n");
    printf("Presione cualquier tecla para volver al menu principal.\n");
    
    controlarVelocidad();
    
    // Código para la secuencia "Auto fantastico"
    
    getch(); // Esperar a que se presione una tecla para volver al menú principal
}

void laCarrera() {
    printf("\nEjecutando secuencia: La carrera\n");
    printf("Presione cualquier tecla para volver al menu principal.\n");
    
    controlarVelocidad();
    
    // Código para la secuencia "La carrera"
    
    getch(); // Esperar a que se presione una tecla para volver al menú principal
}

void mostrarMenu() {
    system("cls");
    printf("MENU PRINCIPAL\n");
    printf("1. Auto fantastico\n");
    printf("2. La carrera\n");
    printf("3. Secuencia propia con algoritmo\n");
    printf("4. Secuencia propia con tabla de datos\n");
    printf("0. Salir\n");
    printf("Seleccione una opcion: ");
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
        
        if (tecla == 224) { // Tecla de función especial
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


