/*
 *  Floor which teleports the sphere on an other floor
 *  with the same type and linked to the first one.
 */

#include "game.h"
#include "field.h"
#include "T130.h"

// Construction from Floor and initialize jumpOn to false
T130::
T130(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Floor(smgr,driver,x,y,pg),
    jumpOn(false)
{
  // Set texture
  texture=driver->getTexture(texturepath+"portal.png");
  block->setMaterialTexture(0,texture); 

  alt_texture=driver->getTexture(texturepath+"fl-plank.png");
  nbRelated = 0;
} ;

fieldtype T130::getFieldType(){ 
  return tT130; 
}

void T130::sphereEnter(Sphere &s){
    // Set texture to vizualize the sphere is in
    block->setMaterialTexture(0,alt_texture);
    
    // To avoid infinite jump (jump after jump...etc)
    if(jumpOn == true) return;
    
    // Get the random among related floors
    int random = rand() % nbRelated;
    T130 *next = related[random];
    
    // Compute the new position
    vector3df before = s.getPosition();
        
    vector3df after;
    after.Z = before.Z + ((next->getx() - this->getx())*160)/20;
    after.X = before.X + ((next->gety() - this->gety())*100)/13;
    after.Y = before.Y;
    
    // Set jumpOn to true and set position
    next->setJumpOn(true);
    s.setPosition(after);

}

void T130::sphereExit(Sphere &s){
    // Set the texture  to visualize the sphere is not in
    block->setMaterialTexture(0,texture);
    // Set jumpOn to false, next sphereEnter will teleport the sphere
    jumpOn = false;
}

void T130::introduceTo(Field &f){
    // Verify it's an other T139 floor
    if(!f.getFieldType() == tT130) error("T130 introduced to a Non-Wall!!\n");
    related[nbRelated++] = (T130 *) &f;
}
