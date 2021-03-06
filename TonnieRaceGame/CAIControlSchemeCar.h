#ifndef CAICONTROLSCHEMECAR_H
#define CAICONTROLSCHEMECAR_H

#include "IBox2DListener.h"
#include "IControlScheme.h"

class CAIControlSchemeCar : public IControlScheme
{
public:
	explicit CAIControlSchemeCar(CEngine* engine);
	void Input(SDL_Event* event) override;
	void Update() override;
	void SetCar(CEntityCar* car) override;
	void SetTire(CEntityTire* tire) override;
	void UpdateFriction() override;
	void UpdateDrive() override;
	void UpdateTurn() override;
	void FinishCallback() override;
	IControlScheme* GetNewTireScheme() override;
private:
	CEngine* engine;
};

#endif
