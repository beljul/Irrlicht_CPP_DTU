// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T99.h"

//////////////////////////////

T99::
T99(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Floor(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
  texture=driver->getTexture(texturepath+"fl-plank.png");
  block->setMaterialTexture(0,texture);
};

fieldtype T99::getFieldType(){ 
  return tT99; 
}

void T99::setX(int x) {
  this->x = x;
}

void T99::setY(int y) {
  this->y = y;
}


