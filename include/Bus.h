#pragma once

#include <array>
#include <cstdint>
#include "olc6502.h"

class Bus {

public:
    Bus();
    ~Bus();

public:
    olc6502 cpu;
    std::array<uint8_t, 64 * 1024> ram; // fake ram

public:
    void write(uint16_t addr, uint8_t data);
    uint8_t read(uint16_t addr, bool bReadOnly = false);
};