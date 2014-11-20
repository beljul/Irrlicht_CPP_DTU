/*
 *  Wall class which is able
 *  to detect all her neighbors.
 */
#include "field.h"
#include "T138.h"

// Constructor from Wall and keep playground
T138::
T138(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg),
    pg(pg)
{
};

// Get Bottom neighbor
Field* T138::getBottomField() {
  return pg.at(this->x).at(this->y+1);
}

// Get Left neighbor
Field* T138::getLeftField() {
  return pg.at(this->x-1).at(this->y);
}

// Get Right neighbor
Field* T138::getRightField() {
  return pg.at(this->x+1).at(this->y);
}

// Get Top neighbor
Field* T138::getTopField() {
  return pg.at(this->x).at(this->y-1);
}

void T138::rejectSphere(Sphere &s, f32 xoverlap, f32 yoverlap) {
  vector3df p=s.getPosition();

  // Horizontal Colision detected
  if (xoverlap!=0){ 
    // Reject the sphere
    p.Z += 2*xoverlap; 
  }
  // Vertical Colision detected
  if (yoverlap!=0){
    // Reject the sphere
    p.X += 2*yoverlap; 
  }
  
  s.setPosition(p);
}