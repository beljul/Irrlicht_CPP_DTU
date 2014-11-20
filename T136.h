/*
 *  Wall class which we can push
 *  thanks to the sphere
 *  on specifiques floors
 */
 
#ifndef ____TT136____
#define ____TT136____

#include "game.h"
#include "T138.h"

// Wall class from T138
class T136: public T138
{
  public:
    // Constructor
    T136(ISceneManager* smgr,
        IVideoDriver* driver,
        int x, int y, playground  pg);
    
    // When the sphere touch the wall.
    virtual void sphereOverlap(Sphere &s, f32 xoverlap, f32 yoverlap);
    
    // Return field's type
    virtual fieldtype getFieldType();
    
    // Swap function between a field and the wall himself
    void swapWithField(Field *f);
};


#endif
