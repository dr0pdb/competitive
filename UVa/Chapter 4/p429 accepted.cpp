#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int main()
{  
    int T;
    cin >> T;
    while ( T-- )
    {
        vector<string> words;
        
        string word;
        while (cin >> word, word != "*")
            words.push_back(word);

        cin.ignore();

        string line;
        while (getline(cin, line) && line != "")
        {
            stringstream ss(line);
            string s, t;
            ss >> s >> t;
            // BFS
            queue<string> q;
            map<string, int> trans;

            trans[s] = 0;
            q.push(s);
            while (!q.empty() && trans.count(t) == 0)
            {
                string u = q.front();
                q.pop();
                // Loop over every word in the dictionary.
                for (size_t i = 0; i < words.size(); ++i)
                {
                    const string &v = words[i];
                    if (! trans.count(v) && u.length() == v.length())
                    {
                        int diff = 0;
                        for (size_t j = 0; j < u.length(); ++j)
                            if (u[j] != v[j])
                                ++diff;
                        if (diff == 1)
                        {
                            trans[v] = trans[u] + 1;
                            q.push(v);
                        }
                    }
                }
            }    
            cout << s << " " << t << " " << trans[t] << endl;
        }
        if (T)
                cout << endl;
    }
    return 0;
}


/*
NOT WORKING :(

#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

std::map<string, int> si;
std::vector<string> istr;

std::vector<std::vector<int> > adjlist(200);

bool check(string a, string b){
    int c=0;
    if (a.length() != b.length())
    {
        return false;
    }

    F(i, 0, b.length()){
        if (a[i] != b[i])
        {
            c++;
        }
    }

    if (c>1)
    {
        return false;
    }
    return true;
}

int main(){
    std::ios::sync_with_stdio(false);
    
    int t,counter;
    cin>>t;

    while(t--){
        //resetting the values
        si.clear();
        istr.clear();
        counter=0;

        string s;
        
        //getting the input
        while(cin>>s && s!="*"){
            istr.push_back(s);
            si[s]=counter++;

            //making the graph edges
            F(i, 0, counter-1){
                if (check(istr[i],istr[counter-1]))
                {
                    adjlist[counter-1].push_back(i);
                    adjlist[i].push_back(counter-1);
                }
            }
        }
        string s1,s2;
        getline(cin,s);
        getline(cin,s);
        while(s != ""){  
            int pos = s.find(" ");
            s1 = s.substr(0,pos);
            s2 = s.substr(pos+1,s.length());
            //bfs to find answer
            queue<int> q;
            bool visited[counter]={false};
            bool ansFound=false;
            q.push(si[s1]);
            int level[counter]={0};
            int depth=1;
            while(!q.empty() && !ansFound){
                int curr= q.front();
                q.pop();

                visited[curr]=true;
                
                F(i, 0, adjlist[curr].size()){
                    int j=adjlist[curr][i];
                    if (!visited[j])
                    {
                        //cout<<istr[adjlist[curr][i]]<<" in the adjlist of "<<istr[curr]<<endl;
                        q.push(j);
                        level[j]=depth;
                        //cout<<istr[adjlist[curr][i]]<<"  "<<depth<<endl;
                        visited[j]=true;
                        if(istr[j] == s2){
                            ansFound=true;
                            break;
                        }   
                    }
                    
                }
                depth++;
            }
            cout<<s1<<" "<<s2<<" "; 
            if (s1.size() < level[si[s2]])
            {
                cout<<s1.size()<<"\n";
            }else{
                cout<<level[si[s2]]<<"\n";
            }

            if (!getline(cin,s))
            {
                break;
            }
            
        }
    }
    return 0;
}


*/