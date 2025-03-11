// Created by Tony on 2024-10-10 10:01:54

#include "Clip.h"

Clip::Clip() : Module("Clip", "Clip onto walls, should never use with surround", Category::MOVEMENT) {
	addSlider<float>("Clip", "NULL", ValueType::FLOAT_T, &Clipvalue, 0.f, 0.35f);
}
/* Crash fixed by shark ^^ */
void Clip::onNormalTick(Actor* actor) {
    LocalPlayer* localPlayer = mc.getLocalPlayer();
    if (!localPlayer) return;
    auto* playerPos = localPlayer->getPosition();
    if (!playerPos) return;
    auto* aabb = localPlayer->getAABB();
    if (!aabb) return;
    aabb->lower.x = playerPos->x - Clipvalue;
    aabb->lower.z = playerPos->z - Clipvalue;
    aabb->upper.x = playerPos->x + Clipvalue;
    aabb->upper.z = playerPos->z + Clipvalue;
}

void Clip::onDisable() {
    LocalPlayer* localPlayer = mc.getLocalPlayer();
    if (!localPlayer) return;
    auto* playerPos = localPlayer->getPosition();
    if (!playerPos) return;
    auto* aabb = localPlayer->getAABB();
    if (!aabb) return;
    aabb->lower.x = playerPos->x - 0.35f;
    aabb->lower.z = playerPos->z - 0.35f;
    aabb->upper.x = playerPos->x + 0.35f;
    aabb->upper.z = playerPos->z + 0.35f;
}
