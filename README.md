# NES Emulator in C++

This project is an NES (Nintendo Entertainment System) emulator written in C++. The goal of the project is to recreate the functionality of an NES using software emulation. This README describes the current progress and functionality, focusing on the 6502 CPU emulation and memory interaction.

## Project Overview

The NES emulator aims to simulate the core components of the NES console, starting with the emulation of the **MOS Technology 6502 CPU**, which is a variation of the Ricoh 2A03, the CPU at the heart of the NES. The current implementation emulates the CPU **behaviorally**, meaning that it recreates the operational behavior of the CPU without emulating its electrical signals. 

At this stage, the emulator has the following completed components:
- **Behavioral Emulation of MOS Technology 6502 CPU**:
  - Emulates the 6502 CPU instruction set used in NES (without illegal opcodes).
  - Allows the CPU to interact with a simple RAM model.
- **RAM Emulation**:
  - A basic RAM module is emulated to allow the CPU to perform read and write operations, providing a testing environment for the CPU.

### Features

- **6502 CPU**: Emulated at the behavioral level, without illegal opcodes.
- **Simple RAM**: Provides a simple addressable memory space for the CPU.
  
### Testing

Testing files for the 6502 CPU were provided by [OneLoneCoder](https://onelonecoder.com). These files help verify the correctness of the CPU instructions and general operation.

### Dependencies

- **C++17 or newer**: The codebase is written in C++ with modern standards.
- **X11**: For windowing and graphical interface management.
- **OpenGL**: For graphics rendering.
- **POSIX**: For multi-threading support.
- **PNG**: For handling PNG images.
- **Filesystem**: For file system operations.

### Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/rospuye/NES_emulator.git
   cd NES_emulator
2. Build the project:
   ```bash
   g++ -Iinclude src/*.cpp main.cpp -o olc6502_demo -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
3. Run the emulator:
   ```bash
   ./olc6502_demo
### Future Work

The next steps for this project involve:
- **Memory Management**: Implement memory buses, RAM, ROM, and mappers for more accurate memory handling.
- **PPU (Picture Processing Unit)**: Begin emulating the NES graphics system to support video output.
- **APU (Audio Processing Unit)**: Emulate the NES audio system for sound output.
