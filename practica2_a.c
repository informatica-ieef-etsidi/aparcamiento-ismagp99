#include <stdio.h>

void main() {
	system("COLOR E4");
	int i, j, k, l, pc1 = 0, pc2 = 0, pm1 = 0, pm2 = 0;
	int cc1, cc2, cm1, cm2;
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
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(m3);
					for (l = 1;l > 0;l++) {
						for (j = 4;j < 7;j++) {
							if (m3[j] >= 'A' && m3[j] <= 'Z') {
								for (k = 0;k < 4;k++) {
									if (m3[k] < '0' || m3[k]>'9') {
										printf("La matricula introducida es incorrecta\n");
										system("pause");
										l = -2;
										break;
									}
								}
							}
							else {
								printf("La matricula introducida es incorrecta\n");
								system("pause");
								l = -2;
								break;
							}
						}
						if (l > 0) {
							pc1 = 1;
							for (j = 0;j < 8;j++) {
								mc1[j] = m3[j];
							}
							printf("El coche con numero de matricula %s ha reservado la plaza 1\n", mc1);
							system("pause");
							break;
						}
					}
				}
				else if (pc2 == 0 && pc1 == 1) {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(m3);
					for (l = 1;l > 0;l++) {
						for (j = 4;j < 7;j++) {
							if (m3[j] >= 'A' && m3[j] <= 'Z') {
								for (k = 0;k < 4;k++) {
									if (m3[k] < '0' || m3[k]>'9') {
										printf("La matricula introducida es incorrecta\n");
										system("pause");
										l = -2;
										break;
									}
								}
							}
							else {
								printf("La matricula introducida es incorrecta\n");
								system("pause");
								l = -2;
								break;
							}
						}
						if (l > 0) {
							pc2 = 1;
							for (j = 0;j < 8;j++) {
								mc2[j] = m3[j];
							}
							printf("El coche con numero de matricula %s ha reservado la plaza 2\n", mc2);
							system("pause");
							break;
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
				if (pm1 == 0) {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(m3);
					for (l = 1;l > 0;l++) {
						for (j = 4;j < 7;j++) {
							if (m3[j] >= 'A' && m3[j] <= 'Z') {
								for (k = 0;k < 4;k++) {
									if (m3[k] < '0' || m3[k]>'9') {
										printf("La matricula introducida es incorrecta\n");
										system("pause");
										l = -2;
										break;
									}
								}
							}
							else {
								printf("La matricula introducida es incorrecta\n");
								system("pause");
								l = -2;
								break;
							}
						}
						if (l > 0) {
							pm1 = 1;
							for (j = 0;j < 8;j++) {
								mm1[j] = m3[j];
							}
							printf("La moto con numero de matricula %s ha reservado la plaza 1\n", mm1);
							system("pause");
							break;
						}
					}
				}
				else if (pm2 == 0 && pm1 == 1) {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(m3);
					for (l = 1;l > 0;l++) {
						for (j = 4;j < 7;j++) {
							if (m3[j] >= 'A' && m3[j] <= 'Z') {
								for (k = 0;k < 4;k++) {
									if (m3[k] < '0' || m3[k]>'9') {
										printf("La matricula introducida es incorrecta\n");
										system("pause");
										l = -2;
										break;
									}
								}
							}
							else {
								printf("La matricula introducida es incorrecta\n");
								system("pause");
								l = -2;
								break;
							}
						}
						if (l > 0) {
							pm2 = 1;
							for (j = 0;j < 8;j++) {
								mm2[j] = m3[j];
							}
							printf("La moto con numero de matricula %s ha reservado la plaza 2\n", mm2);
							system("pause");
							break;
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
			if (pc1 == 0 && pc2 == 0) {
				if (pm1 == 0 && pm2 == 0) {
					printf("El parking esta vacio\n");
					system("pause");
					break;
				}
			}
			else {
				system("cls");
				cc1 = 0;
				cc2 = 0;
				cm1 = 0;
				cm2 = 0;
				printf("Introduzca el numero de matricula\n");
				gets(m3);
				for (j = 0;j < 7;j++) {
					if (m3[j] == mc1[j]) {
						cc1++;
					}
					if (m3[j] == mc2[j]) {
						cc2++;
					}
					if (m3[j] == mm1[j]) {
						cm1++;
					}
					if (m3[j] == mm2[j]) {
						cm2++;
					}
				}
				if (cc1 == 7) {
					pc1 = 0;
					printf("Ahora la plaza 1 de coches esta libre\n");
				}
				else if (cc2 == 7) {
					pc2 = 0;
					printf("Ahora la plaza 2 de coches esta libre\n");
				}
				else if (cm1 == 7) {
					pm1 = 0;
					printf("Ahora la plaza 1 de motos esta libre\n");
				}
				else if (cm2 == 7) {
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
			cc1 = 0;
			cc2 = 0;
			cm1 = 0;
			cm2 = 0;
			printf("Introduzca el numero de matricula de su vehiculo para ver su estado\n");
			gets(m3);
			for (j = 0;j < 7;j++) {
				if (m3[j] == mc1[j]) {
					cc1++;
				}
				if (m3[j] == mc2[j]) {
					cc2++;
				}
				if (m3[j] == mm1[j]) {
					cm1++;
				}
				if (m3[j] == mm2[j]) {
					cm2++;
				}
			}
			if (cc1 == 7) {
				printf("Su coche ocupa la plaza 1\n");
			}
			else if (cc2 == 7) {
				printf("Su coche ocupa la plaza 2\n");
			}
			else if (cm1 == 7) {
				printf("Su moto ocupa la plaza 1\n");
			}
			else if (cm2 == 7) {
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
