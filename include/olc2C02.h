#pragma once

#include <cstdint>
#include <memory>

#include "Cartridge.h"
#include "olcPixelGameEngine.h"

class olc2C02
{
public:
    olc2C02();
    ~olc2C02();

private:
    uint8_t tblName[2][1024]; // two 1kB name tables
    uint8_t tblPalette[32]; // for the color palettes, up to 32 entries

private:
	olc::Pixel  palScreen[0x40];

	olc::Sprite* sprScreen;
	olc::Sprite* sprNameTable[2];
	olc::Sprite* sprPatternTable[2];

public:
	// debugging utilities
	olc::Sprite& GetScreen();
	olc::Sprite& GetNameTable(uint8_t i);
	olc::Sprite& GetPatternTable(uint8_t i);
	bool frame_complete = false;

private:
	int16_t scanline = 0;
	int16_t cycle = 0;

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