function [CarCount,NewCarStatus]=CreateCar(StreetX,StreetY,CarCount,opt,CarSZ,SwitchCarSize)
    PositionDelta=0.01;
    CarCount(opt)=CarCount(opt)+1;
    CarCount(5)=CarCount(5)+1;
    switch opt
        case 1, Posx=0; Posy=StreetY-CarSZ(2)-PositionDelta; SetColor=[1 0 0]; %Towards Right
        case 2, Posx=1; Posy=StreetX+PositionDelta; SetColor=[0 1 0]; %Towards Left
        case 3, Posx=StreetX+PositionDelta; Posy=0; SetColor=[1 0 1]; %Towards Up
        case 4, Posx=StreetY-CarSZ(1)-PositionDelta; Posy=1; SetColor=[0 1 1]; %Towards Down
    end
    NewCarStatus=rectangle('Position',[Posx Posy CarSZ(1) CarSZ(2)],...
					'EdgeColor',SetColor,...
					'LineWidth',0.5);
end