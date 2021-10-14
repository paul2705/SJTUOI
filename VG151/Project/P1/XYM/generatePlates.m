function generatePlates(data)	%generate all plates
	for i=1:data.carnum
		data.carsplate=[data.carsplate,getplate()];
	end
end

function outstr=getplate()	%generate plates number randomly
	alset=[];
	for i=48:57
		alset=[alset,char(i)];
	end
	for i=65:90
		alset=[alset,char(i)];
	end
	alchr=[];
	for i=65:90
		alchr=[alchr,char(i)];
	end
	randnum=randperm(length(alset));
	cap=alchr(floor(rand()*26)+1);
	out=alset(randnum(1:5));
	outstr=cap+" "+out;
end