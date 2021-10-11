n=input('');
f=fopen('ex4.out','w');
for i=0:10
    fprintf(f,"%d * %d = %d\n",n,i,n*i);
end
fclose(f);