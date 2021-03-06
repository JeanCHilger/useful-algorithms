#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > cache;
string a, b;

int lcs (int pa, int pb) {
    /*
     Returns the Longest Common String between two strings.
     The arguments pa and pb must be the first position of both a and b (0, usually).
     The algorithm checks the occurrence of characters in the same order but not necessarily
     in sequence.
    */
    if (pa >= (int)a.length() || pb >= (int)b.length()) {
        return 0;              
    }
     
    if (cache[pa][pb] != -1) return cache[pa][pb];
          
    if (a[pa] == b[pb]) return cache[pa][pb] = lcs(pa+1, pb+1) + 1;
               
    int x = cache[pa][pb] = lcs(pa, pb+1);
    int y = cache[pa][pb] = lcs(pa+1, pb);
                         
    return max(x, y);                          
}


int main() {

    // change this to getline() to accept spaces
    cin >> a >> b;

    cache.assign(a.size()+1, vector<int>(b.size()+1, -1));

    cout << lcs(0, 0) << endl;
    return 0;
}
