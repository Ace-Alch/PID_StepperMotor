# PID-Controlled Stepper Motor: evidence register

| Evidence | Origin | Strength |
| :-- | :-- | :-- |
| Project purpose, stated status and technology list | User-supplied project list, 17 November 2026 | Owner statement; no new execution |
| Repository file inventory | [Ace-Alch/PID_StepperMotor](https://github.com/Ace-Alch/PID_StepperMotor), main | Paths and blob identifiers inspected |
| Previous README | `README-before-rebuild.md` | Historical documentation; claims require the listed checks |

## Evidence limits

The source updates `currentPosition` when it commands a step. It does not read an encoder. The reported position is a commanded step count. It cannot detect missed steps or prove physical closed-loop position control. The integral has no anti-windup bound. The move loop can block input sampling.

## Missing material

- Independent shaft feedback
- Current and thermal checks
- Position limits
- Reproduced tuning measurements
