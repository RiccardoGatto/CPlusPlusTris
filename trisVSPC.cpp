#include <iostream>
#include <random>
#include <time.h>

using namespace std;
const char VUOTO = '_';

void inizializza(char *arr)
{
    for (int i = 0; i < 9; i++)
    {
        arr[i] = VUOTO;
    }

}

// 1 per la vittoria
// 0 per continuare la partita
// -1 per il pareggio
int isWinner(char *arr)
{
    int risultato = -1;
    for (int i = 0; i < 7; i += 3)
    {
        if (((arr[i] == arr[i + 1]) and (arr[i + 1] == arr[i + 2])) && arr[i] != '_')
        {
            return 1;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (((arr[i] == arr[i + 3]) && (arr[i + 3] == arr[i + 6])) and (arr[i] != '_'))
        {
            return 1;
        }
    }
    if (((arr[0] == arr[4]) && (arr[4] == arr[8]) && (arr[0] != '_')) or ((arr[2] == arr[4]) && (arr[4] == arr[6]) && (arr[2] != '_')))
    {
        return 1;
    }
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == '_')
        {
            return 0;
        }
    }
    return -1;
}

void stampa(char *a)
{
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
        if (i == 2 || i == 5 || i == 8)
        {
            cout << endl;
        }
    }
    cout << endl;
}

int turnoGiocatore(char *arr)
{
    int pos;

    cin >> pos;
    pos--;                                              // per capirci ;)
    while (arr[pos] != '_' || (!(0 <= pos && pos < 9))) // controllo 2 condizioni (valido e vuoto)
    {
        cout << "Non puoi inserire qui, riprova" << endl;
        cin >> pos;
        pos--;
    }
    return pos;
}

int turnoPC(char *arr)
{
    srand(time(NULL));
    int pos = rand() % 9;
    cout << "PC fa la sua mossa" << endl;
    while (arr[pos] != '_')
    {
        pos = rand() % 9;
    }
    return pos;
}

int turnoPCNew(char *arr)
{
    srand(time(NULL));

    int risultato = -1;
    char VUOTO = '_';

    // inizializzo la tab
    /*char tab[9];
    for (int i = 0; i < 9; i++)
    {
        tab[i] = VUOTO;
    }
     stampa(tab);
     */

    int combinazioni[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

    /*
        O O _
        X _ _
        X _ _
    */

    // tab[0] = 'O';
    // tab[1] = 'O';
    // tab[3] = 'X';
    // tab[6] = 'X';

    // stampa(tab);

    // QUI LAVORO

    for (int i = 0; i < 8; i++) // due X su 0 e 1
    {

        char a = arr[combinazioni[i][0]];
        char b = arr[combinazioni[i][1]];
        char c = arr[combinazioni[i][2]];

        bool condizione = a == b && c == VUOTO && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][2];
        }
    }

    for (int i = 0; i < 8; i++) // due X su 0 e 2
    {
        char a = arr[combinazioni[i][0]];
        char b = arr[combinazioni[i][2]];
        char c = arr[combinazioni[i][1]];

        bool condizione = a == b && c == VUOTO && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][1];
        }
    }

    for (int i = 0; i < 8; i++) // due X su 1 e 2
    {

        char a = arr[combinazioni[i][1]];
        char b = arr[combinazioni[i][2]];
        char c = arr[combinazioni[i][0]];

        bool condizione = a == b && c == VUOTO && a == 'X';

        if (condizione)
        {
            risultato = combinazioni[i][0];
        }
    }

    // ora controllo se il computer può vincere
    // se ci sono due O metto il terzo

    for (int i = 0; i < 8; i++) // due X su 0 e 1
    {

        char a = arr[combinazioni[i][0]];
        char b = arr[combinazioni[i][1]];
        char c = arr[combinazioni[i][2]];

        bool condizione = a == b && c == VUOTO && a == 'O';

        if (condizione)
        {
            risultato = combinazioni[i][2];
        }
    }

    for (int i = 0; i < 8; i++) // due X su 0 e 2
    {
        char a = arr[combinazioni[i][0]];
        char b = arr[combinazioni[i][2]];
        char c = arr[combinazioni[i][1]];

        bool condizione = a == b && c == VUOTO && a == 'O';

        if (condizione)
        {
            risultato = combinazioni[i][1];
        }
    }

    for (int i = 0; i < 8; i++) // due X su 1 e 2
    {

        char a = arr[combinazioni[i][1]];
        char b = arr[combinazioni[i][2]];
        char c = arr[combinazioni[i][0]];

        bool condizione = a == b && c == VUOTO && a == 'O';

        if (condizione)
        {
            risultato = combinazioni[i][0];
        }
    }

    if (risultato == -1)
    {
        risultato = rand() % 9;
        while (arr[risultato] != VUOTO)
        {
            risultato = rand() % 9;
        }
        return risultato;
    }
    else
    {
        return risultato;
    }
    // cout << "risultato: " << risultato << " atteso: 2" << endl;
}

int main()
{
    string giocatore;
    cout << "Come ti chiami? ";
    cin >> giocatore;
    char vuoto = '_';
    bool xIsNext = false; // gestisce il turno
    // inizializzo la tabella
    char tabella[9];
    inizializza(tabella);
    stampa(tabella);
    while (true) // i turni del gioco
    {
        int mossa;
        // int mossa = (xIsNext) ? turnoGiocatore(tabella) : turnoPC(tabella);
        // cout << xIsNext << endl;
        if (xIsNext)
        {
            cout << giocatore << " fa la sua mossa (1-9) e mette in ";
            mossa = turnoGiocatore(tabella);
        }
        else
        {
            mossa = turnoPCNew(tabella);
            cout << "PC fa la sua mossa e mette in " << mossa + 1 << endl;
        }
        // cout << mossa << endl;

        // se sono arrivato qui è solo perchè l'utente ha inserito un numero corretto
        xIsNext ? tabella[mossa] = 'X' : tabella[mossa] = 'O'; // se è vero metti X altrimenti metti O
        if (!xIsNext)
        stampa(tabella);

        if (isWinner(tabella) == 1)
        {
            if (xIsNext)
            {
                cout << "Complimenti " << giocatore << "!! Hai vintoooo!!!";
            }
            else
            {
                cout << "Eh niente, ha vinto il PC...";
            }
            inizializza(tabella);
            stampa(tabella);
        }
        else if (isWinner(tabella) == -1)
        {
            cout << "Pareggio" << endl;
            // reset del gioco
            inizializza(tabella);
            stampa(tabella);
        }
        else
        {
            xIsNext = !xIsNext; // cambio giocatore
        }
    }
}