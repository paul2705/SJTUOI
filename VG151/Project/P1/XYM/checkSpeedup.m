function checkSpeedup(data) %update data.speedlist
	for i=1:size(data.speedlist,1)
		if i>size(data.speedlist,1)
			return;
		end
		if data.speedlist(i,2)<=data.intimeela
			carid=data.speedlist(i,1);
			lso=[data.allcars(carid,3) data.allcars(carid,4)];
			mk=lso/norm(lso);
			if ~isfinite(mk(1)) || ~isfinite(mk(2))
				data.speedlist(i,:)=[];
				return;
			end
			data.allcars(carid,3)=mk(1);
			data.allcars(carid,4)=mk(2);
			data.speedlist(i,:)=[];  %delete
		end
	end
end