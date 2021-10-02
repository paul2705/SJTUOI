isstop=0;
while ~isstop
    year=input('');
    if ((mod(year,4)==0&&mod(year,100)~=0)||mod(year,400)==0)
        isstop=1; 
        fprintf("Yes, it's a leap year!!\n");
    else
        fprintf("No, it isn't a leap year! Try Again!\n");
    end
end