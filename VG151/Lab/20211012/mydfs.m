generateInput();
stdin=fopen("mydfs.in","r");
x=fscanf(stdin,"%d");
n=x(1); m=x(2);
map=zeros(n+2,m+2);
use=zeros(n+2,m+2);
pos=[];
tmp=fscanf(stdin,"%s");
tmp=reshape(tmp(1:m*n),m,n)';
disp(tmp);
for i=1:n
    for j=1:m
        switch tmp(i,j)
            case '.', map(i+1,j+1)=1;
            case 'X', map(i+1,j+1)=2;
            case 't', map(i+1,j+1)=3;
            case 's', map(i+1,j+1)=4; pos=[i+1,j+1];
        end
    end
end
use=dfs(pos,map,use,n,m);
fprintf("Treasures You Can Reach: \n");
for i=2:n+1
    for j=2:m+1
        if (use(i,j)&&map(i,j)==3)
            fprintf("Location:(%d,%d) \n",i-1,j-1);
        end
    end
end
fclose(stdin);

function use=dfs(pos,map,use,n,m)
    if ((pos(1)==1)||(pos(1)==n+2)||(pos(2)==1)||(pos(2)==m+2)) return; end
    if (use(pos(1),pos(2))||map(pos(1),pos(2))==2) return; end
    use(pos(1),pos(2))=1;
    use=dfs(pos-[0,1],map,use,n,m);
    use=dfs(pos-[0,-1],map,use,n,m);
    use=dfs(pos-[1,0],map,use,n,m);
    use=dfs(pos-[-1,0],map,use,n,m);
end