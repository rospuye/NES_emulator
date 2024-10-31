#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include "olc6502.h"
#include "olc2C02.h"
#include "Cartridge.h"

class Bus {

public:
    Bus();
    ~Bus();

public:
    olc6502 cpu;
    olc2C02 ppu;
    std::shared_ptr<Cartridge> cart;
    uint8_t cpuRam[2048];

public:
    void cpuWrite(uint16_t addr, uint8_t data);
    uint8_t cpuRead(uint16_t addr, bool bReadOnly = false);

public: // NES interface functions
    // you load the cartridge into memory before inserting it into the NES
    // that's why we have a shared pointer to a cartridge object
    void insertCartridge(const std::shared_ptr<Cartridge>& cartridge);
    void reset(); // reset button on the front of the NES
    void clock(); // perform one system tick on the emulation

private:
    // counts how many clocks have passed
    uint32_t nSystemClockCounter = 0;
};