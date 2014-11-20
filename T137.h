/*
 *  Floor used to push a T136 Wall 
 *  on it
 */
 
#ifndef ____TT137____
#define ____TT137____

#include "game.h"
#include "field.h"

// Floor class
class T137: public Floor // if you implement a Floor tile, replace "Wall" with "Floor"
{
  public:
    // Constructor
    T137(ISceneManager* smgr,
        IVideoDriver* driver,
        int x, int y, playground  pg);
    
    // Return field's type
    virtual fieldtype getFieldType();
    
    // Setters in order to swap position of the floor and the wall
    void setX(int x);
    void setY(int y);
    void setPosition(vector3df pos);
    vector3df getPosition();
};


#endif
