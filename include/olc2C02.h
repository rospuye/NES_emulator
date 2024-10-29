#pragma once

class olc2C02
{
public:
    olc2C02();
    ~olc2C02();

    // talk to main bus
    uint8_t cpuRead(uint16_t addr, bool rdonly = false);
    void cpuWrite(uint16_t addr, uint8_t data);

    // talk to its own bus (PPU bus)
    uint8_t ppuRead(uint16_t addr, bool rdonly = false);
    void ppuWrite(uint16_t addr, uint8_t data);
};