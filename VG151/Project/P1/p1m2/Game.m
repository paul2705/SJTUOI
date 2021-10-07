function Game(UIStreetWidth,UICarNumber,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight,UIIntervalLength,UICarPossibilityOmitLight,UIVarifyCarSize,UIAddCarManually,UIAddCarLimitRight,UIAddCarLimitLeft,UIAddCarLimitUp,UIAddCarLimitDown,AnimationLog)
	CarCount=[0 0 0 0 0]; Car=[]; %Initalize Cars
    % Get user's input
	[StreetX,StreetY,CarLimit,CarLine,~,IntervalLength,CarPossibilityOmitLight,SwitchCarSize]=UserChoice(UIStreetWidth,UICarNumber,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight,UIIntervalLength,UICarPossibilityOmitLight,UIVarifyCarSize,UIAddCarManually);
	% Initalize through user's choices
	[v,Light,CarOption,Car,CarCount,AnimationLog]=Initalize(Car,CarCount,StreetX,StreetY,SwitchCarSize,AnimationLog);
    % Create a time counter to control the action of changing traffic light
	LightTimeCounter=[0,0]; LightStatus=[0,2];
	% Taking off
    for i=1:10000
		% Check if add cars manually by pressing button
        [CarLimit,UIAddCarLimitRight,UIAddCarLimitLeft,UIAddCarLimitUp,UIAddCarLimitDown]=CheckIfAddCareManually(CarLimit,UIAddCarLimitRight,UIAddCarLimitLeft,UIAddCarLimitUp,UIAddCarLimitDown);
        % flowing the time counter
		LightTimeCounter=LightTimeCounter+1;
		% Check if user has changed his choice
        [SwitchCarSize,PeriodChangeLight]=ChangeUserChoice(UIVarifyCarSize,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight);
        % Change traffic light
		if (LightTimeCounter(1)==PeriodChangeLight(LightStatus(1)+1))
            [Light,CarOption]=ChangeLight(StreetX,StreetY,Light,CarOption,LightStatus(1),2);
            LightStatus(1)=mod(LightStatus(1)+1,3); LightTimeCounter(1)=0;
        end
        if (LightTimeCounter(2)==PeriodChangeLight(LightStatus(2)+1))
            [Light,CarOption]=ChangeLight(StreetX,StreetY,Light,CarOption,LightStatus(2),1);
            LightStatus(2)=mod(LightStatus(2)+1,3); LightTimeCounter(2)=0;
        end
		% Check if all cars have moved out of screen
        [IFStop,AnimationLog]=CheckOver(Car,CarCount,IntervalLength,AnimationLog);
        if IFStop
            break;
        end
		% After updating data, move cars
        [Car,CarCount,CarLine,AnimationLog]=MoveCar(Car,CarCount,StreetX,StreetY,CarLimit,IntervalLength,CarOption,CarLine,CarPossibilityOmitLight,SwitchCarSize,UIAddCarManually,AnimationLog);
        % record the screen
		pause(0.1);
        v=VedioRecord(v);
		% Check if this movement has caused car crash
        [IFStop,AnimationLog]=CheckCrash(Car,CarCount,AnimationLog);
        if IFStop
            break;
        end
    end
	% After the Animation, output all cars that have broken law
    AnimationLog=IsCarBreakLaw(Car,CarCount,AnimationLog);
end
