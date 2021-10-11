function ex6()
    n=input('');
    f=fopen('ex6.out','w');
    c=zeros(n,n);
    for i=1:n
        c(i,1)=1; c(i,i)=1;
        for j=2:i-1
            c(i,j)=c(i-1,j-1)+c(i-1,j);
        end
    end
    cnt=n-1;
    for i=1:n
        for j=1:cnt
            fprintf(f,"    ");
        end
        for j=1:i
            fprintf(f,"%8d",c(i,j));
        end
        fprintf(f,"\n");
        cnt=cnt-1;
    end
    fclose(f);
end