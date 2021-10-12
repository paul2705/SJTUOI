function generateInput()
    stdout=fopen("mydfs.in","w");
    n=randi([1 10],1,1);
    m=randi([1 10],1,1);
    fprintf(stdout,"%d %d\n",n,m);
    map=randi([1 3],n,m);
    pos=randi([1,min(n,m)],1,2);
    for i=1:n
        for j=1:m
            if (pos==[i,j]) fprintf(stdout,"s"); end
            if (map(i,j)==1) fprintf(stdout,"."); end
            if (map(i,j)==2) fprintf(stdout,"X"); end
            if (map(i,j)==3) fprintf(stdout,"t"); end
        end
        if (i<n) fprintf(stdout,"\n"); end
    end
    fclose(stdout);
end
            