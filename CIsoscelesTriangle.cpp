/*! \file CIsoscelesTriangle.cpp
    \brief implementation of class IsoscelesTriangle
    \author Alessio Pecorari, Davide Racco
*/

#include "CIsoscelesTriangle.h"
#include <iostream>
#include <cmath>

using namespace std;

/* ----------------------------
   CONSTRUCTORS / DESTRUCTOR
   ---------------------------- */

/// @brief default constructor
IsoscelesTriangle::IsoscelesTriangle() : Shape()
{
    cout << "IsoscelesTriangle - default constructor" << endl;
}

/// @brief constructor 
/// @param px position in the grid (x)
/// @param py position in the grid (y)
/// @param w width of the bounding box
/// @param h height of the bounding box
IsoscelesTriangle::IsoscelesTriangle(float px, float py, float w, float h) : Shape(px, py, w, h)
{
    cout << "IsoscelesTriangle - constructor" << endl;
}

/// @brief copy constructor
/// @param r reference to the object to be copied
IsoscelesTriangle::IsoscelesTriangle(const IsoscelesTriangle &r) : Shape(r)
{
    cout << "IsoscelesTriangle - copy constructor" << endl;
}

/// @brief destructor
IsoscelesTriangle::~IsoscelesTriangle()
{
    cout << "IsoscelesTriangle - destructor" << endl;
}

/* ----------------------------
   OPERATORS
   ---------------------------- */

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
IsoscelesTriangle& IsoscelesTriangle::operator=(const IsoscelesTriangle &r)
{
    if (this != &r) 
        Shape::operator=(r);

    return *this;
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two bounding boxes have the same width and the same length  
bool IsoscelesTriangle::operator==(const IsoscelesTriangle &r)
{
    return Shape::operator==(r);
}

/* ----------------------------
   BASIC HANDLING
   ---------------------------- */

/// @brief default initialization of the object
void IsoscelesTriangle::Init()
{
    Shape::Init();
}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void IsoscelesTriangle::Init(const IsoscelesTriangle &r)
{
    Shape::Init(r);
}

/// @brief total reset of the object  
void IsoscelesTriangle::Reset()
{
    Shape::Reset();
}


/* ----------------------------
   GETTERS
   ---------------------------- */
   
/// @brief to get the smaller diagonal of the IsoscelesTriangle
/// @return d
float IsoscelesTriangle::GetB()
{
    float B = width; 
	return B;
}

/// @brief to get the larger diagonal of the IsoscelesTriangle
/// @return D
float IsoscelesTriangle::GetH()
{
    return height;
}

/// @brief computes the area of the IsoscelesTriangle
/// @return area 
float IsoscelesTriangle::GetArea()
{
    float B = width; 
    return (B * height) / 2;
}

/// @brief computes the perimeter of the IsoscelesTriangle
/// @return perimeter 
float IsoscelesTriangle::GetPerimeter()
{
    float B = width; 
    float l = sqrt(pow(height, 2) + pow(B / 2.0, 2));
    return (B + 2 * l);
}

/* ----------------------------
   DEBUG and SERIALIZATION
   ---------------------------- */

/// @brief for debugging: all infos about the object
void IsoscelesTriangle::Dump()
{
	cout << endl <<  "----------------------" << endl;
    cout << "IsoscelesTriangle Dump:" << endl << endl;
    
    cout << "Shape Dump:" << endl;
    cout << "  Position: (" << x << ", " << y << ")" << endl;
    cout << "  Base:  " << width << endl;
    cout << "  Height: " << height << endl;
    cout << "  Bounding Box Area:   " << GetBoundingBoxArea() << endl;
    cout << endl;
    cout << "  Figure area:         " << GetArea() << endl;
    cout << "  Figure perimeter:    " << GetPerimeter() << endl;
    cout << "  Text:                " << (text ? text : "(null)") << endl;
	cout << endl;

}