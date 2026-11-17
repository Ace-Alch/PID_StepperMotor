# PID-Controlled Stepper Motor: setup

## Current entry point

1. Open `sketch_FinalPID/sketch_FinalPID.ino` in Arduino IDE.
2. Select the connected Arduino Uno and port.
3. Check D8–D11 to the driver inputs. Check A0 for the target and A1–A3 for gain controls.
4. Check driver supply, coil current and a common ground against the actual hardware.
5. Upload the sketch and observe serial output at 9600 baud.

The source uses 400 commanded steps per revolution. Confirm the motor and step sequence before treating this count as an angle.

## Required records

- Independent shaft feedback
- Current and thermal checks
- Position limits
- Reproduced tuning measurements

## Reproducibility record

Record the source commit, operating system, tool versions, dependencies, input files, configuration and command. Store the output separately from the expected result. Mark any manual step.
