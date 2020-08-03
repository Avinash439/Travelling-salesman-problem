#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;


        //    Given a complete, weighted graph in the form of an vector of vector type,
        //    returns the smallest tour that visits all nodes and starts and ends at the same
        //    node.

// Add function to add another node in the graph and lets you to add the weights of next node size. Recalculates the distance with the new node.
void addFunction(vector<vector<int>> &node)
{
    vector<int> addedNode(node.size() + 1);
    for (int i = 0; i < node.size() + 1; i++)
    {
        cin >> addedNode[i];
    }
    node.push_back(addedNode);
}

// Delete funtion to delete the node from the graph by the user interest. Delete function list the nodes.
void DeleteFunction(vector<vector<int>> &node)
{
    int number;
    cout << "Listing the nodes" << endl;

    for (int i = 0; i < node.size(); i++)
    {
        cout << "node_number: " << i + 1 << " ";
        for (int j = 0; j < node[i].size(); j++)
            cout << node[i][j] << " ";
        cout << endl;
    }
    cout << "Enter the node number to be deleted : \n";
    int nodeNum;
    cin >> nodeNum;
    node.erase(node.begin() + nodeNum - 1);
}

//shorpath function to calculate the shortest path 
int shortpath(const vector<vector<int>> &node, int &pos, int visited, vector<vector<int>> &state)
{
    if (visited == ((1 << node.size()) - 1))
        return node[pos][0]; // return to starting city

    if (state[pos][visited] != INT_MAX)
        return state[pos][visited];

    for (int i = 0; i < node.size(); ++i)
    {
        
        if (i == pos || (visited & (1 << i))) // visiting all the nodes.
            continue;

        int distance = node[pos][i] + shortpath(node, i, visited | (1 << i), state);
        if (distance < state[pos][visited])
            state[pos][visited] = distance;
        cout << " path " << pos << "\n";
    
        
    }

    return state[pos][visited];
}
// Helpfunction is used to exit the program anytime, adding node to the graph and deleting node from the graph.
void helpFunction()
{

    cout << "1.Press 'q' to exit the program anytime.\n";
    cout << "3.Press 'a' to add the node to the graph.\n";
    cout << "4.Press 'd' to delete the node from graph.\n";
    cout << "4.Press 's' to show the shortest distance.\n";
}

int main()
{
    // Inititalization
    char c;
    bool quit = 0;

    
    vector<vector<int> > node{{0,10,15,20}, {10,0,35,25}, {15,35,0,30}, {20,25,30,0} };// nodes with the weights
    cout << "Hi! Welcome to my travelling salesman solution.\n";
    cout << "1.Press 'h' for help using program\n";

    while (!quit)
    {
        vector<vector<int>> state(node.size());

        for (auto &neighbors : state)
            neighbors = vector<int>((1 << node.size()) - 1, INT_MAX);

        int pos = 0;
        cout << "Shortest Distance: " << shortpath(node, pos, 1, state) << endl;

        

        cin >> c;
        if (c == 'q' || c == 'Q')
        {
            quit = 1;
        }
        else if (c == 'h' || c == 'H')
        {
            helpFunction();
        }
        else if (c == 'a' || c == 'A')
        {
            //
            addFunction(node);
           
        }
        else if (c == 'd' || c == 'D')
        {
            DeleteFunction(node);
        }
        else if (c == 's' || c == 'S')
        {
            cout << "shortest distance: " << shortpath(node, pos, 1, state) << endl;
        }
    }

    return 0;
}


//Reference https://www.youtube.com/watch?v=JE0JE8ce1V0&t=60s

