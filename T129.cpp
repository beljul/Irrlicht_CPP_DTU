// Wall which swap the sphere in the opposite side.

#include "game.h"
#include "T129.h"

// Constructor from T138
T129::
T129(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : T138(smgr,driver,x,y,pg)
{
    // Specify new texture to recognize this wall
    texture=driver->getTexture(texturepath+"moon.png");
    block->setMaterialTexture(0,texture);
};

void T129::sphereOverlap(Sphere &s, f32 xoverlap, f32 yoverlap) {
  vector3df p=s.getPosition();
  
  // Horizontal Colision detected
  if (xoverlap != 0) {
    // From the right
    if(xoverlap > 0) {
      // If it's wall, the swap doesn't work
      if(getLeftField()->isWall()) {
        rejectSphere(s, xoverlap, yoverlap);
        return;
      }
      p.Z -= 10;
    }
    // From the left
    else {
      // If it's wall, the swap doesn't work
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
      // If it's wall, the swap doesn't work
      if(getBottomField()->isWall()) {
        rejectSphere(s, xoverlap, yoverlap);
        return;
      }
      p.X += 10;
    }
    // From the bottom
    else {
      // If it's wall, the swap doesn't work
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

