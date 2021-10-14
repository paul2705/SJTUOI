function ifCanStop(data)    %if some car is crossing the road
	for i=1:data.carnum
		if (data.allcars(i,3)==0 && data.allcars(i,4)==0) || ismember(i,data.violatecars)   %Stopped, so continue
			continue;
		end
		ipos=get(data.allcarshandler(i),'Position');
		p1x=ipos(1);
		p1y=ipos(2)+ipos(4);
		p2x=ipos(1)+ipos(3);
		p2y=ipos(2);
		p3x=-data.streetwidth/2;
		p3y=data.streetwidth/2;
		p4x=data.streetwidth/2;
		p4y=-data.streetwidth/2;
		if ifoverlap(data,i)
			if data.allcars(i,4)==0 && data.allcars(i,3)>0 && (data.status19==2 || data.status19==1) && p2x<=p3x+1
				%right, should try to stop
				if data.allcars(i,3)>1
					%speedup cars,let go
					data.violatecars=[data.violatecars, i];
					data.violatecarsdump=[data.violatecarsdump, data.carsplate(i)];
					continue;
				end
				if rand()>=data.prob
					%let i and >i stop
					data.allcars(i,3)=0;
					set(data.allcarshandler(i),"Position",[-data.streetwidth/2-data.carlength(i) ipos(2:4)]);
				else
					data.violatecars=[data.violatecars, i];
					data.violatecarsdump=[data.violatecarsdump, data.carsplate(i)];
				end
				continue;
			end
			if data.allcars(i,4)==0 && data.allcars(i,3)<0 && (data.status19==2 || data.status19==1) && p1x>=p4x-1
				%left, should try to stop
				if data.allcars(i,3)<-1
					%speedup cars,let go
					data.violatecars=[data.violatecars, i];
					data.violatecarsdump=[data.violatecarsdump, data.carsplate(i)];
					continue;
				end
				if rand()>=data.prob
					data.allcars(i,3)=0;
					set(data.allcarshandler(i),"Position",[data.streetwidth/2 ipos(2:4)]);
				else
					data.violatecars=[data.violatecars, i];
					data.violatecarsdump=[data.violatecarsdump, data.carsplate(i)];
				end
				continue;
			end
			if data.allcars(i,3)==0 && data.allcars(i,4)>0 && (data.status73==2 || data.status73==1) && p1y<=p4y+1
				%up, should try to stop
				if data.allcars(i,4)>1
					%speedup cars,let go
					data.violatecars=[data.violatecars, i];
					data.violatecarsdump=[data.violatecarsdump, data.carsplate(i)];
					continue;
				end
				if rand()>=data.prob
					data.allcars(i,4)=0;
					set(data.allcarshandler(i),"Position",[ipos(1) -data.streetwidth/2-data.carlength(i) ipos(3:4)]);
				else
					data.violatecars=[data.violatecars, i];
					data.violatecarsdump=[data.violatecarsdump, data.carsplate(i)];
				end
				continue;
			end
			if data.allcars(i,3)==0 && data.allcars(i,4)<0 && (data.status73==2 || data.status73==1) && p2y>=p3y-1
				%down, should try to stop
				if data.allcars(i,4)<-1
					%speedup cars,let go
					data.violatecars=[data.violatecars, i];
					data.violatecarsdump=[data.violatecarsdump, data.carsplate(i)];
					continue;
				end
				if rand()>=data.prob
					data.allcars(i,4)=0;
					set(data.allcarshandler(i),"Position",[ipos(1) data.streetwidth/2 ipos(3:4)]);
				else
					data.violatecars=[data.violatecars, i];
					data.violatecarsdump=[data.violatecarsdump, data.carsplate(i)];
				end
				continue;
			end
		end
	end
end

function y=ifoverlap(data,i)
	ipos=get(data.allcarshandler(i),'Position');
	p1x=ipos(1);
	p1y=ipos(2)+ipos(4);
	p2x=ipos(1)+ipos(3);
	p2y=ipos(2);
	if data.allcars(i,4)==0
		%right or left
		p1x=p1x+data.allcars(i,3)*data.velocity;
		p2x=p2x+data.allcars(i,3)*data.velocity;
	end
	if data.allcars(i,3)==0
		%up or down
		p1y=p1y+data.allcars(i,4)*data.velocity;
		p2y=p2y+data.allcars(i,4)*data.velocity;
	end
	p3x=-data.streetwidth/2;
	p3y=data.streetwidth/2;
	p4x=data.streetwidth/2;
	p4y=-data.streetwidth/2;
	if p2y<=p3y && p1y>=p4y && p2x>=p3x && p1x<=p4x
		y=1;
		return;
	end
	y=0;
end