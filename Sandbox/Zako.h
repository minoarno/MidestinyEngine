#pragma once
#include "Enemy.h"
class Zako final : public Enemy
{
public:
    Zako();
    Zako(const Zako& other) = delete;
    Zako& operator=(const Zako& other) = delete;
    Zako(Zako&& other) = delete;
    Zako& operator=(Zako&& other) = delete;
    ~Zako();

    void Dive() override;
private:

};

