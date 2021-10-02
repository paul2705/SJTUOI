function ex3()
    x=input(''); a=[];
    while (x)
        a=[a,mod(x,10)];
        x=floor(x/10);
    end
    for i=length(a):-1:1
        switch i
            case {9,6,3}
                if (a(i-1)+a(i-2)==0)
                    if (i==3) 
                        fprintf("%s hundred",interpret(a(i),0));
                    else
                        fprintf("%s hundred",interpret(a(i),0));
                    end
                else
                    fprintf("%s hundred and ",interpret(a(i),0));
                end
            case {8,5}, fprintf("%s ",interpret(a(i)*10+a(i-1),1));
            case 7, fprintf("million ");
            case 4, fprintf("thousand ");
            case 2, fprintf("%s",interpret(a(i)*10+a(i-1),1));
        end
    end
    fprintf("\n");
end

function s=interpret(x,opt)
    if ~opt
        switch x
            case 1, s="one";
            case 2, s="two";
            case 3, s="three";
            case 4, s="four";
            case 5, s="five";
            case 6, s="six";
            case 7, s="seven";
            case 8, s="eight";
            case 9, s="nine";
            case 0, s=[];
        end
    else
        tmp=floor(x/10);
        tmp1=mod(x,10);
        switch tmp
            case 1
                switch tmp1
                    case 0, s="ten";
                    case 1, s="eleven";
                    case 2, s="twelve";
                    case 3, s="thirteen";
                    case 4, s="fourteen";
                    case 5, s="fifteen";
                    case 6, s="sixteen";
                    case 7, s="seventeen";
                    case 8, s="eighteen";
                    case 9, s="nineteen";
                end
            case 2, s=strcat("twenty ",interpret(tmp1,0));
            case 3, s=strcat("thirty ",interpret(tmp1,0));
            case 4, s=strcat("forty ",interpret(tmp1,0));
            case 5, s=strcat("fifty ",interpret(tmp1,0));
            case 6, s=strcat("sixty ",interpret(tmp1,0));
            case 7, s=strcat("seventy ",interpret(tmp1,0));
            case 8, s=strcat("eighty ",interpret(tmp1,0));
            case 9, s=strcat("ninty ",interpret(tmp1,0));
            case 0, s=interpret(tmp1,0);
        end
    end
end