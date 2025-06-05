# Autonomous Seeding Quadcopter
This repository contains all the information of the developement of an autonomous seeding quadcopter. Also it contains all things needed to fully replicate the project

![image](https://github.com/user-attachments/assets/2cb52437-71e7-4eb6-a9f1-e601019e3aa6)


Modern agriculture faces significant challenges, including the increasing demand for food, labor shortages, and the need to improve resource efficiency. Traditional planting methods, whether manual or using heavy machinery, can be costly and inefficient. Both labor and first investment machinery  can be really expensive in comparison to an autonomous drone, which is smaller, cheaper to buy and doesn’t need an operator.

In recent years, automation and technology have begun transforming the agricultural sector. Drones have proven useful for crop monitoring, spraying, and data collection. However, automated drone-based seeding is still in its early stages of development, presenting an opportunity to enhance precision agriculture and improve farming efficiency. This early developing phase is the reason that made us invest in this project.

## To fully replicate the project, you have to follow the next steps:

### 1st. 3D Printing

Firstly, you have to 3D print all the parts that are uploaded in the _SolidWorks_ parts folder. THis will take time as there are severous parts

### 2nd. PCB Building

Once printed all parts, the next step is to build a PCB that follows the electrical scheme and connect all the components mentioned and soldering all the rest of components as ESC drivers. Its mandatory that the position of the MPU6050 module is completely centered in the PCB frame.

### 3rd. Assembling

Once all the components and parts are done, you have to assemble all the parts as shown in the _Drone final.html_ file.

First, you will start attaching the PCB to the _Bottom body_ (always remember to have all the components connected before assembling the drone), then the next step is to mount from lower to higher 4 _Leg_ with the _Bottom body_ with 4 _Arm_ and closing with the _Upper body_. Once you have this, you will have mounted the main structure of the drone. 

Later on, you have to attach all the brushless motors on each arm and attach the _Upper battery support_ in the upper part of the frame.

Finally, to complete the mounting you have to assemble the hopper. For this, you will have to attach servomotor to the _Rotative valve cover_ and the _Rotative valve_ to the servomotor. Then put 4 inserts in the _Hopper_. Once this is done you can assebmle the full hopper. To attach it to the rest of the drone you have to stick the two _hinge joint_ in their respective insertions. At this point you only have to attach it with a through bolt and the hopper is mounted. To conclude, you have to mount the distance sensor on the _Distance sensor support_ and stick it with glue to the wall of the hopper.

### 4th. Code uploading

Once the drone is fully mounted, you have to download the _General_BT_Testing_ folder and upload the program to your ESP32 microcontroller.

If you arrived here, congratulations, your new Autonomous Seeding Quadcopter is fully built and ready to start testing with a BLE compatible device.
_**Pau Porcuna, Guillem Català, Albert Huéscar & Álvaro Hernández**_

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
