#include <stdio.h>
#include <string.h>

void main() {
	system("COLOR E4");
	int i, pc1 = 0, pc2 = 0, pm1=0, pm2=0, comparacionC1 = 1, comparacionC2 = 1, comparacionM1=1, comparacionM2=1;
	char mc1[8], mm1[8];
	char mc2[8], mm2[8];
	char m3[8];
	char opcion, vehiculo;
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
				if (pc1 == 0) {
					pc1 = 1;
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(mc1);
					printf("El coche con numero de matricula %s ha reservado la plaza 1\n", mc1);
					system("pause");
				}
				else if (pc2 == 0 && pc1 == 1) {
					pc2 = 1;
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(mc2);
					printf("El coche con numero de matricula %s ha reservado la plaza 2\n", mc2);
					system("pause");
				}
				else {
					printf("Lo sentimos, el parking de coches ya esta completo\n");
					system("pause");
				}
				break;
			case 'M':
			case 'm':
				if (pm1 == 0) {
					pm1 = 1;
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(mm1);
					printf("La moto con numero de matricula %s ha reservado la plaza 1\n", mm1);
					system("pause");
				}
				else if (pm2 == 0 && pm1 == 1) {
					pm2 = 1;
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(mm2);
					printf("La moto con numero de matricula %s ha reservado la plaza 2\n", mm2);
					system("pause");
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
			if (pc1 == 0 && pc2 == 0) {
				if (pm1 == 0 && pm2 == 0) {
					printf("El parking esta vacio\n");
					system("pause");
					break;
				}
			}
			else {
				system("cls");
				printf("Introduzca el numero de matricula\n");
				gets(m3);
				comparacionC1 = strcmp(mc1, m3);
				comparacionC2 = strcmp(mc2, m3);
				comparacionM1 = strcmp(mm1, m3);
				comparacionM2 = strcmp(mm2, m3);
				if (comparacionC1 == 0) {
					pc1 = 0;
					printf("Ahora la plaza 1 de coches esta libre\n");
				}
				else if (comparacionC2 == 0) {
					pc2 = 0;
					printf("Ahora la plaza 2 de coches esta libre\n");
				}
				else if (comparacionM1 == 0) {
					pm1 = 0;
					printf("Ahora la plaza 1 de motos esta libre\n");
				}
				else if (comparacionM2 == 0) {
					pm2 = 0;
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
			if (pc1 == 1) {
				printf("La plaza 1 la ocupa el coche %s\n", mc1);
			}
			else {
				printf("La plaza 1 de coches esta libre\n");
			}
			if (pc2 == 1) {
				printf("La plaza 2 la ocupa el coche %s\n", mc2);
			}
			else {
				printf("La plaza 2 de coches esta libre\n");
			}
			if (pm1 == 1) {
				printf("La plaza 1 la ocupa la moto %s\n", mm1);
			}
			else {
				printf("La plaza 1 de motos esta libre\n");
			}
			if (pm2 == 1) {
				printf("La plaza 2 la ocupa la moto %s\n", mm2);
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
			comparacionC1 = strcmp(mc1, m3);
			comparacionC2 = strcmp(mc2, m3);
			comparacionM1 = strcmp(mm1, m3);
			comparacionM2 = strcmp(mm2, m3);
			if (comparacionC1 == 0) {
				printf("Su coche ocupa la plaza 1\n");
			}
			else if (comparacionC2 == 0) {
				printf("Su coche ocupa la plaza 2\n");
			}
			else if (comparacionM1 == 0) {
				printf("Su moto ocupa la plaza 1\n");
			}
			else if (comparacionM2 == 0) {
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