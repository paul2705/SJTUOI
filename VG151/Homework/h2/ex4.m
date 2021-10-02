x=input('');
while 1
    a=0; tmp=x;
    while (tmp)
        tmp1=mod(tmp,10);
        a=a+tmp1*tmp1*tmp1;
        tmp=floor(tmp/10);
    end
    if (x==a) 
        disp(x);
        break;
    end
    x=x+1;
end