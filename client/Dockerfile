# Command to run:
# docker run -p 55443:55443/udp -p 54321:54321 -p 80:80

#### BUILD ####
## Get C++ Compiler
FROM    grpc/cxx:1.10 AS build
LABEL   maintainer Hamdani-Menke
LABEL   stage build

## Install MQTT-client
RUN     apt update
RUN     apt-get install libmosquitto-dev -y
## Build process
# Create directories to build app
RUN     mkdir -p /app
# The source code is built locally
COPY    ./ /app/
WORKDIR /app
RUN make
RUN export GRPC_TRACE=all
#&& make clean

## Expose ports
# Port for http connections
EXPOSE  8001
# Port for udp communication
EXPOSE  55443/udp
# Port for tcp communication
EXPOSE  54321
# Port for gRPC communication
EXPOSE 50051
EXPOSE 50051/udp

WORKDIR /app/
# Run the app (App get's run by docker_compose)
#CMD     ./main -i 4 