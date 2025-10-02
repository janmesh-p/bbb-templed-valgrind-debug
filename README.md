# BBB Templated Valgrind Debug — Beaglebone Branch

This branch contains the **real hardware implementation** of the LED PWM control system on the BeagleBone Black (BBB).  
Unlike the `templated` branch (mock environment for testing), this branch drives actual PWM hardware pins on the BBB.

---

## Hardware Setup

- **Board:** BeagleBone Black  
- **PWM Pins Used:**  
  - P9.42  
  - P9.14  
  - P9.16  

Ensure these pins are not multiplexed for other functions before running.

---

## Software Requirements

- Linux-based BeagleBone Black (Debian or compatible image)  
- GCC toolchain (`make`, `gcc`)  
- Valgrind (optional, for debugging memory usage)  

---

## Build Instructions

From the project root:

```bash
make clean
make bbb
```

This generates the binary:

```
./bbb_debug
```

---

## Pin Configuration

Before running the program, configure the PWM pins:

```bash
./setup_led.sh
```

This script exports and configures the PWM-capable pins **P9.42**, **P9.14**, and **P9.16** for LED control.

---

## Running the Program

After building and configuring:

```bash
./bbb_debug
```

This runs the LED control firmware on the BeagleBone Black, toggling/configuring PWM signals on the specified pins.

---

## Directory Layout

```
/
├── Makefile          # Build targets: bbb, clean
├── setup_led.sh      # Script to configure PWM pins
├── src/              # Source code implementation
├── include/          # Header files
└── bbb_debug         # Binary after compilation
```

---

## Debugging & Validation

Run under Valgrind if available:

```bash
valgrind --leak-check=full ./bbb_debug
```

- Use `dmesg` or `journalctl` for kernel messages if required.  
- Use an oscilloscope or multimeter on pins P9.42, P9.14, and P9.16 to verify PWM output.  

---

## Notes

- This branch is tied to **real BeagleBone hardware**.  
- Root permissions may be required for GPIO/PWM access.  
- Use this branch for hardware testing; use the `templated` branch for mock/debug environments.  

---

## License

MIT License. See [LICENSE](LICENSE).
