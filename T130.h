/*
 *  Floor which teleports the sphere on an other floor
 *  with the same type and linked to the first one.
 */

// Against multiple inclusion
#ifndef ____TT130____
#define ____TT130____

#include "game.h"
#include "field.h"

// Floor class
class T130: public Floor
{
protected:

  ITexture *alt_texture;
  // Other T130 floors linked with this one.
  T130 *related[260];
  int nbRelated;
  // Boolean to know if the sphere enter in the field normally or jumped on
  bool jumpOn;
  
public:
  // Constructor
  T130(ISceneManager* smgr,
      IVideoDriver* driver,
      int x, int y, playground  pg) ;
  
  // Return field's type
  virtual fieldtype getFieldType();

  // Action when the sphere enter on the floor
  virtual void sphereEnter(Sphere &s);
  // Action when the spere exit the floor
  virtual void sphereExit(Sphere &s);
  
  // Link floor between them
  virtual void introduceTo(Field &f);
  
  // Inline function to get the boolean JumpOn
  inline
  bool getJumpOn() {
    return this->jumpOn;
  }
  // Inline function to set the boolean JumpOn
  inline
  void setJumpOn(bool jumpOn) {
    this->jumpOn = jumpOn;
  }
};


#endif
