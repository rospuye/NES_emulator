#include <cstdint>
#include "../include/olc2C02.h"

olc2C02::olc2C02() {}

olc2C02::~olc2C02() {}

uint8_t olc2C02::cpuRead(uint16_t addr, bool rdonly = false)
{
    uint8_t data = 0x00;

    switch (addr)
    {
    case 0x0000: // control
        break;
    case 0x0001: // mask
        break;
    case 0x0002: // status
        break;
    case 0x0003: // OAM address
        break;
    case 0x0004: // OAM data
        break;
    case 0x0005: // scroll
        break;
    case 0x0006: // PPU address
        break;
    case 0x0007: // PPU data
        break;
    }

    return data;
}

void olc2C02::cpuWrite(uint16_t addr, uint8_t data)
{
    switch (addr)
    {
    case 0x0000: // control
        break;
    case 0x0001: // mask
        break;
    case 0x0002: // status
        break;
    case 0x0003: // OAM address
        break;
    case 0x0004: // OAM data
        break;
    case 0x0005: // scroll
        break;
    case 0x0006: // PPU address
        break;
    case 0x0007: // PPU data
        break;
    }
}

uint8_t olc2C02::ppuRead(uint16_t addr, bool rdonly = false) // TODO: doing nothing for now
{
    uint8_t data = 0x00; // placeholder value
    addr &= 0x3FF;
    return data;
}

void olc2C02::ppuWrite(uint16_t addr, uint8_t data) // TODO: doing nothing for now
{
    // masking the address in case the PPU tries to write to its bus in a location beyond its addressable range
    addr &= 0x3FFF;
}
