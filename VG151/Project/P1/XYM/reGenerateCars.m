function reGenerateCars(data,num,game) %create cars 2
	stop(game);
	data.carnum=num;
	initDist(data);
	initCarsPosition(data);
	createCars(data);       %create cars
	generatePlates(data);    %generate plates number
	initPlates(data);       %init plateshandler
	start(game);
end