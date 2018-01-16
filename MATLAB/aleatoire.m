tab = [100;200;500;1000;2000;5000;10000;100000];
X=sqrt(2)*randn(tab(1),1)+5;
subplot(4,2,1);histogram(X,'Normalization','cdf');
for i=2 :8
   X=[X;sqrt(2)*randn(tab(i,1)-tab(i-1,1),1)+5];
   subplot(4,2,i);histogram(X,25);
end