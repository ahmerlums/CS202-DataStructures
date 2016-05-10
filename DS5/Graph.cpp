#ifndef GRAPH__CPP
#define GRAPH__CPP
#include "Graph.h"

bool operator == (edge a, edge b)
{
    if (a.weight == b.weight)
        return 1;
    else
        return 0;
}

bool operator < (edge a, edge b)
{
    if (a.weight<b.weight)
        return 1;
    else
        return 0;
}

bool operator > (edge a, edge b)
{
    if (a.weight>b.weight)
        return 1;
    else
        return 0;
}
bool operator < (node a, node b)
{
}

bool operator > (node a, node b)
{
}

Graph::Graph(char* file)
{
    ifstream inputfile;
    inputfile.open(file);
    vector<string> Nodes;
    vector<string> XCor;
    vector<string> YCor;
    vector <string> origin;
    vector <string> dest;
    vector <string> dist;

    int r = 0;
    string temp;
    getline(inputfile,temp);
    int Counter = 0;
    while (!inputfile.eof())
    {
        inputfile>>temp;
        if (temp=="ARCS")
        {
            Counter = 1;
            inputfile>>temp;
        }

        if (Counter == 0)
        {
        if (r==0)
        {
         Nodes.push_back(temp);
         r=1;
        }
        else if (r==1)
        {
            XCor.push_back(temp);
            r=2;
        }
        else
        {
            YCor.push_back(temp);
            r=0;
        }
        }

        else
        {
            if (r==0)
            {
                origin.push_back(temp);
                r=1;
            }

        else if (r==1)
        {
            dest.push_back(temp);
            r=2;
        }
        else
        {
            dist.push_back(temp);
            r=0;
        }
        }
    }

    vector<string> org;
    for (int i=0;i<origin.size()-1;i++)
        org.push_back(origin[i]);

    for (int i=0;i<Nodes.size();i++)
    {
    node* a = new node();
    a->name = Nodes[i];
    a->x = atof(XCor[i].c_str());
    a->y = atof(YCor[i].c_str());
    cities.push_back(a);
    }

    for (int i=0;i<org.size();i++)
    {
        edge a;
        for (int r=0;r<Nodes.size();r++)
        {
            if (cities[r]->name == org[i])
                a.Origin=cities[r];
            if (cities[r]->name == dest[i])
                a.Dest=cities[r];
        }
        a.weight=atof(dist[i].c_str());
        arcs.push_back(a);
    }

    for (int r=0;r<Nodes.size();r++)
    {
          for (int i=0;i<org.size();i++)
          {
              if (arcs[i].Origin->name == cities[r]->name||arcs[i].Dest->name==cities[r]->name)
              {
                  cities[r]->edges.push_back(arcs[i]);
              }
          }
    }



}





node* Graph::getCity(string s)
{
    for (int i=0;i<cities.size();i++)
    {
        if (cities[i]->name == s)
            return cities[i];
    }
}
void Graph::display(node* temp)
{
	if(temp->visit)
		return;

	cout << "AT: " << temp->name;
	temp->visit = 1;
	for(int i=0; i< temp->edges.size(); i++)
	{
		if(!temp->edges[i].Origin->visit || !temp->edges[i].Dest->visit)
		cout << "->" << temp->edges[i].weight << endl;
		display(temp->edges[i].Origin);
		display(temp->edges[i].Dest);
	}

}
vector<node*> Graph::Kruskal()
{
    pqueue<edge> a;

    for (int i=0;i<arcs.size();i++)
    {
        a.insert(arcs[i]);
    }
    vector < set<node*> > b;

    for (int i=0;i<cities.size();i++)
    {
        set<node*> t;
        t.insert(cities[i]);
        b.push_back(t);
    }

    int l = a.numE;
      set<node*>::iterator it;
      vector<edge> h ;
    for (int i=1;i<=l;i++)
    {
        edge e = a.ExtractMin();
        bool is_in = 0 ;

        bool is_in1 =0;
        int t1;
        int t2;
        int c1=0;
        int c2=0;
        for (int r=0;r<b.size();r++)
        {
            if (is_in==0)
                is_in = b[r].find(e.Origin) != b[r].end();
            if (is_in==1&&c1==0)
            {
                    t1=r;
                    c1=1;
            }
            if (is_in1==0)
                is_in1 = b[r].find(e.Dest) != b[r].end();

            if (is_in1==1&&c2==0)
            {
                    t2=r;
                    c2=1;
            }
        }

        if (is_in==1&&is_in1==1&&t1!=t2)
        {
            for (it=b[t2].begin(); it!=b[t2].end(); it++)
            {
                node* s = *it;
                b[t1].insert(s);
            }
            b.erase (b.begin()+t2);
            h.push_back(e);

        }
    }
    for (int i=0;i<cities.size();i++)
    {
        Mst.push_back(cities[i]);
        Mst[i]->edges.clear();
    }

    for (int r=0;r<Mst.size();r++)
    {
          for (int i=0;i<h.size();i++)
          {
              if (h[i].Origin->name == Mst[r]->name||h[i].Dest->name==Mst[r]->name)
              {
                  Mst[r]->edges.push_back(h[i]);
              }
          }
    }



    return Mst;
}

vector<string> Graph::Dijkstra(string city, string destination, float &d)
{
}
#endif
