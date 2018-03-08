//Programa para gestionar 2 plazas de aparcamiento en un bucle infinito. Por Ismael Gómez Pacheco
#include <stdio.h>

void main() {
	int p1=0, p2=0, m1=0, m2=0, m3;
	char opcion, basura; //basura es un dato que que se guarda y no hace nada, ya que al tocar cualquier tecla el programa la registra y provoca problemas
	system("COLOR E4");
	while (1) {
		system("cls");
		printf("Bienvenido al parking Sol\n");
		printf("Seleccione una opcion\n");
		printf("R - Reservar plaza\n");
		printf("A - Abandonar plaza\n");
		printf("E - Estado del aparcamiento\n");
		scanf_s("%c", &opcion);

		switch (opcion) {
		case 'R':
		case 'r':
			if (p1 == 0) {
				p1 = 1;
				while (1) {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					scanf_s("%d", &m1);
					if (m1 < 0 || m1 > 9999) {
						printf("La matricula debe contener 4 digitos, vuelva a introducirla\n");
					}
					else {
						break;
					}
					system("pause");
					scanf_s("%c", &basura);
				}
				printf("El coche con numero de matricula %d ha reservado la plaza 1\n", m1);
				system("pause");
				scanf_s("%c", &basura);
			}
			else if (p2==0 && p1==1) {
				p2 = 1;
				while (1) {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					scanf_s("%d", &m2);
					if (m2 < 0 || m2 > 9999) {
						printf("La matricula debe contener 4 digitos, vuelva a introducirla\n");
					}
					else {
						break;
					}
					system("pause");
					scanf_s("%c", &basura);
				}
				printf("El coche con numero de matricula %d ha reservado la plaza 2\n", m2);
				system("pause");
				scanf_s("%c", &basura);
			}
			else {
				printf("Lo sentimos, el parking ya esta completo\n");
				system("pause");
				scanf_s("%c", &basura);
			}
			break;
		case 'A':
		case 'a':
			if (p1 == 0 & p2 == 0) {
				printf("El parking esta vacio\n");
				system("pause");
				scanf_s("%c", &basura);
				break;
			}
			else{
				while (1) {
					system("cls");
					printf("Introduzca el numero de matricula\n");
					scanf_s("%d", &m3);
					if (m3 == m1) {
						p1 = 0;
						printf("Ahora la plaza 1 esta libre\n");
						break;
					}
					else if (m3 == m2) {
						p2 = 0;
						printf("Ahora la plaza 2 esta libre\n");
						break;
					}
					else {
						printf("La matricula no corresponde con ningun vehiculo registrado\n");
						break;
					}
				}
			}
			system("pause");
			scanf_s("%c", &basura);
			break;
		case 'E':
		case 'e':
			system("cls");
			if (p1 == 1) {
				printf("La plaza 1 la ocupa el vehiculo %d\n", m1);
			}
			else {
				printf("La plaza 1 esta libre\n");
			}
			if (p2 == 1) {
				printf("La plaza 2 la ocupa el vehiculo %d\n", m2);
			}
			else {
				printf("La plaza 2 esta libre\n");
			}
			system("pause");
			scanf_s("%c", &basura);
			break;
		default:
			printf("Caracter incorrecto\n");
			system("pause");
			scanf_s("%c", &basura);
			break;
		}
	}
}