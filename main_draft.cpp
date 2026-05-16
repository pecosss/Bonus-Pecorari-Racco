#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CIsoscelesTriangle.h"

using namespace std;

#define MAX_SHAPES 10

int main()
{
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    cout << "===== TEST GERARCHIA SHAPE =====" << endl;

    // 1. Creazione figure
    shapes[nShapes++] = new Rectangle(0, 0, 2, 3);
    shapes[nShapes++] = new Rhombus(2, 2, 10, 6);
    shapes[nShapes++] = new IsoscelesTriangle(10, 20, 9, 4);


    // 2. Impostazione testo
    shapes[0]->SetText("rettangolo");
    shapes[1]->SetText("rombo");
    shapes[2]->SetText("triangolo isoscele");

    // 3. Scaling
    cout << endl << "===== TEST SCALING =====" << endl;
    shapes[0]->Scale(2.0);
    cout << "sf = 2.0 - rettangolo" << endl;
    shapes[1]->Scale(0.5);
    cout << "sf = 0.5 - rombo" << endl;
    shapes[2]->Scale(0.0);
    //cout << "sf = 0.0 - triangolo isoscele" << endl;

    // 4. Dump polimorfico
    cout << endl << "===== DUMP POLIMORFICO =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }

    // 5. Distruzione figure
    cout << endl << "===== DISTRUTTORI =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        delete shapes[i];
    }

    cout << endl << "===== FINE TEST =====" << endl;

    return 0;
}