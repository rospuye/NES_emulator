#include "../include/Cartridge.h"
#include <string>
#include <fstream>

Cartridge::Cartridge(const std::string& sFileName)
{
    // iNES format header
    struct sHeader
    {
        char name[4];
        uint8_t prg_rom_chunks;
        uint8_t chr_rom_chunks;
        uint8_t mapper1;
        uint8_t mapper2;
        uint8_t prg_ram_size;
        uint8_t tv_system1;
        uint8_t tv_system2;
        char unused[5];
    } header;

    std::ifstream ifs;
    ifs.open(sFileName, std::ifstream::binary);
    if (ifs.is_open())
    {
        // read file header
        ifs.read((char*)&header, sizeof(sHeader));

        // next 512 bites are training information (don't need it)
        if (header.mapper1 & 0x04)
            ifs.seekg(512, std::ios_base::cur);

        // extract which mapper the ROM is using
        nMapperID = ((header.mapper2 >> 4) << 4) | (header.mapper1 >> 4);

        // discover file format (there are 3 iNES file formats)
        uint8_t nFileType = 1;

        if (nFileType == 0)
        {
            // TODO
        }
        if (nFileType == 1)
        {
            // read how many memory banks are in the ROM for program memory
            nPRGBanks = header.prg_rom_chunks;
            // resize my vector to that size
            // file format standard specifies that a single program memory bank occupies 16kB
            vPRGMemory.resize(nPRGBanks * 16384);
            // read data from the file directly into the vector
            ifs.read((char*)vPRGMemory.data(), vPRGMemory.size());

            nCHRBanks = header.chr_rom_chunks;
            vCHRMemory.resize(nCHRBanks * 8192);
            ifs.read((char*)vCHRMemory.data(), vCHRMemory.size());
        }
        if (nFileType == 2)
        {
            // TODO
        }

        ifs.close();
    }
}

Cartridge::~Cartridge() {}

bool Cartridge::cpuRead(uint16_t addr, uint8_t &data)
{
    return false;
}

bool Cartridge::cpuWrite(uint16_t addr, uint8_t data)
{
    return false;
}

bool Cartridge::ppuRead(uint16_t addr, uint8_t &data)
{
    return false;
}

bool Cartridge::ppuWrite(uint16_t addr, uint8_t data)
{
    return false;
}


