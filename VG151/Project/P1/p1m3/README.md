## The milestone 2 of Project 1

This is the milestone 2 of project 1. The whole project 1 is to create a whole animation for cars crossing. As for milestone 1, it requires creating crossroad and traffic light. As for milestone 2, it requires creating all car-related functions, including input, direction, drawing, output, plate, etc.



## Build

*   Download the file `p1m2`
*   This project requires MatLab without any extra tool-box



## Getting Started

*   Locate the file `p1m2` at any path
*   Run the `Main.m` with MatLab

You would see a figure pop out with various options



## User Choices

You could input variables as follows:

*   The Width of Street
*   The Total Number of Cars
*   The Length of Interval between cars
*   The Possibility of Omitting Light
*   The Period Of Changing Light

**Notice: The Period Of Changing Light can be automatically rewritten to fit The Width of Street, whenever you change  The Width of Street**

*The Game System will initialize those variables above for you. If you want to change those variables, do as you like except inputing invalid inputs.*

After that, you could simply press the「start!」button to start the animation



## Advanced usage

*   You could repress the「start!」 button to interrupt the playing animation and start a new one
*   You could change *The Period Of Changing Light* options during the animation
*   You could press the「pause」button to stop the animation and press the「restart」button to continue playing the animation
*   You could turn on「Switch For adding Car Manually」to ask computer not to automatically determine the number of cars at each direction.
    *   Then, you could press those four「ADD」buttons to add cars
*   You could turn on「Switch For Various Car Sizes」to ask computer for generating car sizes randomly.
*   You could monitor the whole animation by watching the messages on the dashboard at the bottom of the figure



## Contributor

*   DuanLingbo, 521370910033, individual



## Bugs section

*   「pause」button has something in trouble
    *   the *callback* for this button is just `waitforbuttonpress();` Therefore, whenever this button loses its focus, the animation will restart to play



## Changelog

*   Version1.0
*   Version2.0
    *   Add「Switch For adding Car Manually」
    *   Add「Switch For Various Car Sizes」
    *   Add the dashboard

