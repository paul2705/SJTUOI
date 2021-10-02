## The milestone 1 of Project 1

This is the milestone 1 of project 1. The whole project 1 is to create a whole animation for cars crossing. As for milestone 1, it requires creating crossroad and traffic light. 



## Build

*   Download the file `p1m1`
*   This project requires MatLab without any extra tool-box



## Getting Started

*   Locate the file `p1m1` at any path
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



## Contributor

*   DuanLingbo, 521370910033, individual



## Bugs section

*   「pause」button has something in trouble
    *   the *callback* for this button is just `waitforbuttonpress();` Therefore, whenever this button loses its focus, the animation will restart to play



## Changelog

*   Version1.0
