# Our Robot

At the heart of our robot's identity is its remarkable and unique design. Featuring a prominent frame, this defining aspect not only offers a distinctive visual appeal but also plays a crucial role in maintaining structural integrity. Integrated with this primary element are meticulously crafted modular components, achieving a seamless blend of form and function. These components serve as essential building blocks, contributing both aesthetic and structural value to the robot. Additionally, we have incorporated 3D-printed models, strategically placed to provide extra support and strength, thereby enhancing the overall stability and durability of the robot's framework. This thoughtful combination of modular elements and 3D-printed models reflects our team's dedication to creating a well-balanced and visually stunning robotic platform.

# Drivetrain

The drivetrain is a crucial element that greatly impacts the robot's overall performance. It operates with two specialized motors, each assigned a specific function. One motor is dedicated to propelling the robot forward, while the other handles steering. The driving motor, a DS3230 PRO servo, delivers an impressive 600 revolutions per minute (RPM). This motor strikes an ideal balance between speed and torque, essential for the robot's efficiency. By selecting the DS3230 PRO, the team ensures optimal performance in a variety of conditions and challenges faced during competitions. Additionally, the robot is equipped with an ultrasonic sensor and a TCS230 color sensor, enhancing its environmental awareness and adaptability. The integration of an Arduino Mega, PixyCam2, and L298N motor driver further underscores the team's commitment to achieving high performance and versatility.
Sensors and Perception:

# Ultrasonic Sensors

The incorporation of three strategically positioned ultrasonic sensors is a pivotal aspect of our robot's design, playing a crucial role in executing our competition strategy with precision and efficiency. The foremost sensor, strategically placed at the front, serves a dual purpose. Firstly, it significantly contributes to the robot's ability to execute precise turns, a critical skill in navigating the competition's obstacle course. Secondly, it aids in real-time obstacle avoidance, allowing the robot to make split-second adjustments to its trajectory, ensuring it safely navigates around potential obstructions.

In tandem with the front sensor, the left and right sensors assume distinct responsibilities. Their placement is calibrated to detect inner and outer walls, an invaluable feature when navigating confined spaces. This capability equips the robot with a heightened sense of spatial awareness, enabling it to navigate tight corners and narrow passageways with finesse. By intelligently leveraging this sensor arrangement, our plan is to equip the SpikeBot with an enhanced level of accuracy and adaptability, setting it apart as a formidable contender in the WRO Future Engineers competition.

# Pixy 2 Camera

The Pixy 2 camera is a sophisticated smart vision system that seamlessly integrates into our robot. Its plug-and-play nature means it can be easily incorporated into our existing setup without the need for extensive configuration. This powerful component plays a crucial role in our robot's ability to perceive and interact with its environment.

One of the key functionalities of the Pixy 2 camera is its capacity to discern between different obstacle colors. Specifically, it is adept at distinguishing between green, which corresponds to the left side, and red, indicative of the right side. This capability is invaluable as it provides our robot with a clear and reliable method for identifying and classifying obstacles in its path.


By recognizing and categorizing obstacles based on their color, the Pixy 2 camera significantly enhances our robot's decision-making process during navigation. This enables the robot to make informed choices about its path, allowing it to efficiently maneuver around obstacles and reach its destination.


Furthermore, the Pixy 2 camera employs SPI (Serial Peripheral Interface) for communication. This high-speed, synchronous serial communication protocol ensures efficient and reliable data exchange between the camera and the other components of our robot. This means that the Pixy 2 camera can seamlessly transmit information to our robot's processing unit, enabling timely and accurate responses to its environment.


In essence, the Pixy 2 camera serves as a crucial sensory tool for our robot, providing it with the ability to visually identify and differentiate obstacles based on their colors. This capability significantly enhances our robot's decision-making process, allowing it to navigate complex environments with precision and efficiency. Moreover, its seamless integration through SPI communication ensures smooth operation within our existing system. The Pixy 2 camera stands as a testament to the advanced technology employed in our robot, contributing significantly to its performance in the WRO Future Engineers competition.

# Compass Sensor

The HMC5883L is a popular 3-axis digital compass sensor that is used to detect magnetic fields and determine orientation relative to Earth's magnetic field. It's widely used in robotics, navigation systems, drones, and other applications requiring precise heading or directional information.

Applications:
1.   Navigation: It’s often used in GPS and other navigation systems to provide accurate heading information.
   
2.   Drones and Robotics: The sensor helps maintain direction and orientation.

3.   Augmented Reality: In AR applications, it can help align virtual objects with real-world directions.


# Code Overview

The robot's functionality is driven by a carefully crafted code that orchestrates its movements. Our algorithm focuses on moving the bot in a straight line, using the ultrasonic sensors to maintain and correct its position in the straight segments, and turning when the distance from an obstacle, detected by an ultrasonic sensor, is less than a certain threshold.

# Library Inclusions

The code includThe code utilizes key libraries including Pixy2.h, Wire.h, Adafruit_TCS34725.h, and Adafruit_HMC5883_U.h to interface with sensors and control motors. These libraries enable the robot to gather color data from the TCS34725 color sensor and direction data from the HMC5883L magnetometer. The Pixy 2 camera is used for visual detection, which plays a critical role in navigating the robot. The Wire library manages I2C communication between components, ensuring smooth data transmission. The motors are controlled via specific pins, allowing the robot to perform precise movements such as driving forward or turning based on real-time sensor readings, including color detection and heading adjustments.es essential libraries such as Pixy2.h, Wire.h, L298N.h, and Servo.h for interfacing with sensors and motor control. These libraries are used to extract visual data from the Pixy 2 camera, which is crucial for the robot to navigate accurately. We also use the Wire library for I2C communication, the L298N library for motor driver control, and the Servo library to communicate with our servo motors, allowing us to execute precise movements and turns based on the calculations in the code.

# Pin Configuration

The code configures pin modes for the color sensor, compass, motors, and Pixy 2 camera, ensuring smooth communication between all components. Nearly all pins on the Arduino are utilized, optimizing the board's capacity. Pin assignments were chosen strategically to minimize wiring complexity and reduce the need for extensive soldering. Components like the Pixy 2 camera are directly connected to specific pins via a dedicated cable (pins 11, 12, and 13), requiring specialized connections. This setup ensures efficient signal transmission and reliable operation of the robot's navigation and sensor systems..


Our robot exemplifies meticulous engineering and thoughtful component selection, with a distinctive frame design and a differential drive system providing a robust foundation for agile maneuvers. The integration of a TCS34725 color sensor, HMC5883L compass, ultrasonic sensors, and a Pixy 2 camera significantly enhances its perception capabilities. These components work together seamlessly, enabling precise navigation and obstacle detection, making the robot a strong contender in the WRO Future Engineers competition.
