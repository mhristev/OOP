#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

template <class T>
class Graph {
    vector<T> Node;
    map<T, T> connections;
public:
    Graph() {}

    int add_element(T element) {
        for (int i = 0; i < Node.size(); i++) {
           if (Node[i] == element)
            throw "You cant add this element!";
        }
        Node.push_back(element);

        return Node.size() - 1;
    }

    void connection(int a, int b) {
        connections.insert(pair<T, T>(Node[a], Node[b]));
    }

    void print() {
        for (T it : Node) {
            cout << it << endl;
        }
    }

};


int main(){
try {
    Graph<int>intGraph;
    int el = intGraph.add_element(8);
    int el4 = intGraph.add_element(8);
    //cout << el4 << endl;
    int el2 = intGraph.add_element(10);
    intGraph.add_element(12);
    intGraph.print();
    intGraph.connection(el, el2);
}catch(const char* error) {
    cout << error << endl;
}
}