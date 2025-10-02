# BBB Templated Valgrind Debug — Templated Branch

This branch contains the clean, templated implementation for running on the BeagleBone Black (BBB) without additional instrumentation.

## Overview

This repository hosts embedded C code for controlling PWM, reading peripherals, and basic operations on BBB. It is structured for modularity and future debugging instrumentation.

## Features / Modules

- `pwm.c` / `pwm.h`: PWM driver abstraction  
- `bbb_debug` (if present): minimal logging / debug hooks  
- Use of templated architecture (clear separation: HAL, driver, application layers)  
- Makefile for build orchestration  
- `include/` directory with headers  
- `src/` directory with implementation code  
- `tests/` directory for unit / integration tests  

## Building & Deployment

```bash
# from project root
make clean
make all
# deploy to BBB (e.g. via ssh / scp)
scp bbb_debug <ip_address>@beaglebone:/home/debian/
```

## Running

1. Copy binary onto BBB  
2. Setup permissions (if needed)  
3. Execute the binary  
4. Monitor via serial / logs  

## Directory Structure

```
/
├── Makefile
├── include/
│   └── *.h
├── src/
│   └── *.c
├── tests/
│   └── test_*.c
└── bbb_debug  (binary or stub)
```

## Contributing

- Use branches per feature  
- Follow coding style: consistent indent, clear naming  
- Submit PRs with tests  

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
