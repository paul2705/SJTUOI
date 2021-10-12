function [Car,CarCount,AnimationLog]=UpdateCarStatus(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,CarNum,CarOpt,SwitchCarSize,UIAddCarManually,AnimationLog)
	% If Car should move, update the status of the car
	% update position
	Car(CarNum).Status=MoveThisCar(Car(CarNum).IsNotDone,Car(CarNum).Status,Car(CarNum).MoveVector);
    % update plate
	Car(CarNum).Plate=MoveItsPlate(Car(CarNum).IsNotDone,Car(CarNum).Plate,Car(CarNum).MoveVector);
    % check if add car behind
	[Car,CarCount,AnimationLog]=MakeCarLine(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,CarNum,Car(CarNum).Status.Position,SwitchCarSize,AnimationLog);
    % update car status with the new position
	Car=CarOverLine(Car,StreetX,StreetY,IntervalLength,CarNum,Car(CarNum).Status.Position);
    if (CarOpt) Car(CarNum).IsOver=1; Car(CarNum).BreakLaw=1; end
    Car=CarOnLine(Car,StreetX,StreetY,IntervalLength,CarNum,Car(CarNum).Status.Position);
end
