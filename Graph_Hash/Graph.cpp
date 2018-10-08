#include "Graph.h"
using std::vector;
using std::string;
//initializes pointers with input size
Graph::Graph(int size)
    :map(new DblyLinkedList<string>[size])//initializes map as array and sets size }
    , name(new std::string[size])//initializes name as array and sets size
    , visited(new bool[size])//initializes visited as array and sets size
{
    this->size = size;//sets this->size
    this->falsify();//fills visited with false
}

//clears arrays from memory, restores size to 0
Graph::~Graph()
{
    delete[] this->map;
    delete[] this->name;
    delete[] this->visited;
    this->size = 0;
}
//finds location for source to be placed in array
   //modification on the Bernstein Hash
int Graph::hash(string src)
{
    int hashVal = 5381;
    for (char c : src)
        hashVal = (hashVal << 5) + static_cast<int>(c);
    return abs(hashVal % this->size);
    //using abs because previous use of this hash led to a negative number
}

//At Graph call, fills visited array with bool value false. 
//After each search is complete the visited array is refilled with bool value false
void Graph::falsify()
{
    for (int i = 0; i < this->size; i++)//moves through array
        this->visited[i] = false;//sets each location to false
}

//depth first taversal prints out each edge and traverses through the edge's related vertecies
void Graph::depthFirst(int index)
{
    std::cout << index << ".\t" << name[index] << std::endl;//prints index and location name
    node<std::string> *p = this->map[index].getHead();//*p points to edge in array
    this->visited[index] = true;//sets location to true given it is now visited
    while (p != NULL)//moves through vertecies in edge
    {
        if (searchName(p->data))//looks to see is name is in array
        {
            index = getIndex(p->data);//obtains index of vertex
            if (!this->visited[index])//checks if vertex has be visited
                this->depthFirst(index);//recures with index
        }
        p = p->next;//moves to next vertex
    }
}


//addes edge and vertex to map using hashing(linear probing)
void Graph::addEdge(string src, string des)
{
    int index = 0;//initializes index
    if (searchName(src)) {//checks if source(edge) already exits
        index = getIndex(src);//gathers index of source(edge)
        this->map[index].addEnd(des);//adds destination(vertex) to end of source
    }
    else
    {
        index = this->hash(src);//else is source does not exits a hash is found
        int isFull = index;
        while (this->map[index].getHead() != NULL)//checks is location is occupied
        {
            index++;//if occupied, move to next position in array
            if (index == this->size)//checks if at end of array
                index = 0;//moves to beginning of array
            else if (index == isFull)//if index loops back to original index, array is full
            {  //output to increase space to add source
                std::cerr << "Space is full, increment space at Graph g(_space_)";
                exit(-2);//exit loop to prevent infinante looping
            }
        }
        this->map[index].addEnd(src);//once open position is found, source(edge) is added
        this->map[index].addEnd(des);//desination is added
        this->name[index] = src;//hash location and source name is captured for easier search later
    }
}

//gets hashed index associated with hashed source
int Graph::getIndex(string src)
{
    int i = 0;//sets counter
    while (this->name[i] != src)//checks if name at i is equal to src
        i++;//increments counter
    return i;//returns index
}

//checks if source is already present
bool Graph::searchName(string src)
{
    for (int i = 0; i < this->size; i++)//increments through name array
        if (this->name[i] == src)//if name is found then return true
            return true;
    return false;//else return false
}

//depth first traversal by index
void Graph::depthFirstTrav(int index)
{
    this->depthFirst(index);//call to recursive function 
                            //to allow falsify to be called after search is completed
    this->falsify();        //called after search since visited array is already set to all false
}

//depth first traversal by source
void Graph::depthBySource(std::string src)
{
    this->depthFirstTrav(this->getIndex(src));//gets index of source before moving into DFT
}

//prints entire graph
void Graph::print()
{
    for (int i = 0; i < this->size; i++) {//iterates though edges
        std::cout << i << ".\t"; this->map[i].print();//prints out edge and its verticies
    }
}