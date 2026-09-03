#include <iostream>
#include "problemas.h"
#include <cstdlib>    // rand(), srand()
#include <ctime>      // time()

using namespace std;

void convertirMayusculas(char *cadena){
    char *p = cadena;
    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            *p = *p - 32;
        }
        p++;
    }
}

void problema2(){
    const int arreglo = 200;
    const int num_letras = 26;

    char letras[arreglo];
    int conteo[num_letras] = {0};

    srand(time(nullptr));

    cout << "Arreglo generado: \n";

    char *pletra = letras;
    for (int i = 0; i < arreglo; i++, pletra++) {
        *pletra = 'A' + (rand() % num_letras);
        conteo[*pletra - 'A']++;
        cout << *pletra;
    }

    cout << '\n';

    cout << "\nConteo de letras:\n";
    int *pconteo = conteo;
    for (int i = 0; i < num_letras; i++, pconteo++) {
        if (*pconteo > 0){
            char letra = 'A' + i;
            cout << letra << ": " << *pconteo << '\n';
        }
    }
}

int problema4(const char *cadena){
    int numero = 0;

    while (*cadena != '\0'){
        numero = numero * 10 + (*cadena - '0');
        cadena++;
    }
    return numero;
}

void problema6(){
    const int tamano = 100;
    char cadena[tamano];
    cout << "Ingrese una palabra: \n";
    cin >> cadena;
    cout << "Original: " << cadena << ". \n";

    convertirMayusculas(cadena);

    cout << "En mayuscula: " << cadena << ". \n";
}

void problema8(){
    const int tamano = 100;
    char cadena[tamano];
    char texto[tamano];
    char numeros[tamano];

    cout << "Ingrese una palabra: \n";
    cin >> cadena;

    char *pOriginal = cadena;
    char *pTexto = texto;
    char *pNumero = numeros;

    while (*pOriginal != '\0'){
        if (*pOriginal >= '0' && *pOriginal <= '9'){
            *pNumero = *pOriginal;
            pNumero++;
        } else {
            *pTexto = *pOriginal;
            pTexto++;
        }
        pOriginal++;
    }

    *pTexto = '\0';
    *pNumero = '\0';

    cout << "Original: " << cadena << ". \n";
    cout << "Texto: " << texto << ". Numero: " << numeros << ". \n";
}

void problema10(){
    const int tamano = 20;
    char romano[tamano];

    cout << "Ingrese un numero romano: \n";
    cin >> romano;

    convertirMayusculas(romano);

    short int valores[128] = {0};
    valores['I'] = 1;
    valores['V'] = 5;
    valores['X'] = 10;
    valores['L'] = 50;
    valores['C'] = 100;
    valores['D'] = 500;
    valores['M'] = 1000;

    short int total = 0;
    char *p = romano;

    while (*p != '\0'){
        short int actual = valores[*p];
        short int siguiente = valores[*(p + 1)];

        if (actual < siguiente){
            total -= actual;
        } else {
            total += actual;
        }

        p++;
    }

    cout << "El numero ingresado fue: " << romano << "\n";
    cout << "Que corresponde a: " << total << ".\n";
}

void problema12(){
    const int max = 10;
    short int matriz[max][max];
    int n;

    cout << "Ingrese el tamano de la matriz cuadrada (max " << max << "): \n";
    cin >> n;
    if (n <= 0 || n > max) {
        cout << "Tamano invalido.\n";
        return;
    }

    cout << "Ingrese los " << n * n << " elementos:\n";
    for (int i = 0; i < n; i++) {
        short int *p = matriz[i];
        for (int j = 0; j < n; j++, p++) {
            cin >> *p;
        }
    }

    cout << "\nMatriz ingresada:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << '\n';
    }

    int constante = 0;
    for (int j = 0; j < n; j++) {
        constante += matriz[0][j];
    }

    bool esMagico = true;

    for (int i = 0; i < n; i++) {
        int sumaFila = 0;
        int sumaCol = 0;
        for (int j = 0; j < n; j++) {
            sumaFila += matriz[i][j];
            sumaCol  += matriz[j][i];
        }
        if (sumaFila != constante || sumaCol != constante) {
            esMagico = false;
        }
    }

    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        diag1 += matriz[i][i];
        diag2 += matriz[i][n - 1 - i];
    }
    if (diag1 != constante || diag2 != constante) {
        esMagico = false;
    }

    if (esMagico)
        cout << "\nLa matriz SI es un cuadrado magico. Constante magica: " << constante << ".\n";
    else
        cout << "\nLa matriz NO es un cuadrado magico.\n";
}

void problema14(){
    const int N = 5;

    int original[N][N];
    int rot90[N][N];
    int rot180[N][N];
    int rot270[N][N];

    int *pOriginal = &original[0][0];
    int *pRot90    = &rot90[0][0];
    int *pRot180   = &rot180[0][0];
    int *pRot270   = &rot270[0][0];

    int valor = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            *(pOriginal + (i * N) + j)                   = valor;
            *(pRot90    + (j * N) + (N - 1 - i))          = valor;
            *(pRot180   + ((N - 1 - i) * N) + (N - 1 - j)) = valor;
            *(pRot270   + ((N - 1 - j) * N) + i)          = valor;
            valor++;
        }
    }

    int *matrices[4] = { pOriginal, pRot90, pRot180, pRot270 };
    const char *titulos[4] = {
        "Matriz Original:",
        "Matriz Rotada 90 grados:",
        "Matriz Rotada 180 grados:",
        "Matriz Rotada 270 grados:"
    };

    for (int m = 0; m < 4; m++) {
        cout << "\n" << titulos[m] << "\n";
        int *pm = matrices[m];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout.width(4);
                cout << *pm++;
            }
            cout << "\n";
        }
    }
}

void problema16() {
    int n;
    cout << "Ingrese el tamano de la malla (n x n): \n";
    cin >> n;


    //Formula usada: C(2n, n) = (n+1)/1 * (n+2)/2 * (n+3)/3 * ... * (2n)/n coeficiente binomial
    long long resultado = 1;
    int numerador = n + 1;

    for (int i = 1; i <= n; i++) {
        resultado = (resultado * numerador) / i;
        numerador++;
    }

    cout << "Para una malla de " << n << "x" << n << " puntos hay " << resultado << " caminos.\n";
}

