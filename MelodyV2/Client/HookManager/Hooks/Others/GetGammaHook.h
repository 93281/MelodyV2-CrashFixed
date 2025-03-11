#pragma once
#include "../../../../SDK/Classes/Options.h"
#include "../../../../Utils/MemoryUtils.h"
#include "../../../Client.h"
/* Crash fixed by shark ^^ */
class GetGammaHook {
protected:
    using func_t = float(__thiscall*)(Options**);
    static inline func_t func;
    static float GetGamma(Options** optionList) {
        static NoRender* noRenderMod = nullptr;
        static Fullbright* fullBrightMod = nullptr;
        if (client != nullptr && client->moduleMgr != nullptr) {
            noRenderMod = (NoRender*)client->moduleMgr->getModule("NoRender");
            fullBrightMod = (Fullbright*)client->moduleMgr->getModule("Fullbright");
        }
        uintptr_t** list = (uintptr_t**)optionList;
        if (list == nullptr) return func(optionList);
        int obtainedSettings = 0;
        for (uint16_t i = 3; i < 450; i++) {
            if (list[i] == nullptr) continue;
            uintptr_t* info = *(uintptr_t**)((uintptr_t)list[i] + 8);
            if (info == nullptr) continue;
            TextHolder* translateName = (TextHolder*)((uintptr_t)info + 0x158);
            if (translateName == nullptr) continue;
            bool* boolSetting = (bool*)((uintptr_t)list[i] + 16);
            if (boolSetting == nullptr) continue;
            if (strcmp(translateName->getText(), "options.dev_disableRenderWeather") == 0) {
                *boolSetting = (noRenderMod != nullptr && noRenderMod->isEnabled() && noRenderMod->noWeather);
                obtainedSettings++;
            }
            else if (strcmp(translateName->getText(), "options.dev_disableRenderEntities") == 0) {
                *boolSetting = (noRenderMod != nullptr && noRenderMod->isEnabled() && noRenderMod->noEntities);
                obtainedSettings++;
            }
            else if (strcmp(translateName->getText(), "options.dev_disableRenderSky") == 0) {
                *boolSetting = (noRenderMod != nullptr && noRenderMod->isEnabled() && noRenderMod->noSky);
                obtainedSettings++;
            }
            else if (strcmp(translateName->getText(), "options.dev_disableRenderHud") == 0) {
                *boolSetting = (noRenderMod != nullptr && noRenderMod->isEnabled() && noRenderMod->NoHUD);
                obtainedSettings++;
            }
            else if (strcmp(translateName->getText(), "options.dev_disableRenderItemInHand") == 0) {
                *boolSetting = (noRenderMod != nullptr && noRenderMod->isEnabled() && noRenderMod->Noiteminhand);
                obtainedSettings++;
            }
            else if (strcmp(translateName->getText(), "options.dev_disableRenderTerrain") == 0) {
                *boolSetting = (noRenderMod != nullptr && noRenderMod->isEnabled() && noRenderMod->NoTerrain);
                obtainedSettings++;
            }
            else if (strcmp(translateName->getText(), "options.dev_disableRenderMainMenuPaperdollAnimation") == 0) {
                *boolSetting = (noRenderMod != nullptr && noRenderMod->isEnabled() && noRenderMod->NoMainMenuPaperdollAnimation);
                obtainedSettings++;
            }
            else if (strcmp(translateName->getText(), "options.dev_disableRenderMainMenuCubeMap") == 0) {
                *boolSetting = (noRenderMod != nullptr && noRenderMod->isEnabled() && noRenderMod->NoMainMenuCubeMap);
                obtainedSettings++;
            }
            else if (strcmp(translateName->getText(), "options.dev_disableRenderBlockEntities") == 0) {
                *boolSetting = (noRenderMod != nullptr && noRenderMod->isEnabled() && noRenderMod->noBlockEntities);
                obtainedSettings++;
            }
            else if (strcmp(translateName->getText(), "options.dev_disableRenderParticles") == 0) {
                *boolSetting = (noRenderMod != nullptr && noRenderMod->isEnabled() && noRenderMod->noParticles);
                obtainedSettings++;
            }
            if (obtainedSettings == 4) break;
        }
        if (fullBrightMod != nullptr && fullBrightMod->isEnabled()) {
            return fullBrightMod->intensity;
        }
        return func(optionList);
    }
public:
    static void init() {
        uintptr_t address = findSig(Sigs::hook::GetGammaHook);
        if (address == 0) {
            return;
        }
        MemoryUtils::CreateHook("GetGammaHook", address, (void*)&GetGammaHook::GetGamma, (void*)&func);
    }
};
