#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Musical_Play;

class Act
{
    static int instances;
    const int id;
    vector<string> actors;
public:

    Act(vector <string> &actrs): actors(actrs), id(instances++) {}

    virtual void print()
    {
        cout << id << endl;
        for(string names : actors)
        {
            cout << names << " ";
        }
        cout << endl;
    }

    int getId() {
        return id;
    }
    friend Musical_Play;
};

class Musical_Act: public Act 
{
    string song;
public:
    Musical_Act(vector <string> &actrs, string song_name): Act(actrs), song(song_name) {}

    string getSong()
    {
        return this->song;
    }

    void print()
    {
        Act::print();
        cout << song << endl;
    }

    class Musical_Play;
};



class Musical_Play
{
    string name;
    vector <Act*> actions;
public:
    Musical_Play(string nm): name(nm) {}

    void add_action(Act &action) {
        actions.push_back(&action);
    }

    void print() const
    {
        cout << "Musical: " << name << endl;
        for(auto ac: actions)
        {
            ac->print();
        }
    }

    Act* most_crowded_action() const
    {
        if(actions.size() == 0)
        {
            throw "The musical is emty";
        }

        int id;
        int br;

        for(int i = 0; i < actions.size(); i++)
        {
            if(actions[i]->actors.size() > br)
            {
                br = actions[i]->actors.size();
                id = i;
            }
        }

        return actions[id];
    }

    void sort()
    {   
        for(int i = 0; i < actions.size()-1; i++)
        {
            if(actions[i]->id > actions[i+1]->id)
            {
                swap(actions[i], actions[i+1]);
            }
        }
    }


};



int Act::instances = 1;


int main()
{
    vector<string> acts1;
    acts1.push_back("Petar");
    acts1.push_back("swag");
    acts1.push_back("swae");

    vector <string> acts2;
    acts2.push_back("Petar2");
    acts2.push_back("swag2");
    acts2.push_back("swae2");
    //cout << "----------" << endl;
    Act ac1(acts1);
    //cout << ac1.getId() << endl;
    //cout << "---------" << endl;
    Musical_Act m_act(acts2, "Song");
    //cout << m_act.getId() << endl;
    //cout << "--------" << endl;

    Musical_Play play1("Play1");
    
    play1.add_action(ac1);
    play1.add_action(m_act);

    play1.print();

}