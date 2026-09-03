#include <iostream>
#include "problemas.h"

using namespace std;

int main()
{
    int problema;
    bool salir = false;

    while (!salir) {
        cout << "--------------------- Menu -----------------------------" << "\n";
        cout << "Ingrese el numero del problema (0 para salir): " << "\n";
        cout << "--------------------------------------------------------" << "\n";
        cout << "2. Generador y conteo de letras aleatorias P2\n";
        cout << "4. Conversor de cadena a entero p4\n";
        cout << "6. Conversor de minusculas a mayusculas p6\n";
        cout << "8. Separador Numeros y caracteres p8\n";
        cout << "10. Conversor de Romanos a Arabigo p10\n";
        cout << "12. Cuadrado magico p12\n";
        cout << "14. Matriz rotada p14\n";
        cout << "16. Caminos posibles de maya n*n p16\n";
        cout << "0. Salir del programa\n";
        cin >> problema;

        switch (problema) {
        case 2: problema2(); break;

        case 4: {
            const int tamano = 20;

            char cadenaPrueba[tamano];

            cout << "Ingrese una cadena de numeros (maximo " << tamano - 1 << " digitos): \n";
            cin >> cadenaPrueba;

            int resultado = problema4(cadenaPrueba);
            cout << "Cadena: " << cadenaPrueba << '\n';
            cout << "Numero entero: " << resultado << '\n';
            break;
        }

        case 6: problema6(); break;

        case 8: problema8(); break;

        case 10: problema10(); break;

        case 12: problema12(); break;

        case 14: problema14(); break;

        case 16: problema16(); break;

        case 0:
            salir = true;
            break;
        default:
            cout << "Opcion invalida, vuelva a intentar.\n";
        }
    }

    return 0;
}
