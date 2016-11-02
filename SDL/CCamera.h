#ifndef CCAMERA_H
#define CCAMERA_H

#include "CCamera.h"
#include "CEntity.h"

class CCamera {
public:
	CCamera();
	void Update();
	void SetChild(CEntity *child);
	CEntity *GetChild();
	int posX, posY;
	int windowHeight, windowWidth;
private:
	CEntity *child;
};

#endif 