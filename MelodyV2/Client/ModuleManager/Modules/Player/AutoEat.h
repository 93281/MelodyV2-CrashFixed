// Created by Tony on 2024-10-10 10:01:54

#pragma once
#include "../Module.h"

class AutoEat : public Module {
public:
	AutoEat();

	virtual void onNormalTick(Actor* actor) override;
};
