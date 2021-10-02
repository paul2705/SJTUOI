x=input('');
d=x(1); m=x(2)-2; tmp=x(3);
if (m<=0) m=m+12; tmp=tmp-1; end
%fprintf("%d %d %d\n",d,m,tmp);
y=mod(tmp,100);
c=floor(tmp/100);
day=1+mod(d+floor((13*m-1)/5)+y+floor(y/4)+floor(c/4)-2*c,7);
switch day
    case 2, disp("Monday");
    case 3, disp("Tuesday");
    case 4, disp("Wednesday");
    case 5, disp("Thursday");
    case 6, disp("Friday");
    case 7, disp("Saturday");
    case 1, disp("Sunday");
end
