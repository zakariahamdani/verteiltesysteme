## Gitlab handling
- Issues for every group member task
- Milestone for every practical with assigned Issues
- commit message format = **[feat/fix/docs/style/refactor/learn/orga] #IssueId WHY** - vgl. https://github.com/angular/angular.js/commits/master
- Working on own branch for individual tasks and merging locally into master after pulling current master branch. 
- **Always check error free compilation before pushing master!**

## Naming and declaration conventions
- CamleCase notation for variables und methods - except counter variables (oneVariable, oneMethod)
- **using std::string;** etc. instead of **using namespace std;**
- Just declaration in header file and definition and declaration in cpp file
    - **[somehting.h]** someFunction(std::string, std::string, int);
    - **[something.cpp]** someFunction(std::string name, std::string sirname, int age){**implementation**}
- **p_variable** notation for arguments in constructor initialization list to avoid shadow warnings
