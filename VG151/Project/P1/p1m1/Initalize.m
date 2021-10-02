function [v,Light,CarOption,Car,CarCount,AnimationLog]=Initalize(Car,CarCount,StreetX,StreetY,AnimationLog)
	% Record
	v=MakeVideo();
	% Create Streets
    CreateStreet(StreetX,StreetY);
	% Create Lights
    [Light,CarOption]=CreateLight(StreetX,StreetY);
end
