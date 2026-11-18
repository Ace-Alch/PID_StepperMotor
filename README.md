# Tuning a Stepper Motor

An Arduino Uno reads four potentiometers and drives a stepper motor through an L298N. Three knobs set the PID gains. The fourth sets the target position.

**[Open the trace viewer](https://ace-alch.github.io/apps/exhibits/stepper/)** · [Arduino sketch](sketch_FinalPID/sketch_FinalPID.ino) · [Wiring diagram](images/wiring.png)

## From P to PID

<table>
<tr><th>Proportional only</th><th>Manual PID tuning</th></tr>
<tr>
<td width="50%"><img src="results/P.gif" alt="Original Arduino Serial Plotter recording for proportional control"></td>
<td width="50%"><img src="results/PID_opt.gif" alt="Original Arduino Serial Plotter recording after tuning PID gains"></td>
</tr>
</table>

These are the original Arduino Serial Plotter captures. Browse the [PD capture](results/PD.gif), the [earlier PID capture](results/PID.gif), and the [tuning notes](results/README.md).

## How to read the traces

- **Target:** The sketch maps the position knob to 0–400 steps.
- **Position:** The plotted value is the count of steps the sketch commands. The sketch has no shaft encoder, so missed steps would be invisible in this trace.
- **Drive:** The firmware advances through an eight-state coil sequence and waits 2 ms between commanded steps.

The browser trace viewer compares three runs of the original sketch with simulated time, potentiometers, and GPIO. You can scrub through each run and see which of the four outputs the sketch drove at that sample.

<details>
<summary>Arduino pin map</summary>

| Input or output | Pin |
| --- | --- |
| Position / Kp / Ki / Kd | A0 / A1 / A2 / A3 |
| Driver IN1 / IN2 / IN3 / IN4 | D8 / D9 / D10 / D11 |

</details>

[Build and setup](portfolio/SETUP.md) · [Evidence and limits](portfolio/EVIDENCE.md) · [MIT License](LICENSE)
