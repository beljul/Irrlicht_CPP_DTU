/* 
 * File:   T1000.h
 * Author: beljul
 *
 * Created on 12 novembre 2014, 22:18
 */

#ifndef T1000_H
#define	T1000_H

#include "game.h"
#include "field.h"

class T1000: public Wall 
{
  protected:
    playground pg;
    Field* getLeftField();
    Field* getRightField();
    Field* getTopField();
    Field* getBottomField();
    
  public:
    T1000(ISceneManager* smgr,
        IVideoDriver* driver,
        int x, int y, playground pg);
    virtual void rejectSphere(Sphere &s, f32 xoverlap, f32 yoverlap);
};
#endif	/* T1000_H */

