/*! \file ShapeManager.cpp
    \brief implementation of class ShapeManager
	\author Alessio Pecorari, Davide Racco
*/

#include <iostream>
#include "ShapeManager.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CIsoscelesTriangle.h"

using namespace std;

// costruttore (testing)
ShapeManager::ShapeManager(){
    Shape* r = new Rectangle(50, 50, 2, 3);
    r->SetText("rettangolo");
    shapes.push_back(r);

    Shape* rh = new Rhombus(2, 2, 10, 6);
    rh->SetText("rombo");
    shapes.push_back(rh);

    Shape* t = new IsoscelesTriangle(10, 20, 9, 4);
    t->SetText("triangolo isoscele");
    shapes.push_back(t);
}

// distruttore (testing)
ShapeManager::~ShapeManager() {
    rmAll();
}

/// @brief print basic info of all polygons
void ShapeManager::printAll() {
    cout << "=== LISTA POLIGONI ===" << endl;
    if (shapes.empty()) {
        cout << "Nessun poligono presente" << endl;
        return;
    }

    for (size_t i = 0; i < shapes.size(); i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->basicInfo();
    }

    int index;
    cout << "Per informazioni estese, digita l'indice, altrimenti -1: ";
    do {
        cin >> index;
        if (index >= shapes.size() && index != -1)
            cout << "Indice non valido, riprova: ";
    } while (index >= shapes.size() && index != -1);

    if (index != -1) {
        shapes[index]->otherInfo();
    }
}

/// @brief modify a polygon (based on the index of the pol)
void ShapeManager::modifyPol() {
    cout << "=== MODIFICA POLIGONO ===" << endl;
    if (shapes.empty()) return;

    int index;
    cout << "Digita l'indice del poligono (0 - " << shapes.size() - 1 << "), altrimenti -1: ";
    do {
        cin >> index;
        if (index >= shapes.size() && index != -1)
            cout << "Indice non valido, riprova: ";
    } while (index >= shapes.size() && index != -1);

    if (index == -1) return;

    shapes[index]->basicInfo();

    int l, h;
    cout << "Nuova lunghezza: ";
    cin >> l;
    if ((shapes[index]->GetX() + l) > SIZE || l <= 0) {
        cout << "=== ERRORE: fuori griglia o dimensione non valida" << endl;
    } else {
        shapes[index]->SetWidth(l);
        cout << "Larghezza aggiornata." << endl;
    }

    cout << "Nuova altezza: ";
    cin >> h;
    if ((shapes[index]->GetY() + h) > SIZE || h <= 0) {
        cout << "=== ERRORE: fuori griglia o dimensione non valida" << endl;
    } else {
        shapes[index]->SetHeight(h);
        cout << "Altezza aggiornata." << endl;
    }

    char text[100];
    cout << "Inserisci il nuovo testo: ";
    cin >> text;
    shapes[index]->SetText(text);
}

/// @brief move a polygon (based on the index of the pol)
void ShapeManager::movePol() {
    cout << "=== SPOSTAMENTO POLIGONO ===" << endl;
    if (shapes.empty()) return;

    int index;
    cout << "Digita l'indice (0 - " << shapes.size() - 1 << "), altrimenti -1: ";
    do {
        cin >> index;
        if (index >= shapes.size() && index != -1)
            cout << "Indice non valido, riprova: ";
    } while (index >= shapes.size() && index != -1);

    if (index == -1) return;

    int x, y;
    bool statoX = true, statoY = true;

    cout << "Nuova coordinata X: ";
    cin >> x;
    if (x < 0 || (x + shapes[index]->GetWidth()) > SIZE) {
        cout << "=== ERRORE: asse X fuori area" << endl;
        statoX = false;
    }

    cout << "Nuova coordinata Y: ";
    cin >> y;
    if (y < 0 || (y + shapes[index]->GetHeight()) > SIZE) {
        cout << "=== ERRORE: asse Y fuori area" << endl;
        statoY = false;
    }

    if (statoX && statoY) {
        shapes[index]->SetPosition(x, y);
        cout << "Spostamento effettuato con successo!" << endl;
    }
}

/// @brief create a polygon (Rectangle, Rhombus or IsoscelesTriangle)
void ShapeManager::newPol(){

}

/// @brief remove a polygon (based on the index of the pol)
void ShapeManager::rmPol(){
    
}

/// @brief remove all the polygons
void ShapeManager::rmAll(){ 
    for(size_t i=0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();
}