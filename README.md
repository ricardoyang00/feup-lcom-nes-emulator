# MINIX - NES Emulator 
An NES emulator coded entirely in C using device drivers developed for [LCOM](https://sigarra.up.pt/feup/en/UCURR_GERAL.FICHA_UC_VIEW?pv_ocorrencia_id=520323) course at @FEUP.

<a href="https://minix3.org/"><img src="https://img.shields.io/badge/OS-Minix%203-blue"></a>
</br>

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [System Requirements](#system-requirements)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Akacknowledgements](#acknowledgements)


## Introduction
Welcome to the NES Emulator! This project aims to provide an emulator for the Nintendo Entertainment System (NES), written from the ground up to be portable and easily compatible with various device drivers, whether for Linux, Windows and Minix. This allows users to play classic NES games on modern hardware.

## Features
- Accurate emulation of NES CPU, PPU, cartidge loading, mapping and contoller connection.
- Support for the popular NES file formats (.nes) with iNES headers.
- Serial connection to real controller through a `ESP8266` being used as a bridge.
- Various resolutions and scalling.
- Very fast loading and unloading of games.

## System Requirements
This repository only runs on the Minix image developed for the LCOM course at FEUP. 

**You can download the image [here](https://drive.google.com/file/d/1dM32zTzkTUEqNtTwsO-n__XO6r1Y5I-f/view?usp=sharing)**.

> Since we are working with low-level hardware configurations and direct access to the programmatic interface of a computer’s I/O devices raises security risks, it is recommended to use a `virtual machine` to emulate this project. The suggested solution is to run it on VirtualBox (the link above contains the `.vb` file).

## Installation

1. **Install VirtualBox**: Download and install [VirtualBox](https://www.virtualbox.org/wiki/Downloads) for your system.

2. **Download MINIX Image**: Get the MINIX image provided in the [System Requirements](#system-requirements).

3. **Open MINIX in VirtualBox**:
- Double-click the `.vbox` file to open VirtualBox with the settings for the MINIX-LCOM VM.

4. **Clone the Repository**:
```bash
# clone the repository
git clone git@github.com:ricardoyang00/NES_Emulator-LCOM.git
```

5. **Set Up Shared Folder**:
- In the `MINIX-LCOM/` folder, create a `shared/` folder.
- Open the settings for the MINIX VM in VirtualBox and set the shared folder to the `shared/` directory you just created.
- Move the cloned repository into the `shared/` folder.

6. **Start the VM**:
- Boot up the VM. Use `lcom` for the login and `lcom` for the password.

7. **Get the ROMs**: 
- To use the emulator, ensure all [ROMs](roms/roms.txt) are placed in the `roms/` folder.
- The roms that are expected to have are `supermariobros`, `soccer`, `DonkeyKong`, `mspacman`, and `BattleCity`.

8. **Build and Run the Project**:
```bash
cd labs/src/
make
lcom_run proj

# see more in USAGE about extra flags
```

9. To exit the emulator's interface you can press `exit` key.

## Usage

To run use `lcom_run proj`

You can also use these flags:
| Syntax | Description |
| --- | ----------- |
| --no-uart | Disables serial connection |
| --player-1-serial | Swaps controller 1 from keyboard to Serial |
| --vmode 0x115 | Enables VBE_MODE_DC_24 video mode while emulator running |

**(Don't forget to wrap the flags in " ")**

> for example `lcom_run proj "--no-uart"`

## Controls

### Menu
- **Mouse** - to select game
- **Arrows** - &larr; and &rarr; to change menu page
- **Exit** -  to quit the program

### Game (emulator)
<p align="center"><img src="/doc/image.png" alt="controller or keyboard instructions image" width=700></p>

## Acknowledgements
A big thanks to:

- Professor **Nuno Cardoso** for his unwavering support and encouragement, inspiring us to learn more and never give up.
- **OneLoneCoder** (Javidx9) for his insightful series on NES emulator development, and his community for helping me understand the inner workings of the NES.
