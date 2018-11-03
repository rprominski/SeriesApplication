#include <iostream>
#include "../include/UserInterface.h"

using namespace std;


int main() {
    /*
    Movie m("Nazwa","Opis",10,11);
    Movie *ptr = &m;


    Movie m2("Nazwa2","Opis2",20,21);
    Movie m3("Nazwa3","Opis3",30,31);
    Movie m4("Nazwa4","Opis4",40,41);

    Series s("Nazwa11","Opis11",100,101,102,vector<string>{"monday"});
    Series s2("Nazwa22","Opis22",200,201,202,vector<string>{"tuesday"});
    Series s3("Nazwa33","Opis33",300,301,302,vector<string>{"wednesday"});
    Series s4("Nazwa44","Opis44",400,401,402,vector<string>{"thursday"});



    Pool<Movie*> pool;
    pool.add(&s);
    pool.add(&s2);
    pool.add(&s3);
    pool.add(&m4);
    pool.add(&m);
    pool.add(&m2);
    pool.add(&m3);
    pool.add(&m4);
    pool.remove("Nazwa33");

    pool.sort();
    for(auto i : pool.getRecords()) {
        cout << *i <<endl;
    }*/
    UserInterface userInterface;
    userInterface.start();
    return 0;
}