// note that your header files must be protected against multiple inclusion using the definition of a special identifier
// note that you also need the #endif at the end of the file
 
#ifndef ____TT129____
#define ____TT129____

#include "game.h"
#include "T1000.h"

class T129: public T1000 
{ 
  public:
    T129(ISceneManager* smgr,
        IVideoDriver* driver,
        int x, int y, playground pg);

    virtual void sphereOverlap(Sphere &s, f32 xoverlap, f32 yoverlap);
    virtual fieldtype getFieldType();
};


#endif
