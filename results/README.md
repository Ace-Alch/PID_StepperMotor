#  PID Stepper Motor Results

This folder showcases the live response of the stepper motor using different combinations of PID tuning. The plots are captured using the Arduino Serial Plotter while adjusting Kp, Ki, and Kd in real time via potentiometers.

---

##  P-Control Only

- **GIF**: `P.gif`
- **Description**:  
  Only the **proportional (P)** term is active. The system follows the target but:
  - Steady-state error remains.
  - Noticeable fluctuations occur due to lack of damping.

![P Control](./P.gif)

---

##  PD-Control

- **GIF**: `PD.gif`
- **Description**:  
  The **derivative (D)** term is added to reduce noise and provide damping.
  - Fluctuations are reduced.
  - Steady-state error still persists.

![PD Control](./PD.gif)

---

##  PID-Control (Non-Optimized)

- **GIF**: `PID.gif`
- **Description**:  
  The **integral (I)** term is now introduced to eliminate steady-state error.
  - The system is stable and accurate.
  - However, it is **sluggish** and **less responsive** due to under-tuned P.

![PID Control](./PID.gif)

---

##  PID-Control (Optimized)

- **GIF**: `PID_opt.gif`
- **Description**:  
  After increasing **Kp**, the system becomes:
  - Faster
  - More responsive
  - Still stable

This version is the most optimal in terms of responsiveness and accuracy.

![Optimized PID Control](./PID_opt.gif)

---

##  Summary

| Controller | Stability | Steady-State Error | Responsiveness | Damping |
|------------|-----------|--------------------|----------------|---------|
| **P**      |    ✕      |        ✕          |    Medium      |   ✕     |
| **PD**     |    ✓      |        ✕          |    Medium      |   ✓     |
| **PID**    |    ✓      |        ✓          |     Slow       |   ✓     |
| **PID Opt**|    ✓      |        ✓          |     Fast       |   ✓     |

---

##  Notes

- Plots were captured using **Arduino Serial Plotter**
- Tuning was done **live** using 3 potentiometers for Kp, Ki, and Kd

