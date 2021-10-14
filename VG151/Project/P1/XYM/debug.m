function debug(data)    %debug mode, dump variables
    if data.ischanging
        return;
    end
    allname=fieldnames(data);
    finalstr="";
    for i=1:length(allname)
        thisvar=data.(string(allname(i)));
        if class(thisvar)=="double" && length(thisvar)==1
            finalstr=finalstr+string(allname(i))+":"+string(thisvar)+";  ";
        end
    end
    data.dedown.String=finalstr;
    finalstr="carvelocity:";
    for i=1:data.carnum
        ipos=get(data.allcarshandler(i),'Position');
        finalstr=[finalstr;string(data.allcars(i,3))+","+string(data.allcars(i,4))+" ; "+ipos(1)+","+ipos(2)];
    end
    data.deleft.String=finalstr;
    finalstr="speedlist:";
    spdlist=data.speedlist;
    for i=1:size(data.speedlist,1)
        finalstr=[finalstr;string(spdlist(i,1))+","+string(spdlist(i,2))+","+string(spdlist(i,3))]; 
    end
    finalstr=[finalstr;"carsplate: "];
    f1="";
    f2="";
    f3="";
    for i=1:length(data.carsplate)
        f1=f1+" "+data.carsplate(i);
    end
    finalstr=[finalstr;f1];
    finalstr=[finalstr;"violate: "];
    for i=1:length(data.violatecars)
        f2=f2+" "+data.violatecars(i);
    end
    finalstr=[finalstr;f2];
    finalstr=[finalstr;"violatedump: "];
    for i=1:length(data.violatecarsdump)
        f3=f3+" "+data.violatecarsdump(i);
    end
    finalstr=[finalstr;f3];
    data.deright.String=finalstr;
end