// Created by Tony on 2024-10-10 10:01:54
/* Crash fixed by shark ^^ */
#include "HurtColor.h"

HurtColor::HurtColor() : Module("HurtColor", "Changes hurt color.", Category::RENDER) {
	addColorPicker("Hurt Color", "NULL", &hurtColor);
	addBoolCheck("Fade", "Fade hurt colors.", &fade);
}