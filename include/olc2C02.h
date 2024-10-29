#pragma once

class olc2C02
{
public:
    olc2C02();
    ~olc2C02();

private:
    uint8_t tblName[2][1024]; // two 1kB name tables
    uint8_t tblPalette[32]; // for the color palettes, up to 32 entries

public:
    // talk to main bus
    uint8_t cpuRead(uint16_t addr, bool rdonly = false);
    void cpuWrite(uint16_t addr, uint8_t data);

    // talk to its own bus (PPU bus)
    uint8_t ppuRead(uint16_t addr, bool rdonly = false);
    void ppuWrite(uint16_t addr, uint8_t data);

private:
    // the PPU also has access to the cartridge
    std::shared_ptr<Cartridge> cart;

public:
    // connect the cartridge to the PPU
    void connectCartridge(const std::shared_ptr<Cartridge>& cartridge);
    void clock();
};