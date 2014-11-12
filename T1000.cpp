#include "field.h"
#include "T129.h"

//////////////////////////////

T1000::
T1000(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg),
    // calling the parent constructor 
    pg(pg)
{
};

Field* T1000::getBottomField() {
  return pg.at(this->x).at(this->y+1);
}

Field* T1000::getLeftField() {
  return pg.at(this->x-1).at(this->y);
}

Field* T1000::getRightField() {
  return pg.at(this->x+1).at(this->y);
}

Field* T1000::getTopField() {
  return pg.at(this->x).at(this->y-1);
}

void T1000::rejectSphere(Sphere &s, f32 xoverlap, f32 yoverlap) {
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