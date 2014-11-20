/*
 *  Floor used to push a T136 Wall 
 *  on it
 */

#include "game.h"
#include "field.h"
#include "T137.h"

// Constructor from Floor
T137::
T137(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Floor(smgr,driver,x,y,pg)
{
  // Set texture to recognize we can push a wall
  texture=driver->getTexture(texturepath+"fl-plank.png");
  block->setMaterialTexture(0,texture);
};

fieldtype T137::getFieldType(){ 
  return tT137; 
}

// Return x 
void T137::setX(int x) {
    this->x = x;
}

// Return y
void T137::setY(int y) {
    this->y = y;
}

// Return position
vector3df T137::getPosition() {
    return this->block->getPosition();
}

// Set position
void T137::setPosition(vector3df pos) {
    this->block->setPosition(pos);
}


