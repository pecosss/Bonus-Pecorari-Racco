#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CIsoscelesTriangle.h"

using namespace std;

#define MAX_SHAPES 10
#define SIZE 100

int main()
{
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;
    unsigned int status;
    int index;

    shapes[nShapes++] = new Rectangle(50, 50, 2, 3);
    shapes[0]->SetText("rettangolo");

    shapes[nShapes++] = new Rhombus(2, 2, 10, 6);
    shapes[1]->SetText("rombo");

    shapes[nShapes++] = new IsoscelesTriangle(10, 20, 9, 4);
    shapes[2]->SetText("triangolo isoscele");

    do {
        cout << "========= MENU =========" << endl;
        cout << "1 - Visualizza tutti i poligoni" << endl;
        cout << "2 - Modifica le proprietà di un poligono" << endl;
        cout << "3 - Sposta un poligono sulla griglia" << endl;
        cout << "4 - Inserisci un nuovo poligono" << endl;
        cout << "5 - Cancella un poligono" << endl;
        cout << "6 - Cancella tutti i poligoni" << endl;
        cout << "0 - Esci" << endl;
        cout << "========= END MENU =========" << endl << endl;
        cout << "Scelta: ";
        cin >> status;
    
        switch(status){
            case 0:
                cout << "Bye" << endl;
                return 0;
            case 1:
                cout << "=== LISTA POLIGONI ===" << endl;
                if (nShapes == 0){
                    cout << "Nessun poligono presente" << endl;
                }
                for (int i = 0; i < nShapes; i++){
                    cout << endl << "Figura [" << i << "]" << endl;
                    shapes[i]->basicInfo();
                }
                cout << "Per visualizzare altri parametri di un poligono, digitare l'indice del poligono, altrimenti -1: ";
                do {
                    cin >> index;
                    if (index > nShapes)
                        cout << "Indice non valido, riprova" << endl;
                } while (index > nShapes);
                    
                if (index == -1){
                    break;
                }
                else {
                    shapes[index]->otherInfo();
                }
                break;
            case 2:
                cout << "=== MODIFICA POLIGONO ===" << endl;
                cout << "Per modificare proprietà di un poligono, digitare l'indice del poligono (0 - " << nShapes-1 << "), altrimenti -1: ";
                do {
                    cin >> index;
                    if (index > nShapes)
                        cout << "Indice non valido, riprova" << endl;
                } while (index > nShapes);
                    
                if (index == -1){
                    break;
                }
                else {
                    shapes[index]->basicInfo();

                    int l;
                    cout << "Nuova lunghezza: ";
                    cin >> l;
                    if(((shapes[index]->GetX()) + l) > SIZE)
                        cout << "=== ERRORE: fuori griglia (100x100)" << endl;
                    else {
                        cout << "Modifica effettuata" << endl;
                        shapes[index]->SetWidth(l);
                    }

                    int h;
                    cout << "Nuova altezza: ";
                    cin >> h;
                    if(((shapes[index]->GetY()) + h) > SIZE)
                        cout << "=== ERRORE: fuori griglia (100x100)" << endl;
                    else {
                        cout << "Modifica effettuata" << endl;
                        shapes[index]->SetHeight(h);
                    }

                    char text[TEXTSIZE];
                    cout << "Inserisci il nuovo testo: ";
                    cin >> text;
                    shapes[index]->SetText(text);
                }
                break;
            case 3:
                cout << "=== SPOSTAMENTO POLIGONO ===" << endl;
                cout << "Per spostare un poligono, digitare l'indice del poligono (0 - " << nShapes-1 << "), altrimenti -1: ";
                do {
                    cin >> index;
                    if (index > nShapes)
                        cout << "Indice non valido, riprova" << endl;
                } while (index > nShapes);
                    
                if (index == -1){
                    break;
                }
                else {
                    shapes[index]->basicInfo();

                    int x, statoX;
                    cout << "Nuova coordinata x del vertice alto sx: ";
                    cin >> x;
                    statoX = 1;
                    if (x + shapes[index]->GetWidth() > SIZE){
                        cout << "=== ERRORE: fuori area" << endl;
                        statoX = 0;
                    }

                    int y, statoY;
                    cout << "Nuova coordinata y del vertice alto sx: ";
                    cin >> y;
                    statoY = 1;
                    if (y + shapes[index]->GetHeight() > SIZE){
                        cout << "=== ERRORE: fuori area" << endl;
                        statoY = 0;
                    }

                    if (statoX = 0 && statoY != 0)
                        shapes[index]->SetPosition(x, y);
                }
                // shapes[index]->
                // ref: angolo in alto a sx
                break;
            case 4:
                cout << "caso 4" << endl;
                break;
            case 5:
                cout << "caso 5" << endl;
                break;
            case 6:
                cout << "caso 6" << endl;
                break;
            default: 
                cout << "Scelta non valida" << endl;
                break;
        }
    } while (status != 0);

    for (int i = 0; i < nShapes; i++) {
        delete shapes[i];
    }
    return 0;
}