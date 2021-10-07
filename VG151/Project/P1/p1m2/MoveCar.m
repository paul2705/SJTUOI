function [Car,CarCount,CarLine,AnimationLog]=MoveCar(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,CarOption,CarLine,CarPossibilityOmitLight,SwitchCarSize,UIAddCarManually,AnimationLog)
	% Move all Cars
	for i=1:CarCount(5)
		% Determine if Car is breaking law
        CarPossibility=rand();
		% Cars behind should stop if the previous car stops
        if (i>CarLine(Car(i).Type)) continue; end
		% Check if this car should move
        if ((Car(i).Type==1 || Car(i).Type==2))
            if ((CarOption(1) || (CarOption(1)==0&&Car(i).IsOn==0) || Car(i).IsOver))
                if (Car(i).IsOn==1) Car(i).IsOn=0; end
                CarLine(Car(i).Type)=1000;
                [Car,CarCount,AnimationLog]=UpdateCarStatus(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,i,0,SwitchCarSize,UIAddCarManually,AnimationLog);
            else if (CarPossibility<=CarPossibilityOmitLight) 
                    [Car,CarCount,AnimationLog]=UpdateCarStatus(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,i,1,SwitchCarSize,UIAddCarManually,AnimationLog);
                    AnimationLog=ChangeAnimationLog(AnimationLog,strcat(Car(i).PlateName," is breaking the traffic rule!"));
                else CarLine(Car(i).Type)=i; end
            end
        elseif ((Car(i).Type==3 || Car(i).Type==4))
            if ((CarOption(2) || (CarOption(2)==0&&Car(i).IsOn==0) || Car(i).IsOver))
                if (Car(i).IsOn==1) Car(i).IsOn=0; end
                CarLine(Car(i).Type)=1000;
                [Car,CarCount,AnimationLog]=UpdateCarStatus(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,i,0,SwitchCarSize,UIAddCarManually,AnimationLog);
            else if (CarPossibility<=CarPossibilityOmitLight) 
                    [Car,CarCount,AnimationLog]=UpdateCarStatus(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,i,1,SwitchCarSize,UIAddCarManually,AnimationLog);
                    AnimationLog=ChangeAnimationLog(AnimationLog,strcat(Car(i).PlateName," is breaking the traffic rule!"));
                else CarLine(Car(i).Type)=i; end
            end
        else
            CarLine(Car(i).Type)=i;   
        end
    end
end
