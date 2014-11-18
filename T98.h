// note that your header files must be protected against multiple inclusion using the definition of a special identifier
// note that you also need the #endif at the end of the file
 
#ifndef ____TT98____
#define ____TT98____

#include "game.h"
#include "T1000.h"

class T98: public T1000 // if you implement a Floor tile, replace "Wall" with "Floor"
{
  public:
    T98(ISceneManager* smgr,
        IVideoDriver* driver,
        int x, int y, playground  pg);
  
    virtual void sphereOverlap(Sphere &s, f32 xoverlap, f32 yoverlap);
    
    virtual fieldtype getFieldType();
    
    void swapWithField(Field *f);
};


#endif
