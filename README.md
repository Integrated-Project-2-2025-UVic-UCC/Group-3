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
