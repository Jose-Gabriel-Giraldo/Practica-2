#include <iostream>
#include "problemas.h"
#include <cstdlib>    // rand(), srand()
#include <ctime>      // time()

using namespace std;

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
    const int tamano =100;
    char cadena[tamano];

    cout << "Ingrese una palabra: \n";
    cin >> cadena;

    cout << "Original: " << cadena << ". \n";

    char *p = cadena;
    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z'){
            *p = *p - 32;
        }
        p++;
    }

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
