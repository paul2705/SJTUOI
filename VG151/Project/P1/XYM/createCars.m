function createCars(data)   %create cars once
	for i=1:data.carnum
		if data.allcars(i,3)==0 %up and down
			if data.allcars(i,4)==1
				data.allcarshandler(i)=rectangle('Position',[data.allcars(i,1) data.allcars(i,2) data.cary data.carlength(i)],'facecolor',[rand/2+0.5,rand/2+0.5,rand/2+0.5]);
			else
				data.allcarshandler(i)=rectangle('Position',[data.allcars(i,1) data.allcars(i,2) data.cary data.carlength(i)],'facecolor',[rand/2+0.5,rand/2+0.5,rand/2+0.5]);
			end
		elseif data.allcars(i,4)==0 %left and right
			if data.allcars(i,3)==1
				data.allcarshandler(i)=rectangle('Position',[data.allcars(i,1) data.allcars(i,2) data.carlength(i) data.cary],'facecolor',[rand/2+0.5,rand/2+0.5,rand/2+0.5]);
			else
				data.allcarshandler(i)=rectangle('Position',[data.allcars(i,1) data.allcars(i,2) data.carlength(i) data.cary],'facecolor',[rand/2+0.5,rand/2+0.5,rand/2+0.5]);
			end
		end
	end
end