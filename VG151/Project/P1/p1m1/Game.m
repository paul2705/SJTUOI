function Game(UIStreetWidth,UICarNumber,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight,UIIntervalLength,UICarPossibilityOmitLight,AnimationLog)
    CarCount=[0 0 0 0 0]; Car=[]; %Initalize Cars
	% Get user's input
	[StreetX,StreetY,CarLimit,CarLine,PeriodChangeLight,IntervalLength,CarPossibilityOmitLight]=UserChoice(UIStreetWidth,UICarNumber,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight,UIIntervalLength,UICarPossibilityOmitLight);
    % Initalize the Animation through user's choices
	[v,Light,CarOption,Car,CarCount,AnimationLog]=Initalize(Car,CarCount,StreetX,StreetY,AnimationLog);
    % Create a time counter to manage the traffic light
	LightTimeCounter=[0,0]; LightStatus=[0,2];
    for i=1:10000
		% Flowing the time counter
        LightTimeCounter=LightTimeCounter+1;
		% Change the traffic light
        if (LightTimeCounter(1)==PeriodChangeLight(LightStatus(1)+1))
            [Light,CarOption]=ChangeLight(StreetX,StreetY,Light,CarOption,LightStatus(1),2);
            LightStatus(1)=mod(LightStatus(1)+1,3); LightTimeCounter(1)=0;
        end
        if (LightTimeCounter(2)==PeriodChangeLight(LightStatus(2)+1))
            [Light,CarOption]=ChangeLight(StreetX,StreetY,Light,CarOption,LightStatus(2),1);
            LightStatus(2)=mod(LightStatus(2)+1,3); LightTimeCounter(2)=0;
        end
		% Record
        v=VedioRecord(v);
    end
end
