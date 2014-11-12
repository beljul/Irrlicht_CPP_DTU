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
  // Horizontal Colision detected
  if (xoverlap != 0) {
    // From the right
    if(xoverlap > 0 && this->getLeftField()->getFieldType() == tT99) {
      int prevX = this->getLeftField()->getx();
      cout << "y = " << this->y << endl;
      cout <<  "x = " << this->x << endl;
      cout << "x left = " << this->getLeftField()->getx() << endl;
      cout << "y left = " << this->getLeftField()->gety() << endl;
      ((T99 *)this->getLeftField())->setX(this->x);
      this->x = prevX;
    }
    // From the left
    else if (xoverlap < 0 && this->getRightField()->getFieldType() == tT99){
      
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
      
    }
    // From the bottom
    else if (yoverlap > 0 && this->getTopField()->getFieldType() == tT99) {
      
    }
    else {
      rejectSphere(s, xoverlap, yoverlap);
      return;
    }
  }
}

fieldtype T98::getFieldType(){ 
  return tT98; 
}
