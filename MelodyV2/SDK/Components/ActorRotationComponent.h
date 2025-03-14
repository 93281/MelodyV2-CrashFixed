// Created by Tony on 2024-10-10 10:01:54

#pragma once

#include "../../Utils/Math.h"

struct ActorRotationComponent
{
public:
    Vec2<float> rotation;
    Vec2<float> oldRotation;

    ActorRotationComponent(const Vec2<float>& rotation) : rotation(rotation), oldRotation(rotation) {}
    bool IsValidRotation(const Vec2<float>& rots) const
    {
        return !std::isnan(rots.x) && !std::isnan(rots.y) && std::isfinite(rots.x) && std::isfinite(rots.y);
    }

    [[nodiscard]] const Vec2<float>& Get() const
    {
        return this->rotation;
    }

    void Set(Vec2<float> rots)
    {
        if (IsValidRotation(rots))
        {
            this->oldRotation = this->rotation;
            this->rotation = rots;
        }
        else
        {
            this->rotation = this->oldRotation;
        }
    }
};
