// Wall which swap the sphere in the opposite side.

// Against multiple inclusion
#ifndef ____TT129____
#define ____TT129____

#include "game.h"
#include "T138.h"

/*
 *  Wall class from T138
 *  Mother class with detection of neighbors
 */ 
class T129: public T138 
{ 
  public:
    // Constructor
    T129(ISceneManager* smgr,
        IVideoDriver* driver,
        int x, int y, playground pg);
    
    // When the sphere touch the wall.
    virtual void sphereOverlap(Sphere &s, f32 xoverlap, f32 yoverlap);
    // Return field's type
    virtual fieldtype getFieldType();
};


#endif
