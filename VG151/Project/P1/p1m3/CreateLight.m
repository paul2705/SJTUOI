function [Light,CarOption]=CreateLight(StreetX,StreetY)
	% Create Light through coordinate (x,y)
	Light(1)=scatter(StreetX,StreetX,25,'MarkerFaceColor','green','MarkerEdgeColor','green');
    Light(2)=scatter(StreetY,StreetY,25,'MarkerFaceColor','green','MarkerEdgeColor','green');
    % Change the status whether cars should move in front of crossing
	CarOption(1)=0;
    Light(3)=scatter(StreetX,StreetY,25,'MarkerFaceColor','red','MarkerEdgeColor','red');
    Light(4)=scatter(StreetY,StreetX,25,'MarkerFaceColor','red','MarkerEdgeColor','red');
    CarOption(2)=1;
    
    hold on;
end
