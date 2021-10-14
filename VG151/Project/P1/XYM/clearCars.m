function clearCars(data,game)	%Clear cars in the map
	stop(game);
	for i=1:data.carnum
		delete(data.allcarshandler(i));
		delete(data.platehandler(i));
	end
	data.carnum=0;
	data.allcars=[];
	data.carsdist=zeros(4);
	data.speedlist=[];
	data.allcarshandler=[];
	data.platehandler=[];
	data.carsplate=[];
	data.carlength=[];
	start(game);
end