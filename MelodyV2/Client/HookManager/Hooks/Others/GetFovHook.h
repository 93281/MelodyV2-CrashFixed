#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../Client.h"
/* Crash fixed by shark ^^ */
class GetFovHook {
protected:
    using func_t = float(__thiscall*)(LevelRendererPlayer*, float, bool);
    static inline func_t func;
    static float LevelRendererPlayer_getFov(LevelRendererPlayer* _this, float a, bool applyEffects) {
        static CustomFov* customFovMod = nullptr;
        if (client != nullptr && client->moduleMgr != nullptr) {
            customFovMod = (CustomFov*)client->moduleMgr->getModule("CustomFov");
        }
        if (customFovMod != nullptr && customFovMod->isEnabled()) {
            return customFovMod->fov;
        }
        return func(_this, a, applyEffects);
    }
public:
    static void init() {
        uintptr_t address = findSig(Sigs::hook::getFovHook);
        if (address == 0) {
            return;
        }
        MemoryUtils::CreateHook("GetFovHook", address, (void*)&GetFovHook::LevelRendererPlayer_getFov, (void*)&func);
    }
};
