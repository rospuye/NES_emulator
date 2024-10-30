#pragma once

#include <cstdint>
#include <vector>
#include <memory>
#include "../include/Mapper_000.h"

class Cartridge
{
public:
    Cartridge(const std::string& sFileName);
    ~Cartridge();

private:
    std::vector<uint8_t> vPRGMemory; // virtual program memory
    std::vector<uint8_t> vCHRMemory; // virtual character memory

    uint8_t nMapperID = 0; // which mapper we are using
    uint8_t nPRGBanks = 0; // how many banks of vPRG memory there are
    uint8_t nCHRBanks = 0; // how many banks of vCHR memory there are

    std::shared_ptr<Mapper> pMapper;

public:
    // talk to the main bus
    bool cpuRead(uint16_t addr, uint8_t &data);
    bool cpuWrite(uint16_t addr, uint8_t data);

    // talk to the PPU bus
    bool ppuRead(uint16_t addr, uint8_t &data);
    bool ppuWrite(uint16_t addr, uint8_t data);
};