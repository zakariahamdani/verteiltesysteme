# Command to run:
# docker run -p 55443:55443/udp -p 54321:54321 -p 80:80

#### BUILD ####
## Get C++ Compiler
FROM    gcc:bullseye AS build
LABEL   maintainer Hamdani-Menke
LABEL   stage build

## Build process
# Create directories to build app
RUN     mkdir -p /shared_volume/app
# The source code to build has to be locally on the directory "sources"
COPY    ./ /shared_volume/app/
WORKDIR /shared_volume/app
# Build the files inside
RUN [ "g++","-static","-pthread","-o","main","main.cpp" ]     


#### RUN APP ####
## Get Ubuntu 18.04
FROM    ubuntu:bionic
LABEL   stage run
## Expose ports
# Port for http things
EXPOSE  8001
# Port for udp communication
EXPOSE  55443/udp
# Port for tcp communication
EXPOSE  54321
## Copy and run application
# Copy the builded files to our image
COPY    --from=build /shared_volume/app/main $HOME/
WORKDIR $HOME/
# Run the app (App get's run by docker_compose)
#CMD     $HOME/main 