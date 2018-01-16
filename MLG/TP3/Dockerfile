FROM debian:jessie

MAINTAINER Damien Reimert<damien@reimert.fr>

EXPOSE 8332
EXPOSE 8333

RUN apt-get update && apt-get install -y \
    git \
    autoconf \
    wget \
    gcc \
    make \
    g++ \
    pkg-config \
    bsdmainutils \
    libtool \
    db-util \
    libboost-all-dev \
    libevent-dev \
    libssl-dev \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /root/

RUN git clone https://github.com/bitcoin/bitcoin

WORKDIR /root/bitcoin

#RUN git checkout 0.12

#RUN ./autogen.sh

#RUN ./configure --disable-wallet
#RUN make