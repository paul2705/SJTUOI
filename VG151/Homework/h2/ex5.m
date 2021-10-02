x=input('');
while 1
    a=0; tmp=x;
    num=0;
    while (tmp) 
        num=num+1;
        tmp=floor(tmp/10);
    end
    tmp=x;
    while (tmp)
        tmp1=mod(tmp,10);
        tmp2=1;
        for i=1:num
            tmp2=tmp2*tmp1;
        end
        a=a+tmp2;
        tmp=floor(tmp/10);
    end
    if (x==a) 
        disp(x);
        break;
    end
    x=x+1;
    
end