f=2*10^9;
lambda=3*10^8/f;
pas=lambda/10;
n=8;
A=rand(1,n);
Psi=rand(1,n)*2*pi;
Phi=rand(1,n)*2*pi;
t=[0:(1/f)/50:1/f];
for k=1:1:101
    for m=1:1:101
        for i=1:n
            S(k,m,i,:)=A(i)*cos(2*pi*f*t-Psi(i)-(k-1)*pas*cos(Phi(i))-(n-1)*pas*sin(Psi(i)));
        end
    end
end
