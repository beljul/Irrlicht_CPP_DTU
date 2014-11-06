// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T130.h"
#include <stdlib.h>

//////////////////////////////

T130::
T130(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Floor(smgr,driver,x,y,pg),
    jumpOn(false)
{
  texture=driver->getTexture(texturepath+"fl-bridgex-closed.png");
  block->setMaterialTexture(0,texture); 

  alt_texture=driver->getTexture(texturepath+"fl-plank.png");
  nbRelated = 0;
} ;

fieldtype T130::getFieldType(){ 
  return tT130; 
}

void T130::sphereEnter(Sphere &s){
    block->setMaterialTexture(0,alt_texture);
    
    if(jumpOn == true) return;
    
    cout << nbRelated << endl;

    int random = rand() % nbRelated;
    T130 *next = related[random];
    
    vector3df before = s.getPosition();
    
    cout << "x: " << before.X << ", y: " << before.Y << ", z: " << before.Z << endl;
    
    vector3df after;
    after.Z = before.Z + ((next->getx() - this->getx())*160)/20;
    after.X = before.X + ((next->gety() - this->gety())*160)/20;
    after.Y = before.Y;
    
    cout << "x: " << after.X << ", y: " << after.Y << ", z: " << after.Z << endl;
    
    next->setJumpOn(true);
    s.setPosition(after);

}

void T130::sphereExit(Sphere &s){
    block->setMaterialTexture(0,texture);
    jumpOn = false;
}

void T130::introduceTo(Field &f){
    if(!f.getFieldType() == tT130) error("T130 introduced to a Non-Wall!!\n");
    related[nbRelated++] = (T130 *) &f;
}
