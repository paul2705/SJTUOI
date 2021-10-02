function [StreetX,StreetY,CarLimit,CarLine,PeriodChangeLight,IntervalLength,CarPossibilityOmitLight,SwitchCarSize]=UserChoice(UIStreetWidth,UICarNumber,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight,UIIntervalLength,UICarPossibilityOmitLight,UIVarifyCarSize,UIAddCarManually)
	% Get user's input
	CarLine=[1000 1000 1000 1000];
	% Get the possibility of omitting light and manipulate this possibility
    CarPossibilityOmitLight=str2double(get(UICarPossibilityOmitLight,'string'));
    if (CarPossibilityOmitLight<0.1) CarPossibilityOmitLight=CarPossibilityOmitLight/1000;
    else if (CarPossibilityOmitLight<0.2) CarPossibilityOmitLight=CarPossibilityOmitLight/500;
        else if (CarPossibilityOmitLight<0.3) CarPossibilityOmitLight=CarPossibilityOmitLight/200;
            else if (CarPossibilityOmitLight<0.4) CarPossibilityOmitLight=CarPossibilityOmitLight/50;
                else if (CarPossibilityOmitLight<0.5) CarPossibilityOmitLight=CarPossibilityOmitLight/10;
                    end
                end
            end
        end
    end
	% Get the length of Interval
    IntervalLength=str2double(get(UIIntervalLength,'string'));
	% Get the Period of remaining the Light
    PeriodChangeLight=[str2double(get(UIPeriodChangeGreenLight,'string')),str2double(get(UIPeriodChangeYellowLight,'string')),...
                    str2double(get(UIPeriodChangeRedLight,'string'))];
	% Get the Cup of the number of cars
    Lim=str2double(get(UICarNumber,'string'));
	% Get the option for varifing car size
    if (get(UIVarifyCarSize,'value')==get(UIVarifyCarSize,'max')) SwitchCarSize=1;
    else SwitchCarSize=0; end
    for i=1:10
        CarLimit=rand(1,4);
        AlterRatio=1/sum(CarLimit);
        CarLimit=floor(CarLimit*AlterRatio*Lim);
        if (sum(CarLimit)==Lim) 
            break;
        end
    end
    if (get(UIAddCarManually,"value")==get(UIAddCarManually,"max"))  CarLimit=[1 1 1 1]; end
    % Get the width of street
	StreetDelta=str2double(get(UIStreetWidth,'string'));
    StreetX=0.5-StreetDelta;
    StreetY=0.5+StreetDelta;
end
