/*
 *  Wall class which we can push
 *  thanks to the sphere
 *  on specifiques floors
 */

#include "game.h"
#include "T136.h"
#include "T137.h"

// Constructor from T138
T136::
T136(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : T138(smgr,driver,x,y,pg)
{
};

void T136::sphereOverlap(Sphere& s, f32 xoverlap, f32 yoverlap) {
    Field *target;
    
  // Horizontal Colision detected
  if (xoverlap != 0) {
    // From the right
    if(xoverlap > 0 && this->getLeftField()->getFieldType() == tT137) {
      target = this->getLeftField();
    }
    // From the left
    else if (xoverlap < 0 && this->getRightField()->getFieldType() == tT137){
      target = this->getRightField();
    }
    // If the field on we want push the wall is not a T137 floor
    else {
      rejectSphere(s, xoverlap, yoverlap);
      return;
    }
  }
  
  // Vertical Colision detected
  if (yoverlap != 0) {
    // From the top
    if(yoverlap < 0 && this->getBottomField()->getFieldType() == tT137) {
      target = this->getBottomField();
    }
    // From the bottom
    else if (yoverlap > 0 && this->getTopField()->getFieldType() == tT137) {
      target = this->getTopField();
    }
    // If the field on we want push the wall is not a T137 floor
    else {
      rejectSphere(s, xoverlap, yoverlap);
      return;
    }
  }
  
  // Swap the wall and the T137 floor
  swapWithField(target);
}

void T136::swapWithField(Field *f) {
  //Wall is 8 above Floor in Y coordinate
  vector3df targetPos = ((T137 *)f)->getPosition();
  targetPos.Y += 8;
  
  //Floor is 8 below Wall in Y coordinate
  vector3df currentPos = this->block->getPosition();
  currentPos.Y -= 8;
  
  //Swap the playground references
  Field *tmp = this;
  pg[x][y] = f;
  pg[f->getx()][f->gety()] = tmp;
  
  //Swap the object attributes
  int curX = this->x;
  int curY = this->y;
  
  this->x = f->getx();
  this->y = f->gety();
  ((T137 *)f)->setX(curX);
  ((T137 *)f)->setY(curY);
  
  //Swap the positions (3D)
  this->block->setPosition(targetPos);
  ((T137 *)f)->setPosition(currentPos);
}

fieldtype T136::getFieldType(){ 
  return tT136; 
}
