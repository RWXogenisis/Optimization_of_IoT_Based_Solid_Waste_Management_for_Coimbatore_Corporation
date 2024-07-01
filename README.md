# Optimization of IoT Based Solid Waste Management for Coimbatore Corporation

Solid waste management is a global issue faced by municipalities worldwide due to the
increasing generation of waste driven by rapid urbanization, population growth, and changing
lifestyles. Coimbatore municipality is no exception and faces numerous challenges in managing its
waste. To address these challenges, the team has developed a project aimed at improving the existing
solid waste management system in Coimbatore by digitizing garbage collection and developing a
monitoring dashboard.
The key component of this project is a smart dustbin prototype equipped with digital sensors
that detect when the bin is full and notify waste management personnel through a digital platform.
The team has used an Arduino Uno microcontroller board to interface with the sensors and enable
wired transfer of data from the sensors to a real-time database.
The smart dustbin prototype's digital sensors provide real-time data to waste management
personnel, enabling them to optimize waste collection routes, reduce collection frequency, and
prevent overflowing bins, ultimately reducing litter and pollution. This report outlines the key
components of the project, including the design and development of the smart dustbin prototype,
the use of digital sensors, and the monitoring dashboard for waste collection.

# Problem Statement
To improve the existing solid waste management system in Coimbatore municipality by
building a prototype of a smart dustbin that uses digital sensors to detect when the bin is full and
notify waste management personnel via a digital platform. The prototype also transmits data to a
real time database for monitoring purposes.

# Module Description
So this is a rough diagram on how we will be implementing the prototype
![Screenshot 2024-07-01 192918](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/5c03b734-c1a1-4ace-9389-9ac5105300ca)

## Hardware Side
The prototype has the following parts:
1. 2 Ultrasonic sensors, one inside the garbage can to detect the level of garbage inside it and notify the personnel accordingly. The second ultrasonic sensor detects if a person is standing in front of the can so that it can open accordingly.
2. There will be a buzzer that will be periodically beeping in case the garbage can has reached its limit and requires the authorities to be emptied.
3. ESP to send the data to the database on the municipal corporation side so that the authorities can respond to the distress calls.
4. The servo motor, to open and close the lid of the garbage can.

### Circuit diagram
![image](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/644072ef-f9f6-496a-9e26-10a78878c46e)

### Block Diagram
![image](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/1a8bdbfd-297a-4635-bd1d-80d187d88dc5)

## Software side
On the software side, the municipal corporation is equipped with a dashboard to access the garbage levels in real time. It is connected to the firebase in the background where the Arduino pushes all the data. The firebase also authenticates the user and determines whethter the user logged in is a driver or supervisor.


# The actual prototype:

## Hardware
![setup](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/f4089a7b-2369-4eb9-82b9-507e39198559)

# Testing
To test the functionality of the smart dustbin prototype, several experiments were conducted.
In each experiment, various amounts of garbage were added to the dustbin to simulate different
levels of waste.

In addition to detecting the height of the garbage inside the dustbin, the smart dustbin
prototype was also tested for its ability to detect the presence of an object near its lid. To simulate
this scenario, an object was placed near the dustbin lid and the ultrasonic distance sensor accurately
detected the distance between the object and the lid.
Based on this data, the Arduino Uno board was able to trigger the servo motor to open the
lid, allowing for easy disposal of waste. Once the object was removed, the sensor detected the
change in distance and the servo motor closed the lid automatically as shown in the following video.


https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/6e62f8b0-160e-4c2a-91c4-d943299528a1

## Software
### Dashboard
![Screenshot 2024-07-01 194101](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/d0d4249a-5051-43d2-84cd-b4d4af5d7260)

This is the login screen where the municipal authorities can login

![Screenshot 2024-07-01 194304](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/d91d8733-fb1e-4896-bd5c-3f782099a2db)

![image](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/6f48478a-ef93-4d94-9d60-6fec7c2724e3)

The supervisor can check the status of his area's dustbins after logging into the portal and notify the drivers to collect the trash accordingly.

![image](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/fe50641b-bb74-46c5-9352-85fe8ba2e8d3)

![Screenshot 2024-07-01 194402](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/9488b06a-c31b-4c08-94db-a370bddf38e1)

Whereas on the driver side:

![image](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/fff5c4f5-87ca-4dd6-b279-f900bd30e68c)
![image](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/845da2a5-0942-4abb-9b74-6aade2cd0ce4)

The link gives the driver the shortest distance to collect all those garbage bins, as it has
been integrated with google maps.

![image](https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/b553d09c-188e-408c-bec6-7364a856a6ac)

When we take a peek at the backend, here is how the firebase is getting updated:

https://github.com/RWXogenisis/Optimization_of_IoT_Based_Solid_Waste_Management_for_Coimbatore_Corporation/assets/65536776/30e60a9b-617e-47a4-823e-d92bc17bc6d2


In the data collected, the "peelemedu_distance" parameter represents the distance between
the lid of the dustbin and the garbage inside it. The "peelamedu" parameter provides the status of
the dustbin as follows:

0 – Empty (if the distance the greater than 9cm)

1 – Partially Full (if the distance is between 4cm and 9cm)

2 - Full (if the distance is lesser than 4cm)


