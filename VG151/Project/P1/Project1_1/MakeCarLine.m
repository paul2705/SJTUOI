function [Car,CarCount,AnimationLog]=MakeCarLine(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,CarNum,CarPosition,SwitchCarSize,AnimationLog)
	% Create Car Line by adding more cars
	tmp=CarPosition;
    if (Car(CarNum).Type<=2) CarSize=[0.1,0.05];
    else CarSize=[0.05,0.1];
    end
	% Varify Car Size based on Switch
    if (SwitchCarSize)
        switch Car(CarNum).Type
            case 1
                CarSize=[rand()*(tmp(1)-IntervalLength),rand()*((StreetY-StreetX)/2-IntervalLength)];
            case 2
                CarSize=[rand()*0.5,rand()*((StreetY-StreetX)/2-IntervalLength)];
            case 3
                CarSize=[rand()*((StreetY-StreetX)/2-IntervalLength),rand()*(tmp(2)-IntervalLength)];
            case 4
                CarSize=[rand()*((StreetY-StreetX)/2-IntervalLength),rand()*0.5];
        end
    end
    if (CarSize(1)<0.05||CarSize(2)<0.05) return; end
    CarSize(1)=min(CarSize(1),0.2); CarSize(2)=min(CarSize(2),0.2);
	% Create this car without crashing the previous car
    if (Car(CarNum).Type==1 && Car(CarNum).IsLast==1 && tmp(1)>=CarSize(1)+IntervalLength && CarCount(1)<CarLimit(1)) 
        %fprintf("1：%d\n",CarCount(5)+1);
        Car(CarNum).IsLast=0;
        [Car,CarCount,AnimationLog]=ConstructCar(Car,CarCount,StreetX,StreetY,CarCount(5)+1,CarSize,1,[0.01 0 0 0],SwitchCarSize,@CreateCar,AnimationLog);
    end
    if (Car(CarNum).Type==2 && Car(CarNum).IsLast==1 && tmp(1)<=1-Car(CarNum).Size(1)-IntervalLength && CarCount(2)<CarLimit(2)) 
        %fprintf("2：%d\n",CarCount(5)+1);
        Car(CarNum).IsLast=0;
        [Car,CarCount,AnimationLog]=ConstructCar(Car,CarCount,StreetX,StreetY,CarCount(5)+1,CarSize,2,[-0.01 0 0 0],SwitchCarSize,@CreateCar,AnimationLog);
    end
    if (Car(CarNum).Type==3 && Car(CarNum).IsLast==1 && tmp(2)>=CarSize(2)+IntervalLength && CarCount(3)<CarLimit(3)) 
        %fprintf("3：%d\n",CarCount(5)+1);
        Car(CarNum).IsLast=0;
        [Car,CarCount,AnimationLog]=ConstructCar(Car,CarCount,StreetX,StreetY,CarCount(5)+1,CarSize,3,[0 0.01 0 0],SwitchCarSize,@CreateCar,AnimationLog);
    end
    if (Car(CarNum).Type==4 && Car(CarNum).IsLast==1 && tmp(2)<=1-Car(CarNum).Size(2)-IntervalLength && CarCount(4)<CarLimit(4)) 
        %fprintf("4：%d\n",CarCount(5)+1);
        Car(CarNum).IsLast=0;
        [Car,CarCount,AnimationLog]=ConstructCar(Car,CarCount,StreetX,StreetY,CarCount(5)+1,CarSize,4,[0 -0.01 0 0],SwitchCarSize,@CreateCar,AnimationLog);
    end
end

