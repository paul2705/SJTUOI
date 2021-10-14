function initDist(data)   %randomly Initialize car numbers of four roads
	xtemp=rand(1,4);
	xtemp=round(xtemp/sum(xtemp)*data.carnum);
	data.carsdist=xtemp;
	data.carsdist(4)=data.carnum-(sum(data.carsdist)-data.carsdist(4));
	if data.carsdist(4)<=0 || data.carsdist(1)==0 || data.carsdist(2)==0 || data.carsdist(3) ==0
		initDist(data);
	end
end