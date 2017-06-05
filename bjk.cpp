#include <iostream>
#include <conio.h>

using namespace std;

int tablero[8][8];
bool turno = true;

bool lleno(int (*mat)[8]){
	int *row = *mat;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (*row != 0){
				row++;
			} else {
				return 0;
			}
		}
		mat++;
	}
	cout << "Tablero lleno.\n";
	return 1;
}

void winner(int (*mat)[8]){ ///1 si gano P1, 0 si ganó P2
	int uno = 0, dos = 0;
	int *row = *mat;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (*row == 1){
				uno++;
			} else {
				dos++;
			}
			row++;
		}
		mat++;
	}
	if (uno > dos){
		cout << "Gano el jugador 1! Con un puntaje de " << uno << " contra " << dos << endl;
	}
	else if (uno < dos){
		cout << "Gano el jugador 2! Con un puntaje de " << dos << " contra " << uno << endl;
	} else {
		cout << "Empate! Ambos consiguieron un puntaje de " << uno << endl;
	}
}

void imprimir(int (*mat)[8]){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << *(*(mat+i)+j) << " ";
		}
		cout << endl;
	}
}

void initTablero(int (*mat)[8]){
	*(*(mat+3)+3) = 1;
	*(*(mat+4)+4) = 1;
	*(*(mat+3)+4) = 2;
	*(*(mat+4)+3) = 2;
}

bool eval(int (*mat)[8], int j, int x, int y){
	if (*(*(mat+y)+x) == j) return true;
	else return false;
}

void presionar(int (*mat)[8], int pos_x, int pos_y, int j, int o){
	int t, x, y, cont;
	t = getch();
	if (t == 224){
		t = getch();
	}
	cout << t << endl;
	switch(t){
		case 72:
		///Arriba
		cout << "Arriba!\n";
		if(pos_y != 0){
			x = pos_x;
			y = pos_y;
			pos_y--;
			cont = 0;
			while( *(*(mat+pos_y)+pos_x) == o && pos_y > 0){
				*(*(mat+pos_y)+pos_x) = j;
				--pos_y;
				cont++;
			}
			if (cont > 0)
				*(*(mat+pos_y)+pos_x) = j;
		}
		break;
		
	case 80:
		///Abajo
		if(pos_y != 7){
			pos_y++;
			cont = 0;
			while( *(*(mat+pos_y)+pos_x) == o && pos_y < 7){
				*(*(mat+pos_y)+pos_x) = j;
				++pos_y;
				cont++;
			}
			if (cont > 0)
				*(*(mat+pos_y)+pos_x) = j;
		}
		break;
		
	case 75:
		///Izquierda
		if(pos_x != 0){
			pos_x--;
			cont = 0;
			while( *(*(mat+pos_y)+pos_x) == o && pos_x > 0){
				*(*(mat+pos_y)+pos_x) = j;
				--pos_x;
				cont++;
			}
			if (cont > 0)
				*(*(mat+pos_y)+pos_x) = j;
		}
		break;
		
	case 77:
		///Derecha
		if(pos_x != 7){
			pos_x++;
			cont = 0;
			while( *(*(mat+pos_y)+pos_x) == o && pos_x < 7){
				*(*(mat+pos_y)+pos_x) = j;
				++pos_x;
				cont++;
			}
			if (cont > 0)
				*(*(mat+pos_y)+pos_x) = j;
		}
		break;
	}
}

int main(int argc, char *argv[]) {
	initTablero(tablero);
	imprimir(tablero);
	int x, y, j, o;
	while(!lleno(tablero)){
		if (turno){
			cout << "Turno del jugador 1\n";
			turno = false; j = 1; o = 2;
		} else {
			cout << "Turno del jugador 2\n";
			turno = true; j = 2; o = 1;
		}
		cout << "Ingrese la posicion con la que va a jugar (primero x, luego y)";
		cin >> x;
		cin >> y;
		while (!eval(tablero, j, x, y)){
			cout << "Reingrese los valores:";
			cin >> x;
			cin >> y;
		}
		cout << "Aprete una tecla....\n";
		presionar(tablero, x, y, j, o);
		imprimir(tablero);
	}
	winner(tablero);
	return 0;
}
