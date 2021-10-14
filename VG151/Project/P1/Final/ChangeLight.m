function [Light,CarOption]=ChangeLight(StreetX,StreetY,Light,CarOption,LightStatus,AimLight)
	% Clearify which color should traffic lights turn to based on LightStatus
	% if traffic lights turn to 'yellow' or 'red', CarOption should be rewritten to let the cars know they should stop
	if (LightStatus==2) tmp=["green","green"]; CarOption(AimLight)=1; end
    if (LightStatus==0) tmp=["yellow","yellow"]; CarOption(AimLight)=0; end
    if (LightStatus==1) tmp=["red","red"]; CarOption(AimLight)=0; end
	% Use tmp to change the color of specific traffic lights
    if (AimLight==1) 
        Light(1)=scatter(StreetX,StreetX,25,'MarkerFaceColor',tmp(1),'MarkerEdgeColor',tmp(1));
        Light(2)=scatter(StreetY,StreetY,25,'MarkerFaceColor',tmp(2),'MarkerEdgeColor',tmp(2));
    end
    if (AimLight==2)
        Light(3)=scatter(StreetX,StreetY,25,'MarkerFaceColor',tmp(1),'MarkerEdgeColor',tmp(1));
        Light(4)=scatter(StreetY,StreetX,25,'MarkerFaceColor',tmp(2),'MarkerEdgeColor',tmp(2));
    end
    hold on;
end
