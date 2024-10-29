#include "../include/Bus.h"

Bus::Bus()
{
    // clear ram contents, just in case!
    for (auto &i : cpuRam) i = 0x00;

    // connect cpu to communication bus
    cpu.ConnectBus(this);
}

Bus::~Bus() {}

void Bus::cpuWrite(uint16_t addr, uint8_t data)
{
    if (addr >= 0x0000 && addr <= 0x1FFF) // main RAM range
        cpuRam[addr & 0x07FF] = data;
    else if (addr >= 0x2000 && addr <= 0x3FFF) // PPU range
        ppu.cpuWrite(addr & 0x0007, data); // mirroring again, because we only have 8 elements to write to
}

uint8_t Bus::cpuRead(uint16_t addr, bool bReadOnly)
{
    uint8_t data = 0x00; // 0x00 if we read outside the range
    if (addr >= 0x0000 && addr <= 0x1FFF)
        data = cpuRam[addr & 0x07FF]; // & 0x07FF -> mirror the RAM every 2kB
    else if (addr >= 0x2000 && addr <= 0x3FFF)
        data = ppu.cpuRead(addr & 0x0007, bReadOnly);
    return data;
}
