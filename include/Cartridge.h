#pragma once

#include <cstdint>

class Cartridge
{
public:
    Cartridge();
    ~Cartridge();

public:
    // talk to the main bus
    bool cpuRead(uint16_t addr, uint8_t &data);
    bool cpuWrite(uint16_t addr, uint8_t data);

    // talk to the PPU bus
    bool ppuRead(uint16_t addr, uint8_t &data);
    bool ppuWrite(uint16_t addr, uint8_t data);
};