function Car=CarOnLine(Car,StreetX,StreetY,IntervalLength,CarNum,CarPosition)
    % Use tmp to replace CarPosition to make expressions simplier
	tmp=CarPosition;
	% Check if this car should stop when traffic light is red
    if (Car(CarNum).Type==1 && (tmp(1)+tmp(3)<=StreetX-IntervalLength&&tmp(1)+tmp(3)+IntervalLength>StreetX-IntervalLength)) Car(CarNum).IsOn=1; end
    if (Car(CarNum).Type==2 && (tmp(1)>=StreetY+IntervalLength&&tmp(1)-IntervalLength<StreetY+IntervalLength)) Car(CarNum).IsOn=1; end
    if (Car(CarNum).Type==3 && (tmp(2)+tmp(4)<=StreetX-IntervalLength&&tmp(2)+tmp(4)+IntervalLength>StreetX-0.01)) Car(CarNum).IsOn=1; end
    if (Car(CarNum).Type==4 && (tmp(2)>=StreetY+IntervalLength&&tmp(2)-IntervalLength<StreetY+IntervalLength)) Car(CarNum).IsOn=1; end
end
