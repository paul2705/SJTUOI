function initCarsPosition(data)	%initialize position of all cars
	difficulty=data.difficulty;
	data.carlength=ones(1,data.carnum)*data.carx;
	data.carlength=data.carlength+rand(1,data.carnum)*difficulty;
	for it=1:data.carsdist(1)
		data.allcars=[data.allcars;data.len+sum(data.carlength(1:it-1))+data.carmargin*it data.streetwidth/4-data.cary/2-data.cans -1 0];
	end
	for it=1:data.carsdist(2)
		data.allcars=[data.allcars;-data.len-sum(data.carlength(data.carsdist(1)+1:data.carsdist(1)+it))-data.carmargin*it -data.streetwidth/4-data.cary/2+data.cans 1 0];
	end
	for it=1:data.carsdist(3)
		data.allcars=[data.allcars;data.streetwidth/4-data.cary/2-data.cans -data.len-sum(data.carlength(data.carsdist(1)+data.carsdist(2)+1:data.carsdist(1)+data.carsdist(2)+it))-data.carmargin*it 0 1];
	end
	for it=1:data.carsdist(4)
		data.allcars=[data.allcars;-data.streetwidth/4-data.cary/2+data.cans data.len+sum(data.carlength(data.carsdist(1)+data.carsdist(2)+data.carsdist(3)+1:data.carsdist(1)+data.carsdist(2)+data.carsdist(3)+it-1))+data.carmargin*it 0 -1];
	end
end