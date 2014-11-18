// Skeleton of implementation file for groups

#include "game.h"
#include "T1000.h"
#include "T98.h"
#include "T99.h"

//////////////////////////////

T98::
T98(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : T1000(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
};

void T98::sphereOverlap(Sphere& s, f32 xoverlap, f32 yoverlap) {
    Field *target;
    
  // Horizontal Colision detected
  if (xoverlap != 0) {
    // From the right
    if(xoverlap > 0 && this->getLeftField()->getFieldType() == tT99) {
      target = this->getLeftField();
    }
    // From the left
    else if (xoverlap < 0 && this->getRightField()->getFieldType() == tT99){
      target = this->getRightField();
    }
    else {
      rejectSphere(s, xoverlap, yoverlap);
      return;
    }
  }
  
  // Vertical Colision detected
  if (yoverlap != 0) {
    // From the top
    if(yoverlap < 0 && this->getBottomField()->getFieldType() == tT99) {
      target = this->getBottomField();
    }
    // From the bottom
    else if (yoverlap > 0 && this->getTopField()->getFieldType() == tT99) {
      target = this->getTopField();
    }
    else {
      rejectSphere(s, xoverlap, yoverlap);
      return;
    }
  }
  
  swapWithField(target);
}

void T98::swapWithField(Field *f) {
  //Wall is 8 above Floor in Y coordinate
  vector3df targetPos = ((T99 *)f)->getPosition();
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
  ((T99 *)f)->setX(curX);
  ((T99 *)f)->setY(curY);
  
  //Swap the positions (3D)
  this->block->setPosition(targetPos);
  ((T99 *)f)->setPosition(currentPos);
}

fieldtype T98::getFieldType(){ 
  return tT98; 
}
