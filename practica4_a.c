#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NPLAZAS 10 //N�mero de plazas del parking
#define NPLAZASC 5 //N�mero de plazas de coche
#define AUTORIZACIONES 3 //N�mero de usuarios distintos autorizados para usar el programa

struct TPlaza {
	char tipo; //C si es de coche y M si es de moto
	int estado; //0-libre 1-ocupado
	char matricula[8];
};
struct TUsuario {
	char nombreusuario[50];
	char contrase�a[50];
};

void main() {
	system("COLOR E4"); //Color amarillo de fondo y letras rojas
	struct TPlaza parking[NPLAZAS]; //Vector de estructura de las plazas
	struct TUsuario autorizados[AUTORIZACIONES] = { //Vector de estructura de los usuarios
		{ "Admin", "administrador1234" }, //Usuario1
		{ "Revisor", "revision" }, //Usuario2
		{ "ismagp99", "practicainformatica" } //Usuario3
	};
	int i, j, k; //Para bucles, contadores y dem�s utilidades
	char acceso[50]; //Registra el usuario y despu�s la contrase�a introducidos
	char mat[8]; //valor que introduce la persona y se usa para comparar con los ya registrados
	char opcion, vehiculo;
	for (i = 0;i < NPLAZAS;i++) { //Ponemos que el parking inicialmente est� vac�o
		parking[i].estado = 0;
	}
	for (i = 1; i < 4; i++) { //Ofrece 3 intentos para introducir usuario y contrase�a
		system("cls");
		printf("Introduzca su usuario: ");
		gets(acceso);
		for (j = 0;j < AUTORIZACIONES;j++) { //Compara usuario
			if (strcmp(acceso, autorizados[j].nombreusuario) == 0) {
				break;
			}
		}
		if (j < AUTORIZACIONES) { //Compara contrase�a, solo la asociada al usuario introducido previamente
			printf("\nIntroduzca su contrasena: ");
			gets(acceso);
			if (strcmp(acceso, autorizados[j].contrase�a) == 0) {
				break;
			}
			else {
				printf("Contrasena incorrecta\n");
			}
		}
		else {
			printf("Usuario incorrecto\n");
		}
		printf("Le quedan %d intentos\n", 3-i);
		system("pause");
		if (i == 3) { //A los 3 intentos se cierra el programa
			system("cls");
			printf("Ha gastado los 3 intentos que tenia, vuelva otro dia\n");
			system("pause");
			return;
		}
	}
	for (i = 1; i > 0;i++) {
		system("cls");
		printf("Bienvenido al parking Sol\n");
		printf("Seleccione una opcion\n");
		printf("R - Reservar plaza\n");
		printf("A - Abandonar plaza\n");
		printf("E - Estado del aparcamiento\n");
		printf("B - Buscar vehiculo por matricula\n");
		printf("S - Salir del programa\n");
		scanf_s("%c", &opcion);
		getchar();
		switch (opcion) {
		case 'R':
		case 'r':
			system("cls");
			printf("C - Reservar plaza de coche\n");
			printf("M - Reservar plaza de moto\n");
			scanf_s("%c", &vehiculo);
			getchar();
			switch (vehiculo) {
			case 'C':
			case 'c':
				for (j = 0;j < NPLAZASC;j++) { //Busca si hay plazas libres
					if (parking[j].estado != 1) {
						break;
					}
				}
				if (j == NPLAZASC) {
					printf("Lo sentimos, el parking de coches ya esta completo\n");
					system("pause");
				}
				else {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(mat);
					for (j = 0;j < NPLAZAS;j++) { //Busca matr�culas repetidas
						if (strcmp(mat, parking[j].matricula) == 0) {
							break;
						}
					}
					if (j != NPLAZAS) { //Impide que se repitan matr�culas
						printf("El vehiculo con la matricula introducida ya esta registrado\n");
						system("pause");
						break;
					}
					else { //Se analiza que la matr�cula siga la estructura NNNNLLL
						k = 0;
						for (j = 0;j < 4;j++) { //Primero comprueba los n�meros
							if (mat[j] >= '0' && mat[j] <= '9') {
								k++;
							}
						}
						for (j = 4;j < 7;j++) { //Aqu� comprueba las letras
							if (mat[j] >= 'A' && mat[j] <= 'Z') {
								k++;
							}
						}
						if (k != 7) { //Si el contador k no valida los 7 caracteres se rechaza la matr�cula
							printf("La matricula introducida es incorrecta\n");
							system("Pause");
						}
						else {
							for (j = 0;j < NPLAZASC;j++) { //Solo se ofrecen NPLAZASC de coches
								if (parking[j].estado == 0) {
									parking[j].estado = 1;
									parking[j].tipo = 'C'; //Registra el veh�culo como coche
									strcpy(parking[j].matricula, mat); //Registra la matr�cula introducida como matr�cula de la plaza j
									printf("El coche con numero de matricula %s ha reservado la plaza %d\n", parking[j].matricula, j + 1); //j+1 porque j empieza en 0
									system("pause");
									break;
								}
							}
						}
					}
				}
				break;
			case 'M':
			case 'm':
				for (j = NPLAZASC;j < NPLAZAS;j++) {
					if (parking[j].estado != 1) {
						break;
					}
				}
				if (j == NPLAZAS) {
					printf("Lo sentimos, el parking de motos ya esta completo\n");
					system("pause");
				}
				else {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(mat);
					for (j = 0;j < NPLAZAS;j++) {
						if (strcmp(mat, parking[j].matricula) == 0) {
							break;
						}
					}
					if (j != NPLAZAS) {
						printf("El vehiculo con la matricula introducida ya esta registrado\n");
						system("pause");
						break;
					}
					else {
						k = 0;
						for (j = 0;j < 4;j++) {
							if (mat[j] >= '0' && mat[j] <= '9') {
								k++;
							}
						}
						for (j = 4;j < 7;j++) {
							if (mat[j] >= 'A' && mat[j] <= 'Z') {
								k++;
							}
						}
						if (k != 7) {
							printf("La matricula introducida es incorrecta\n");
							system("Pause");
						}
						else {
							for (j = NPLAZASC;j < NPLAZAS;j++) { //Ofrece el resto de plazas (NPLAZAS-NPLAZASC)
								if (parking[j].estado == 0) {
									parking[j].estado = 1;
									parking[j].tipo = 'M'; //Registra el veh�culo como moto
									strcpy(parking[j].matricula, mat);
									printf("La moto con numero de matricula %s ha reservado la plaza %d\n", parking[j].matricula, j + 1);
									system("pause");
									break;
								}
							}
						}
					}
				}
				break;
			default:
				printf("Caracter incorrecto\n");
				system("pause");
			}
			break;
		case 'A':
		case 'a':
			k = 0;
			for (j = 0;j < NPLAZAS;j++) { //El contador k comprueba cuantas plazas libres hay
				if (parking[j].estado == 0) {
					k++;
				}
			}
			if (k == NPLAZAS) {
				printf("El parking esta vacio\n");
				system("pause");
				break;
			}
			else {
				system("cls");
				printf("Introduzca el numero de matricula\n");
				gets(mat);
				for (j = 0;j < NPLAZAS;j++) {
					if (strcmp(mat, parking[j].matricula) == 0) {
						if (parking[j].estado == 0) { //Si el veh�culo ha abandonado el parking su matricula sigue registrada
							j = NPLAZAS;
							break;
						}
						parking[j].estado = 0;
						if (parking[j].tipo == 'C') { //Se ve si el veh�culo que va a salir es coche o moto
							printf("Su coche ha abandonado el parking, ahora la plaza %d esta libre\n", j + 1);
						}
						else {
							printf("Su moto ha abandonado el parking, ahora la plaza %d esta libre\n", j + 1);
						}
						break;
					}
				}
				if (j == NPLAZAS) {
					printf("La matricula no corresponde con ningun vehiculo registrado\n");
				}
			}
			system("pause");
			break;
		case 'E':
		case 'e':
			system("cls");
			printf("Las plazas entre 1 y %d son de coches y entre %d y %d, de motos\n\n", NPLAZASC, NPLAZASC+1, NPLAZAS); //Indica qu� plazas corresponden a cada veh�culo
			for (j = 0;j < NPLAZAS;j++) {
				if (parking[j].estado == 1) { //Indica si plaza la ocupa un coche o una moto
					if (parking[j].tipo == 'C') {
						printf("La plaza %d la ocupa el coche %s\n", j+1, parking[j].matricula);
					}
					else {
						printf("La plaza %d la ocupa la moto %s\n", j + 1, parking[j].matricula);
					}
				}
				else {
					printf("La plaza %d esta libre\n", j+1);
				}
			}			
			system("pause");
			break;
		case 'B':
		case 'b':
			system("cls");
			printf("Introduzca el numero de matricula de su vehiculo para ver su estado\n");
			gets(mat);
			for (j = 0;j < NPLAZAS;j++) {
				if (strcmp(mat, parking[j].matricula) == 0) { //Similar a la opci�n de abandonar
					if (parking[j].estado == 0) { //Si el veh�culo ha abandonado el parking su matricula sigue registrada
						j = NPLAZAS;
						break;
					}
					if (parking[j].tipo == 'C') {
						printf("Su coche ocupa la plaza %d\n", j + 1);
					}
					else {
						printf("Su moto ocupa la plaza %d\n", j + 1);
					}
					break;
				}
			}			
			if (j == NPLAZAS) {
				printf("La matricula no corresponde con ningun vehiculo registrado\n");
			}
			system("pause");
			break;
		case 'S':
		case 's':
			i = -1;
			printf("Gracias por usar nuestros servicios\n");
			break;
		default:
			printf("Caracter incorrecto\n");
			system("pause");
		}
	}
	system("pause");
}