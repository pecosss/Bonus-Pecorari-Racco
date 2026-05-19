/*! \file ShapeManager.h
    \brief Declaration of the base class ShapeManager
	\author Alessio Pecorari, Davide Racco
*/

#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include <vector>
#include "CShape.h"

#define SIZE 100 
using namespace std;

/// @class ShapeManager
/// @brief to manage a generic object with a shape
class ShapeManager {
private:
    /// dynamic container
    vector <Shape*> shapes;

public:
    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    ShapeManager();
    ~ShapeManager();
    /// @}

    /// @name GETTERS / SETTERS
    /// @{
    void printAll();
    void modifyPol();
    void movePol();
    void newPol();
    void rmPol();
    void rmAll();
    /// @}
};

#endif