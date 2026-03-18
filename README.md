# STM32H7 Dual-Core-Based Environmental Monitoring System

A high-performance environment monitoring system based on the **STM32H755ZI-Q** (Cortex-M7 + Cortex-M4). This project demonstrates an **Asymmetric Multi-Processing (AMP)** architecture to decouple sensor data acquisition from graphical user interface (GUI) rendering.

## ystem Architecture

This project leverages the dual-core capability of the STM32H7 series:

* **Cortex-M7 (CM7)**: 
    * Handles **ST7735S 1.8" LCD** driver and GUI rendering logic.
    * Communicates via **SPI1** protocol.
    * Reads environmental data from shared memory for real-time display updates.
* **Cortex-M4 (CM4)**:
    * Manages sensor data acquisition for **SHT31** (Temp/Humi) and **DS3231** (RTC) via **I2C1**.
    * Processes data validation (CRC) and writes results to the shared memory region.



## Hardware Configuration

| Component | Interface | Core Assignment | Key Pins |
| :--- | :--- | :--- | :--- |
| **ST7735S LCD** | SPI | CM7 | PB3(SCK), PB5(MOSI), PD15(CS), PE11(DC), PE14(RES)|
| **SHT31 / DS3231** | I2C | CM4 | PB8(SCL), PB9(SDA) |
| **HSEM** | Internal | Dual | Hardware Semaphore for sync |

## Key Technical Features

1.  **Inter-Core Communication (IPC)**: Utilizes **SRAM4 (0x38000000)** as a shared buffer. Synchronization is managed by **HSEM (Hardware Semaphore)** to prevent race conditions during multi-core read/write operations.

## Development Environment
* **IDE**: STM32CubeIDE v2.1.0
* **Configuration**: STM32CubeMX v6.17.0
* **Framework**: HAL (Hardware Abstraction Layer)

## Getting Started
1. Clone this repository.
2. Open the `.project` file in STM32CubeIDE.
3. Build the CM4 project first, then the CM7 project.
4. Flash the dual-core binary to your NUCLEO-H755ZI-Q board.
 
