x=input('');
while (1)
   x=x+1;
   fg=0; ansx=0; ansy=0;
   for i=2:sqrt(x)
       if (mod(x,i)==0) 
           fg=1;
           break;
       end
   end
   if (fg) 
       continue;
   end
   for i=1:x
       if (i*i>x) 
           break;
       end
       tmp=floor(sqrt(x-i*i));
       if (i*i+tmp*tmp==x&&tmp>0) 
           fg=1; ansx=i; ansy=tmp;
       end
   end
   if (fg) 
       if (ansx>ansy) 
           t=ansx; ansx=ansy; ansy=t;
       end
       fprintf("%d = %d^2 + %d^2\n",x,ansx,ansy);
       break;
   end
end