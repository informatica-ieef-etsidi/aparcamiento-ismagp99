#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NPLAZAS 20 //Número de plazas máximas del parking, las exactas se extraen del fichero
#define AUTORIZACIONES 3 //Número de usuarios distintos autorizados para usar el programa

typedef struct {
	char tipo; //C si es de coche y M si es de moto
	int estado; //0-libre 1-ocupado
	char matricula[8];
}Plaza;
typedef struct { //Para ordenar las plazas alfabéticamente
	char matricula[8];
	char mataux[8]; //Seguirá la estructura LLLNNNN
}Plazaux;
typedef struct {
	char nombreusuario[50];
	char contraseña[50];
}Usuario;

char menu();
int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[]);
int existeUsuario(Usuario usuarioValido[], char username[], char password[]);
void recuento(Plaza aparcamiento[], int dim, int *nLibresCoches, int *nLibresMotos);
void letrero();
int buscarPlazaLibre(Plaza aparcamiento[], int dim, char tipo);
int buscarVehiculo(Plaza aparcamiento[], int dim, char matricula[]);
void ordenar(Plaza aparcamiento[], int dim, Plazaux plaza[]);
void sacarMataux(Plaza aparcamiento[], Plazaux plaza[], int dim); //Necesaria para ordenar las matrículas
void leerFichero(char nombreFichero[], Plaza aparcamiento[], int * dim);
void salvarFichero(char nombreFichero[], Plaza aparcamiento[], int dim);

void main() {
	system("COLOR E4"); //Color amarillo de fondo y letras rojas
	Plazaux plazaux[NPLAZAS];
	Plaza parking[NPLAZAS]; //Vector de estructura de las plazas
	Usuario autorizados[AUTORIZACIONES] = { //Vector de estructura de los usuarios
		{ "Admin", "administrador1234" }, //Usuario1
		{ "Revisor", "revision" }, //Usuario2
		{ "ismagp99", "practicainformatica" } //Usuario3
	};
	int i = 1, j; //Para bucles, contadores y demás utilidades
	int nplazas, nplazasc = 0; //nplazasc indica las plazas que hay de coche
	int libC, libM, plaza; //lib son el número de plazas de coches y motos libres y plaza es la primera plaza libre que encuentra la función buscarPlazaLibre
	char acceso1[50]; //Registra el usuario introducido
	char acceso2[50]; //Registra la contraseña introducida
	char mat[8]; //valor que introduce la persona y se usa para comparar con los ya registrados
	char opcion; //Para los switch
	while (1) { //Bucle para iniciar sesión
		system("cls");
		letrero();
		printf("Introduzca su usuario: ");
		gets(acceso1);
		printf("Introduzca su contrasena: ");
		gets(acceso2);
		if (existeUsuario(autorizados, acceso1, acceso2) == 1) { //Si coincide el usuario y contraseña sale del bucle e inicia el programa
			break;
		}
		else {
			printf("Usuario o contrasena incorrectos\n");
		}
		printf("Le quedan %d intentos\n", 3-i);
		system("pause");
		if (i == 3) { //A los 3 intentos se cierra el programa
			system("cls");
			printf("Ha gastado los 3 intentos que tenia, vuelva otro dia\n");
			system("pause");
			return;
		}
		i++;
	}
	leerFichero("plazas.txt", parking, &nplazas);
	while (1) {
		menu();
		scanf_s("%c", &opcion);
		getchar();
		switch (opcion) {
		case 'R':
		case 'r':
			system("cls");
			printf("C - Reservar plaza de coche\n");
			printf("M - Reservar plaza de moto\n");
			scanf_s("%c", &opcion);
			getchar();
			switch (opcion) {
			case 'C':
			case 'c':
				plaza = buscarPlazaLibre(parking, nplazas, 'C'); //Busca si hay plazas libres
				if (plaza == -1) {
					printf("Lo sentimos, el parking de coches ya esta completo\n");
					system("pause");
				}
				else {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(mat);
					for (i = 0;i < nplazas;i++) { //Busca matrículas repetidas
						if (strcmp(mat, parking[i].matricula) == 0) {
							break;
						}
					}
					if (i != nplazas) { //Impide que se repitan matrículas
						printf("El vehiculo con la matricula introducida ya esta registrado\n");
						system("pause");
						break;
					}
					else { //Se analiza que la matrícula siga la estructura NNNNLLL
						if (esMatriculaValida(mat) == 0) {
							printf("La matricula introducida es incorrecta\n");
							system("Pause");
						}
						else {
							parking[plaza].estado = 1;
							strcpy(parking[plaza].matricula, mat); //Registra la matrícula introducida como matrícula de la posición plaza
							printf("El coche con numero de matricula %s ha reservado la plaza %d\n", parking[plaza].matricula, plaza + 1); //plaza + 1 porque parking empieza en 0
							system("pause");
							salvarFichero("plazas.txt", parking, nplazas);
						}
					}
				}
				break;
			case 'M':
			case 'm':
				plaza = buscarPlazaLibre(parking, nplazas, 'M');
				if (plaza == -1) {
					printf("Lo sentimos, el parking de motos ya esta completo\n");
					system("pause");
				}
				else {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(mat);
					for (i = 0;i < nplazas;i++) {
						if (strcmp(mat, parking[i].matricula) == 0) {
							break;
						}
					}
					if (i != nplazas) {
						printf("El vehiculo con la matricula introducida ya esta registrado\n");
						system("pause");
						break;
					}
					else {
						if (esMatriculaValida(mat) == 0) {
							printf("La matricula introducida es incorrecta\n");
							system("Pause");
						}
						else {
							parking[plaza].estado = 1;
							strcpy(parking[plaza].matricula, mat);
							printf("La moto con numero de matricula %s ha reservado la plaza %d\n", parking[plaza].matricula, plaza + 1);
							system("pause");
							salvarFichero("plazas.txt", parking, nplazas);
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
			for (i = 0;i < nplazas;i++) { //i comprueba cuantas plazas libres hay
				if (parking[i].estado != 0) {
					break;
				}
			}
			if (i == nplazas) { //Si i = nplazas significa que ninguna plaza está vacía y por eso no ha hecho el break en el bucle anterior
				printf("El parking esta vacio\n");
				system("pause");
				break;
			}
			else {
				system("cls");
				printf("Introduzca el numero de matricula\n");
				gets(mat);
				for (i = 0;i < nplazas;i++) {
					if (strcmp(mat, parking[i].matricula) == 0) {
						parking[i].estado = 0;
						for (j = 0;j < 7;j++) { //Se "borra" la matrícula del vehículo que sale
							parking[i].matricula[j] = '-';
						}
						if (parking[i].tipo == 'C') { //Se ve si el vehículo que va a salir es coche o moto
							printf("Su coche ha abandonado el parking, ahora la plaza %d esta libre\n", i + 1);
						}
						else {
							printf("Su moto ha abandonado el parking, ahora la plaza %d esta libre\n", i + 1);
						}
						salvarFichero("plazas.txt", parking, nplazas);
						break;
					}
				}
				if (i == nplazas) {
					printf("La matricula no corresponde con ningun vehiculo registrado\n");
				}
			}
			system("pause");
			break;
		case 'E':
		case 'e':
			system("cls");
			recuento(parking, nplazas, &libC, &libM); //Dice cuantas plazas libres hay de cada tipo
			for (i = 0;i < nplazas;i++) { //Saca cuántas plazas de coche hay
				if (parking[i].tipo == 'C') {
					nplazasc++;
				}
			}
			printf("Las plazas entre 1 y %d son de coches y entre %d y %d, de motos\n\n", nplazasc, nplazasc+1, nplazas); //Indica qué plazas corresponden a cada vehículo
			printf("Ahora hay %d plazas libres de coche y %d de moto\n\n", libC, libM);
			for (i = 0;i < nplazas;i++) {
				if (parking[i].estado == 1) { //Indica si plaza la ocupa un coche o una moto
					if (parking[i].tipo == 'C') {
						printf("La plaza %d la ocupa el coche %s\n", i + 1, parking[i].matricula);
					}
					else {
						printf("La plaza %d la ocupa la moto %s\n", i + 1, parking[i].matricula);
					}
				}
				else {
					printf("La plaza %d esta libre\n", i + 1);
				}
			}			
			printf("\n");
			system("pause");
			break;
		case 'B':
		case 'b':
			system("cls");
			printf("Introduzca el numero de matricula de su vehiculo para ver su estado\n");
			gets(mat);	
			i = buscarVehiculo(parking, nplazas, mat); //Busca en que plaza está el vehículo o si no está resgistrado
			if (i == -1) {
				printf("La matricula no corresponde con ningun vehiculo registrado\n");
			}
			else {
				if (parking[i].tipo == 'C') {
					printf("Su coche ocupa la plaza %d\n", i + 1);
				}
				else {
					printf("Su moto ocupa la plaza %d\n", i + 1);
				}
			}
			system("pause");
			break;
		case 'O':
		case 'o':
			sacarMataux(parking, plazaux, nplazas);
			ordenar(parking, nplazas, plazaux); //Imprime todos los vehículos aparcados ordenados alfabéticamente según su matrícula
			system("pause");
			break;
		case 'S':
		case 's':
			printf("Gracias por usar nuestros servicios\n");
			system("pause");
			return;
		default:
			printf("Caracter incorrecto\n");
			system("pause");
		}
	}
	system("pause");
}

char menu() {
	system("cls");
	letrero();
	printf("Bienvenido al parking Sol\n");
	printf("Seleccione una opcion\n");
	printf("R - Reservar plaza\n");
	printf("A - Abandonar plaza\n");
	printf("E - Estado del aparcamiento\n");
	printf("B - Buscar vehiculo por matricula\n");
	printf("O - Para ordenar las plazas alfabeticamente\n");
	printf("S - Salir del programa\n");
}
int esDigitoValido(char caracter) { //Comprueba que el caracter sea un número y devuelve un 1 si lo es
	int i = 1;
	if (caracter < '0' || caracter >'9') {
		i = 0;
	}
	return i;
}
int esLetraValida(char caracter) { //Comprueba que el caracter sea una consonante mayúscula y devuelve un 1 si lo es
	int i = 0;
	if (caracter >= 'B' && caracter <= 'Z' && caracter != 'A' && caracter != 'E' && caracter != 'I' && caracter != 'O' && caracter != 'U') {
		i = 1;
	}
	return i;
}
int esMatriculaValida(char matricula[]) { //Comprueba la estructura NNNNLLL con las funciones anteriores, devuelve un booleano
	int i, j=0;
	for (i = 0;i < 4;i++) {
		if (esDigitoValido(matricula[i]) == 0) {
			return j; //En el momento en el que si incumpla una condición devuelve j=0
		}
	}
	for (i = 4;i < 7;i++) {
		if (esLetraValida(matricula[i]) == 0) {
			return j;
		}
	}
	j = 1;
	return j;
}
int existeUsuario(Usuario usuarioValido[], char username[], char password[]) { //Si el usuario y la contraseña coinciden devuelve un 1
	int i;
	for (i = 0;i < AUTORIZACIONES;i++) {
		if (strcmp(usuarioValido[i].nombreusuario, username) == 0) {
			if (strcmp(usuarioValido[i].contraseña, password) == 0) {
				return 1;
			}
		}
	}
	return 0;
}
void recuento(Plaza aparcamiento[], int dim, int *nLibresCoches, int *nLibresMotos) { //Saca las plazas libresde coches y motos
	int i;
	*nLibresCoches = 0;
	*nLibresMotos = 0;
	for (i = 0;i < dim;i++) {
		if (aparcamiento[i].estado == 0) {
			if (aparcamiento[i].tipo == 'C') {
				*nLibresCoches = *nLibresCoches + 1;
			}
			if (aparcamiento[i].tipo == 'M') {
				*nLibresMotos = *nLibresMotos + 1;
			}
		}
	}
}
void letrero() { //Un letrero para adornar el menú
	printf(" ______     ______     ______    __  _  __  ___     __     _                     _    __     __\n");
	printf("||    \\\\   //    \\\\   ||    \\\\   || //  ||  ||\\\\    ||    //                    //   //\\\\    ||\n");
	printf("||     || //      \\\\  ||     ||  ||//   ||  || \\\\   ||   //                    //   //  \\\\   ||\n");
	printf("||_____|| ||______||  ||_____||  |||    ||  ||  \\\\  ||  ||     ___             \\\\   \\\\   \\\\  ||\n");
	printf("||        ||      ||  ||  \\\\     ||\\\\   ||  ||   \\\\ ||   \\\\     //              \\\\   \\\\  //  ||\n");
	printf("||        ||      ||  ||   \\\\    || \\\\  ||  ||    \\\\||    \\\\___//               //    \\\\//   ||_____\n\n");
}
int buscarPlazaLibre(Plaza aparcamiento[], int dim, char tipo) { //Devuelve la primera plaza libre que encuentra, si no hay devuelve -1
	int i;
	for (i = 0;i < dim;i++) {
		if (aparcamiento[i].tipo ==  tipo) { //Para que si buscamos plaza de un tipo solo saque de ese tipo
			if (aparcamiento[i].estado == 0) {
				break;
			}
		}
	}
	if (i == dim) {
		i = -1;
	}
	return i;
}
int buscarVehiculo(Plaza aparcamiento[], int dim, char matricula[]) { //Devuelve la plaza de un vehículo, si no lo encuentra devuelve -1
	int i;
	for (i = 0;i < dim;i++) {
		if (strcmp(matricula, aparcamiento[i].matricula) == 0) {
			break;
		}
	}
	if (i == dim) {
		i = -1;
	}
	return i;
}
void ordenar(Plaza aparcamiento[], int dim, Plazaux plaza[]) {
	int i, j, p;
	for (i = 0;i < dim - 1;i++) { //Ordena el vector de estructuras auxiliar
		for (j = i + 1;j < dim;j++) {
			if (strcmp(plaza[i].mataux, plaza[j].mataux) == 1) {
				plaza[dim] = plaza[i];
				plaza[i] = plaza[j];
				plaza[j] = plaza[dim];
			}
		}
	}
	for (i = 0, j = 1;i < dim;i++) { //Imprime las matrículas ordenadas
		if (esMatriculaValida(plaza[i].matricula) == 1) {
		p = buscarVehiculo(aparcamiento, dim, plaza[i].matricula); //Averigua en que plaza está la matrícula a imprimir
			printf("%d: El vehiculo con la matricula %s que esta en la plaza %d\n", j, plaza[i].matricula, p + 1);
			j++;
		}
	}
}
void sacarMataux(Plaza aparcamiento[], Plazaux plaza[], int dim) { //Convierte la estructura NNNNLLL en LLLNNNN
	int i, j, k;
	char aux;
	for (i = 0;i < dim;i++) {
		strcpy(plaza[i].mataux, aparcamiento[i].matricula);
		strcpy(plaza[i].matricula, aparcamiento[i].matricula);
		for (j = 0;j < 3;j++) {
			aux = plaza[i].mataux[6];
			for (k = 5;k >= 0;k--) {
				plaza[i].mataux[k + 1] = plaza[i].mataux[k];
			}
			plaza[i].mataux[0] = aux;
		}
	}
}
void leerFichero(char nombreFichero[], Plaza aparcamiento[], int * dim) {
	int i;
	FILE * fichero;
	errno_t error;
	error = fopen_s(&fichero, nombreFichero, "r");
	fscanf_s(fichero, "%d", &*dim); //Saca el valor de nplazas
	for (i = 0;i < *dim;i++) {
		fscanf_s(fichero, "%s %d %c", &aparcamiento[i].matricula, 8, &aparcamiento[i].estado, &aparcamiento[i].tipo); //Inicializa las plazas del programa
	}
	fclose(fichero);
}
void salvarFichero(char nombreFichero[], Plaza aparcamiento[], int dim){
	int i;
	FILE * fichero;
	errno_t error;
	error = fopen_s(&fichero, nombreFichero, "w");
	fprintf(fichero, "%d\n", dim);
	for (i = 0;i < dim;i++) {
		fprintf(fichero, "%s %d %c\n", aparcamiento[i].matricula, aparcamiento[i].estado, aparcamiento[i].tipo);
	}
	fclose(fichero);
}