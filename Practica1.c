#include <stdio.h>
#include <string.h>

void main() {
	system("COLOR E4"); //Color amarillo de fonfo y letras rojas
	int p1 = 0, p2 = 0, comparacion1=1, comparacion2=1; //p1=0 y p2=0 significa que las plazas 1 y 2 están inicialmente libres
	char m1[8];
	char m2[8];
	char m3[8]; //m3 es el valor que introduce la persona y se usa para comparar con los ya registrados
	char opcion;
	while (1) {
		system("cls");
		printf("Bienvenido al parking Sol\n");
		printf("Seleccione una opcion\n");
		printf("R - Reservar plaza\n");
		printf("A - Abandonar plaza\n");
		printf("E - Estado del aparcamiento\n");
		scanf_s("%c", &opcion);
		getchar();
		switch (opcion) {
		case 'R':
		case 'r':
			if (p1 == 0) {
				p1 = 1;
				system("cls");
				printf("Introduzca el numero de su matricula\n");
				gets(m1);
				printf("El coche con numero de matricula %s ha reservado la plaza 1\n", m1);
				system("pause");
			}
			else if (p2 == 0 && p1 == 1) {
				p2 = 1;
				system("cls");
				printf("Introduzca el numero de su matricula\n");
				gets(m2);
				printf("El coche con numero de matricula %s ha reservado la plaza 2\n", m2);
				system("pause");
			}
			else {
				printf("Lo sentimos, el parking ya esta completo\n");
				system("pause");
			}
			break;
		case 'A':
		case 'a':
			if (p1 == 0 & p2 == 0) {
				printf("El parking esta vacio\n");
				system("pause");
				break;
			}
			else {
				system("cls");
				printf("Introduzca el numero de matricula\n");
				gets(m3);
				comparacion1 = strcmp(m1, m3); //Con strcmp se comparan las cadenas, si es 0 es que son iguales
				comparacion2 = strcmp(m2, m3);
				if (comparacion1 == 0) {
					p1 = 0;
					printf("Ahora la plaza 1 esta libre\n");
				}
				else if (comparacion2 == 0) {
					p2 = 0;
					printf("Ahora la plaza 2 esta libre\n");
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
			if (p1 == 1) {
				printf("La plaza 1 la ocupa el vehiculo %s\n", m1);
			}
			else {
				printf("La plaza 1 esta libre\n");
			}
			if (p2 == 1) {
				printf("La plaza 2 la ocupa el vehiculo %s\n", m2);
			}
			else {
				printf("La plaza 2 esta libre\n");
			}
			system("pause");
			break;
		default:
			printf("Caracter incorrecto\n");
			system("pause");
		}
	}
	system("pause");
}
