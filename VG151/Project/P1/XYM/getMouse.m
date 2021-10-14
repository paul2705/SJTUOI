function getMouse(data)	%Mouse trigger
	if data.ischanging
		return;
	end
	point = get(gca,'CurrentPoint');
	x = point(1,1);
	y = point(1,2);
	for i=1:data.carnum
		ipos=get(data.allcarshandler(i),'Position');
		p1x=ipos(1);
		p1y=ipos(2)+ipos(4);
		p2x=ipos(1)+ipos(3);
		p2y=ipos(2);
		if p1x<x && x<p2x && p1y>y && p2y<y
			%Accelerate!
			for j=1:size(data.speedlist,1)
				if data.speedlist(j,1)==i
					data.speedlist(j,2)=data.speedlist(j,2)+10;
					data.speedlist(j,3)=data.speedlist(j,3)*1.5;
					data.allcars(i,3)=data.allcars(i,3)*1.5;
					data.allcars(i,4)=data.allcars(i,4)*1.5;
					return;
				end
			end
			data.speedlist=[data.speedlist;i,data.intimeela+7,2.5];
			data.allcars(i,3)=data.allcars(i,3)*2.5;
			data.allcars(i,4)=data.allcars(i,4)*2.5;
			return;
		end
	end
end