N=length(X);
for i=1:N
    if X(i)<0.5 Y(i)=1.5* X(i);
    else Y(i)=0.5*X(i)+0,5;
    end
end