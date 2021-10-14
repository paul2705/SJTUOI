function detectLight(data)  %test if it's time to change light(and let stopped cars move)
	hstatus=mod(floor(data.intimeela),data.gtime+data.otime+data.rtime);
	%73lights
	if hstatus==0 && data.status73==2
		%change red to green
		data.status73=0;
		set(data.light37,'edgecolor','green','facecolor','green');
		set(data.light73,'edgecolor','green','facecolor','green');
		for i=data.carsdist(1)+data.carsdist(2)+1:data.carsdist(1)+data.carsdist(2)+data.carsdist(3)
			%if has nospeed
			if data.allcars(i,4)~=0
				continue;
			end
			data.allcars(i,4)=1;
		end
		for i=data.carsdist(1)+data.carsdist(2)+data.carsdist(3)+1:data.carsdist(1)+data.carsdist(2)+data.carsdist(3)+data.carsdist(4)
			if data.allcars(i,4)~=0
				continue;
			end
			data.allcars(i,4)=-1;
		end
	end
	if hstatus==data.gtime && data.status73==0
		%change green to orange
		data.status73=1;
		set(data.light73,'edgecolor','#F6E124','facecolor','#F6E124');
		set(data.light37,'edgecolor','#F6E124','facecolor','#F6E124');
	end
	if hstatus==data.gtime+data.otime && data.status73==1
		%change orange to red
		data.status73=2;
		set(data.light73,'edgecolor','red','facecolor','red');
		set(data.light37,'edgecolor','red','facecolor','red');
	end
	%19lights
	if hstatus==0 && data.status19==1
		%change orange to red
		data.status19=2;
		set(data.light19,'edgecolor','red','facecolor','red');
		set(data.light91,'edgecolor','red','facecolor','red');
	end
	if hstatus==data.gtime+data.otime && data.status19==2
		%change red to green
		data.status19=0;
		set(data.light19,'edgecolor','green','facecolor','green');
		set(data.light91,'edgecolor','green','facecolor','green');
		for i=1:data.carsdist(1)
			if data.allcars(i,3)~=0
				continue;
			end
			data.allcars(i,3)=-1;
		end
		for i=data.carsdist(1)+1:data.carsdist(1)+data.carsdist(2)
			if data.allcars(i,3)~=0
				continue;
			end
			data.allcars(i,3)=1;
		end
	end
	if hstatus==data.rtime+data.gtime && data.status19==0
		%change green to orange
		data.status19=1;
		set(data.light19,'edgecolor','#F6E124','facecolor','#F6E124');
		set(data.light91,'edgecolor','#F6E124','facecolor','#F6E124');
	end
end