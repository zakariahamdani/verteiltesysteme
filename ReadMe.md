# Praktikum Verteilte Systeme
## Getting started
These instructions will cover the installation of the containers and usage information

### Prerequisites
In order to run this set of docker containers you'll need docker installed

### Installation
1. Clone this repository locally.
    ```shell
    git clone  https://code.fbi.h-da.de/istzahamd/ss21-verteiltesysteme-do1y-hamdani-menke
    ```
2. Enter the project folder and build the containers with docker-compose:
    ```shell
    docker compose build
    ```
3. To start all the containers, just run:
    ```shell
    docker compose up
    ```

### Usage
Once the containers start running, you will see the messages being transmitted by the clients to the server. 

You can access historical information from a client under the url:
>http://localhost:8001/api/[producer-consumer]/[id]

For example, you can find the historical information from the consumer with the ID 5 under:
>http://localhost:8001/api/consumer/5

## Gitlab handling
- Issues for every group member task
- Milestone for every practical with assigned Issues
- commit message format = **[feat/fix/docs/style/refactor/learn/orga] #IssueId WHY** - vgl. https://github.com/angular/angular.js/commits/master
- Working on own branch for individual tasks and merging locally into master after pulling current master branch. 
- **Always check error free compilation before pushing master!**

## Naming and declaration conventions
- CamelCase notation for variables und methods - except counter variables (oneVariable, oneMethod)
- **using std::string;** etc. instead of **using namespace std;**
- Just declaration in header file and definition and declaration in cpp file
    - **[somehting.h]** someFunction(std::string, std::string, int);
    - **[something.cpp]** someFunction(std::string name, std::string sirname, int age){**implementation**}
- **p_variable** notation for arguments in constructor initialization list to avoid shadow warnings
