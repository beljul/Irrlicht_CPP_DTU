// note that your header files must be protected against multiple inclusion using the definition of a special identifier
// note that you also need the #endif at the end of the file
 
#ifndef ____TT130____
#define ____TT130____

#include "game.h"
#include "field.h"

class T130: public Floor // if you implement a Floor tile, replace "Wall" with "Floor"
{
protected:

  ITexture *alt_texture;
  T130 *related[260];
  int nbRelated;

public:
  T130(ISceneManager* smgr,
      IVideoDriver* driver,
      int x, int y, playground  pg) ;
  
  virtual fieldtype getFieldType();

  virtual void sphereEnter(Sphere &s);
  virtual void sphereExit(Sphere &s);
  
  virtual void introduceTo(Field &f);
  /*
  virtual void handleSphere(Sphere &s, position2di mousemove, f32 frameDeltaTime);

  virtual void timeProgress(f32 frameDeltaTime);

  virtual void sphereOverlap(Sphere &s, f32 xoverlap, f32 yoverlap);

  virtual void alternateSphereProgress(position2di mousemove, f32 frameDeltaTime, f32 friction);
   * 
  virtual void introduceSphere(Sphere &s);
  */
};


#endif
