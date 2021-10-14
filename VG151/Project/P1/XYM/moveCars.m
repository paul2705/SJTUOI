function moveCars(data)     %move cars
	%special case
	specialset=[1,data.carsdist(1)+1,data.carsdist(1)+data.carsdist(2)+1,data.carsdist(1)+data.carsdist(2)+data.carsdist(3)+1];
	specialset=unique(specialset);
	for i=1:length(specialset)
		curposition=get(data.allcarshandler(specialset(i)),'Position');
		set(data.allcarshandler(specialset(i)),'Position',curposition+[data.allcars(specialset(i),3)*data.velocity data.allcars(specialset(i),4)*data.velocity 0 0]);
	end
	allset=1:data.carnum;
	remainset=setdiff(allset,specialset);
	for i=1:length(remainset)
		curposition=get(data.allcarshandler(remainset(i)),'Position');
		previousposition=get(data.allcarshandler(remainset(i)-1),'Position');
        diff=curposition-previousposition;
		if (1<=remainset(i) && remainset(i)<=data.carsdist(1)) || data.carsdist(1)+data.carsdist(2)+data.carsdist(3)+1<=remainset(i)
			%right and top cars
			if abs(diff(1))+abs(diff(2))>=data.carlength(remainset(i)-1)+data.carmargin || abs(data.allcars(remainset(i),3))>1 || abs(data.allcars(remainset(i),4))>1
				%move this car
				set(data.allcarshandler(remainset(i)),'Position',curposition+[data.allcars(remainset(i),3)*data.velocity data.allcars(remainset(i),4)*data.velocity 0 0]);
			end
		else
			%left and bottom
			if abs(diff(1))+abs(diff(2))>=data.carlength(remainset(i))+data.carmargin || abs(data.allcars(remainset(i),3))>1 || abs(data.allcars(remainset(i),4))>1
				%move this car
				set(data.allcarshandler(remainset(i)),'Position',curposition+[data.allcars(remainset(i),3)*data.velocity data.allcars(remainset(i),4)*data.velocity 0 0]);
			end
		end
	end
end