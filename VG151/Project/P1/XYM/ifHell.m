function ifHell(data,game)        %judge if two cars crashed
	for i=1:size(data.allcars,1)
		for j=i+1:size(data.allcars,1)
			ipos=get(data.allcarshandler(i),'Position');
			jpos=get(data.allcarshandler(j),'Position');
			p1x=ipos(1);
			p1y=ipos(2)+ipos(4);
			p2x=ipos(1)+ipos(3);
			p2y=ipos(2);
			p3x=jpos(1);
			p3y=jpos(2)+jpos(4);
			p4x=jpos(1)+jpos(3);
			p4y=jpos(2);
			pp3x=-data.len;
			pp3y=data.len;
			pp4x=data.len;
			pp4y=-data.len;
			if p2y<=pp3y && p1y>=pp4y && p2x>=pp3x && p1x<=pp4x && p4y<=pp3y && p3y>=pp4y && p4x>=pp3x && p3x<=pp4x
				if p2y<=p3y && p1y>=p4y && p2x>=p3x && p1x<=p4x
					data.ischanging=1;
					delete(data.player);
					sound(data.fail,data.failFs);
					if ~isempty(data.violatecarsdump)
						%list cars
						msgstr="Two cars crashed, and there is(are) "+length(data.violatecarsdump)+" car(s) that did not stop at the traffic light: ";
						for k=1:length(data.violatecarsdump)-1
							msgstr=msgstr+data.violatecarsdump(k)+",";
						end
						msgstr=msgstr+data.violatecarsdump(end)+".";
						wavemsg="";
						if data.isinfinity
							wavemsg="You survived "+data.currentwave+" wave(s).";
						end
						msgbox({msgstr,wavemsg});
					else
						wavemsg="";
						if data.isinfinity	%infinite mode
							wavemsg="You survived "+data.currentwave+" wave(s).";
						end
						msgstr="Two cars crashed!";
						msgbox({msgstr,wavemsg});
					end
					stop(game);
					delete(game);
					close;
                    return;
				end
			end
		end
	end
end