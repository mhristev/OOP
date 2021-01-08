#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Musical_Play;

class Act
{
    static int id;
    vector<string> actors;
public:

    Act(vector <string> &actrs)
    {
        //cout << "in act" << endl;
        this->actors = actrs;
        this->id = id + 1;
    }

    virtual void print()
    {
        cout << id << endl;
        for(string names : actors)
        {
            cout << names << " ";
        }
        cout << endl;
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
        cout << song << endl;
    }

    class Musical_Play;
};



class Musical_Play
{
    string name;
    vector <Act> actions;
public:
    Musical_Play(string nm): name(nm) {}

    void add_action(Act action)
    {
        actions.push_back(action);
    }

    void print() const
    {
        cout << "Musical: " << name << endl;

        for(Act ac: actions)
        {
            ac.print();
        }
    }

    Act most_crowded_action() const
    {
        if(actions.size() == 0)
        {
            throw "The musical is emty";
        }

        int id;
        int br;

        for(int i = 0; i < actions.size(); i++)
        {
            if(actions[i].actors.size() > br)
            {
                br = actions[i].actors.size();
                id = i;
            }
        }

        return actions[id];
    }

    void sort()
    {   
        for(int i = 0; i < actions.size()-1; i++)
        {
            if(actions[i].id > actions[i+1].id)
            {
                swap(actions[i], actions[i+1]);
            }
        }
    }


};



int Act::id = 0;


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
    //cout << "---------" << endl;
    Musical_Act m_act(acts2, "Song");
    //cout << "--------" << endl;

    Musical_Play play1("Play1");
    
    play1.add_action(ac1);
    play1.add_action(acts2);

    play1.print();

}