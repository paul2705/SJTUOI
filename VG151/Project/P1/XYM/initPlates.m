function initPlates(data)	%Initialize plates
	for i=1:data.carnum
		if data.allcars(i,3)==0
			%up or down
			pos=get(data.allcarshandler(i),'Position');
			data.platehandler=[data.platehandler,text(pos(1)+data.cary/2,pos(2)+data.cary/2,data.carsplate(i),'FontSize',data.streetwidth/2,'Rotation',90)];
		else
			%left or right
			pos=get(data.allcarshandler(i),'Position');
			data.platehandler=[data.platehandler,text(pos(1)+data.cary/2,pos(2)+data.cary/2,data.carsplate(i),'FontSize',data.streetwidth/2)];
		end
	end
end