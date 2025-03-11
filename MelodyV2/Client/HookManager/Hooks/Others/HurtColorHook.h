#pragma once
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../SDK/Classes/Actor.h"

#include "../../../Client.h"
/* Crash fixed by shark ^^ */
class HurtColorHook {
protected:
    using func_t = MC_Color * (__fastcall*)(__int64, MC_Color*, __int64);
    static inline func_t func;
    static MC_Color* HurtColorCallback(__int64 a1, MC_Color* color, __int64 a3) {
        // Validate if the `hurtColorMod` module is available before using it
        static HurtColor* hurtColorMod = (HurtColor*)client->moduleMgr->getModule("HurtColor");
        if (hurtColorMod == nullptr || !hurtColorMod->isEnabled()) {
            return func(a1, color, a3);
        }
        __int64 actor = *(uintptr_t*)(a3 + 0x38);
        if (actor == 0) {
            return func(a1, color, a3);
        }
        int* v7 = *(int**)(actor + 0x630);
        if (v7 == nullptr) {
            return func(a1, color, a3);
        }
        color->r = hurtColorMod->hurtColor.r / 255.f;
        color->g = hurtColorMod->hurtColor.g / 255.f;
        color->b = hurtColorMod->hurtColor.b / 255.f;
        color->a = hurtColorMod->hurtColor.a / 255.f;
        if (hurtColorMod->fade) {
            color->a *= (*v7 / 10.f);
        }
        return color;
    }
public:
    static void init() {
        uintptr_t address = MemoryUtils::getFuncFromCall(findSig(Sigs::hook::HurtColorHook));
        if (address == 0) {
            return;
        }
        MemoryUtils::CreateHook("HurtColorHook", address, (void*)&HurtColorHook::HurtColorCallback, (void*)&func);
    }
};
