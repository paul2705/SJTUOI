function [Car,CarCount,AnimationLog]=ConstructCar(Car,CarCount,StreetX,StreetY,CarNum,CarSize,CarType,CarMoveVector,SwitchCarSize,CarStatus,AnimationLog)
	% initialize the status of a car with input
    Car(CarNum).Size=CarSize;
    Car(CarNum).Type=CarType;
    Car(CarNum).MoveVector=CarMoveVector;
    [CarCount,Car(CarNum).Status]=CarStatus(StreetX,StreetY,CarCount,CarType,CarSize,SwitchCarSize);
    [Car(CarNum).PlateName,Car(CarNum).Plate]=NewCarPlate(CarType,Car(CarNum).Status.Position,@CreateNewPlate);
    Car(CarNum).IsOver=0;
    Car(CarNum).IsOn=0;
    Car(CarNum).IsLast=1;
    Car(CarNum).IsNotDone=1;
    Car(CarNum).BreakLaw=0;
	% Output message on the screen through AnimationLog
    switch CarType
        case 1, CarToward="Towards Right";
        case 2, CarToward="Towards Left";
        case 3, CarToward="Towards Up";
        case 4, CarToward="Towards Down";
    end
    AnimationLog=ChangeAnimationLog(AnimationLog,strcat("Create A New Car. CarType: ",CarToward,"; CarSize: ",num2str(CarSize(1)),"*",num2str(CarSize(2)),"; CarPlate: ",Car(CarNum).PlateName));
end
