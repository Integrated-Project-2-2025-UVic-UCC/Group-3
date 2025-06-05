# Autonomous Seeding Quadcopter

This repository contains all the information related to the development of an **autonomous seeding quadcopter**. It also includes everything needed to fully replicate the project.

![image](https://github.com/user-attachments/assets/2cb52437-71e7-4eb6-a9f1-e601019e3aa6)

## 🌱 Motivation

Modern agriculture faces significant challenges, including rising food demand, labor shortages, and the need to improve resource efficiency. Traditional planting methods—whether manual or reliant on heavy machinery—can be costly and inefficient. Labor and initial machinery investments can be very expensive compared to an autonomous drone, which is smaller, cheaper to purchase, and doesn’t require a human operator.

In recent years, automation and technology have started transforming the agricultural sector. Drones have proven useful for crop monitoring, spraying, and data collection. However, **automated drone-based seeding** is still in its early stages of development, presenting a unique opportunity to enhance precision agriculture and improve overall efficiency. This early-stage potential is what inspired us to pursue this project.

## 💪 How to Build

To fully replicate the project, follow these steps:

### 1️⃣ 3D Printing

First, 3D print all the components found in the _SolidWorks parts_ folder. Note that this process may take time, as there are several parts to produce.

### 2️⃣ PCB Building

Once all parts are printed, build the PCB according to the provided electrical schematic. Connect and solder all components, including ESC drivers. It's essential that the MPU6050 module is perfectly centered on the PCB frame.

### 3️⃣ Assembling the Drone

With all parts ready:

**1.** Attach the PCB to the _Bottom body_ (make sure all components are connected before assembly).

**2.** Assemble from bottom to top:

  - Attach the 4 _Leg_ to the _Bottom body_.
  - Attach the 4 _Arm_.
  - Close the structure with the _Upper body_.

At this point, the main structure is complete.

Then:

- Mount the brushless motors to each arm.
- Attach the _Upper battery support_ on top of the frame.

**Hopper Assembly**

1. Attach the servomotor to the _rotative valve cover_, and connect the _rotative valve_ to the servomotor.

2. Insert 4 inserts into the _hopper_.

3. Assemble the full hopper.

4. Attach it to the drone by inserting the two _hinge joints_ into their respective slots.

5. Secure the hopper using a through bolt.

6. Mount the distance sensor onto its support and glue it to the hopper wall.

### 4️⃣ Code Uploading

Once assembly is complete:

- Download the General_BT_Testing folder.
- Upload the program to your ESP32 microcontroller.

### ✅ Completion

If you've followed all the steps — congratulations! 🎉
Your **Autonomous Seeding Quadcopter** is now fully built and ready for testing using a **BLE-compatible device**.

Project by: _**Pau Porcuna, Guillem Català, Albert Huéscar & Álvaro Hernández**_
