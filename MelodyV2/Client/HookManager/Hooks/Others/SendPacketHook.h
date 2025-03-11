#pragma once
/* Crash fixed by shark ^^ */
#include "../../../../Utils/MemoryUtils.h"
#include "../../../../SDK/Classes/LoopbackPacketSender.h"

#include "../../../Client.h"

class SendPacketHook {
protected:
    using func_t = void(__fastcall*)(LoopbackPacketSender*, Packet*);
    static inline func_t oFunc;
    static void LoopbackPacketSender_sendToServer(LoopbackPacketSender* _this, Packet* packet) {
        if (packet == nullptr) {
            return;
        }
        if (packet->getName() == "LoginPacket") {
            int numDots = (static_cast<int>(ImGui::GetTime() * 8) % 3) + 1;
            std::string dots = std::string(numDots, '.');
            Notifications::addNotifBox("Connecting to server" + dots, 5.f);
        }
        LocalPlayer* localPlayer = mc.getLocalPlayer();
        if (localPlayer == nullptr) {
            return;
        }
        bool shouldCancel = false;
        if (packet->getId() == PacketID::Text) {
            TextPacket* tPacket = reinterpret_cast<TextPacket*>(packet);
            if (tPacket && tPacket->messageType == 1) {
                client->commandMgr->onSendTextPacket(tPacket, shouldCancel);
            }
        }
        static NoPacket* noPacketMod = (NoPacket*)client->moduleMgr->getModule("NoPacket");
        if (noPacketMod != nullptr && noPacketMod->isEnabled() && localPlayer != nullptr) {
            return;
        }
        client->moduleMgr->onSendPacket(packet, shouldCancel);
        if (shouldCancel) {
            return;
        }
        oFunc(_this, packet);
    }
public:
    static void init(uintptr_t address) {
        if (address == 0) {
            return;
        }
        MemoryUtils::CreateHook("SendPacketHook", address, (void*)&SendPacketHook::LoopbackPacketSender_sendToServer, (void*)&oFunc);
    }
};
