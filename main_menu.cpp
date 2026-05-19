#include <iostream>
#include "ShapeManager.h"

using namespace std;

int main() {
    ShapeManager manager;
    int status;

    do {
        cout << "\n========= MENU =========" << endl;
        cout << "1 - Visualizza tutti i poligoni" << endl;
        cout << "2 - Modifica le proprieta' di un poligono" << endl;
        cout << "3 - Sposta un poligono sulla griglia" << endl;
        cout << "4 - Inserisci un nuovo poligono" << endl;
        cout << "5 - Cancella un poligono" << endl;
        cout << "6 - Cancella tutti i poligoni" << endl;
        cout << "0 - Esci" << endl;
        cout << "========================" << endl;
        cout << "Scelta: ";
        cin >> status;
    
        switch(status) {
            case 1:
                manager.VisualizzaTutti();
                break;
            case 2:
                manager.ModificaPoligono();
                break;
            case 3:
                manager.SpostaPoligono();   
                break;
            case 4:
                manager.InserisciPoligono();
                break;
            case 5:
                manager.CancellaPoligono();
                break;
            case 6: 
                manager.CancellaTutto(); 
                cout << "Tutti i poligoni eliminati." << endl;
                break;
            case 0: 
                cout << "Bye" << endl;
                break;
            default:
                cout << "Scelta non valida!" << endl;
                break;
        }
    } while (status != 0);

    return 0;
}