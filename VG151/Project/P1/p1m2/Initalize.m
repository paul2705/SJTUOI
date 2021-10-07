function [v,Light,CarOption,Car,CarCount,AnimationLog]=Initalize(Car,CarCount,StreetX,StreetY,SwitchCarSize,AnimationLog)
	% initialize screen grasp device
	v=MakeVideo();
	% Create streets
    CreateStreet(StreetX,StreetY);
	% Create Lights
    [Light,CarOption]=CreateLight(StreetX,StreetY);
	% Create the first four cars
    [Car,CarCount,AnimationLog]=ConstructCar(Car,CarCount,StreetX,StreetY,1,[0.1 0.05],1,[0.01 0 0 0],SwitchCarSize,@CreateCar,AnimationLog);
    [Car,CarCount,AnimationLog]=ConstructCar(Car,CarCount,StreetX,StreetY,2,[0.1 0.05],2,[-0.01 0 0 0],SwitchCarSize,@CreateCar,AnimationLog);
    [Car,CarCount,AnimationLog]=ConstructCar(Car,CarCount,StreetX,StreetY,3,[0.05 0.1],3,[0 0.01 0 0],SwitchCarSize,@CreateCar,AnimationLog);
    [Car,CarCount,AnimationLog]=ConstructCar(Car,CarCount,StreetX,StreetY,4,[0.05 0.1],4,[0 -0.01 0 0],SwitchCarSize,@CreateCar,AnimationLog);
end
