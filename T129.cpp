// Swap wall in the opposite side.

#include "game.h"
#include "field.h"
#include "T129.h"

//////////////////////////////

T129::
T129(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg),
    pg(pg)
    // calling the parent constructor 
{
  texture=driver->getTexture(texturepath+"moon.png");
  block->setMaterialTexture(0,texture);
};

Field* T129::getBottomField() {
  return pg.at(this->x).at(this->y+1);
}

Field* T129::getLeftField() {
  return pg.at(this->x-1).at(this->y);
}

Field* T129::getRightField() {
  return pg.at(this->x+1).at(this->y);
}

Field* T129::getTopField() {
  return pg.at(this->x).at(this->y-1);
}


void rejectSphere(Sphere &s, f32 xoverlap, f32 yoverlap) {
  vector3df p=s.getPosition();
  vector3df v=s.getVelocity();
  
  if (xoverlap!=0){ 
    v.Z= -v.Z; 
    p.Z += 2*xoverlap; 
  }
  if (yoverlap!=0){
    v.X= -v.X; 
    p.X += 2*yoverlap; 
  }
  s.setPosition(p);
}

void T129::sphereOverlap(Sphere &s, f32 xoverlap, f32 yoverlap) {
  vector3df p=s.getPosition();
  
  // Horizontal Colision detected
  if (xoverlap != 0) {
    // From the right
    if(xoverlap > 0) {
      if(getLeftField()->isWall()) {
        rejectSphere(s, xoverlap, yoverlap);
        return;
      }
      p.Z -= 10;
    }
    // From the left
    else {
      if(getRightField()->isWall()) {
        rejectSphere(s, xoverlap, yoverlap);
        return;
      }
      p.Z += 10;
    }
  }
  
  // Vertical Colision detected
  if (yoverlap != 0) {
    // From the top
    if(yoverlap < 0) {
      if(getBottomField()->isWall()) {
        rejectSphere(s, xoverlap, yoverlap);
        return;
      }
      p.X += 10;
    }
    // From the bottom
    else {
      if(getTopField()->isWall()) {
        rejectSphere(s, xoverlap, yoverlap);
        return;
      }
      p.X -= 10;
    }
  }
  s.setPosition(p);
}

fieldtype T129::getFieldType(){ 
  return tT129; 
}

