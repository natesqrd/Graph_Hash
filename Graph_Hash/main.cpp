#include <iostream>
#include "Graph.h"
#include <string>
using std::string;

//if you decide to mess around with the City class, add a string to one of the string arrays
//or take one away, change the size of the array. If you add or take away an array, change the 
//number in the size() function. 
//When adding citied to one of the arrays, move it addEdge association to the proper
//loop, if there are only 2 strings in the array, there is no need to loop it.

//Try adding more cities than there is allowed to see the error pop up.

//City connections must be atleast 2. Think of them as psudo node pointers
class City
{
public:
    //array includes name of array for PNP
    /*0*/ string Menifee[6] = { "Menifee", "Sun City", "French Valley", "Murrieta", "Canyon Lake", "Wildomar" };
    /*1*/ string Murrieta[5] = { "Murrieta", "Menifee", "French Valley", "Temecula", "Wildomar" };
    /*2*/ string Temecula[4] = { "Temecula", "Murrieta", "French Valley" , "Fallbrook" };
    /*3*/ string French_Valley[4] = { "French Valley", "Menifee", "Murrieta", "Temecula" };
    /*4*/ string Wildomar[4] = { "Wildomar","Lake Elsinore", "Murrieta", "Menifee" };
    /*5*/ string Lake_Elsinore[4] = { "Lake Elsinore", "Canyon Lake", "Wildomar", "Corona" };
    /*6*/ string Sun_City[3] = { "Sun City", "Menifee", "Perris" };
    /*7*/ string Canyon_Lake[3] = { "Canyon Lake","Lake Elsinore","Menifee" };
    /*8*/ string Corona[3] = { "Corona", "Riverside", "Lake Elsinore" };
    /*9*/ string Riverside[3] = { "Riverside", "Corona", "Moreno Valley" };
    /*10*/string Moreno_Valley[3] = { "Moreno Valley", "Riverside", "Perris" };
    /*11*/string Perris[3] = { "Perris",  "Sun City", "Moreno Valley" };
    /*12*/string Escondido[4] = { "Escondido", "Fallbrook", "San Diego", "Vista" };
    /*13*/string Fallbrook[3] = { "Fallbrook", "Escondido", "Temecula" };
    /*14*/string San_Diego[2] = { "San Diego", "Carlsbad" };
    /*15*/string Carlsbad[2] = { "Carlsbad","Vista" };
    /*16*/string Vista[3] = { "Vista", "Escondido", "Oceanside" };
    /*17*/string Oceanside[2] = { "Oceanside", "Vista" };
   
    int size() { return 18; }//-|
                            //  |
}   c;//estab City var     //   |
                          //    |
int main()               //     |
{                       //      |
    Graph g(c.size()); //<------|  
    /*
    In the loops, the Source is declaired at the beginning of the array in City
    So to add Source, 0 is only needed to be called
    All destinations can be added by use of _i_ in the loop starting at 1
    This is used for ease of writting code and is not needed

    If City is used, when adding a new Source(look at above comment)
    make a declairation of addEdge then move it to the proper loop.
    if the number of destinations is greater than 6, make new loop
    */
    for (int i = 1; i < 6; i++)
        g.addEdge(c.Menifee[0], c.Menifee[i]); //0
    for (int i = 1; i < 5; i++)
    {
        g.addEdge(c.Murrieta[0], c.Murrieta[i]); //1
    }
    for (int i = 1; i < 4; i++)
    {
        g.addEdge(c.Temecula[0], c.Temecula[i]); //2
        g.addEdge(c.French_Valley[0], c.French_Valley[i]); //3
        g.addEdge(c.Wildomar[0], c.Wildomar[i]); //4
        g.addEdge(c.Lake_Elsinore[0], c.Lake_Elsinore[i]); //5
        g.addEdge(c.Escondido[0], c.Escondido[i]);//6
    }

    for (int i = 1; i < 3; i++)
    {
        g.addEdge(c.Sun_City[0], c.Sun_City[i]);//7
        g.addEdge(c.Canyon_Lake[0], c.Canyon_Lake[i]);//8
        g.addEdge(c.Corona[0], c.Corona[i]);//9
        g.addEdge(c.Riverside[0], c.Riverside[i]);//10
        g.addEdge(c.Moreno_Valley[0], c.Moreno_Valley[i]);//11
        g.addEdge(c.Perris[0], c.Perris[i]);//12
        g.addEdge(c.Fallbrook[0], c.Fallbrook[i]);//13
        g.addEdge(c.Vista[0], c.Vista[i]);//14
    }
    g.addEdge(c.San_Diego[0], c.San_Diego[1]);//15
    g.addEdge(c.Carlsbad[0], c.Carlsbad[1]);//16
    g.addEdge(c.Oceanside[0], c.Oceanside[1]);//17

    g.print();
    std::cout << "\n";
    g.depthFirstTrav(0);
    /*for (int i = 0; i < c.size(); i++)
    {
        g.depthFirstTrav(i);
        std::cout << "\n";
    }*///try me

    
    return 0;
}