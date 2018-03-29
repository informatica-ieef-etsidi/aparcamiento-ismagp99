#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct TPlaza {
	char tipo;
	int estado;
	char matricula[8];
};
struct TUsuario {
	char nombreusuario[50];
	char contraseña[50];
};

void main() {
	system("COLOR E4");
	struct TPlaza Plaza1 = { "C", 0 }, Plaza2 = { "C", 0 }, Plaza3 = { "M", 0 }, Plaza4 = { "M", 0 };
	struct TUsuario Usuario = { "Admin", "administrador1234" };
	int i, j, k, l;
	char acceso[50];
	char m3[8];
	char opcion, vehiculo;
	for (i = 1; i < 4; i++) {
		system("cls");
		printf("Introduzca su usuario: ");
		gets(acceso);
		if (strcmp(acceso, Usuario.nombreusuario) == 0) {
			printf("\nIntroduzca su contrasena: ");
			gets(acceso);
			if (strcmp(acceso, Usuario.contraseña) == 0) {
				break;
			}
		}
		printf("El usuario o la contrasena son incorrectos, le quedan %d intentos\n", 3-i);
		system("pause");
		if (i == 3) {
			system("cls");
			printf("Ha gastado los 3 intentos que tenia, vuelva otro dia\n");
			system("pause");
			return;
		}
	}
	for (i = 1; i > 0;i++) {
		l = 0;
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
				if (Plaza1.estado != 1 || Plaza2.estado != 1) {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(m3);
					if (strcmp(m3, Plaza1.matricula) == 0 || strcmp(m3, Plaza2.matricula) == 0) {
						printf("El vehiculo con la matricula introducida ya esta registrado\n");
						system("pause");
						break;
					}
					else if (strcmp(m3, Plaza3.matricula) == 0 || strcmp(m3, Plaza4.matricula) == 0) {
						printf("El vehiculo con la matricula introducida ya esta registrado\n");
						system("pause");
						break;
					}
					for (j = 0;j < 4;j++) {
						if (m3[j] >= '0' && m3[j] <= '9') {
							l++;
						}
					}
					for (j = 4;j < 7;j++) {
						if (m3[j] >= 'A' && m3[j] <= 'Z') {
							l++;
						}
					}
					if (l != 7) {
						printf("La matricula introducida es incorrecta\n");
						system("Pause");
					}
					else {
						if (Plaza1.estado == 0) {
							Plaza1.estado = 1;
							strcpy(Plaza1.matricula, m3);
							printf("El coche con numero de matricula %s ha reservado la plaza 1\n", Plaza1.matricula);
							system("pause");
						}
						else {
							Plaza2.estado = 1;
							strcpy(Plaza2.matricula, m3);
							printf("El coche con numero de matricula %s ha reservado la plaza 2\n", Plaza2.matricula);
							system("pause");
						}
					}
				}
				else {
					printf("Lo sentimos, el parking de coches ya esta completo\n");
					system("pause");
				}
				break;
			case 'M':
			case 'm':
				if (Plaza3.estado != 1 || Plaza4.estado != 1) {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(m3);
					if (strcmp(m3, Plaza3.matricula) == 0 || strcmp(m3, Plaza4.matricula) == 0) {
						printf("El vehiculo con la matricula introducida ya esta registrado\n");
						system("pause");
						break;
					}
					else if (strcmp(m3, Plaza1.matricula) == 0 || strcmp(m3, Plaza2.matricula) == 0) {
						printf("El vehiculo con la matricula introducida ya esta registrado\n");
						system("pause");
						break;
					}
					for (j = 0;j < 4;j++) {
						if (m3[j] >= '0' && m3[j] <= '9') {
							l++;
						}
					}
					for (j = 4;j < 7;j++) {
						if (m3[j] >= 'A' && m3[j] <= 'Z') {
							l++;
						}
					}
					if (l != 7) {
						printf("La matricula introducida es incorrecta\n");
						system("Pause");
					}
					else {
						if (Plaza3.estado == 0) {
							Plaza3.estado = 1;
							strcpy(Plaza3.matricula, m3);
							printf("La moto con numero de matricula %s ha reservado la plaza 1\n", Plaza3.matricula);
							system("pause");
						}
						else {
							Plaza4.estado = 1;
							strcpy(Plaza4.matricula, m3);
							printf("La moto con numero de matricula %s ha reservado la plaza 2\n", Plaza4.matricula);
							system("pause");
						}
					}
				}
				else {
					printf("Lo sentimos, el parking de motos ya esta completo\n");
					system("pause");
				}
				break;
				
			default:
				printf("Caracter incorrecto\n");
				system("pause");
			}
			break;
		case 'A':
		case 'a':
			if (Plaza1.estado == 0 && Plaza2.estado == 0) {
				if (Plaza3.estado == 0 && Plaza4.estado == 0) {
					printf("El parking esta vacio\n");
					system("pause");
					break;
				}
			}
			else {
				system("cls");
				printf("Introduzca el numero de matricula\n");
				gets(m3);
				if (strcmp(m3, Plaza1.matricula) == 0) {
					Plaza1.estado = 0;
					printf("Ahora la plaza 1 de coches esta libre\n");
				}
				else if (strcmp(m3, Plaza2.matricula) == 0) {
					Plaza2.estado = 0;
					printf("Ahora la plaza 2 de coches esta libre\n");
				}
				else if (strcmp(m3, Plaza3.matricula) == 0) {
					Plaza3.estado = 0;
					printf("Ahora la plaza 1 de motos esta libre\n");
				}
				else if (strcmp(m3, Plaza4.matricula) == 0) {
					Plaza4.estado = 0;
					printf("Ahora la plaza 2 de motos esta libre\n");
				}
				else {
					printf("La matricula no corresponde con ningun vehiculo registrado\n");
				}
			}
			system("pause");
			break;
		case 'E':
		case 'e':
			system("cls");
			if (Plaza1.estado == 1) {
				printf("La plaza 1 la ocupa el coche %s\n", Plaza1.matricula);
			}
			else {
				printf("La plaza 1 de coches esta libre\n");
			}
			if (Plaza2.estado == 1) {
				printf("La plaza 2 la ocupa el coche %s\n", Plaza2.matricula);
			}
			else {
				printf("La plaza 2 de coches esta libre\n");
			}
			if (Plaza3.estado == 1) {
				printf("La plaza 1 la ocupa la moto %s\n", Plaza3.matricula);
			}
			else {
				printf("La plaza 1 de motos esta libre\n");
			}
			if (Plaza4.estado == 1) {
				printf("La plaza 2 la ocupa la moto %s\n", Plaza4.matricula);
			}
			else {
				printf("La plaza 2 de motos esta libre\n");
			}
			system("pause");
			break;
		case 'B':
		case 'b':
			system("cls");
			
			printf("Introduzca el numero de matricula de su vehiculo para ver su estado\n");
			gets(m3);
			if (strcmp(m3, Plaza1.matricula) == 0) {
				printf("Su coche ocupa la plaza 1\n");
			}
			else if (strcmp(m3, Plaza2.matricula) == 0) {
				printf("Su coche ocupa la plaza 2\n");
			}
			else if (strcmp(m3, Plaza3.matricula) == 0) {
				printf("Su moto ocupa la plaza 1\n");
			}
			else if (strcmp(m3, Plaza4.matricula) == 0) {
				printf("Su moto ocupa la plaza 2\n");
			}
			else {
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