function [IFStop,AnimationLog]=CheckOver(Car,CarCount,IntervalLength,AnimationLog)
	% Check if all cars have moved out of screen
	CarDoneCount=0;
    for i=1:CarCount(5)
        CarPosition=Car(i).Status.Position;
		% Check if this car has moved out of screen
        CarStop=0;
        if (Car(i).Type==1&&CarPosition(1)-IntervalLength>1) CarStop=1; end
        if (Car(i).Type==2&&CarPosition(1)+CarPosition(3)+IntervalLength<0) CarStop=1; end
        if (Car(i).Type==3&&CarPosition(2)-IntervalLength>1) CarStop=1; end
        if (Car(i).Type==4&&CarPosition(2)+CarPosition(4)+IntervalLength<0) CarStop=1; end
        % If this car has moved out of screen, delete its plate, update the status of this car
		if CarStop
            Car(i).Plate.String='';
            Car(i).IsNotDone=0;
        end
        CarDoneCount=CarDoneCount+Car(i).IsNotDone;
    end
    if CarDoneCount==0
        IFStop=1;
    else IFStop=0; end
	% If all cars have moved out of screen, output this message on the screen through AnimationLog
    if IFStop
        AnimationLog=ChangeAnimationLog(AnimationLog,"All Cars are over!!");
    end
end
