function [StreetX,StreetY,CarLimit,CarLine,PeriodChangeLight,IntervalLength,CarPossibilityOmitLight]=UserChoice(UIStreetWidth,UICarNumber,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight,UIIntervalLength,UICarPossibilityOmitLight)
    % Get user's choices
	CarLine=[1000 1000 1000 1000];
	% Get the possibility of omitting light
    CarPossibilityOmitLight=str2double(get(UICarPossibilityOmitLight,'string'));
	% Get the length of interval
    IntervalLength=str2double(get(UIIntervalLength,'string'));
	% Get the period of remaining traffic light
    PeriodChangeLight=[str2double(get(UIPeriodChangeGreenLight,'string')),str2double(get(UIPeriodChangeYellowLight,'string')),...
                    str2double(get(UIPeriodChangeRedLight,'string'))];
	% Get the cup of cars
    Lim=str2double(get(UICarNumber,'string'));
    for i=1:10
        CarLimit=rand(1,4);
        AlterRatio=1/sum(CarLimit);
        CarLimit=floor(CarLimit*AlterRatio*Lim);
        if (sum(CarLimit)==Lim) 
            break;
        end
    end
	% Get the width of street
    StreetDelta=str2double(get(UIStreetWidth,'string'));
    StreetX=0.5-StreetDelta;
    StreetY=0.5+StreetDelta;
end
