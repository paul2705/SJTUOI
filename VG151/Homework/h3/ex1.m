n=8*8;
a=zeros(1,41);
a(1)=1; a(2)=1;
for i=1:n
    for j=2:a(1)+1
        a(j)=a(j)*2;
    end
    for j=2:a(1)+1
        a(j+1)=a(j+1)+floor(a(j)/10);
        a(j)=mod(a(j),10);
    end
    while (a(a(1)+2)>0)
        a(a(1)+2)=a(a(1)+2)+floor(a(a(1)+1)/10);
        a(a(1)+1)=mod(a(a(1)+1),10);
        a(1)=a(1)+1;
    end
end
a(2)=a(2)-1;
a
for i=a(1)+1:-1:2
    fprintf("%d",a(i));
end