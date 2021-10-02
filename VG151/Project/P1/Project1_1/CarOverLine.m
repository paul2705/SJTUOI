function Car=CarOverLine(Car,StreetX,StreetY,IntervalLength,CarNum,CarPosition)
	% Use tmp to replace CarPosition to make the expressions simplier
	tmp=CarPosition;
	% Check if this car shouldn't stop even when traffic light is red
    if (Car(CarNum).Type==1 && tmp(1)>=StreetX-IntervalLength) Car(CarNum).IsOver=1; end
    if (Car(CarNum).Type==2 && tmp(1)+tmp(3)<=StreetY+IntervalLength) Car(CarNum).IsOver=1; end
    if (Car(CarNum).Type==3 && tmp(2)>=StreetX-IntervalLength) Car(CarNum).IsOver=1; end
    if (Car(CarNum).Type==4 && tmp(2)+tmp(4)<=StreetY+IntervalLength) Car(CarNum).IsOver=1; end
end
