#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NPLAZAS 10 //Número de plazas del parking
#define NPLAZASC 5 //Número de plazas de coche
#define AUTORIZACIONES 3 //Número de usuarios distintos autorizados para usar el programa

typedef struct {
	char tipo; //C si es de coche y M si es de moto
	int estado; //0-libre 1-ocupado
	char matricula[8];
}Plaza;
typedef struct { //Para ordenar las plazas alfabéticamente
	char matricula[8];
	char mataux[8];
}Plazaux;
typedef struct {
	char nombreusuario[50];
	char contraseña[50];
}Usuario;

char menu();
int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[]);
int existeUsuario(Usuario usuarioValido, char username[], char password[]);
void recuento(Plaza aparcamiento[], int *nLibresCoches, int *nLibresMotos);
void letrero();
void inicializar(Plaza aparcamiento[]);
int buscarPlazaLibre(Plaza aparcamiento[], char tipo);
int buscarVehiculo(Plaza aparcamiento[], char matricula[]);
void ordenar(Plaza aparcamiento[], Plazaux plaza[]);
void sacarMataux(Plaza aparcamiento[], Plazaux plaza[], int i, int pos); //Necesaria para ordenar las matrículas
int sacarPos(Plaza aparcamiento[], Plazaux plaza[]); //Para sacar el valor de pos

void main() {
	system("COLOR E4"); //Color amarillo de fondo y letras rojas
	Plazaux plazaux[NPLAZAS + 1]; //Requiere una posición extra que actúa de auxiliar como se vera en la función sacarMataux
	Plaza parking[NPLAZAS]; //Vector de estructura de las plazas
	Usuario autorizados[AUTORIZACIONES] = { //Vector de estructura de los usuarios
		{ "Admin", "administrador1234" }, //Usuario1
		{ "Revisor", "revision" }, //Usuario2
		{ "ismagp99", "practicainformatica" } //Usuario3
	};
	int i, j, pos; //Para bucles, contadores y demás utilidades, pos es la posición que se usara en el vector plazaux
	int libC, libM, plaza; //lib son el número de plazas de coches y motos libres y plaza es la primera plaza libre que encuentra la función buscarPlazaLibre
	char acceso1[50]; //Registra el usuario introducido
	char acceso2[50]; //Registra la contraseña introducida
	char mat[8]; //valor que introduce la persona y se usa para comparar con los ya registrados
	char opcion, vehiculo;
	inicializar(parking); //Ponemos que el parking inicialmente esté vacío
	for (i = 1; i < 4; i++) { //Ofrece 3 intentos para introducir usuario y contraseña
		system("cls");
		letrero();
		printf("Introduzca su usuario: ");
		gets(acceso1);
		printf("Introduzca su contrasena: ");
		gets(acceso2);
		for (j = 0;j < AUTORIZACIONES;j++) {
			if (existeUsuario(autorizados[j], acceso1, acceso2) == 1) {
				j = -1; //si j=-1 se sale del bucle de iniciar sesión y empieza el programa
				break;
			}
		}
		if (j == -1) {
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
	}
	for (i = 1; i > 0;i++) {
		pos = sacarPos(parking, plazaux);
		menu();
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
				plaza = buscarPlazaLibre(parking, 'C'); //Busca si hay plazas libres
				if (plaza == -1) {
					printf("Lo sentimos, el parking de coches ya esta completo\n");
					system("pause");
				}
				else {
					system("cls");
					printf("Introduzca el numero de su matricula\n");
					gets(mat);
					for (j = 0;j < NPLAZAS;j++) { //Busca matrículas repetidas
						if (strcmp(mat, parking[j].matricula) == 0) {
							break;
						}
					}
					if (j != NPLAZAS) { //Impide que se repitan matrículas
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
							strcpy(parking[plaza].matricula, mat); //Registra la matrícula introducida como matrícula de la plaza j
							sacarMataux(parking, plazaux, plaza, pos); //Saca la mataux del vector auxiliar para cuando queramos ordenarlas
							printf("El coche con numero de matricula %s ha reservado la plaza %d\n", parking[plaza].matricula, plaza + 1); //j+1 porque j empieza en 0
							system("pause");
						}
					}
				}
				break;
			case 'M':
			case 'm':
				plaza = buscarPlazaLibre(parking, 'M'); //Busca la primera plaza libre
				if (plaza == -1) {
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
						if (esMatriculaValida(mat) == 0) {
							printf("La matricula introducida es incorrecta\n");
							system("Pause");
						}
						else {
							parking[plaza].estado = 1;
							strcpy(parking[plaza].matricula, mat);
							sacarMataux(parking, plazaux, plaza, pos);
							printf("La moto con numero de matricula %s ha reservado la plaza %d\n", parking[plaza].matricula, plaza + 1);
							system("pause");
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
			for (j = 0;j < NPLAZAS;j++) { //j comprueba cuantas plazas libres hay
				if (parking[j].estado != 0) {
					break;
				}
			}
			if (j == NPLAZAS) {
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
						parking[j].estado = 0;
						parking[j].matricula[0] = '\0';
						if (parking[j].tipo == 'C') { //Se ve si el vehículo que va a salir es coche o moto
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
			recuento(parking, &libC, &libM); //Dice cuantas plazas libres hay de cada tipo
			printf("Las plazas entre 1 y %d son de coches y entre %d y %d, de motos\n\n", NPLAZASC, NPLAZASC+1, NPLAZAS); //Indica qué plazas corresponden a cada vehículo
			printf("Ahora hay %d plazas libres de coche y %d de moto\n\n", libC, libM);
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
			printf("\n");
			system("pause");
			break;
		case 'B':
		case 'b':
			system("cls");
			printf("Introduzca el numero de matricula de su vehiculo para ver su estado\n");
			gets(mat);	
			j = buscarVehiculo(parking, mat); //Busca en que plaza está el vehículo o si no está resgistrado
			if (j == -1) {
				printf("La matricula no corresponde con ningun vehiculo registrado\n");
			}
			else {
				if (parking[j].tipo == 'C') {
					printf("Su coche ocupa la plaza %d\n", j + 1);
				}
				else {
					printf("Su moto ocupa la plaza %d\n", j + 1);
				}
			}
			system("pause");
			break;
		case 'O':
		case 'o':
			ordenar(parking, plazaux); //Imprimer todos los vehículos aparcados ordenados alfabéticamente según su matrícula
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
			return j;
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
int existeUsuario(Usuario usuarioValido, char username[], char password[]) { //Si el usuario y la contraseña coinciden devuelve un 1
	if (strcmp(usuarioValido.nombreusuario, username) == 0) {
		if (strcmp(usuarioValido.contraseña, password) == 0) {
			return 1;
		}
	}
	return 0;
}
void recuento(Plaza aparcamiento[], int *nLibresCoches, int *nLibresMotos) { //Saca las plazas libres de coches y motos teniendo en cuenta las plazas ocupadas
	int i;
	*nLibresCoches = NPLAZASC;
	*nLibresMotos = NPLAZAS - NPLAZASC;
	for (i = 0;i < NPLAZASC;i++) {
		if (aparcamiento[i].estado == 1) {
			*nLibresCoches = *nLibresCoches - 1;
		}
	}
	for (i = NPLAZASC;i < NPLAZAS;i++) {
		if (aparcamiento[i].estado == 1) {
			*nLibresMotos = *nLibresMotos - 1;
		}
	}
}
void letrero() {
	printf(" ______     ______     ______    __  _  __  ___     __     _                     _    __     __\n");
	printf("||    \\\\   //    \\\\   ||    \\\\   || //  ||  ||\\\\    ||    //                    //   //\\\\    ||\n");
	printf("||     || //      \\\\  ||     ||  ||//   ||  || \\\\   ||   //                    //   //  \\\\   ||\n");
	printf("||_____|| ||______||  ||_____||  |||    ||  ||  \\\\  ||  ||     ___             \\\\   \\\\   \\\\  ||\n");
	printf("||        ||      ||  ||  \\\\     ||\\\\   ||  ||   \\\\ ||   \\\\     //              \\\\   \\\\  //  ||\n");
	printf("||        ||      ||  ||   \\\\    || \\\\  ||  ||    \\\\||    \\\\___//               //    \\\\//   ||_____\n\n");
}
void inicializar(Plaza aparcamiento[]) { //Vacía el parking al inicio del programa y establece el tipo de vehículo
	int i;
	for (i = 0;i < NPLAZASC;i++) {
		aparcamiento[i].estado = 0;
		aparcamiento[i].tipo = 'C';
	}
	for (i = NPLAZASC;i < NPLAZAS;i++) { 
		aparcamiento[i].estado = 0;
		aparcamiento[i].tipo = 'M';
	}
}
int buscarPlazaLibre(Plaza aparcamiento[], char tipo) { //Devuelve una plaza libre, si no hay devuelve -1
	int i;
	if (tipo == 'C') {
		for (i = 0;i < NPLAZASC;i++) { 
			if (aparcamiento[i].estado != 1) {
				break;
			}
		}
		if (i == NPLAZASC) {
			i = -1;
		}
	}
	if (tipo == 'M') {
		for (i = NPLAZASC;i < NPLAZAS;i++) { 
			if (aparcamiento[i].estado != 1) {
				break;
			}
		}
		if (i == NPLAZAS) {
			i = -1;
		}
	}
	return i;
}
int buscarVehiculo(Plaza aparcamiento[], char matricula[]) { //Devuelve la plaza de un vehículo, si no lo encuentra devuelve -1
	int i;
	for (i = 0;i < NPLAZAS;i++) {
		if (strcmp(matricula, aparcamiento[i].matricula) == 0) {
			break;
		}
	}
	if (i == NPLAZAS) {
		i = -1;
	}
	return i;
}
void ordenar(Plaza aparcamiento[], Plazaux plaza[]) {
	int i, j, p;
	for (i = 0;i < NPLAZAS - 1;i++) { //Ordena el vector auxiliar
		for (j = i + 1;j < NPLAZAS;j++) {
			if (strcmp(plaza[i].mataux, plaza[j].mataux) == 1) {
				plaza[NPLAZAS] = plaza[i];
				plaza[i] = plaza[j];
				plaza[j] = plaza[NPLAZAS];
			}
		}
	}
	for (i = 0;i < NPLAZAS;i++) { //Imprime las matrículas ordenadas
		if (esMatriculaValida(plaza[i].matricula) == 0) {
			break;
		}
		p = buscarVehiculo(aparcamiento, plaza[i].matricula);
		if (p != -1) { //Si el vehículo ha abandonado el parking el auxiliar no se borra, pero sale que p = -1
			printf("%d: El vehiculo con la matricula %s que esta en la plaza %d\n", i + 1, plaza[i].matricula, p + 1);
			}
		}
}
void sacarMataux(Plaza aparcamiento[], Plazaux plaza[], int i, int pos) { //Convierte la estructura NNNNLLL en LLLNNNN
	int j, k;
	char aux;
	strcpy(plaza[pos].mataux, aparcamiento[i].matricula);
	strcpy(plaza[pos].matricula, aparcamiento[i].matricula);
	for (j = 0;j < 3;j++) {
		aux = plaza[pos].mataux[6];
		for (k = 5;k >= 0;k--) {
			plaza[pos].mataux[k + 1] = plaza[pos].mataux[k];
		}
		plaza[pos].mataux[0] = aux;
	}
}
int sacarPos(Plaza aparcamiento[], Plazaux plaza[]) { //Encuentra una posición vacía del parking porque al abandonar un vehículo el parking el vector auxiliar no se modifica
	int i;
	for (i = 0;i < NPLAZAS;i++) {
		if (buscarVehiculo(aparcamiento, plaza[i].matricula) == -1) {
			break;
		}
	}
	return i;
}