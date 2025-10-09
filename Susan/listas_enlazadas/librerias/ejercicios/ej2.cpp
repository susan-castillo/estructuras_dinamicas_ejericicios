#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    int opc;
    queue<string> players;

    do
    {
        cout << "1. Registrar jugadores" << endl;
        cout << "2. Mostrar jugadores" << endl;
        cout << "3. Siguiente turno(rotar)" << endl;
        cout << "4. Salir " << endl;
        cin >> opc;

        string player;
        queue<string> copy;
        string actual;

        switch (opc)
        {
        case 1:
            cout << "Ingrese el nombre del jugador: ";
            cin >> player;
            players.push(player);
            cout << "jugador registrado: " << player << endl;
            break;
        case 2:
            copy = players;
            if (players.empty())
            {
                cout << "No hay jugadores" << endl;
            }
            while (!copy.empty())
            {
                cout << copy.front() << endl;
                copy.pop();
                if (!copy.empty())
                {
                    cout << "->";
                }
                cout << endl;
            }
            break;
        case 3:
            actual = players.front();
            if (players.empty())
            {
                cout << "No hay jugadores" << endl;
            }
            players.pop();
            players.push(actual);
            cout << "Siguiente turno: " << actual << endl;
            break;
        default:
            break;
        }
    } while (opc != 4);

    return 0;
}