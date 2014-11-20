/*
 *  Wall class which is able
 *  to detect all her neighbors.
 */

#ifndef ____TT138____
#define ____TT138____

#include "game.h"
#include "field.h"

// Wall class
class T138: public Wall 
{
  protected:
    // Save the playground to know his neighbors
    playground pg;
    // Get all neighbors
    Field* getLeftField();
    Field* getRightField();
    Field* getTopField();
    Field* getBottomField();
    
  public:
    // Construction
    T138(ISceneManager* smgr,
        IVideoDriver* driver,
        int x, int y, playground pg);
    // Reject sphere function used is the neighbor is a wall for example
    virtual void rejectSphere(Sphere &s, f32 xoverlap, f32 yoverlap);
};
#endif

