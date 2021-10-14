function [SwitchCarSize,PeriodChangeLight]=ChangeUserChoice(UIVarifyCarSize,UIPeriodChangeRedLight,UIPeriodChangeGreenLight,UIPeriodChangeYellowLight)
	% Check if user has changed Advanced Options 
	% Update whether cars should be generated with various sizes
	if (get(UIVarifyCarSize,'value')==get(UIVarifyCarSize,'max')) SwitchCarSize=1;
    else SwitchCarSize=0; end
	% Update the periods lights should remain 
    PeriodChangeLight=[str2double(get(UIPeriodChangeGreenLight,'string')),str2double(get(UIPeriodChangeYellowLight,'string')),...
                    str2double(get(UIPeriodChangeRedLight,'string'))];
end
