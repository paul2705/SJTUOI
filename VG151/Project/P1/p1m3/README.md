## The milestone 3 of Project 1

This is the milestone 3 of project 1. The whole project 1 is to create a whole animation for cars crossing. As for milestone 1, it requires creating crossroad and traffic light. As for milestone 2, it requires creating all car-related functions, including input, direction, drawing, output, plate, etc. As for milestone 3, create the whole animation.



## Build

*   Download the file `p1m3`
*   This project requires MatLab without any extra tool-box



## Getting Started

*   Locate the file `p1m3` at any path
*   Run the `./Main.m` with MatLab

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



## Advanced usage (Bonus)

*   You could repress the「start!」 button to interrupt the playing animation and start a new one
*   You could change *The Period Of Changing Light* options during the animation
*   You could press the「pause」button to stop the animation and press the「restart」button to continue playing the animation
*   You could turn on「Switch For adding Car Manually」to ask computer not to automatically determine the number of cars at each direction.
    *   Then, you could press those four「ADD」buttons to add cars
    *   **Notice: the newly-added cars may not appear immediately because the certain Car Line can't add any more cars, but they would be created and appear afterwards.**
*   You could turn on「Switch For Various Car Sizes」to ask computer for generating car sizes randomly.
*   You could monitor the whole animation by watching the messages on the dashboard at the bottom of the figure
*   You could select the level of the game, i.e. EasyMode, HardMode



## Algorithm

*   The whole Animation

    *   I take each movement of car as **the basic unit of time**. *(Car Speed is fixed)*
        *   Thus, the whole Animation is simply loaded by a big  `for-loop`
        *   Traffic lights shift every $x$ seconds means they will shift every $x$ movements
    *   Generate cars one by one as splited and individual objects, and examine whether the certain car is on line or not, whether the certain car is over line or not, etc.
        *   Meanwhile, all the status of each car is loaded in a structure called `Car`. i.e. `Car Size, Car Move Vector, On Line, Over Line, Stop, Out Of Screen`
        *   This way to construct cars gives me a shortcut in manipulating cars during the Animation

*   Use recursive function to generate Car Plate

    *   Create a pool builded by all valid char with random order

    *   Start a recursion

        *   Check if the recursion have reached a complete plate
        *   Take step by step to determine the exact char that should be put in
        *   Recall the recursion with step++

    *   Code as follow:

        *   ```matlab
            function PlatePool=RecursionForPlate(Step,PlatePool,Plate,Pool,Use)
                if (Step==6)
                    PlatePool=[PlatePool string(char(Plate))];
                    return;
                end
                if (length(PlatePool)>500) return; end
                for i=1:36
                    if (Use(i)) continue; end
                    Use(i)=1;
                    Plate(Step)=char(Pool(i));
                    PlatePool=RecursionForPlate(Step+1,PlatePool,Plate,Pool,Use);
                    Use(i)=0;
                end
            end
            ```



## Function

| Name                                                         | Function                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Car=CarOnLine(Car,StreetX,StreetY,IntervalLength,CarNum,CarPosition) | Check if Car is On Line                                      |
| Car=CarOverLine(Car,StreetX,StreetY,IntervalLength,CarNum,CarPosition) | Check if Car is Over Line                                    |
| AnimationLog=ChangeAnimationLog(AnimationLog,AddLogText)     | Load the Animation Log and Output them                       |
| [Light,CarOption]=ChangeLight(StreetX,StreetY,Light,CarOption,LightStatus,AimLight); | Change the Color of Lights and Update Car Status controlling Stop |
| [SwitchCarSize,PeriodChangeLight]=ChangeUserChoice(UIVarifyCarSize,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight) | Update User Data during the Animation                        |
| [IFStop,AnimationLog]=CheckCrash(Car,CarCount,AnimationLog)  | Check if Cars Crashed                                        |
| [CarLimit,UIAddCarLimitRight,UIAddCarLimitLeft,UIAddCarLimitUp,UIAddCarLimitDown]=CheckIfAddCareManually(CarLimit,UIAddCarLimitRight,UIAddCarLimitLeft,UIAddCarLimitUp,UIAddCarLimitDown) | Check if User have added Cars Manually                       |
| [IFStop,AnimationLog]=CheckOver(Car,CarCount,IntervalLength,AnimationLog) | Check if All Cars are Out Of Screen                          |
| [Car,CarCount,AnimationLog]=ConstructCar(Car,CarCount,StreetX,StreetY,CarNum,CarSize,CarType,CarMoveVector,SwitchCarSize,CarStatus,AnimationLog) | Construct Car structure                                      |
| [CarCount,NewCarStatus]=CreateCar(StreetX,StreetY,CarCount,opt,CarSZ,SwitchCarSize) | Draw a Car and Return a Handle                               |
| [Light,CarOption]=CreateLight(StreetX,StreetY)               | Draw Traffic Lights and Return Handles                       |
| Plate=CreateNewPlate()                                       | Create Car Plate                                             |
| CreateStreet(StreetX,StreetY)                                | Draw Cross Roads                                             |
| Game(UIStreetWidth,UICarNumber,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight,UIIntervalLength,UICarPossibilityOmitLight,UIVarifyCarSize,UIAddCarManually,UIAddCarLimitRight,UIAddCarLimitLeft,UIAddCarLimitUp,UIAddCarLimitDown,AnimationLog) | Manage Animation and Intake UIbutton Handles                 |
| [v,Light,CarOption,Car,CarCount,AnimationLog]=Initalize(Car,CarCount,StreetX,StreetY,SwitchCarSize,AnimationLog) | Initialize the whole figure                                  |
| AnimationLog=IsCarBreakLaw(Car,CarCount,AnimationLog)        | Check if Car is Broken Law                                   |
| [Car,CarCount,AnimationLog]=MakeCarLine(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,CarNum,CarPosition,SwitchCarSize,AnimationLog) | Create Car Line by adding continuously                       |
| v=MakeVideo() & v=VedioRecord(v)                             | Record the Animation by a file `project1.avi`                |
| [Car,CarCount,CarLine,AnimationLog]=MoveCar(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,CarOption,CarLine,CarPossibilityOmitLight,SwitchCarSize,UIAddCarManually,AnimationLog) | Manage the Movement of Cars                                  |
| CarNewPlate=MoveItsPlate(CarIsNotDone,ThisCarPlate,MovePosition) | Manage the Movement of Plates following the Cars             |
| CarNewStatus=MoveThisCar(CarIsNotDone,ThisCarStatus,MovePosition) | Manage the Movement of a certain Car                         |
| [NewPlate,PlateStatus]=NewCarPlate(CarType,CarPosition,Plate) | Draw Car Plates                                              |
| [Car,CarCount,AnimationLog]=UpdateCarStatus(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,CarNum,CarOpt,SwitchCarSize,UIAddCarManually,AnimationLog) | Update Car Status                                            |
| [StreetX,StreetY,CarLimit,CarLine,PeriodChangeLight,IntervalLength,CarPossibilityOmitLight,SwitchCarSize]=UserChoice(UIStreetWidth,UICarNumber,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight,UIIntervalLength,UICarPossibilityOmitLight,UIVarifyCarSize,UIAddCarManually) | Input User Choice at the beginning of the Animation          |
| Main.m                                                       | Create UI                                                    |



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
*   Version3.0
    *   Add Mode(Level)

**Notice: You can find a more detailed Changelog.md**

