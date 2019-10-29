#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void dibujar_torres(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[]);
void mover_torre_uno_a_torre_dos(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[]);
void mover_torre_uno_a_torre_tres(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[]);
void mover_torre_dos_a_torre_uno(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[]);
void mover_torre_dos_a_torre_tres(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[]);
void mover_torre_tres_a_torre_uno(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[]);
void mover_torre_tres_a_torre_dos(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[]);
int cantidad_esperada(int cantidad_discos);
int mostrar_menu();

int main(int argc, char const *argv[])
{
    int cantidad_discos;
    cout << "ingrese la cantidad de discos" << endl;
    cin >> cantidad_discos;
    system("clear");

    char *torre_uno = new char[cantidad_discos];
    char *torre_dos = new char[cantidad_discos];
    char *torre_tres = new char[cantidad_discos];
    char *torre_copia = new char[cantidad_discos];

    // inicializar los arrays
    for (int i = 1; i <= cantidad_discos; i++)
    {
        torre_copia[i - 1] = i + '0';
        torre_uno[i - 1] = i + '0';
        torre_dos[i - 1] = ' ';
        torre_tres[i - 1] = ' ';
    }

    // mostramos la opciones de menu
    bool iniciar = true;
    int cantidad_jugadas = 0;

    cout << "LIMITE DE JUGADAS: " << cantidad_esperada(cantidad_discos) << endl;
    cout << "CANTIDAD DE JUGADAS: " << cantidad_jugadas << endl;
    dibujar_torres(cantidad_discos, torre_uno, torre_dos, torre_tres);

    do
    {
        int opcion = mostrar_menu();
        
        switch (opcion)
        {
            case 1: // 1 -> 2
                system("clear");
                cantidad_jugadas++;
                cout << "LIMITE DE JUGADAS: " << cantidad_esperada(cantidad_discos) << endl;
                cout << "CANTIDAD DE JUGADAS: " << cantidad_jugadas << endl;
                mover_torre_uno_a_torre_dos(cantidad_discos, torre_uno, torre_dos, torre_tres);
                dibujar_torres(cantidad_discos, torre_uno, torre_dos, torre_tres);
                break;
            case 2: // 1 -> 3
                system("clear");
                cantidad_jugadas++;
                cout << "LIMITE DE JUGADAS: " << cantidad_esperada(cantidad_discos) << endl;
                cout << "CANTIDAD DE JUGADAS: " << cantidad_jugadas << endl;
                mover_torre_uno_a_torre_tres(cantidad_discos, torre_uno, torre_dos, torre_tres);
                dibujar_torres(cantidad_discos, torre_uno, torre_dos, torre_tres);
                break;
            case 3: // 2 -> 1
                system("clear");
                cantidad_jugadas++;
                cout << "LIMITE DE JUGADAS: " << cantidad_esperada(cantidad_discos) << endl;
                cout << "CANTIDAD DE JUGADAS: " << cantidad_jugadas << endl;
                mover_torre_dos_a_torre_uno(cantidad_discos, torre_uno, torre_dos, torre_tres);
                dibujar_torres(cantidad_discos, torre_uno, torre_dos, torre_tres);
                break;
            case 4: // 2 -> 3
                system("clear");
                cantidad_jugadas++;
                cout << "LIMITE DE JUGADAS: " << cantidad_esperada(cantidad_discos) << endl;
                cout << "CANTIDAD DE JUGADAS: " << cantidad_jugadas << endl;
                mover_torre_dos_a_torre_tres(cantidad_discos, torre_uno, torre_dos, torre_tres);
                dibujar_torres(cantidad_discos, torre_uno, torre_dos, torre_tres);
                break;
            case 5:
                system("clear");
                cantidad_jugadas++;
                cout << "LIMITE DE JUGADAS: " << cantidad_esperada(cantidad_discos) << endl;
                cout << "CANTIDAD DE JUGADAS: " << cantidad_jugadas << endl;
                mover_torre_tres_a_torre_uno(cantidad_discos, torre_uno, torre_dos, torre_tres);
                dibujar_torres(cantidad_discos, torre_uno, torre_dos, torre_tres);
                break;
            case 6:
                system("clear");
                cantidad_jugadas++;
                cout << "LIMITE DE JUGADAS: " << cantidad_esperada(cantidad_discos) << endl;
                cout << "CANTIDAD DE JUGADAS: " << cantidad_jugadas << endl;
                mover_torre_tres_a_torre_dos(cantidad_discos, torre_uno, torre_dos, torre_tres);
                dibujar_torres(cantidad_discos, torre_uno, torre_dos, torre_tres);
                break;
            default:
                iniciar = false;
                break;
        }

        for (int i = 0; i < cantidad_discos; i++)
        {
            if (torre_copia[i] != torre_tres[i])
            {
                iniciar = true;
                break;
            }
            cout << "FELICIDADES GANASTE!" << endl;
            iniciar = false;
            break;
        }

        if (cantidad_jugadas > cantidad_esperada(cantidad_discos))
        {
            cout << "PERDISTE!" << endl;
            cout << "\nFIN DEL JUEGO" << endl;
            iniciar = false;
        }
        
    } while (iniciar);

    return 0;
}

void mover_torre_uno_a_torre_dos(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[])
{
    int pos;
    for (int i = 0; i < cantidad_discos; i++)
    {
        if (torre_uno[i] != ' ')
        {
            pos = i;
           break;
        }
    }

    for (int i = cantidad_discos - 1; i >= 0; i--)
    {
        if (torre_dos[i] == ' ') // 4
        {
            if (i == cantidad_discos - 1)
            {
                torre_dos[i] = torre_uno[pos];
                torre_uno[pos] = ' ';
            } else
            {
                int valor_uno = torre_uno[pos] - '0';
                int valor_dos = torre_dos[i + 1] - '0';
                if (valor_uno < valor_dos)
                {
                    torre_dos[i] = torre_uno[pos];
                    torre_uno[pos] = ' ';
                }
                break;
            }
        }
    }
}

void mover_torre_uno_a_torre_tres(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[])
{
    int pos;
    for (int i = 0; i < cantidad_discos; i++)
    {
        if (torre_uno[i] != ' ')
        {
            pos = i;
            break;
        }
    }

    for (int i = cantidad_discos - 1; i >= 0; i--)
    {
        if (torre_tres[i] == ' ') // 4
        {
            if (i == cantidad_discos - 1)
            {
                torre_tres[i] = torre_uno[pos];
                torre_uno[pos] = ' ';
            } else
            {
                int valor_uno = torre_uno[pos] - '0';
                int valor_dos = torre_tres[i + 1] - '0';
                if (valor_uno < valor_dos)
                {
                    torre_tres[i] = torre_uno[pos];
                    torre_uno[pos] = ' ';
                }
                break;
            }
        }
    }
}

void mover_torre_dos_a_torre_uno(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[])
{
    int pos;
    for (int i = 0; i < cantidad_discos; i++)
    {
        if (torre_dos[i] != ' ')
        {
            pos = i;
           break;
        }
    }

    for (int i = cantidad_discos - 1; i >= 0; i--)
    {
        if (torre_uno[i] == ' ') // 4
        {
            if (i == cantidad_discos - 1)
            {
                torre_uno[i] = torre_dos[pos];
                torre_dos[pos] = ' ';
            } else
            {
                int valor_uno = torre_dos[pos] - '0';
                int valor_dos = torre_uno[i + 1] - '0';
                if (valor_uno < valor_dos)
                {
                    torre_uno[i] = torre_dos[pos];
                    torre_dos[pos] = ' ';
                }
                break;
            }
        }
    }
}

void mover_torre_dos_a_torre_tres(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[])
{
    int pos;
    for (int i = 0; i < cantidad_discos; i++)
    {
        if (torre_dos[i] != ' ')
        {
            pos = i;
           break;
        }
    }

    for (int i = cantidad_discos - 1; i >= 0; i--)
    {
        if (torre_tres[i] == ' ') // 4
        {
            if (i == cantidad_discos - 1)
            {
                torre_tres[i] = torre_dos[pos];
                torre_dos[pos] = ' ';
            } else
            {
                int valor_uno = torre_dos[pos] - '0';
                int valor_dos = torre_tres[i + 1] - '0';
                if (valor_uno < valor_dos)
                {
                    torre_tres[i] = torre_dos[pos];
                    torre_dos[pos] = ' ';
                }
                break;
            }
        }
    }
}

void mover_torre_tres_a_torre_uno(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[])
{
    int pos;
    for (int i = 0; i < cantidad_discos; i++)
    {
        if (torre_tres[i] != ' ')
        {
            pos = i;
           break;
        }
    }

    for (int i = cantidad_discos - 1; i >= 0; i--)
    {
        if (torre_uno[i] == ' ') // 4
        {
            if (i == cantidad_discos - 1)
            {
                torre_uno[i] = torre_tres[pos];
                torre_tres[pos] = ' ';
            } else
            {
                int valor_uno = torre_tres[pos] - '0';
                int valor_dos = torre_uno[i + 1] - '0';
                if (valor_uno < valor_dos)
                {
                    torre_uno[i] = torre_tres[pos];
                    torre_tres[pos] = ' ';
                }
                break;
            }
        }
    }
}


void mover_torre_tres_a_torre_dos(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[])
{
    int pos;
    for (int i = 0; i < cantidad_discos; i++)
    {
        if (torre_tres[i] != ' ')
        {
            pos = i;
           break;
        }
    }

    for (int i = cantidad_discos - 1; i >= 0; i--)
    {
        if (torre_dos[i] == ' ') // 4
        {
            if (i == cantidad_discos - 1)
            {
                torre_dos[i] = torre_tres[pos];
                torre_tres[pos] = ' ';
            } else
            {
                int valor_uno = torre_tres[pos] - '0';
                int valor_dos = torre_dos[i + 1] - '0';
                if (valor_uno < valor_dos)
                {
                    torre_dos[i] = torre_tres[pos];
                    torre_tres[pos] = ' ';
                }
                break;
            }
        }
    }
}

int mostrar_menu()
{   int opcion;
    cout << "OPCIONES" << endl;
    cout << "1: mover de torre  1 -> 2" << endl;
    cout << "2: mover de torre  1 -> 3" << endl;
    cout << "3: mover de torre  2 -> 1" << endl;
    cout << "4: mover de toore  2 -> 3" << endl;
    cout << "5: mover de torre  3 -> 1" << endl;
    cout << "6: mover de torre  3 -> 2" << endl;
    cout << "=> ";
    cin >> opcion;
    return opcion;
}

void dibujar_torres(int cantidad_discos, char torre_uno[], char torre_dos[], char torre_tres[])
{
    cout << "\n====================================" << endl;
    for (int i = 0; i < cantidad_discos; i++)
    {
        cout << "     " << torre_uno[i] << "           " << torre_dos[i] << "            " << torre_tres[i] << endl;
    }
    cout << "=========== =========== ============" << endl;
    cout << " torre uno   torre dos   torre tres " << endl << endl;
}

int cantidad_esperada(int cantidad_discos)
{
    int cantidad = 0;
    cantidad = pow(2, cantidad_discos) - 1;
    return cantidad;
}